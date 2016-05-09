//	
//	Name: .../kuzniaprogramistow/zadaniakorekta/Zadanie 10.4-2.cpp
//	Copyright: ?
//	Author: Tomasz Sobolewski (tso)
//	Date: 30-01-14 23:23/03-02-14 16:21/04-02-14 22:09
//	Description: KOREKTA pierwszej wersji programu, teraz rzuty zapisywane w tablicy 'liniowej' d³ugosci 21 pol
//	
//	
//	Zadanie 10.4. Bowling
//	
//	Napisz program, który policzy punkty gracza graj¹cego w bowling.
//	
//	Game rules:
//	
//	Each game, or "line" of bowling, includes ten turns, or "frames" for the bowler.
//	In each frame, the bowler gets up to two tries to knock down all the pins.
//	If in two tries, he fails to knock them all down, his score for that frame is the total number of pins knocked down in his two tries.
//	If in two tries he knocks them all down, this is called a "spare" and his score for the frame is ten plus the number of pins knocked down on his next throw (in his next turn).
//	If on his first try in the frame he knocks down all the pins, this is called a "strike". His turn is over, and his score for the frame is ten plus the simple total of the pins knocked down in his next two rolls.
//	If he gets a spare or strike in the last (tenth) frame, the bowler gets to throw one or two more bonus balls, respectively. These bonus throws are taken as part of the same turn. If the bonus throws knock down all the pins, the process does not repeat: the bonus throws are only used to calculate the score of the final frame.
//	The game score is the total of all frame scores.
//	More info on the rules at: www.topendsports.com/sport/tenpin/scoring.htm
//	 
//	
//	Wymagania do programu:
//	
//	Program posiada funkcjê int rzut(int iloscKregli);
//	Za pomoc¹ tej funkcji symulujemy rzut kul¹. Argument iloscKregli to liczba zbitych krêgli w jednym rzucie. Funkcja zwraca ca³kowit¹ punktacjê po danym rzucie.
//	Funkcja int rzut(int iloscKregli);  po ka¿dym rzucie wypisze na ekran za pomoc¹ polecenia cout komunikat: "runda x, rzut y"
//	Po ostatnim rzucie na ekranie pojawi siê komunikat: "Koniec gry. Uzyskane punkty: x", gdzie x to suma zdobytych punktów.
//	 
//	
//	Przyk³adowy kod s³u¿¹cy do testowania programu:
//	
//	int score = 0;
//	score = rzut(4); // funkcja zwróci 4. Komunikat na ekranie: "runda 1, rzut 1" 
//	score = rzut(3); // funkcja zwróci 7. Komunikat na ekranie: "runda 1, rzut 2"
//	score = rzut(10); // funkcja zwróci 17. Kolejne dwa rzuty bêd¹ punktowane podwójnie (strike). Komunikat na ekranie: "runda 2, rzut 1"
//	score = rzut(8); // funkcja zwróci 33. Rzut by³ punktowany podwójnie. Komunikat na ekranie: "runda 3, rzut 1"
//	score = rzut(2); // funkcja zwróci 37. Rzut by³ punktowany podwójnie. Kolejny rzut te¿ bêdzie punktowany podwójnie (spare). Komunikat na ekranie: "runda 3, rzut 2"
//	score = rzut(0); // funkcja zwróci 37. Komunikat na ekranie: "runda 4, rzut 1"
//	score = rzut(4); // funkcja zwróci 41. Komunikat na ekranie: "runda 4, rzut 2"
//	 
//	
//	Uwagi, które mog¹ byæ przydatne podczas pisania programu:
//	
//	W rundach 1 - 9 gracz mo¿e wykonaæ 1 rzut (strike) lub 2 rzuty.
//	W rundzie 10 mo¿e wykonaæ 2 lub 3 rzuty (jeœli bêdzie mia³ rzut bonusowy po strike lub spare)
//	Testy automatyczne polegaj¹ na wywo³ywaniu funkcji rzut() i sprawdzaniu, czy zwrócony wynik jest prawid³owy.
//	Aby program dzia³a³ prawid³owo, za pomoc¹ zmiennych trzeba zapamiêtaæ numer rundy, numer rzutu oraz wynik gry. Mo¿na to zrobiæ deklaruj¹c zmienne globalne (sposób przez nas niepolecany) lub deklaruj¹c wewn¹trz funkcji rzut() zmienne statyczne (sposób polecany). Zmienne statyczne deklaruje siê nastêpuj¹co:
//	static int runda = 0;
//	static int rzut = 0;
//	static int punkty = 0;
//	Mimo, ¿e nie opisywaliœmy do tej pory dzia³ania zmiennych globalnych, to warto sprawdziæ samemu, czym takie zmienne siê charakteryzuj¹ i jak dzia³aj¹.
//	W sytuacji, kiedy gracz rzuci dwa razy strike pod rz¹d, kolejny rzut jest punktowany potrójnie! Przyk³ad opisuj¹cy ten wyj¹tek:
//	int score = 0;
//	score = rzut(10); 
//	 "runda 1, rzut 1" Wyst¹pi³ strike: kolejne dwa rzuty bêd¹ punktowane podwójnie
//	
//	score = rzut(10); 
//	 "runda 2, rzut 1" Ten rzut punktowany jest podwójnie, poniewa¿ w rundzie 1 by³ strike. W sumie rzut uzyska 20 pkt: +10 pkt do rundy 1, +10 pkt do rundy 2. Jednak w tej rundzie (runda 2) te¿ jest strike: kolejne dwa rzuty bêd¹ punktowane podwójnie.
//	
//	score = rzut(3); 
//	  "runda 3, rzut 1" Ten rzut punktowany jest podwójnie, poniewa¿ w rundzie 1 by³ strike. Jednak tak¿e w rundzie 2 by³ strike, który ka¿e ten rzut punktowaæ podwójnie. Sumuj¹c: rzut uzyska ³¹cznie 9 punktów: +3 pkt do rundy 1, +3 pkt do rundy 2, +3 pkt do rundy 3.
//	
//	score = rzut(5); 
//	  "runda 3, rzut 2" Ten rzut punktowany jest podwójnie, poniewa¿ w rundzie 2 by³ strike. Rzut uzyska 10 pkt: +5 pkt do rundy 2, +5 pkt do rundy 3.
//

