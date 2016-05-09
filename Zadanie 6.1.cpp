#include <iostream>
using namespace std;

/*
Zadanie 6.1. Karty

Dane s¹ typy wyliczeniowe:

enum figury
{
     dziewiatka = 9,
     dzisiatka,
     walet,
     dama,
     krol,
     as
};

enum kolory
{
     pik = 40,
     trefl = 60,
     caro = 80,
     kier = 100
};

Napisz program, który za pomoc¹ polecenia cin pobierze od u¿ytkownika dwie liczby ca³kowite 
oddzielone spacj¹, np. "11 60". Program za pomoc¹ polecenia cout wyœwietli opis karty, jaka 
zakodowana jest w podanych liczbach. Przyk³adowo dla danych wejœciowych "11 60" program 
wyœwietli: "walet trefl". Je¿eli u¿ytkownik poda pierwsz¹ liczbê spoza zakresu 9..14 lub drug¹ 
inn¹ ni¿ 40, 60, 80 lub 100, program wyœwietli komunikat: "niepoprawna wartosc".

*/

int main()
{
	int a;
	int b;
	
// wstepnie ustawiony test = 1 => tj. zaklada wartosci 'a' i 'b' s¹ poprawne	
	int test = 1;

// wczytanie danych - dwie wartosci w jednej linni oddzielone spacja
	cin >> a >> b ;
	
// test pooprawnosci wartosci 'a', test = 0 => wartosc 'a' jest niepoprawna

	if ( a < 9 )
		{
					test = 0; 
		}
	else if ( a <= 14 )
		{
					// instrukcja pusta, pozostaje test = 1;
		}
	else 
		{
					test = 0;
		}
	
// test poprawnosci wartosci 'b', test = 0 => wartosc 'b' jest niepoprawna
	
	switch (b)
		{
			case 40:  break;
			case 60:  break;
			case 80:  break;
			case 100: break;
			default:  test = 0; break;
		}


// wyprowadzenie wynikow na konsole

	if ( test == 0 )
 		{
 			cout << "niepoprawna wartosc";
 		}
 	else
 		{
 			switch (a)
 				{
 					case 9 : cout << "dziewiatka " ; break; 
 					case 10 : cout << "dziesiatka "; break;
 					case 11 : cout << "walet "; break;
 					case 12 : cout << "dama "; break;
 					case 13 : cout << "krol "; break;
 					case 14 : cout << "as "; break;
 					default : cout << "blad w 'swich (a)' " << endl; break;
 				}
 			
 			
 			switch (b)
			 	{
			 		case 40: cout << "pik" << endl; break;
					case 60: cout << "trefl" << endl; break;
					case 80: cout << "caro" << endl; break;
					case 100: cout << "kier" << endl; break;
					default: cout << "blad w 'swich (b)' " << endl;break;
			 	}		
 		}
 

	return 0;
}
