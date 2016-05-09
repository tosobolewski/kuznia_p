#include <iostream>
using namespace std;

/*
Zadanie 11.1. Zamiana liczb

Napisz funkcjê swapNum(int *num1, int *num2), która zamienia miejscami dwie liczby.
Napisz funkcjê reverseText(char *text)która zamienia kolejnoœæ liter w podanym tekœcie.
*/


/*********************************************************
*
*	void swapNum(int *num1, int *num2)
*
*********************************************************/

void swapNum(int *num1, int *num2){
	
	/* zamienia wartosci dwoch liczb podanych przez wskazniki jako parametry funkcji */
	
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	
	cout << __FUNCTION__ << endl;
}

/*********************************************************
*
*	void reverseText(char *text)
*
*********************************************************/

void reverseText(char *text){
	
	/* 	i - indeks kolejnych znakow od poczatku ciagu,
		j - indeks kolejnych znakow od konca ciagu
	funkcja w petli zamienia miejscami znaki o indeksach i, j.
	powodujac w rezultacie odwrocenie kolejnosci znakow w calym ciagu 'tekst' */
	
	int temp;
	int i = 0;		
	int j = 0;
	int len = 0;	
	
	// oblicz 'len' = dlugosc ciagu znakow parametru 'text' BEZ konczacego '\0'
	while (text[len] != '\0'){
				
		len++;
	}
	
	// zmniejsz dlugosc o 1
	// poniewaz indeksy w tablicy liczone od zera
	j = len-1; 
	
	// zamieniaj znaki i<->j
	while (i <= j){
		
		temp = text[i];
		text[i] = text[j];
		text[j] = temp;

		i++;
		j--;
	}
}

/*********************************************************
*
*	main
*
*********************************************************/

int main()
	{
		int x = 66, y = -22;
		char ala[] = "Ala ma kota";
		char *pTekst = ala;
		
		swapNum(&x, &y);
		cout << x << " " << y << endl;

		reverseText(pTekst);
		cout << pTekst;
		
		return 0;
	}