#include <iostream>
using namespace std;

/****************************************************
*
*	int rzut(int iloscKregli)
*
*****************************************************/

int rzut(int iloscKregli) {
	
	static int runda = 0;
	static int rzut = 0;
	static int punktyGry = 0;

	static int rzutKolejki = 0;					// indeks rzutów danej kolejki, wyjatek dla kolejki 10 => max trzy rzuty
	static int rzutyKolejki10 = 0;				// indeks rzutow w kolejce 10

	static int tablica[21] = {0};				// tablica [rzut] rzutow w rundach 1..9 (9 x 2 rzuty) + 3 rzuty (kolejka 10) = 21 rzutów

	static int iloscPremiiStrike[2] = {0};		// = 2 liczniki premii punktacji po 'strike' (drugi licznik bo premia z jednego 'strike' moze zachodzic na drugi 'strike')
	static int iloscPremiiSpare[1] = {0};		// = 1 licznik premii punktacji po 'spare'

	int premiaStrike = 0;							
	int premiaSpare = 0;


	// wypisz komunkiat: "runda x, rzut y"
	cout << "runda " << runda+1 << ", rzut " << rzutKolejki+1 << endl;				// wypisz komunikat

	// zapisz ilosc zbitych kregli w tablicy rzutow
	tablica[rzut] = iloscKregli;		


	// oblicz premie 'strike' wynikajace z przebiegu dotychczasowej gry
	// na podstawie dwoch licznikow:
	// 	licznik..[0] - pierwszy licznik premii 'strike'
	// 	licznik..[1] - drugi licznik premii 'strike'
	// w pierwszym rzucie 1 kolejki brak premii
	// liczniki 'zasilane' s¹ w dalszej czesci programu
	
	if (iloscPremiiStrike[0] != 0 ){												// premie
		premiaStrike = premiaStrike + iloscKregli;
		iloscPremiiStrike[0] -= 1;
	}
	
	if (iloscPremiiStrike[1] != 0 ){												
		premiaStrike = premiaStrike + iloscKregli;								
		iloscPremiiStrike[1] -= 1;
	}
	
	
	// oblicz premie 'spare' wynikajace z przebiegu dotychczasowej gry
	// w pierwszej kolejce brak premii
	// licznik 'zasilany' jest w dalszej czesci programu
	
	if (iloscPremiiSpare[0] != 0 ){
		premiaSpare = iloscKregli;												
		iloscPremiiSpare[0] -= 1;
	}

	//-- suma punktów --
	// oblicz sume punktow po biezacej kolejce
	// i zapamietaj wynik do nastepnej rundy (zmienna static)
	
	punktyGry = punktyGry + iloscKregli + premiaStrike + premiaSpare;				// suma punktow	Gry						


																					
	
	
	// -- ilosci premii --
	// w zaleznosci od nr rzutu i ilosci zbitych kregli
	// ustaw liczniki ilosci premii, nr kolejnej rundy oraz
	// nr kolejnego rzutu

	if (rzutKolejki == 0){
		
		if (iloscKregli == 10){									// jezeli rzutKolejki =  0 z premia 'strike'  
		
			for (int i = 0; i < 2; i++){						
				if (iloscPremiiStrike[i] == 0){					// jezeli licznik jest wolny (wyzerowany)
					iloscPremiiStrike[i] = 2;					// to ustaw licznik = 2 (dwie kolejki doliczania premii) 
					// przerywamy petle zeby zmiana 
					// dotyczyla tylko jednego licznika 				
					break;										
				}
			}
		
			// pomin (przeskocz) II rzut i przejdz do nastepnej rundy
			rzut++;	
				
		} 
	
	
	} else {													// jezeli rzutKolejki = 1	
				
		if ((tablica[rzut-1] + tablica[rzut]) == 10){				//-// jezeli rzut z premia 'spare' 
		
			// ustaw licznik na 1
			// bo w 1 nastepnej kolejce
			// bed¹ premiowane punkty
			iloscPremiiSpare[0] = 1;									// to ustaw iloscPremiiSpare[] na = 1
																		// bo premia bedzie liczona w 1 nastepnej kolejce									
		} 																								
	
	}
	
	
	//--  nastepna runda, nastepny rzut, zakonczenie + zwroc wynik --
	if (runda < 9){
		
		rzut++; // wartosci rzut: 0,1,2,3,4,..,17 , rzuty rund < 10 zapisywane w tablica[rzut] na indeksach 0,...17.
		runda = rzut / 2;	
		rzutKolejki = rzut % 2; // rzuty w cyklu: 0,1,0,1,0,1, ...
		
		return punktyGry;														// zwroc wynik jezeli (runda 1..9)
		
	} else {
		
		//-- licznik rzutow kolejki 10--
		// nowy licznik rzutow jest potrzebny aby uniezaleznic siê
		// od przeskoku w kolejki w przypadku stracenia 10-ciu kregli
		// w pierwszym rzucie, tj warunku 'strike'
		rzutyKolejki10++; 
		
		rzut = 17 + rzutyKolejki10; // kolejka 10 zapisywana w tablicy[rzut] na indeksach 18,..,20		
		rzutKolejki = rzutyKolejki10; // zmienna rzutKolejki uzywana do okreslania czy by³ 'strike' czy 'spare' czy rzut bez premii
	
		
	
		//-- zakonczenie gry --	
		// jezeli runda 10 i rzut 2 oraz uwzgledniono wszystkie premie 'spare' i 'strike'
		if (((rzutKolejki == 2) && (iloscPremiiSpare[0] == 0) && (iloscPremiiStrike[0] == 0) && (iloscPremiiStrike[1] == 0)) 
			// lub runda 10 i rzut 3
			|| (rzutKolejki > 2)){  
			
			//cout << "*****" << rzutKolejki << endl;
			
			// przygotuj zmienne statyczne	
			// do nowej rozgrywki
			runda = 0;
			rzut = 0;
			rzutKolejki = 0;
			rzutyKolejki10 = 0;
		
			// i zwróc ilosc dotychczas zdobytych punktów,
			// zapamientaj punkty w zmiennej tymczasowej,
			// wyzeruj star¹ - punkty nowej rozgrywki bed¹ liczona od 0															
			int punktyNaZakonczenieGry = punktyGry;
			punktyGry = 0;					
			return punktyNaZakonczenieGry;										// zwroc wynik (jezeli runda 10, ostatni rzut)
		}
		
		//-- zwroc wynik --
		return punktyGry;														// zwroc wynik jezeli (runda 10)
	}															
}
//***



