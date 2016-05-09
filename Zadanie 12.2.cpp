#include <iostream>
using namespace std;

/*
Zadanie 12.2: Top 10

Napisz program, który trzyma w pamiêci 10 najlepszych wyników w grze. Przy starcie program wypisze na ekran wstêpne wyniki w nastêpuj¹cej formie:

Top 10 results:
1. 10 points
2.  9 points
3.  8 points
4.  7 points
5.  6 points
6.  5 points
7.  4 points
8.  3 points
9.  2 points
10. 1 points
Nastêpnie pyta u¿ytkownika, ile punktów zdoby³. Punkty te wpisuje na odpowiedni¹ pozycjê w tabeli, po czym wypisuje uaktualnion¹ tabelê na ekran. Program pyta u¿ytkowników o zdobyte punkty tak d³ugo, dopóki u¿ytkownik nie wpisze 0. Po wpisaniu wartoœci 0 program zakoñczy siê.
Przyk³adowo po dwóch "kolejkach" u¿ytkownik wpisa³ 7 i 12 punktów. Ekran powinien wygl¹daæ tak:

Top 10 results:
1. 12 points
2. 10 points
3.  9 points
4.  8 points
5.  7 points
6.  7 points
7.  6 points
8.  5 points
9.  4 points
10.  3 points
Program musi dzia³aæ na jednej (i nie wiêcej) tabeli int tab[10]. Operacje na tej tabeli nale¿y wykonywaæ za pomoc¹ wskaŸników
*/

/*********************************************************
*
*	void wypiszWyniki(int * tab)
*
*********************************************************/

void wypiszWyniki(int * tab)
{
	// funkcja wypisuje na ekran z tablicy 10-cio elementowej wyniki
	
	cout << "Top 10 results:" << endl;
	
	for (int i = 0 ; i < 10 ; i++)
	{
		cout << i+1 << ".   " << *(tab + i) << " points" <<endl;
	}
}

/*********************************************************
*
*	void insertionSort(int *tab, int len)
*
*********************************************************/

void insertionSort(int *tab, int len){
	
	//
	// UWAGA :  wersja sortuje od najwiekszego do najmniejszego
	// 
	
	int elem_i = 0;
	int offset = 0; // miejsce wstawienia nowego elementu


	
	for (int i = 1; i < len; i++)	// dla kazdego elementu poza elementem (0) 1..len
	{
		elem_i = *(tab+i);			// pobierz kolejny element z czesci nieposortowanej -> 'elem_i'
				
				
		if ( elem_i <= *(tab+i-1) )
		{
			// jezeli jest mniejszy od posortowanego pierwszego z prawej
			// nic nie rób
			continue;
		} 
		else
		{	// przesun komorki, podaj miejsce wstawienia elementu, wstaw element
			
			offset = 0;
			
			
			// petla konczy siê jezeli znajdzie siê element posortowany -mniejszy- od elem_i
			// jezeli takiego elememtu nie ma tzn. ze miejscem wstawienia nowego elementu 
			// bedzie komorka o indeksie (0) , czyli offset = 0
			for (int j = i-1 ; j>=0 ; j--)
			{
				// porównaj (j) z (elem_i)
				if ( *(tab+j) <= elem_i )
				{
					// jezeli (j) jest mniejszy od wstawianego to tylko przesun element w prawo ( na pozycje (j+1) )
					*(tab+j+1) = ( *(tab+j));	
				} 
				else 
				{
					// jezeli (j) jest wiekszy od wstawianego to punktem wstawienia bedzie pozycja (j+1)
					// punkt wstawienia bedzie przesuniety o 1 wzgledem (j)
					
					offset = j+1;
					break;
					// dla elementu (0) offset moze byc rowny 0 lub 1 
				}	
			
			
			}
		
			// wstaw element
			*(tab+offset) = elem_i;
	
		}	
	}
}


/*********************************************************
*
*	main
*
*********************************************************/

int main()
{
	int wyniki[10] = {0};
	int nowyWynik = -1 ;
	
	
	while (nowyWynik != 0)
	{

		// pobierz nowy wynik	
		cin >> nowyWynik;
		
		if (nowyWynik == 0)
		{
			// wypisz wyniki 
			wypiszWyniki(wyniki);
			// i zakoncz glowna petle programu		
		} 
		else if ( *(wyniki + 9) >= nowyWynik )
		{
			// wynik poza zakresem Top 10,
			// wypisz wyniki i przejdz do pobrania nowego wyniku
			wypiszWyniki(wyniki);	
		}
		else 
		{
			// nowy wynik w zakresie punktacji Top 10
			
			// zapisz wstepnie wynik na ostatniej pozycji	
			*(wyniki+9) = nowyWynik;
			
			// sortuj tabele
			insertionSort(wyniki, 10);
			
			// wypisz wyniki
			wypiszWyniki(wyniki);	
		}
	}		
	return 0;
}

