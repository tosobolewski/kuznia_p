#include <iostream>
#include <stdlib.h>	/* rand() */
using namespace std;

/*
Zadanie 10.5. Paradoks urodzin

Paradoks urodzin brzmi: prawdopodobie�stwo, �e w grupie 23 os�b co najmniej dwie z nich maj� urodziny tego samego dnia w roku, jest wi�ksze od 50%. 
Napisz program, kt�ry b�dzie symulowa� paradoks urodzin przy du�ej ilo�ci pr�b, aby udowodni� t� tez�. 

Wymagania:

-Program posiada funkcj� int birthdayParadox(int people, int tests)
-Program wykonuje tests pr�b. Zmienna tests b�dzie mie�ci�a si� w zakresie 1000..100000.
-W ka�dej pr�bie losuje dzie� urodzin dla ka�dej z people os�b. Zmienna people b�dzie mie�ci�a si� w zakresie 2..50.
-W ka�dej pr�bie program sprawdzi, czy przynajmniej dwie osoby w grupie maj� taki sam dzie� urodzin.
-Funkcja ma zwr�ci� jedn� tylko liczb�: ilo�� pr�b, w kt�rej paradoks urodzin si� sprawdzi� dla podanych argument�w.

Dla dobrze wykonanego zadania dla 23 os�b i 10000 test�w, funkcja birthdayParadox(23, 10000) powinna zwr�ci� liczb� blisk� 5000.

*/



/****************************************************
*
*	int birthdayParadox(int people, int tests)
*
*****************************************************/


int birthdayParadox(int people, int tests)
{
	
	int osoby[50] = {0};		// tablica na dane 2..50 osob
	int licznikTrafien = 0;
	
	/* program wykonuje 'tests' p�b (1000..100000) */
	for (int i=0; i < tests; i++){ 	
		
		/* wypelnij tablice osob losowo wybranymi dniami urodzin z zakresu 1-365 */
		for (int j=0; j < people; j++){
			osoby[j] = (rand() % 365) +1;
		}
		
		/* czy przynajmniej dwie osoby w grupie maj� taki sam dzie� urodzin */
		for (int j=0; j < people-1; j++){
			for (int k=j+1 ; k < people; k++){
				if ( osoby[j] == osoby[k] ){	// jezeli dwie osoby urodzone tego samego dnia
					licznikTrafien++;
					j = people;	// przesuniecie wskaznika petli 'j' na koniec tablicy zako�czy petjl� j
					break;	// ko�czy petl� 'k'
				}	
			}
		}
	/* koniec petli (1000..100000) pr�b */	
	}
	
	/* zwroc wynik dzialania funkcji */
	return licznikTrafien;
}



/****************************************************
*
*	main
*
*****************************************************/

int main()
{
	
	//cout << birthdayParadox(23,10000) << endl;
	
	return 0;
}