/****************************************************
*
*	main
*
*****************************************************/


int main()
{
	// przyk³adowe dane testowe dla trzech rozgrywek
	
	//1
	cout << rzut(5) << endl;
	cout << rzut(3) << endl;
	
	//2 
	cout << rzut(5) << endl;
	cout << rzut(5) << endl;
	
	//3 
	cout << rzut(10) << endl;
	
	//4 
	cout << rzut(10) << endl;
	
	//5 
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

// ******************************

	//1
	cout << rzut(5) << endl;
	cout << rzut(3) << endl;
	
	//2 
	cout << rzut(5) << endl;
	cout << rzut(5) << endl;
	
	//3 
	cout << rzut(10) << endl;
	
	//4 
	cout << rzut(10) << endl;
	
	//5 
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
	cout << rzut(10) << endl;
	//cout << rzut(5) << endl;

	//11
	cout << rzut(2) << endl;
	cout << rzut(2) << endl;
	
//***************************************

	//1
	cout << rzut(5) << endl;
	cout << rzut(3) << endl;
	
	//2 
	cout << rzut(5) << endl;
	cout << rzut(5) << endl;
	
	//3 
	cout << rzut(10) << endl;
	
	//4 
	cout << rzut(10) << endl;
	
	//5 
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
	cout << rzut(3) << endl;
	cout << rzut(3) << endl;

	//11
	cout << rzut(2) << endl;
//	cout << rzut(2) << endl;


char test ('p');




	return 0;
}

