#include <iostream>
using namespace std;

/*
Zadanie 6.1. Karty

Dane s� typy wyliczeniowe:

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

Napisz program, kt�ry za pomoc� polecenia cin pobierze od u�ytkownika dwie liczby ca�kowite 
oddzielone spacj�, np. "11 60". Program za pomoc� polecenia cout wy�wietli opis karty, jaka 
zakodowana jest w podanych liczbach. Przyk�adowo dla danych wej�ciowych "11 60" program 
wy�wietli: "walet trefl". Je�eli u�ytkownik poda pierwsz� liczb� spoza zakresu 9..14 lub drug� 
inn� ni� 40, 60, 80 lub 100, program wy�wietli komunikat: "niepoprawna wartosc".

*/

int main()
{
	int a;
	int b;
	
// wstepnie ustawiony test = 1 => tj. zaklada wartosci 'a' i 'b' s� poprawne	
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
