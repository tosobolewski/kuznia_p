#include <iostream>
using namespace std;

/*

*/
enum menu_bankomat 
	{
		stan_konta = 0,
		wyplata_50 = 1,
		wyplata_100 = 2,
		wyplata_inna = 3,
		wyjscie = 4
	};

int main()
{

// wypisz menu na konsoli
	cout << "1 - Sprawdzenie salda\n";
	cout << "2 - Szybka wyplata 50 zl\n";
	cout << "3 - Szybka wyplata 100 zl\n";
	cout << "4 - Wyplata innej kwoty\n";
	cout << "0 - Wyjscie z programu\n";

	
	enum menu
			{
				wyjscie = 0,
				stan_konta = 1,
				wyplata_50 = 2,
				wyplata_100 = 3,
				wyplata_inna = 4
			};








	int wybor;
	
	cin >> wybor;
	
	switch (wybor)
		{
			case stan_konta:
				break;
			
			case wyplata_50:
				break;
			
			case wyplata_100:
				cout << "3" << endl;
				break;
			
			case wyplata_inna:
				break;
			
			case wyjscie:
				break;
			
			default:
				break;
		}

	return 0;
}

