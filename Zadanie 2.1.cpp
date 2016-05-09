#include <iostream>
using namespace std;

int main()
{
	int year;
	cout << "Podaj rok: ";
	cin >> year;
	
	
	if (year == 0)
		{
				cout << "Wprowadzone dane sa nieprawidlowe" << endl;
		}
	else if (year < 0)
		{
				cout << "Rok " << -year << " p.n.e. byl " << -year + 2014<< " lat temu" << endl;
		}
	else if (year < 2014)
		{
				cout << "Rok " << year << " byl " << 2014 - year << " lat temu" << endl;
		}
	else if (year == 2014)
		{
				cout << "Rok 2014 jest obecnie" << endl;
		}
	else if (year > 2014)
		{
				cout << "Rok " << year << " nastapi za " << year - 2014 << " lat" << endl;
		}
	
	return 0;
}
