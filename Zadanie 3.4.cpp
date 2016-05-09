#include <iostream>
using namespace std;

/*
Zadanie 3.4. Dart - 301

Je�eli uczyli�cie si� je�dzi� na rowerze metod� prowadzenia na kiju przez osob� starsz�, to pewnie pami�tacie dzie�, w kt�rym odwr�cili�cie si� za siebie i okaza�o si�, �e jedziecie samodzielnie. Wasz tata (albo starszy brat, albo inny mentor) stwierdzi�, �e radzicie sobie na tyle dobrze, �e mo�e Was ju� pu�ci�. Cz�sto ko�czy�o si� to upadkiem, ale upadki to cz�� nauki.

My doszli�my w uczeniu Was do podobnego momentu - uwa�amy, �e nie musimy ju� trzyma� kija i mo�emy pozwoli� Wam pobawi� si� samodzielnie. Teraz r�wnie� przygotowali�my zadanie �yciowe: chcieliby�my �eby�cie napisali program, kt�ry zlicza punkty w darta.

Zasady gry 301 dla 1 gracza:
Jest to najbardziej znana gra w darta. Grana w wi�kszo�ci Dart-ligach i wielu turniejach. Zawodnik zaczyna gr� od stanu punktowego 301. Na koniec ka�dej kolejki (po rzuceniu 3 rzutek) odejmuje si� sum� zdobytych punkt�w od poprzedniego stanu punktowego. Zawodnik, musi zredukowa� ilo�� punkt�w dok�adnie do zera. Gdy zawodnik w jednej kolejce zdob�dzie wi�cej punkt�w ni� potrzebne jest do osi�gni�cia zera - oznacza to "BUST" i nie b�d� one zapisane. Ca�kowita punktacja powraca do stanu z poprzedniej kolejki.

Tre�� zadania
Napisz program, kt�ry zlicza punkty w gr� 301 dla jednego gracza, wed�ug zasad podanych powy�ej. Program mo�e mie� dowoln� liczb� rund. W ka�dej rundzie zawodnik ma do wykorzystania 3 lotki. Ka�da lotka mo�e punktowa� w zakresie 0 � 60 punkt�w. Je�li punktacja podana przez gracza b�dzie mie�ci�a si� w tym zakresie, nie b�dziemy sprawdzali poprawno�ci punkt�w (w prawdziwej grze zawodnik nie ma szans zdoby� np. 59 punkt�w w jednym rzucie, a w naszej grze mo�e). Je�li jednak warto�� jednego rzutu nie mie�ci si� w zakresie 0 - 60, program wy�wietli komunikat: "Niepoprawna ilosc punktow".

Gra ko�czy si�, gdy zawodnik osi�gnie 0 punkt�w - nawet, je�li b�dzie to po pierwszej lub drugiej lotce, a wi�c w �rodku rundy!

W ka�dej rundzie program wy�wietli nast�puj�ce komunikaty:
Runda 1, rzut 1: Podaj ilo�� punkt�w
Runda 1, rzut 2: Podaj ilo�� punkt�w
Runda 1, rzut 3: Podaj ilo�� punkt�w
Runda 1, liczba twoich punkt�w: x

Gdzie x jest liczb� punkt�w posiadanych przez gracza, a nie ilo�ci� punkt�w zdobytych w rundzie. Przyk�adowo je�eli w pierwszej rundzie rzuci�em 20 pkt, to x = 301 � 20 = 281.
Je�eli gracz w rundzie rzuci wi�cej punkt�w ni� mu pozosta�o, zobaczymy komunikat:
Runda 1, BUST!
Liczba twoich punkt�w: x

Komunikat BUST! pojawi si� bezpo�rednio po rzucie, w kt�rym gracz przekroczy� punktacj�. Oznacza to, �e BUST! mo�e by� po 1, 2 lub 3 rzucie. Niezale�nie od numeru rzutu, BUST! zawsze ko�czy bie��c� rund�.

Na zako�czenie gry (w momencie, gdy u�ytkownik uzyska 0 pkt) program wypisze komunikat:
Gra zakonczona w rundzie X 

Dodatkowym wymaganiem jest, aby program zako�czy� si� natychmiast po wprowadzeniu przez u�ytkownika liczby -1. Po wprowadzeniu liczby punkt�w -1 program nie musi wy�wietla� na ekranie �adnego komunikatu.
*/

int main()
{
	int runda = 0;
	int rzut = 0;
	
	int punkty_rzutu = 0;
	int punkty_rundy = 0;
	int punkty_gry = 301;
	int punkty_zakonczonej_rundy = 0;
		
	while(1)
	{
		runda += 1;
		
		while (rzut < 3)
		{
				rzut += 1;
				punkty_rzutu = 0;
				
				cout << "Runda "<< runda <<", rzut "<< rzut <<": Podaj ilosc punktow ";
				cin >> punkty_rzutu;
			
			// warunek wyjscia z programu		
				if (punkty_rzutu == -1)
					{
						break;
					}
					
			// warunek czy punkty sa w zakresie 0-60 pkt. je�eli tak to cofnij licznik rzutow i powtorz rzut 
				if(punkty_rzutu < 0)
					{
						cout << "Niepoprawna ilosc punktow" << endl;
						rzut -= 1;
						punkty_rzutu = 0;
						continue;
					}
				if(punkty_rzutu > 60)
					{
						cout << "Niepoprawna ilosc punktow" << endl;
						rzut -= 1;
						punkty_rzutu = 0;
						continue;
					}
		
			
			// sumowanie punktow rundy
				punkty_rundy += punkty_rzutu;
		
		
			// sumowanie punktow gry (odejmowanie od 301pkt.)
				punkty_gry -= punkty_rzutu;
				
				
			// sprawdzenie warunkoww zakonczenia gry w trakcie rundy			
				if (punkty_gry == 0)
					{
						// komunikat "Gra zakonczona w rundzie " przeniesiony do petli while(1) obslugujacej cykl rund
						break;
					}				
			
					
			// sprawdzenie warunku BUST! i obsluga zakonczenia rundy w trybie BUST! , BUST = punkty_gry < 0
 				if (punkty_gry < 0)
					{
						cout << "Runda "<< runda <<", BUST!" << endl;
						cout << "Liczba twoich punktow: " << punkty_zakonczonej_rundy << endl;
						
						// korekta punktow
						punkty_gry = punkty_zakonczonej_rundy;
						
						//zakonczenie rundy = zakonczenie petli while
						break;				
					}

		}   // <- koniec petli while obsluguj�cej cykl 3 rzuty
		
		
	// aktualizacja licznika punkt�w zakonczonych rund	
		punkty_zakonczonej_rundy = punkty_gry;	
		
				
	// sprawdzenie warunku zakonczenia programu po wpisaniu "-1"	
		if (punkty_rzutu == -1 )
					{
						cout << "Gra zakonczona w rundzie " << runda << endl;
						break;
					}
		
	
	// wypisanie komunikatow dla uzytkownika po zakonczonej rundzie	
		if (punkty_zakonczonej_rundy == 0)
					{
						cout << "Gra zakonczona w rundzie " << runda << endl;
						break;
					}
		else 
					{
						cout << "Runda " << runda << ", liczba twoich punktow: " << punkty_zakonczonej_rundy << endl;
					}	
	
	
	// zerowanie zmiennych petli "3 rzuty"								
		rzut = 0;
		punkty_rzutu = 0;
		
		
					
	} // <- koniec petli while obslugujacej cykl rund
	
	
	return 0;
}
