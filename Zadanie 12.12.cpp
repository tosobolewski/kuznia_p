#include <iostream>
#include <stdlib.h> // rand();
#include <time.h>	// time();
using namespace std;

/*
Zadanie 12.1: Sortowanie

 Celem zadania jest sprawdzenie szybko�ci dzia�ania trzech algorytm�w sortuj�cych:
	sortowanie b�belkowe (bubble sort), tutaj przyk�ad implementacji
	sortowanie przez wstawianie (insertion sort) tutaj przyk�ad implementacji
	sortowanie przez wybieranie (selection sort) tutaj przyk�ad implementacji
O r�nicach pomi�dzy tymi sposobami sortowania mo�esz poczyta� np. na wikipedii.

Wymagania:
	Napisz trzy funkcje dla trzech rodzaj�w sortowania: bubble, insertion, selection.
	Ka�da z tych funkcji ma za zadanie przesortowa� dwie tablice, jedn� z 10000 element�w (int tab1[10000]), a drug� z 30000 element�w (int tab2[30000])
	Tablice powinny zawiera� liczby ca�kowite z przedzia�u 1..1000. Do wygenerowania tablic mo�esz wykorzysta� funkcj� rand().
	Wynikiem dzia�ania ka�dej funkcji ma by� tablica liczb posortowana od najmniejszej do najwi�kszej
	Ka�da z tych funkcji ma dosta� na wej�cie tablice z tymi samymi danymi, aby u�o�enie danych w tablicy nie mia�o wp�ywu na szybko�� sortowania.
	Funkcje sortuj�ce musz� dzia�a� na wska�nikach. Zabroniony jest zapis tablicowy typu wsk[500].
	Program na ekran wypisze czas sortowania dla sze�ciu przypadk�w testowych: dla dw�ch tablic, ka�da po trzy rodzaje sortowania.
	Wskaz�wki, kt�re mog� pom�c przy implementacji:

Na pocz�tku zbadaj, czy algorytmy dzia�aj� poprawnie. Wypr�buj dzia�anie funkcji na ma�ej tablicy (np. 10 element�w). Wypisz na ekran posortowan� tablic�, aby widzie�, czy posortowana jest prawid�owo.
Do mierzenia czasu mo�esz u�y� funkcji clock(). Zacznij mierzy� czas tu� przed fragmentem kodu, kt�ry sortuje tablic�. 
Czas tworzenia tablicy czy jej kopiowania oraz wypisywania informacji na ekran nie powinien by� brany do obliczenia czasu.
Poniewa� funkcje maj� dosta� tablice z tymi samymi danymi, wi�c mo�esz stworzy� tablice na 10000 i 30000 element�w, a nast�pnie skopiowa� je np. za pomoc� funkcji memcpy().
*/



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

// funkcja wypisuje na console podsumowanie wynik�w
// pomiaru czasu na podstawie wartosci tick zegara systemowego
// zwracanych przez funkcje clock() <time.h>
void printTimeSummary(int c1, int c2)
{
	cout << endl << "Wyniki pomiaru czasu wykonania funkcji:" << endl << endl;
	cout << "[ticks] = " << c2 - c1 << endl;
	// przelicz 'ticki' na sekundy
	cout << "[sec.]  = " << (c2-c1) / CLOCKS_PER_SEC << endl;
	// podaj wartosc stalej CLOCKS_PER_SEC : sta�a charakterystyczna dla systemu
	cout << endl << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << " [ticks/sec.]" << endl; 
}










/*********************************************************
*
*	void bubbleSort(int *tab)
*
*********************************************************/

