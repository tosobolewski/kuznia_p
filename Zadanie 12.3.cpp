#include <iostream>
using namespace std;

/*
Zadanie 12.3: Sudoku

Napisz funkcjê bool checkSudoku(int *tab), która sprawdza, czy tablica 9x9 elementów jest wype³nionym poprawnie diagramem gry Sudoku. Zasady gry znajdziesz na Wikipedii. Dla poprawnie wype³nionej tablicy funkcja zwróci true, dla b³êdnie wype³nionej tablicy zwróci false. Operacje na tablicy nale¿y wykonywaæ tylko za pomoc¹ wskaŸników. Do sprawdzania poprawnoœci mo¿na kopiowaæ tablicê lub jej czêœæ (nie ma ograniczenia co do zu¿ycia pamiêci).

Przyk³adowy kod s³u¿¹cy do sprawdzenia poprawnoœci zadania:
	static int sudokuCorrect[9][9] =  
	{ 	
	{ 4,6,7,3,1,5,9,2,8 },
	{ 1,8,2,9,4,6,7,5,3 },
	{ 5,3,9,2,7,8,1,4,6 },
	{ 6,5,3,4,8,7,2,9,1 },
	{ 2,7,8,1,9,3,4,6,5 },
	{ 9,4,1,5,6,2,8,3,7 },
	{ 7,9,6,8,5,4,3,1,2 },
	{ 8,2,4,6,3,1,5,7,9 },
	{ 3,1,5,7,2,9,6,8,4 } 
	};
				 	
	int *pSudoku = &sudokuCorrect[0][0];
	if (checkSudoku(pSudoku) == true)
	{
		// Test passed
	}
*/

/*********************************************************
*
*	void insertionSort(int *tab, int len)
*
*********************************************************/

