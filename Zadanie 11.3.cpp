#include <iostream>
using namespace std;

/*
Zadanie 11.3: Scalanie tablic

Napisz program, który po³¹czy dwie tablice 5-elementowe w jedn¹ 10-elementow¹, która bêdzie posortowana rosn¹co (od wartoœci najmniejszej do najwiêkszej). Program musi mieæ zadeklarowane dwie funkcje:

void scalTablice(int *t1, int *t2, int *t3) - Funkcja przyjmuje w argumentach trzy wskaŸniki. t1 oraz t2 s¹ wskaŸnikami do tablic 5-elementowych, t3 jest wskaŸnikiem do tablicy 10-elementowej, 
która jest wynikiem scalenia dwóch tablic 5 elementowych.

void sortuj(int *tab) - Funkcja przyjmuje jako argument wskaŸniki do tablicy 10-elementowej, któr¹ nastêpnie posortuje rosn¹co.
Program mo¿e posiadaæ wiêcej funkcji, jednak dwie powy¿sze musz¹ byæ zadeklarowane dok³adnie w takiej postaci jak powy¿ej. Do operacji na tablicach trzeba u¿yæ wskaŸników. 

Przyk³adowy kod testuj¹cy poprawnoœæ funkcji: ( jest w funkcji main )
*/

/*********************************************************
*
*	void scalTablice(int *t1, int *t2, int *t3)
*
*********************************************************/

void scalTablice(int *t1, int *t2, int *t3) {
	
	/* funkcja przepisuje wartosci do tablicy *t3:
	najpierw z tablicy *t1, potem z tablicy *t2
	za³o¿enia: wskazniki *t1 i *t2 wskazuj¹ na tablice 5 elementowe, 
	*t3 wskazuje na tablice 10 elementowa
	funkcja nie zwraca wartosci poniewa¿ operuje na danych 
	znanych funkcji ja wywoluj¹cej - tj. adresie do t3 i d³ugosci t3*/
	
	
	for (int i = 0; i < 5; i++) {	
	
		// przepisz elementy 1..5 tablicy *t1 do 1..5 tablicy *t3
		*(t3+i) = *(t1+i);
	}
	
	
	for (int i = 0; i < 5; i++) { 
	
		// przepisz elementy 1..5 tablicy *t2 do 6..10 tablicy *t3
		*(t3+5+i) = *(t2+i);
	}
	
	
}

/*********************************************************
*
*	void sortuj(int *tab)
*
*********************************************************/

void sortuj(int *tab) {
	
	/* sortuje rosnaco (od najmniejszego do najwiekszego) 
	10 elementowa tablice podana wskaznikiem na wejsciu, 
	
	sortowanie: dla kazdego elementu (i) sprawdzamy czy w pozosta³ej czesci (j)
	jest element mniejszy. jezeli tak to wpisujemy na miejsce elementu (i),
	a element (i) na pozycjê (j) 	
	
	podobne rozwiazanie jak w Zadaniu 10.1 */
	
	int e;		// e= wartosc elemenu tablicy bioracego udzial w sortowaniu
	int n;		// n= indeks (zmienny) polozenia elementu o najmniejszej wartosci
	
	
	for(int i=0; i<10; i++) {
		
		// sortowanie tablicy - zamienia kolejny element tablicy z najmniejszym elementem w pozosta³ej nieposortowanej czêsci tablicy

		e = *(tab+i);		// e= wstepna wartosc elementu o najmniejszej wartosci
		n = i;				// n= indeks po³ozenia elementu o najmniejszej wartosci
		
		for (int j = i+1 ; j < 10 ; j++) {
			
			if (*(tab+j) < e) {
				
				e = *(tab+j);		// e= znaleziony nowy najmniejszy element tablicy
				n = j; 				// n= index najmniejszego elementu w pozostalej czesci tablicy, element bedzie zamieniany z elementem (i)	
			}
		}
		
		// zamien elementy (i) <-> (j)
		
		*(tab+n) = *(tab+i); 		// do tablicy z indekdem [n] wpisuje nieposortowany element [i]
		*(tab+i) = e; 				// do tablicy z indeksem [i] wpisuje nowy najmniejszy element e
	}
}

/*********************************************************
*
*	main
*
*********************************************************/

int main()
{
	const int rozmiar = 5;
	int tabA [rozmiar] = {5,8,12,-5,7};
	int tabB [rozmiar] = {0, -1, -2,-3, 12};
	int tabC [2 * rozmiar] = {0};
	int *ptabA, *ptabB, *ptabC;
	ptabA=tabA;
	ptabB=tabB;
	ptabC=tabC;

	scalTablice(ptabA, ptabB, ptabC);
	cout << "Wynikiem dzialania funkcji scalTablice jest tablica tabC w takiej postaci: \n";
	for (int i=0;i<2*rozmiar;i++)
	{
		cout<<*(ptabC + i)<<" ";
	}

	sortuj(ptabC);
	cout << "\n\nWynikiem dzialania funkcji sortuj jest tablica tabC w takiej postaci: \n";
	for (int i=0;i<2*rozmiar;i++)
	{
		cout<<*(ptabC + i)<<" ";
	}
	return 0;
	
//	Przy podanym kodzie testuj¹cym program wypisze na konsolê nastêpuj¹ce informacje:
//
//	Wynikiem dzialania funkcji scalTablice jest tablica tabC w takiej postaci:
//	5 8 12 -5 7 0 -1 -2 -3 12
//
//	Wynikiem dzialania funkcji sortuj jest tablica tabC w takiej postaci:
//	-5 -3 -2 -1 0 5 7 8 12 12
}