void bubbleSort(int *tab, int len){
	
	int i = 0;
	int temp = 0;
	
	for (int k = len-1 ; k > 1 ; k--)		// k - dlugosc nieposortowanej czesci tablicy, zmniejsza si� po ka�dym przejsciu petli 'while'
	{ 	
		i = 0;	
		while ( i < k )
		{	
			if ( *(tab+i) > *(tab+i + 1) ) 		// jezeli A > B (przeciwnie ni� w posortowanej tablicy)
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
*	void insertionSort(int *tab, int len)
*
*********************************************************/

void insertionSort(int *tab, int len){
	
	int elem_i = 0;
	int offset = 0; // miejsce wstawienia nowego elementu


	
	for (int i = 1; i < len; i++)	// dla kazdego elementu poza elementem (0) 1..len
	{
		elem_i = *(tab+i);			// pobierz kolejny element z czesci nieposortowanej -> 'elem_i'
				
				
		if ( elem_i >= *(tab+i-1) )
		{
			// jezeli jest wiekszy od posortowanego pierwszego z prawej
			// nic nie r�b
			continue;
		} 
		else
		{	// przesun komorki, podaj miejsce wstawienia elementu, wstaw element
			
			offset = 0;
			
			
			// petla konczy si� jezeli znajdzie si� element posortowany -mniejszy- od elem_i
			// jezeli takiego elememtu nie ma tzn. ze miejscem wstawienia nowego elementu 
			// bedzie komorka o indeksie (0) , czyli offset = 0
			for (int j = i-1 ; j>=0 ; j--)
			{
				// por�wnaj (j) z (elem_i)
				if ( *(tab+j) >= elem_i )
				{
					// jezeli (j) jest wiekszy od (elem_i) to tylko przesun element w prawo ( na pozycje (j+1) )
					*(tab+j+1) = ( *(tab+j));	
				} 
				else 
				{
					// jezeli (j) jest mniejszy od 'elem_i' to punktem wstawienia 'elem_i' bedzie pozycja (j+1)
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
*	void selectionSort(int *tab)
*
*********************************************************/

void selectionSort(int *tab){
	
	
}







/*********************************************************
*
*	main
*
*********************************************************/

int main()
{

	int random[30000] = {0}; 		// do zasilania tablic danymi losowymi wygenerowana zopstania jednaa tablica
									// o rozmiarze wi�kszej z tablic i z niej bed� kopiowane dane 
	
	
	int tabTest10000[10000] = {0};					// tablice testowe - wypelniane na nowo przed kazdym testem danymi z tablicy random[..]
	int tabTest30000[30000] = {0};
	
	
	time_t t1;										// zmienne do pomiaru czasu w sekundach
	time_t t2;
	
	
	clock_t c1;										// zmienne do pomiaru czasu w tickach zegara systemowego
	clock_t c2;
		
	
	for( int i=0; i < 30000; i++)					// wypelnienie tablicy matrycy danymi losowymi
	{					
		*(random+i) = ( rand() % 1000 ) + 1; 		// liczby losowe z zakresu 1..1000
	}
	

	int int_byte_size = sizeof(random[0]); 	//ile bajtow ma w systemie typ 'int' czyli jedna komorka tabeli
											// potrzebne do obliczenia ilosci bajtow kopiowanych przez funkcje memcpy()
	
	
	
	// testowanie funkcji insertionSort(), 10000 elementow


	memcpy(tabTest10000,random,10000 * int_byte_size );	// wypelnienie losowymi danymi dwoch tablic testowych
	memcpy(tabTest30000,random,30000 * int_byte_size );	// przez kopiowanie pamieci z tablicy random[..]


	printArrayContent(tabTest10000,20);	// wypisz zawartosc czesci tabeli na konsole
	
	c1 = clock();   					// pomiar czasu na starcie
										// processor time, value returned is expressed in clock ticks
	insertionSort(tabTest10000, 10000);	// wywolanie funkcji sortujacej
	
	c2 = clock(); 						// pomiar czasu po zakonczeniu

	
	printArrayContent(tabTest10000,20);	// wypisz wyniki na konsole
	printTimeSummary(c1, c2);
	
	
	// testowanie funkcji insertionSort(), 30000 elementow 

	
	printArrayContent(tabTest30000,20);	// wypisz zawartosc czesci tabeli na konsole
	
	c1 = clock();   					// pomiar czasu na starcie
										// processor time, value returned is expressed in clock ticks
	insertionSort(tabTest30000, 30000);	// wywolanie funkcji sortujacej
	
	c2 = clock(); 						// pomiar czasu po zakonczeniu

	
	for (int i = 0; i < 30000-1; i++)
	{
		if (tabTest30000[i] > tabTest30000[i+1])
		{
			cout << i << "nieposortowane" << endl;	
		}
	}
	
	
	printArrayContent(tabTest30000,20);	// wypisz wyniki na konsole
	printTimeSummary(c1, c2);	
	

	
	
	
	
	
	
	
	//time(&t1);	
	//time(&t2);	
	return 0;
}

