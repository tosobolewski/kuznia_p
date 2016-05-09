#include <iostream>
using namespace std;

/*
Zadanie 10.1. 10 liczb

Napisz program, który za pomoc¹ polecenia cin wczyta 10 liczb ca³kowitych podanych z klawiatury. Nastêpnie za pomoc¹ polecenia cout 
wypisze na ekran te same liczby oddzielone spacj¹ z uwzglêdnieniem poni¿szych warunków:
- Je¿eli pierwsza podana liczba jest ujemna, to wczytane liczby nale¿y wydrukowaæ na ekranie w odwrotnej kolejnoœci.
- Je¿eli pierwsza podana liczba jest dodatnia lub jest zerem, to program wypisze wczytane liczby od najmniejszej do najwiêkszej.
- Aby poprawnie wykona³y siê testy automatyczne, program powinien sk³adaæ siê tylko z funkcji int main(). Niedozwolone jest tworzenie innych funkcji.
*/

int main()
{
	int tablica[10] = {0};
	int e=0, n=0;
	
// wczytanie 10 liczb z konsoli

	for (int i = 0; i < 10; i++){
			cin >> tablica[i];
	}

// obliczenia + wydruk 	

	if (tablica[0] < 0) { 				// jezeli pierwsza liczba jest ujemna
			for (int i = 9; i >= 0; i--){		// drukuj w odwrotnej kolejnosci (i--)
				cout << tablica[i] << " ";
			}
	} else {			  			// je¿eli pierwsza liczba jest dodatnia lub jest = 0
		
			// sortowanie tablicy - zamienia kolejny element tablicy z najmniejszym elementem w pozosta³ej nieposortowanej czêsci tablicy
			
			for (int i=0; i< 10; i++){				// podobne rozwiazanie - patrz zadanie 12.3
					e = tablica[i];	
					n = i;				
					for (int j=i+1; j < 10; j++){
							if (tablica[j] < e){
								e = tablica[j];		// e= znaleziony nowy najmniejszy element tablicy
								n = j;				// n= index najmniejszego elementu w pozostalej czesci tablicy
								
							}
					}
					tablica[n]=tablica[i];			// do tablicy z indekdem [n] wpisuje nieposortowany element [i]
					tablica[i] = e;					// do tablicy z indeksem [i] wpisuje nowy najmniejszy element
			
			}
			
			// wydruk posortowanej tablicy
			for (int i=0; i<10; i++){
				cout << tablica[i] << " " ;
			}
	
	}

	return 0;
}

