#include <iostream>
using namespace std;

/*
Zadanie 10.2. �rednia ocen

Napisz funkcj� obliczaj�c� �redni� ocen w szkole dla jednego ucznia.

Wymagania:
Funkcja float obliczSrednia(int tablica[8][10]) b�dzie pracowa�a na jednej tablicy dwuwymiarowej o rozmiarze 8x10 element�w.
- W tablicy przes�anej jako argument mo�e znajdowa� si� max 10 ocen w semestrze z ka�dego przedmiotu (mo�e by� mniej, reszta b�dzie uzupe�niona zerami, kt�rych nie liczymy do �redniej).
- W tablicy przes�anej jako argument mo�e znajdowa� si� max 8 przedmiot�w (mo�e by� mniej, reszta przedmiot�w b�dzie uzupe�niona zerami, kt�rych nie liczymy do �redniej). W tablicy 
mo�e znajdowa� si� ca�y rz�d zer - oznacza to, �e danego przedmiotu nie liczymy do �redniej ocen.
- Program wypisze na ekran w pierwszej linii liczby zmiennoprzecinkowe ze �redni� ocen z ka�dego przedmiotu oddzielnie (max 8 liczb oddzielonych spacjami).
- Program wypisze na ekran w drugiej linii tylko jedn� liczb� zmiennoprzecinkow� ze �redni� ocen z przedmiot�w (�rednia arytmetyczna z max. 8 liczb). T� sam� liczb� funkcja zwraca.
- �rednie powinny by� w formacie 3.4, a wi�c z jednym miejscem po przecinku.
Przyk�adowa tablica z ocenami:
		tablica[0][0] = 5;
		tablica[0][1] = 4;
		tablica[0][2] = 4;
		tablica[0][3] = 5;
		tablica[0][4] = 4;
		tablica[0][5] = 3;
		tablica[0][6] = 1;
		tablica[0][7] = 6;
		tablica[0][8] = 5;
		tablica[0][9] = 5;    

		tablica[1][0] = 2;
		tablica[1][1] = 3;
		tablica[1][2] = 2;
		tablica[1][3] = 3;
		tablica[1][4] = 2;
		tablica[1][5] = 3;
		tablica[1][6] = 2;
		tablica[1][7] = 3;
		tablica[1][8] = 2;
		tablica[1][9] = 3;  
			
		tablica[2][0] = 1;
		tablica[2][1] = 6;
		tablica[2][2] = 0;
		tablica[2][3] = 0;
		tablica[2][4] = 0;
		tablica[2][5] = 0;
		tablica[2][6] = 0;
		tablica[2][7] = 0;
		tablica[2][8] = 0;
		tablica[2][9] = 0;     

		// reszta tabeli zawiera same zera
		
Przyk�adowe wyj�cie:
4.2 2.5 3.5
3.4
*/


/***************************************************************
*
*	funkcja obliczSrednia(int tablica[8][10]);
*   
*	
*
****************************************************************/


float obliczSrednia(int tablica[8][10]){
	
	// tablica[przedmiot][ocena]
	
	// precyzja wypisania na konsole srednich ocen
	cout.precision(2);
	
	
	int iloscSrednichOcenZPrzedmiotow = 0;
	float sumaSrednichOcenZPrzedmiotow = 0;
			
	//  dla kazdego przedmiotu [p] wykonaj petle 'for' - obliczenie sredniej z ocen + sumowanie tych srednich
	
	for (int p = 0; p < 8; p++){
	
		int iloscOcen = 0;
		float sumaOcen = 0;
		float sredniaOcen = 0;
		
		for (int i = 0; i < 10; i++){			// dla kazdej oceny [i] z jednego przedmiotu			
				if (tablica[p][i] != 0){		
						iloscOcen +=1;
						sumaOcen += tablica[p][i];	//sumuj kolejne [i] oceny dla jednego przedmiotu, ale tylko oceny != 0
			}
		}	
		
		
		
		// srednia ocen jednego przedmiotu [p]
		if (iloscOcen != 0){
			sredniaOcen = sumaOcen/iloscOcen; 		
		} else {
			sredniaOcen = 0; // wyjatek je�eli powstanie dzielenie przez 0
		}
		
		
		if (sredniaOcen != 0){				
				cout << sredniaOcen << " ";	// wypisz na ekran srednie != 0
		}
		


		// sumowanie do obliczenia sredniej z przedmiot�w, tylko srednie != 0
		
		if (sredniaOcen != 0){					
				iloscSrednichOcenZPrzedmiotow += 1;
				sumaSrednichOcenZPrzedmiotow += sredniaOcen;
		}
	
	}
	// zakoncz wypisywanie srednich ocen przejsciem do nowej linii
	cout << endl; 					
	
	
	
	// obliczenie sredniej z przedmiotow	
	
	float sredniaOcenZPrzedmiotow;
	
	if(iloscSrednichOcenZPrzedmiotow != 0){
		sredniaOcenZPrzedmiotow = sumaSrednichOcenZPrzedmiotow / iloscSrednichOcenZPrzedmiotow;
	} else{
		sredniaOcenZPrzedmiotow = 0;	// wyjatek je�eli powstanie dzielenie przez 0
	}
	
	
	
	if (sredniaOcenZPrzedmiotow != 0){
		cout << sredniaOcenZPrzedmiotow << endl;	// wypisz na ekran srednia jezeli jest != 0
	}
	
	return sredniaOcenZPrzedmiotow;

}
// ***


/**************************************************
*
*	main
*
**************************************************/


int main()
{
	int tablica[8][10] ={0};
	
		tablica[0][0] = 5;
		tablica[0][1] = 4;
		tablica[0][2] = 4;
		tablica[0][3] = 5;
		tablica[0][4] = 4;
		tablica[0][5] = 3;
		tablica[0][6] = 1;
		tablica[0][7] = 6;
		tablica[0][8] = 5;
		tablica[0][9] = 5;    

		tablica[1][0] = 2;
		tablica[1][1] = 3;
		tablica[1][2] = 2;
		tablica[1][3] = 3;
		tablica[1][4] = 2;
		tablica[1][5] = 3;
		tablica[1][6] = 2;
		tablica[1][7] = 3;
		tablica[1][8] = 2;
		tablica[1][9] = 3;  
			
		tablica[2][0] = 1;
		tablica[2][1] = 6;
		tablica[2][2] = 0;
		tablica[2][3] = 0;
		tablica[2][4] = 0;
		tablica[2][5] = 0;
		tablica[2][6] = 0;
		tablica[2][7] = 0;
		tablica[2][8] = 0;
		tablica[2][9] = 0;  
		
	cout << obliczSrednia(tablica) << endl;

	return 0;
}