void insertionSort(int *tab, int len){
	
	// funkcja sortuje tablice *tab rosnaco
	// metoda wstawiania kolejnych elementow
	
	int elem_i = 0;
	int offset = 0; // miejsce wstawienia nowego elementu


	
	for (int i = 1; i < len; i++)	// dla kazdego elementu poza elementem (0) 1..len
	{
		elem_i = *(tab+i);			// pobierz kolejny element z czesci nieposortowanej -> 'elem_i'
				
				
		if ( elem_i >= *(tab+i-1) )
		{
			// jezeli jest wiekszy od posortowanego pierwszego z prawej
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
				// porównaj (j) z elementem wstawianym
				if ( *(tab+j) >= elem_i )
				{
					// jezeli (j) jest wiekszy od elementu wstawianego to tylko przesun element w prawo ( na pozycje (j+1) )
					*(tab+j+1) = ( *(tab+j));	
				} 
				else 
				{
					// jezeli (j) jest mniejszy od elementu wstawianego to punktem wstawienia 'elem_i' bedzie pozycja (j+1)
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
*	bool int * getCopyTab(int * tab, int row, int col)
*
*********************************************************/

int * getCopyTab(int * tab, int row, int col)
{
	// funkcja kopiuje i zwraca wskaznik do kopii tablicy otrzymanej w parametrze wejsciowym
	// funkcja przyjmuje tablice 9x9 i 3x3 elementy, w innym przypadku zwraca wskaznik na NULL
	// czesc funkcji dotycz¹ca tablicy 3x3 ostatecznie nie jest wykorzystywana w Zadaniu 12.3 
	
	static int copyTab9x9[9*9] = {0}; 				// czy ma byæ static ? <------------------
	static int copyTab3x3[3*3] = {0}; 				// czy ma byæ static ? <------------------
	
		
	if ( (row == 9) && (col==9) ) // kopiowanie dla tablicy 9 x 9
	{
		for (int i = 0; i < row*col; i ++)
		{
			*(copyTab9x9+i) = *(tab + i);
		}		
		// zwroc wskaznik do tablicy 9 x 9
		return copyTab9x9;
	}
	else if ( (row == 3) && (col== 3) ) // kopiowanie dla tablicy 3 x 3
	{
		for (int i = 0; i < row*col; i ++)
		{
			*(copyTab3x3+i) = *(tab + i);
		}
		// zwroc wskaznik do tablicy 3 x 3
		return copyTab3x3;		
					
	}
	else
	{
		// wariant nieobslugiwany przez funkcje
		cout << "Rozmiar kopiowanej tablicy ro¿ny od 9 x 9 lub 3 x 3." << endl;
		
		return NULL; // zwroc wskaznik wskazujacy na 0
	}
	

}


/*********************************************************
*
*	bool sudokuTestRows(int *tab, int len)
*
*********************************************************/

bool sudokuTestRows(int *tab, int len)
{
	// funkcja testuje wszystkie wiersze w tablicy,
	// pod katem warunku 'sudoku' - braku powtarzajacych sie elementow w jednym wierszu
	
	
	// zrob kopie tablicy i pracuj na kopii
	int * copyTab = getCopyTab(tab,len, len);
	
	int * poczatekWiersza = NULL;
	
	// w kazdym wierszu
	for (int w=0 ; w<len ; w++)
	{
		poczatekWiersza = copyTab + (w * len);
		
		// posortuj wartosci w wierszu (row)
		insertionSort(poczatekWiersza,len);
		
		// sprawdz czy nie wystepuja obok siebie dwie takie same wartosci
		for (int i = 0 ; i< len-1 ; i++)
		{
			if (*(poczatekWiersza + i ) == *(poczatekWiersza + i + 1))
			{
				//tu dwa elementy sa równe 
				// -> nie jest spe³niony warunek sudoku
				cout << "Nie jest spelniony warunek sudoku." << endl;
				cout << "wiersz:" << w << "." << i << "." << *(poczatekWiersza+i) <<"." << *(poczatekWiersza+i+1) << endl;
				return false;
			}
		}
	}
	// ok, w kazdym wierszu nie znaleziono pary takich samych elementow
	return true;
}

/*********************************************************
*
*	bool sudokuTestColumns(int *tab, int len)
*
*********************************************************/

bool sudokuTestColumns(int *tab, int len)
{
	// funkcja testuje wszystkie kolumny w tablicy,
	// pod katem warunku 'sudoku' - braku powtarzajacych sie elementow w jednej kolumnie
	// - tworzy lokalna tablice liniowa [9] elem.
	// - przepisuje jedn¹ cala kolumne do tablicy liniowej,
	// - sortuje tab. liniowa,
	// - nastepnie sprawdza czy nie ma dwóch takich samych elementow obok siebie
	// UWAGA: parametr wejsciowy 'len' nie mo¿e przekroczyc 9
		
	int * poczatekKolumny = NULL;
	int lineTab[9] = {0}; // elementy z kolumny beda przepisywane do tablicy liniowej
	
	
	// w kazdej kolumnie
	for (int k=0 ; k<len ; k++)
	{
		poczatekKolumny = tab + k;
		
		// przepisz kolumne do tablicy liniowej:  lineTab[]
		for (int i = 0 ; i < len ; i++ )
		{
			*(lineTab+i) = (*(poczatekKolumny + len * i));
		}
		
		// posortuj wartosci w tablicy liniowej
		insertionSort(lineTab,9);					// ! len = 9 -> tj. dlugosc tablicy liniowej
		
		// sprawdz czy nie wystepuja obok siebie dwie takie same wartosci
		for (int i = 0 ; i< len-1 ; i++)
		{
			if (*(lineTab + i ) == *(lineTab + i + 1))
			{
				// tu dwa elementy sa równe 
				// -> nie jest spe³niony warunek sudoku
				cout << "Nie jest spelniony warunek sudoku." << endl;
				cout << "kolumna:" << k << "." << i << "." << *(lineTab+i) <<"." << *(lineTab+i+1) << endl;
				return false;
			}
		}
	}
	// ok, w kazdej kolumnie nie znaleziono pary takich samych elementow
	return true;
}


/*********************************************************
*
*	bool sudokuTestInnerTables(int *tab, int len)
*
*********************************************************/

bool sudokuTestInnerTables(int *tab, int len)
{
	int * pierwszyElementPodtablicy = NULL;
	int lineTab[9] = {0}; // elementy z kolumny beda przepisywane do tablicy liniowej 	
	
	for(int w = 0; w < 9 ; w +=3)
	{
		for (int k=0 ; k < 9 ; k+=3)
		{
			// teraz para w,k wskazuje na wiersz i kolumne pierwszych elementów podtablic 3x3 sudoku
			
			
			pierwszyElementPodtablicy = (tab + k + 9 * w);
			
			// przepisz podtablice 3x3 do tablicy liniowej
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3 ; j++)
				{
					*(lineTab + i + 3*j) = *(pierwszyElementPodtablicy + i + 9*j);
				}
			}
			
			// posortuj wartosci w tablicy liniowej
			insertionSort(lineTab,9);
			
			
			// sprawdz czy nie wystepuja obok siebie dwie takie same wartosci
			for (int i = 0 ; i< len-1 ; i++)
			{
				if (*(lineTab + i ) == *(lineTab + i + 1))
				{
					// tu dwa elementy w podtablicy 3x3 sa równe 
					// -> nie jest spe³niony warunek sudoku
					cout << "Nie jest spelniony warunek sudoku." << endl;
					cout << "podtablica:" << w << "." << k << "." << *(lineTab+i) <<"." << *(lineTab+i+1) << endl;
					return false;
				}
			}		
		}
	}
	
	// ok, w kazdej podtablicy nie znaleziono pary takich samych elementow
	return true;
}


/*********************************************************
*
*	bool checkSudoku(int *tab, int len)
*
*********************************************************/

bool checkSudoku(int *tab)
{	
	
	bool sudokuTR = sudokuTestRows(tab, 9);
	bool sudokuTC = sudokuTestColumns(tab, 9);
	bool sudokuTIT = sudokuTestInnerTables(tab, 9);
	
	if (( sudokuTR && sudokuTC && sudokuTIT) == true)
	{
		cout << "Test Rows : " << sudokuTR << endl;
		cout << "Test Columns : " << sudokuTC << endl;
		cout << "Test Inner Tables : " << sudokuTIT << endl;
		cout << endl;	
		
		return true;
	}	
	else
	{
		cout << "Test Rows : " << sudokuTR << endl;
		cout << "Test Columns : " << sudokuTC << endl;
		cout << "Test Inner Tables : " << sudokuTIT << endl;
		cout << endl;
		
		return false;
	}
}




/*********************************************************
*
*	main
*
*********************************************************/

int main()
{


	
	static int sudokuCorrect[9][9] =  
	{ 	
	{ 4,6,7,3,1,5,9,2,8 },
	{ 1,8,2,9,4,6,7,5,3 },
	{ 5,3,9,2,7,8,1,4,6 },
	{ 6,5,3,4,8,7,2,9,1 },
	{ 2,7,8,1,9,3,4,6,5 },
	{ 9,4,1,5,6,2,8,3,7 },
	{ 7,9,6,8,5,4,3,1,2 },
	{ 8,2,4,6,3,1,5,7,9 },
	{ 3,1,5,7,2,9,6,8,4 } 
	};
				 	
	int *pSudoku = &sudokuCorrect[0][0];
	if (checkSudoku(pSudoku) == true)
	{
		// Test passed	
		cout << "Test Sudoku : True" << endl;
		
	}



	return 0;
}

