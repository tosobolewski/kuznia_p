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
	int wybor;
	
	cin >> wybor;
	
	switch (wybor)
		{
			case stan_konta:
				break;
			
			case wyplata_50:
				break;
			
			case wyplata_100:
				//cout << "3" << endl;
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

