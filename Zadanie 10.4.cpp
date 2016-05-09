#include <iostream>
using namespace std;

/*
Zadanie 10.4. Bowling

Napisz program, który policzy punkty gracza graj¹cego w bowling.

Game rules:

Each game, or "line" of bowling, includes ten turns, or "frames" for the bowler.
In each frame, the bowler gets up to two tries to knock down all the pins.
If in two tries, he fails to knock them all down, his score for that frame is the total number of pins knocked down in his two tries.
If in two tries he knocks them all down, this is called a "spare" and his score for the frame is ten plus the number of pins knocked down on his next throw (in his next turn).
If on his first try in the frame he knocks down all the pins, this is called a "strike". His turn is over, and his score for the frame is ten plus the simple total of the pins knocked down in his next two rolls.
If he gets a spare or strike in the last (tenth) frame, the bowler gets to throw one or two more bonus balls, respectively. These bonus throws are taken as part of the same turn. If the bonus throws knock down all the pins, the process does not repeat: the bonus throws are only used to calculate the score of the final frame.
The game score is the total of all frame scores.
More info on the rules at: www.topendsports.com/sport/tenpin/scoring.htm
 

Wymagania do programu:

Program posiada funkcjê int rzut(int iloscKregli);
Za pomoc¹ tej funkcji symulujemy rzut kul¹. Argument iloscKregli to liczba zbitych krêgli w jednym rzucie. Funkcja zwraca ca³kowit¹ punktacjê po danym rzucie.
Funkcja int rzut(int iloscKregli);  po ka¿dym rzucie wypisze na ekran za pomoc¹ polecenia cout komunikat: "runda x, rzut y"
Po ostatnim rzucie na ekranie pojawi siê komunikat: "Koniec gry. Uzyskane punkty: x", gdzie x to suma zdobytych punktów.
 

Przyk³adowy kod s³u¿¹cy do testowania programu:

int score = 0;
score = rzut(4); // funkcja zwróci 4. Komunikat na ekranie: "runda 1, rzut 1" 
score = rzut(3); // funkcja zwróci 7. Komunikat na ekranie: "runda 1, rzut 2"
score = rzut(10); // funkcja zwróci 17. Kolejne dwa rzuty bêd¹ punktowane podwójnie (strike). Komunikat na ekranie: "runda 2, rzut 1"
score = rzut(8); // funkcja zwróci 33. Rzut by³ punktowany podwójnie. Komunikat na ekranie: "runda 3, rzut 1"
score = rzut(2); // funkcja zwróci 37. Rzut by³ punktowany podwójnie. Kolejny rzut te¿ bêdzie punktowany podwójnie (spare). Komunikat na ekranie: "runda 3, rzut 2"
score = rzut(0); // funkcja zwróci 37. Komunikat na ekranie: "runda 4, rzut 1"
score = rzut(4); // funkcja zwróci 41. Komunikat na ekranie: "runda 4, rzut 2"
 

Uwagi, które mog¹ byæ przydatne podczas pisania programu:

W rundach 1 - 9 gracz mo¿e wykonaæ 1 rzut (strike) lub 2 rzuty.
W rundzie 10 mo¿e wykonaæ 2 lub 3 rzuty (jeœli bêdzie mia³ rzut bonusowy po strike lub spare)
Testy automatyczne polegaj¹ na wywo³ywaniu funkcji rzut() i sprawdzaniu, czy zwrócony wynik jest prawid³owy.
Aby program dzia³a³ prawid³owo, za pomoc¹ zmiennych trzeba zapamiêtaæ numer rundy, numer rzutu oraz wynik gry. Mo¿na to zrobiæ deklaruj¹c zmienne globalne (sposób przez nas niepolecany) lub deklaruj¹c wewn¹trz funkcji rzut() zmienne statyczne (sposób polecany). Zmienne statyczne deklaruje siê nastêpuj¹co:
static int runda = 0;
static int rzut = 0;
static int punkty = 0;
Mimo, ¿e nie opisywaliœmy do tej pory dzia³ania zmiennych globalnych, to warto sprawdziæ samemu, czym takie zmienne siê charakteryzuj¹ i jak dzia³aj¹.
W sytuacji, kiedy gracz rzuci dwa razy strike pod rz¹d, kolejny rzut jest punktowany potrójnie! Przyk³ad opisuj¹cy ten wyj¹tek:
int score = 0;
score = rzut(10); 
// "runda 1, rzut 1" Wyst¹pi³ strike: kolejne dwa rzuty bêd¹ punktowane podwójnie

score = rzut(10); 
// "runda 2, rzut 1" Ten rzut punktowany jest podwójnie, poniewa¿ w rundzie 1 by³ strike. W sumie rzut uzyska 20 pkt: +10 pkt do rundy 1, +10 pkt do rundy 2. Jednak w tej rundzie (runda 2) te¿ jest strike: kolejne dwa rzuty bêd¹ punktowane podwójnie.

score = rzut(3); 
//  "runda 3, rzut 1" Ten rzut punktowany jest podwójnie, poniewa¿ w rundzie 1 by³ strike. Jednak tak¿e w rundzie 2 by³ strike, który ka¿e ten rzut punktowaæ podwójnie. Sumuj¹c: rzut uzyska ³¹cznie 9 punktów: +3 pkt do rundy 1, +3 pkt do rundy 2, +3 pkt do rundy 3.

score = rzut(5); 
//  "runda 3, rzut 2" Ten rzut punktowany jest podwójnie, poniewa¿ w rundzie 2 by³ strike. Rzut uzyska 10 pkt: +5 pkt do rundy 2, +5 pkt do rundy 3.
*/


