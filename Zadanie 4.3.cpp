#include <iostream>
using namespace std;

/*
Zadanie 4.3. Tabliczka mno�enia

U�ywaj�c p�tli for wypisz na ekran tabliczk� mno�enia dla pierwszych 10 liczb naturalnych:
 1  2  3  4  5  6  7  8  9 10
 2  4  6  8 10 12 14 16 18 20
 3  6  9 12 15 18 21 24 27 30
...
10 20 30 40 50 60 70 80 90 100
W ka�dej linii liczby powinny by� oddzielone jedn� spacj�.
*/

int main()
{
	for (int i = 1; i <=10 ; i++)
		{
			for (int j = 1; j <=10; j++)
				{
					cout << i*j << " ";
					
				}
			cout << endl;
		}

	return 0;
}
