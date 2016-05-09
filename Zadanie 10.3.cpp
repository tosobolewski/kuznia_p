#include <iostream>
using namespace std;

/*
Zadanie 10.3. Ci�g Fibonacciego

Napisz funkcj� int fibonacci(int n) generuj�c� ci�g n pocz�tkowych liczb Fibonacciego. Funkcja przyjmuje na wej�ciu liczb� n, 
wypisuje na ekran ci�g n liczb oddzielonych spacjami, oraz jako wynik swojego dzia�ania zwraca ostatni� liczb� ci�gu.

Przyk�adowo dla liczby n = 10, funkcja powinna zwr�ci� liczb� 34, a na ekranie powinien pojawi� si� ci�g liczb: 0 1 1 2 3 5 8 13 21 34
*/



/****************************************************
*
*	int fibonacci(int n)
*
*****************************************************/

int fibonacci(int n){
	
	if (n == 1){					// dla n = 1
		cout << "0" << endl;
		return 0;
	} else if (n == 2){			// dla n = 2
		cout << "0 1" << endl;
		return 1;
	} else {					// dla pozostalych n
		
		int m = 0;
		int prev2 = 0;
		int prev1 = 1;
		
		cout << prev2 << " " << prev1;
		
		for (int i = 2; i < n; i++ ){
			m = prev1 + prev2;
			prev2 = prev1;
			prev1 = m;
			cout << " " << m ;
		}
		
		cout << endl;
		
		return m;
	}
	
}



/****************************************************
*
*	main
*
*****************************************************/


int main()
{
	
	cout << fibonacci(10) << endl;
	
	return 0;
}

