#include <iostream>
using namespace std;

/*
Zadanie 5.1. Temperatura

Napisz program, który temperaturê w stopniach Fahrenheita zamieni na temperaturê w stopniach Celsjusza, 
z dok³adnoœci¹ minimum dwóch miejsc po przecinku. Program wypisze na ekran przeliczanie stopni Fahrenheita 
z zakresu <0..100> co dziesiêæ stopni. Oczekiwane wyjœcie wygl¹da tak:
 

    0  F = -17.7778 C
    10 F = -12.2222 C
    20 F = -6.66667 C
    30 F = -1.11111 C
    40 F = 4.44444 C
*/


int main()
{

	float stopnie_c;


	for (int stopnie_f = 0 ; stopnie_f <=100 ; stopnie_f += 10)
			{
				//stopnie_c = (5/9)*(stopnie_f-32);	
				stopnie_c = (5.0/9.0)*(stopnie_f-32);	
				//cout << stopnie_c;
				cout << stopnie_f << " F = " << stopnie_c << " C" << endl;
			}

	return 0;
}
