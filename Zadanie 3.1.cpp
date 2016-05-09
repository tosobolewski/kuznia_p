#include <iostream>
using namespace std;

/*
Zadanie 3.1. Suma liczb

Napisz program, który za pomoc¹ polecenia cin pobiera liczby podane przez u¿ytkownika. Nastêpnie 
sumuje te liczby tak d³ugo, dopóki u¿ytkownik nie poda liczby zero. Jako wynik dzia³ania program 
wypisze na ekran tylko jedn¹ liczbê, bêd¹c¹ sum¹ liczb dotychczas wpisanych przez u¿ytkownika.

Przyk³adowo dla liczb wpisanych przez u¿ytkownika: 4 8 9 44 0 program wypisze na ekran liczbê: 65.
*/

int main()
{
	int liczba = 0;
	int sumaLiczb = 0;
	
	while (1)
	{
		
		cin >> liczba;
			
		if (liczba==0) 
			{
				break;
			}
		
		sumaLiczb += liczba;
		
	}
	
	cout << sumaLiczb;
	
	return 0;
}
