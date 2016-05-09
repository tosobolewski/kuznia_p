#include <iostream>
using namespace std;

/*
Zadanie 9.1. Tr�jk�t

Napisz funkcj� jakiTrojkat. Funkcja b�dzie mia�a trzy argumenty, dzi�ki kt�rym pobierze d�ugo�ci trzech bok�w tr�jk�ta: a, b i c. 

Funkcja sprawdzi jaki tr�jk�t mo�na stworzy� z podanych bok�w tr�jk�ta. Jako wynik swego dzia�ania funkcja zwr�ci jedn� z warto�ci:

enum rodzajTrojkata
{
	BRAK,		// jezeli nie mozna stworzyc trojkata
	PROSTOKATNY,	// jezeli trojkat jest prostokatny
	ROZWARTOKATNY,	// jezeli trojkat jest rozwartokatny
	OSTROKATNY	// jezeli trojkat jest ostrokatny
};
Przyk�adowe wej�cie i wyj�cie programu:

1 1 10 = BRAK
3 4 5 = PROSTOKATNY
2 3 4 = ROZWARTOKATNY
7 7 7 = OSTROKATNY		
*/

enum rodzajTrojkata
{
	BRAK,		// jezeli nie mozna stworzyc trojkata
	PROSTOKATNY,	// jezeli trojkat jest prostokatny
	ROZWARTOKATNY,	// jezeli trojkat jest rozwartokatny
	OSTROKATNY	// jezeli trojkat jest ostrokatny
};



rodzajTrojkata jakiTrojkat(float pa, float pb, float pc)
{

// znalezienie najd�u�szego boku (przeciwprostokatnej) z pa, pb, pc i przypisanie wartosci do (c)

float a, b, c;

if ((pa >= pb) && (pa >= pb)) // jezeli parametr a (pa) jest najwiekszy
{
	a = pb; b = pc; c = pa;
}


if ((pb >= pa) && (pb >= pc)) // jezeli parametr b (pb) jest najwiekszy
{
	a = pc; b = pa; c = pb;
}


if ((pc >= pa) && (pc >= pb)) // jezeli parametr c (pc) jest najwiekszy
{
	a = pa; b = pb; c = pc;
}

// obliczenia

if ((c >= a) && (c >= b)) // je�eli c jest przeciwprostokatna
{
		if ((a+b)<=c)
		{
				cout << a << " " << b << " " << c << " = " << "BRAK" << endl;
				return BRAK;  // BRAK TROJKATA = 0
				
		}
		else if ((a*a + b*b)<(c*c)) 
		{
				cout << a << " " << b << " " << c << " = " << "ROZWARTOKATNY" << endl;
				return ROZWARTOKATNY; //ROZWARTOKATNY = 3
				
		}
		else if ((a*a + b*b)==(c*c))
		{
				cout << a << " " << b << " " << c << " = " << "PROSTOKATNY" << endl;
				return PROSTOKATNY; //PROSTOKATNY = 2
				
		}
		else if ((a*a + b*b)>(c*c))
		{
				cout << a << " " << b << " " << c << " = " << "OSTROKATNY" << endl;
				return OSTROKATNY; // OSTROKATNY = 4
				
		}		
}
else
{
	cout << "blad w sprawdzaniu warunkow trojkata - np. trzeci parametr (c)  nie jest przeciwprostokatna" << endl;
	
	//return BRAK; // nie do ko�ca prawidlowe bo przeciwprostokatna moze byc parametr (a) lub (b) niekoniecznie (c)
}
	
}

int main()
{
		/*
		cout << jakiTrojkat(1,1,10) << endl;
		cout << jakiTrojkat(3,4,5) << endl;
		cout << jakiTrojkat(2,3,4) << endl;
		cout << jakiTrojkat(7,7,7) << endl;
		
		cout << jakiTrojkat(3.3,4.1,5.1) << endl;
		cout << jakiTrojkat(5,4,3) << endl;
		cout << jakiTrojkat(3,6,4) << endl;
		cout << jakiTrojkat(7,4,3) << endl;
		*/
		
		//cout << rodzajTrojkata(3) << endl;

	return 0;
}

