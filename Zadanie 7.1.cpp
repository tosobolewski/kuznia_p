#include <iostream>
using namespace std;

/*
Zadanie 7.1. FizzBuzz

Napisz program spe�niaj�cy wszystkie poni�sze wymagania:

Wypisz na ekran liczby od 1 do 100 oddzielone pojedy�czym znakiem spacji lub pojedy�czym znakiem ko�ca linii
Dla wielokrotno�ci liczby 3 wy�wietl "Fizz" zamiast liczby
Dla wielokrotno�ci pi�tki wy�wietl "Buzz" zamiast liczby
Dla liczb b�d�cych wielokrotno�ciami 3 i 5 wy�wietli "FizzBuzz" zamiast liczby
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
