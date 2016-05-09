#include <iostream>
using namespace std;

int main()
{
	int osoby;
	cout << "Podaj liczbe osob: ";
	cin >> osoby;
	
	
	if (osoby < 1)
		{
				cout << 0 << endl;
		}	
	else if (osoby <= 2 )
		{
				cout << 2 << endl;
		}
	else if (osoby <= 4 )
		{
				cout << 4 << endl;
		}
	else if (osoby <= 6 )
		{
				cout << 6 << endl;
		}
	else if ( osoby <= 10 )
		{
				cout << 10 << endl;
		}
	else if ( osoby > 10)
		{
				cout << 0 << endl;
		}
	
	return 0;
}
