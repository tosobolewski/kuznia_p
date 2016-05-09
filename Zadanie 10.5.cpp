#include <iostream>
#include <stdlib.h>	/* rand() */
using namespace std;

/*
Zadanie 10.5. Paradoks urodzin

Paradoks urodzin brzmi: prawdopodobieñstwo, ¿e w grupie 23 osób co najmniej dwie z nich maj¹ urodziny tego samego dnia w roku, jest wiêksze od 50%. 
Napisz program, który bêdzie symulowa³ paradoks urodzin przy du¿ej iloœci prób, aby udowodniæ t¹ tezê. 

Wymagania:

-Program posiada funkcjê int birthdayParadox(int people, int tests)
-Program wykonuje tests prób. Zmienna tests bêdzie mieœci³a siê w zakresie 1000..100000.
-W ka¿dej próbie losuje dzieñ urodzin dla ka¿dej z people osób. Zmienna people bêdzie mieœci³a siê w zakresie 2..50.
-W ka¿dej próbie program sprawdzi, czy przynajmniej dwie osoby w grupie maj¹ taki sam dzieñ urodzin.
-Funkcja ma zwróciæ jedn¹ tylko liczbê: iloœæ prób, w której paradoks urodzin siê sprawdzi³ dla podanych argumentów.

Dla dobrze wykonanego zadania dla 23 osób i 10000 testów, funkcja birthdayParadox(23, 10000) powinna zwróciæ liczbê blisk¹ 5000.

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
	
	/* program wykonuje 'tests' pób (1000..100000) */
	for (int i=0; i < tests; i++){ 	
		
		/* wypelnij tablice osob losowo wybranymi dniami urodzin z zakresu 1-365 */
		for (int j=0; j < people; j++){
			osoby[j] = (rand() % 365) +1;
		}
		
		/* czy przynajmniej dwie osoby w grupie maj¹ taki sam dzieñ urodzin */
		for (int j=0; j < people-1; j++){
			for (int k=j+1 ; k < people; k++){
				if ( osoby[j] == osoby[k] ){	// jezeli dwie osoby urodzone tego samego dnia
					licznikTrafien++;
					j = people;	// przesuniecie wskaznika petli 'j' na koniec tablicy zakoñczy petjlê j
					break;	// koñczy petlê 'k'
				}	
			}
		}
	/* koniec petli (1000..100000) prób */	
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

