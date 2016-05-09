#include <iostream>
#include <stdlib.h> // rand();
#include <time.h>	// time();
using namespace std;

/*
Zadanie 12.1: Sortowanie

 Celem zadania jest sprawdzenie szybkoœci dzia³ania trzech algorytmów sortuj¹cych:
	sortowanie b¹belkowe (bubble sort), tutaj przyk³ad implementacji
	sortowanie przez wstawianie (insertion sort) tutaj przyk³ad implementacji
	sortowanie przez wybieranie (selection sort) tutaj przyk³ad implementacji
O ró¿nicach pomiêdzy tymi sposobami sortowania mo¿esz poczytaæ np. na wikipedii.

Wymagania:
	Napisz trzy funkcje dla trzech rodzajów sortowania: bubble, insertion, selection.
	Ka¿da z tych funkcji ma za zadanie przesortowaæ dwie tablice, jedn¹ z 10000 elementów (int tab1[10000]), a drug¹ z 30000 elementów (int tab2[30000])
	Tablice powinny zawieraæ liczby ca³kowite z przedzia³u 1..1000. Do wygenerowania tablic mo¿esz wykorzystaæ funkcjê rand().
	Wynikiem dzia³ania ka¿dej funkcji ma byæ tablica liczb posortowana od najmniejszej do najwiêkszej
	Ka¿da z tych funkcji ma dostaæ na wejœcie tablice z tymi samymi danymi, aby u³o¿enie danych w tablicy nie mia³o wp³ywu na szybkoœæ sortowania.
	Funkcje sortuj¹ce musz¹ dzia³aæ na wskaŸnikach. Zabroniony jest zapis tablicowy typu wsk[500].
	Program na ekran wypisze czas sortowania dla szeœciu przypadków testowych: dla dwóch tablic, ka¿da po trzy rodzaje sortowania.
	Wskazówki, które mog¹ pomóc przy implementacji:

Na pocz¹tku zbadaj, czy algorytmy dzia³aj¹ poprawnie. Wypróbuj dzia³anie funkcji na ma³ej tablicy (np. 10 elementów). Wypisz na ekran posortowan¹ tablicê, aby widzieæ, czy posortowana jest prawid³owo.
Do mierzenia czasu mo¿esz u¿yæ funkcji clock(). Zacznij mierzyæ czas tu¿ przed fragmentem kodu, który sortuje tablicê. 
Czas tworzenia tablicy czy jej kopiowania oraz wypisywania informacji na ekran nie powinien byæ brany do obliczenia czasu.
Poniewa¿ funkcje maj¹ dostaæ tablice z tymi samymi danymi, wiêc mo¿esz stworzyæ tablice na 10000 i 30000 elementów, a nastêpnie skopiowaæ je np. za pomoc¹ funkcji memcpy().
*/

/*********************************************************
*
*	void bubbleSort(int *tab)
*
*********************************************************/

void bubbleSort(int *tab, int len){
	
	int i = 0;
	int temp = 0;
	
	for (int k = len-1 ; k > 1 ; k--)		// k - dlugosc nieposortowanej czesci tablicy, zmniejsza siê po ka¿dym przejsciu petli 'while'
	{ 	
		i = 0;	
		while ( i < k )
		{	
			if ( *(tab+i) > *(tab+i + 1) ) 		// jezeli A > B (przeciwnie ni¿ w posortowanej tablicy)
			{
				temp = *(tab+i);				// zamien porownywane wartosci miejscami
				*(tab+i) = (*(tab+i + 1));
				*(tab+i + 1) = temp;
			} 
			//cout << *(tab+i) << " ";
			i++;	
		}	
		//cout << endl << k << endl;
	}
}

/*********************************************************
*
*	void insertionSort(int *tab)
*
*********************************************************/

void insertionSort(int *tab){
	
	
}

/*********************************************************
*
*	void selectionSort(int *tab)
*
*********************************************************/

void selectionSort(int *tab){
	
	
}


/*********************************************************
*
*	void printArrayContent(int *arr, int len)
*
*********************************************************/

// funkcja wypisuje na console pierwsze 'len' znakow 
// tablicy 'int' podanej wskaznikiem
void printArrayContent(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << *(arr+i) <<" ";
	}
	cout << endl;
}

/*********************************************************
*
*	void printTimeSummary(c1, c2);
*
*********************************************************/

// funkcja wypisuje na console podsumowanie wyników
// pomiaru czasu na podstawie wartosci tick zegara systemowego
// zwracanych przez funkcje clock() <time.h>
void printTimeSummary(int c1, int c2)
{
	cout << endl << "Wyniki pomiaru czasu wykonania funkcji:" << endl << endl;
	cout << "[ticks] = " << c2 - c1 << endl;
	// przelicz 'ticki' na sekundy
	cout << "[sec.]  = " << (c2-c1) / CLOCKS_PER_SEC << endl;
	// podaj wartosc stalej CLOCKS_PER_SEC : sta³a charakterystyczna dla systemu
	cout << endl << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << " [ticks/sec.]" << endl; 
}


/*********************************************************
*
*	kody z wikipedii
*	void bubblesortlastchange(int tab[], int size)
*	void bubblesortflag( TYP a[], int n )
*	void bubblesortclasic(int table[], int size)	
*
*********************************************************/