/****************************************************
*
*	int rzut(int iloscKregli)
*
*****************************************************/

int rzut(int iloscKregli){
	
	static int runda = 0;
	static int rzut = 0;
	static int sumaPunktow = 0;
	
	int punkty = iloscKregli;
	
	static int tablica[11] [2] = {0};									// = tablica [runda] [rzut] ; 10 rund + 1 extra
	static int licznikStrike[2] = {0};									// = 2 liczniki zmian punktacji 'strike' /.. drugi licznik bo premia z jednego 'strike' moze zachodzic na drugi 'strike'
	static int licznikSpare[1] = {0};									// = 1 licznik zmian punktacji 'spare'
	
	int premiaStrike = 0;							
	int premiaSpare = 0;
	
		
	
	int rundaBiezaca = runda;
	int rzutBiezacy = rzut;
	static int licznikDodatkowaRunda = 0;
	int rzutDodatkowaRunda = 0;				// zmieniona numeracja dodatkowych rzutow po 10-tej rundzie (runda extra po "strike" lub "spare" w 10-tej) zaliczanych do rundy 10
	
	int koniecRozgrywki = 0;
	
	tablica[runda][rzut] = iloscKregli;									// zapamietaj ilosc zbitych kregli w tablicy rzutow
																		// rzuty z rundy extra (po rundzie 10-tej) zapamietywane jako runda 11


																		
	// oblicz premie 'strike' wynikajace z poprzednich rzutów
	
	if (licznikStrike[0] != 0){												// premia 'strike' z pierwszego licznika
		premiaStrike = premiaStrike + punkty;
		licznikStrike[0] -=1;
	}
	
	if (licznikStrike[1] != 0){												// premia 'strike' z drugiego licznika
		premiaStrike = premiaStrike + punkty;								
		licznikStrike[1] -= 1;
	}
	
	// oblicz premie 'spare' wynikajace z poprzedniego rzutu
	
	if (licznikSpare[0] != 0 ){												// premia 'spare'
		premiaSpare = punkty;
		licznikSpare[0] -= 1;
	}
	
	
	
	sumaPunktow = sumaPunktow + punkty + premiaStrike + premiaSpare;									// oblicz sume punktow po biezacej kolejce
																							// i zapamietaj wynik
	
	
	// oblicz i zapamietaj szczegolne warunki obliczen na przyszlosc
	// liczniki zmian punktacji, runde, rzut
	
	
	if ((rzut == 0) && (punkty == 10)){								//-// jezeli 'strike' to zwiêksz licznikStrike[]
	
		// ustaw na = 2 wolny licznik
		for (int i=0; i < 2; i++){											// modyfikuj licznik zmian punktacji
			if (licznikStrike[i] == 0){
				licznikStrike[i] = 2;										// licznik = 2 bo modyfikujemy kolejne 2 rzuty
				break;														// przerywamy petle zeby zmiana dotyczyla tylko jednego licznika 
			}
		}
	
		// ustaw nastepna: runda, rzut
		runda = runda + 1;															
		rzut = 0;															// pomin II rzut
		
	} else if ((tablica[runda][0] + tablica[runda][1]) == 10){				//-// jezeli 'spare' to zwieksz licznikSpare[]
		
		// ustaw licznik na 1
		licznikSpare[0] = 1;	
		
		// ustaw nastepna: runda, rzut
		runda = runda + 1;														
		rzut = 0;														
		
	} else if (rzut == 1){													// jezeli zwykly rzut , bez premii
		
		// ustaw nastepna: runda, rzut
		runda += 1;
		rzut = 0;
	} else { // (rzut == 0)
		
		// ustaw nastepna: runda, rzut
		//runda = runda;
		rzut = 1;
	}
	


	// wypisz informacje o Biezacej rundzie i rzucie: "runda x, rzut y"
	
	if (rundaBiezaca < 9 ){
		cout << "runda "<< rundaBiezaca + 1<< ", rzut "<< rzutBiezacy + 1 << endl;			// wypisz komunikat dla rund 1..9
	} else if (rundaBiezaca == 9){
		cout << "runda "<< rundaBiezaca + 1 << ", rzut "<< rzutBiezacy + 1 << endl;			// wypisz dla rundy 10
		if ((rzutBiezacy == 1) && (licznikStrike[0] == 0 ) && (licznikStrike[1] == 0) && (licznikSpare[0] == 0)){  
		
			// jezeli runda 10 i rzut 2 oraz nie ma aktywnego 'spare' i 'strike'
			koniecRozgrywki = 1;
		}
		
	} else { 
			// jezeli runda 11 extra (index = 10)
			// zalicz rzuty z rundy 11 do rundy 10
			// kontynuujac numeracje z rundy 10
			if (tablica[9][0] == 10) {			// wypisz komunikat dla rundy extra (11-tej)
				// jezeli 11 runda wynika z warunku 'strike' w 10-tej
				licznikDodatkowaRunda += 1; 
				rzutDodatkowaRunda = licznikDodatkowaRunda + 1;
				if (rzutDodatkowaRunda == 3 ) { 
					
					koniecRozgrywki = 1;
				
				}
			} else if ((tablica[9][0] + tablica[9][1]) == 10){
				//jezeli 11 runda wynika z warunku 'spare' w 10-tej
				licznikDodatkowaRunda += 1; 
				rzutDodatkowaRunda = licznikDodatkowaRunda + 2;
				
				if (rzutDodatkowaRunda == 3 ) { 
					
					koniecRozgrywki = 1;
				
				}
			}
			
			// wypisz komunikat dla rundy 11 extra
			cout << "runda "<< 10 << ", rzut "<< rzutDodatkowaRunda << endl;
							
	}




	// jezeli koniec rozgrywki

	
	if (koniecRozgrywki){
		// wyzeruj zmienne
		runda = 0;
		rzut = 0;
																			// jezeli ostatnia rozgrywka (runda 10/11)
		int sumaPunktowTemp = sumaPunktow;									// zapamientaj punkty w nowej zmiennej
		sumaPunktow = 0;													// wyzeruj star¹  - przygotowanie do nowej rozgrywki liczonej od 0
		return sumaPunktowTemp;												// zwroc wynik jezeli ostatnia runda
	}


	// jezeli jeszcze nie koniec rozgrywki
																			
	return sumaPunktow;														// zwroc wynik 
	
	
}
//***



/****************************************************
*
*	main
*
*****************************************************/


int main()
{
	cout << rzut(5) << endl;
	cout << rzut(3) << endl;
	
	cout << rzut(5) << endl;
	cout << rzut(5) << endl;
	
	cout << rzut(10) << endl;
	
	cout << rzut(10) << endl;
	
	cout << rzut(10) << endl;
	
	//6
	cout << rzut(5) << endl;
	cout << rzut(2) << endl;
	
	//7
	cout << rzut(2) << endl;
	cout << rzut(2) << endl;
	
	//8
	cout << rzut(5) << endl;
	cout << rzut(3) << endl;
	
	//9
	cout << rzut(5) << endl;
	cout << rzut(5) << endl;
	
	//10
	cout << rzut(5) << endl;
	cout << rzut(5) << endl;

	//11
	cout << rzut(2) << endl;
//	cout << rzut(2) << endl;






	return 0;
}

