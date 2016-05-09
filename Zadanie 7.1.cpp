#include <iostream>
using namespace std;

/*
Zadanie 7.1. FizzBuzz

Napisz program spe³niaj¹cy wszystkie poni¿sze wymagania:

Wypisz na ekran liczby od 1 do 100 oddzielone pojedyñczym znakiem spacji lub pojedyñczym znakiem koñca linii
Dla wielokrotnoœci liczby 3 wyœwietl "Fizz" zamiast liczby
Dla wielokrotnoœci pi¹tki wyœwietl "Buzz" zamiast liczby
Dla liczb bêd¹cych wielokrotnoœciami 3 i 5 wyœwietli "FizzBuzz" zamiast liczby
*/

int main()
{
	for (int i = 1; i <=100; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
			{
				cout << "FizzBuzz" << endl; // 3,5
			}
			else
			{
				cout << "Fizz" << endl; //3
			}
		}
		else
		{
			if (i % 5 == 0)
			{
				cout << "Buzz" << endl; // 5
			}
			else
			{
				cout << i << endl;
			}
		}
	}

	return 0;
}