void bubblesortlastchange(int tab[], int size) // zapamietuje miejsce ostatniej zmiany
{
	int loop, last, i, j, temp;
	last = size - 1;
 
	for(i = size - 1; i > 0; i--)
	{
		loop = last;
		last = 0;
		for(j = 0; j < loop; j++)
		{
			if(tab[j] > tab[j+1])
			{
				last = j;
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
		}
	}
}

typedef int TYP;
 
void bubblesortflag( TYP a[], int n ) // korzysta z flagi informujacej o zamianie elementow tablicy
{
  int i,j;
  TYP tmp;
  int change;
 
  for (i=0; i<n-1; ++i) 
  {
       change=0;
       for (j=0; j<n-1-i; j++)
       { 
          if (a[j+1] < a[j])   //porównanie s¹si¹dów
          {  
              tmp = a[j];      
              a[j] = a[j+1];
              a[j+1] = tmp;    //wypchanie b¹belka     
              change=1;
          }
       }
       if(!change) break;      // nie dokonano zmian - koniec!
  }
}

void bubblesortclasic(int table[], int size) // klasyczna wersja sortowania babelkowego
{
	int i, j, temp;
	for (i = 0; i<size; i++)
        {
		for (j=0; j<size-1-i; j++)
		{
			if (table[j] > table[j+1])
			{
				temp = table[j+1];
				table[j+1] = table[j];
				table[j] = temp;
			}
		}
        }
}

template <class T>
    void bubble_sort(T* tab, int n) {
        bool swapped; // Czy zamieniono w ostatnim obrocie?
 
        do {
            swapped = false;
            for (int i = 0; i < n - 1; ++i) {
                if (tab[i] > tab[i + 1]) {
                    swap(tab[i], tab[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);
    }



/*********************************************************
*
*	main
*
*********************************************************/

int main()
{
	const int MAX_SIZE = 50000;									// maksymalny rozmiar tablicy testowej

	int testSize[] = {10000, 20000, 30000, 50000};						// dla jakich wielkosci tablicy robimy testy
	int testNumbers = sizeof(testSize)/ sizeof(testSize[0]);				// ile elementow ma tablica z testami
	
	// w zaleznosci od ilosci elementow w danym tescie
	// bedzie przekazywana ta sama tablica 
	// ze zmieniona wskazywana iloscia elementow do posortowania
	int testArray[MAX_SIZE] = {0}; 
	
	int int_byte_size = sizeof(testArray[0]); 	//ile bajtow ma w systemie typ 'int' czyli jedna komorka tabeli
												// potrzebne do obliczenia ilosci bajtow kopiowanych przez funkcje memcpy()	
	clock_t c1;										// zmienna do pomiaru czasu w tickach zegara systemowego
	
	string opisFunkcji;								// do wydruku na konsoli				
	


	
	// przygotuj tablice o maksymalnym rozmiarze z wartosciami losowymi z zakresu 1..1000
	int arrRandoms[MAX_SIZE] = {0};
	
	srand(1);
	for( int i=0 ; i < MAX_SIZE ; i++)				
	{					
		*(arrRandoms+i) = ( rand() % 1000 ) + 1; 
	}
												
												

	
	/*
	***
	***		test bubbleSort() / (tso)
	***
	*/
												
	
	for (int i =  0; i < testNumbers; i++)
	{
		// czy rozmiar tablicy testowej nie przekroczyl tablicy wartosci losowych
		if (testSize[i] > MAX_SIZE) {
			cout << "Rozmiar tablicy = " << testSize[i] << " przekracza stala MAX_SIZE = " << MAX_SIZE << "." << endl << "Powieksz MAX_SIZE." << endl;
			return 0;
		}		
		
		
		// skopiuj z tablicy random wartosci do tablicy testowej
		memcpy(testArray,arrRandoms,testSize[i] * int_byte_size );	// wypelnienie losowymi danymi dwoch tablic testowych
		
		c1 = clock();
		
		bubbleSort(testArray,testSize[i]); // testowana funkcja
		
		c1 = clock() - c1;


		// wypisz wyniki
		opisFunkcji = "bubbleSort() / by (tso)";		
		cout << opisFunkcji << "     Test " << i+1 << ", TAB_SIZE = " << testSize[i] << ", ticks = " << c1 << endl << endl;
 
	}
	cout << endl;	
		
	
//	bubblesortlastchange(testArray, testSize[i]);	// wywolanie funkcji sortujacej
//	bubblesortflag(testArray, testSize[i]);	// wywolanie funkcji sortujacej
//	bubblesortclasic(testArray, testSize[i]);	// wywolanie funkcji sortujacej	
//	bubble_sort(testArray, testSize[i]);	// wywolanie funkcji sortujacej	
	
	/*
	***
	***		test bubblesortclasic() / (Wikipedia)
	***
	*/
												
	
	for (int i =  0; i < testNumbers; i++)
	{
		// czy rozmiar tablicy testowej nie przekroczyl tablicy wartosci losowych
		if (testSize[i] > MAX_SIZE) {
			cout << "Rozmiar tablicy = " << testSize[i] << " przekracza stala MAX_SIZE = " << MAX_SIZE << "." << endl << "Powieksz MAX_SIZE." << endl;
			return 0;
		}		

		// skopiuj z tablicy random wartosci do tablicy testowej
		memcpy(testArray,arrRandoms,testSize[i] * int_byte_size );	
		
		
		c1 = clock();
		
		bubblesortclasic(testArray,testSize[i]); // testowana funkcja
		
		c1 = clock() - c1;


		// wypisz wyniki
		opisFunkcji = "bubblesortclasic() / by (Wikipedia)";		
		cout << opisFunkcji << "     Test " << i+1 << ", TAB_SIZE = " << testSize[i] << ", ticks = " << c1 << endl << endl;
 
	}
	cout << endl;	
	

	
	
	
	
	
	//time(&t1);	
	//time(&t2);	
	return 0;
}

