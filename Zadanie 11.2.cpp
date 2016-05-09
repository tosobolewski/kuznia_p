#include <iostream>
using namespace std;

/*
Zadanie 11.2. Bez samog�osek

Napisz funkcj� discardVowels(char *text), kt�ra pobiera tekst nie d�u�szy ni� 100 znak�w. 
Je�li tekst jest kr�tszy ni� 100 znak�w, to ostatnim znakiem b�dzie '\0'. 
Nast�pnie z podanego tekstu wyrzuca wszystkie samog�oski.
*/

/*********************************************************
*
*	discardVowels(char *text)
*
*********************************************************/

void discardVowels(char *text){
	
	/* funkcja usuwa samogloski z tekstu,
	ktorego wskaznik otrzymuje jako parametr.
	dlugosc tekstu nie moze przekraczac 100 znakow 
	tekst konczy sie znakiem '/0' 
	zwracany tekst jest krotszy o ilosc usunietych samoglosek*/
	
	int i = 0; // zktorego pola pobieramy znak
	int j = 0; // do ktorego pola zapisujemy
	
	while ( text[i] != '\0' ){
		
		switch (text[i]){
			case 'a':
			case 'A':				
			case 'e':
			case 'E':
			case 'o':
			case 'O':	
			case 'u':
			case 'U':	
			case 'y':
			case 'Y':
			case 'i':
			case 'I':	
				// jezeli pobrana samogloska a,-,e,-,o,-,u,y,i +  odpowiednie duze litery - nic nie zapisuj
				break;
			default:
				text[j] = text[i]; // jezeli pozostale znaki, spolgloska, spacja, '.', itp.  - zapisz ja na miejscu 'indeks j' w skroconym ciagu
				j++; 
				break; 
		}	
		i++; // przejdz do nastepnego znaku		
	}
	text[j] = '\0'; // zakoncz nowy tekst znakiem '\0'
}


/*********************************************************
*
*	main
*
*********************************************************/

int main()
	{
		char ala[] = "Ala ma kota mruczka.";
		char *pTekst = ala;		
		
		discardVowels (pTekst);
		cout << pTekst;	// pozadany wynik : 'l m kt mrczk.'
		
		return 0;
	}
