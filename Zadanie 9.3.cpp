#include <iostream>
//#include <basic_string.h>
using namespace std;

/*
Zadanie 9.3. S³ownie

Jedn¹ z najbardziej irytuj¹cych rzeczy podczas wype³niania przelewów pocztowych jest wpisywanie kwoty s³ownie. Dlatego celem programu jest zautomatyzowanie tej ¿mudnej czynnoœci.
Wymagania: program zapyta u¿ytkownika o podanie liczby naturalnej z przedzia³u 1..1 000 000 000 000. Nastêpnie wyœwietli t¹ liczbê w zapisie s³ownym (w wyrazach nie u¿ywamy polskich znaków). W zapisie nale¿y u¿yæ nastêpuj¹cych skrótów:
tys. - tysi¹c, mln. - milion, mld. - miliard, bln. - bilion.
Przyk³ady:
1459 -> jeden tys. czterysta piecdziesiat dziewiec
123456789 -> sto dwadziescia trzy mln. czterysta piecdziesiat szesc tys. siedemset osiemdziesiat dziewiec

Zadanie to jest wariacj¹ zadania dostêpnego na SPOJ: Liczba na s³owo.
*/

/*************************************************************
*
*	int funkcja ileMaCyfr(int liczba)
*
**************************************************************/

int ileMaCyfr(long long int liczba){
	
	int iloscCyfr = 0;
	
	while(liczba > 0 ){
			liczba = liczba / 10;
			iloscCyfr += 1;		
	}
		
	return iloscCyfr;
}
/***************************************************************/

/*
*	funkcja jednosciTekst(int)
*/

string jednosciTekst(int liczba){
		
		string exitTekst; 
		
		switch(liczba){
			case 0:
				exitTekst = "";
				break;
			case 1:
				exitTekst = "jeden ";
				break;
			case 2:
				exitTekst = "dwa ";
				break;
			case 3:
				exitTekst = "trzy ";
				break;
			case 4:
				exitTekst = "cztery ";
				break;
			case 5:
				exitTekst = "piec ";
				break;
			case 6:
				exitTekst = "szesc ";
				break;
			case 7:
				exitTekst = "siedem ";
				break;
			case 8:
				exitTekst = "osiem ";
				break;
			case 9:
				exitTekst = "dziewiec ";
				break;
			default:
				exitTekst = "blad przy ustalaniu tekstu dla jednostek \n";
				break;
		}
		return exitTekst;
}

/*
*	funkcja nascieTekst(int)
*/

string nascieTekst(int liczba){
		
		string exitTekst; 
		
		switch(liczba){
			case 0:
				exitTekst = "dziesiec ";
				break;
			case 1:
				exitTekst = "jedenascie ";
				break;	
			case 2:
				exitTekst = "dwanascie ";
				break;
			case 3:
				exitTekst = "trzynascie ";
				break;
			case 4:
				exitTekst = "czternascie ";
				break;
			case 5:
				exitTekst = "pietnascie ";
				break;
			case 6:
				exitTekst = "szesnascie ";
				break;
			case 7:
				exitTekst = "siedemnascie ";
				break;
			case 8:
				exitTekst = "osiemnascie ";
				break;
			case 9:
				exitTekst = "dziewietnascie ";
				break;
			default:
				exitTekst = "blad przy ustalaniu tekstu dla -nascie \n";
				break;
		}
		return exitTekst;
}


/*
*	funkcja dziesiatkiTekst(int)
*/

string dziesiatkiTekst(int liczba){
		
		string exitTekst; 
		
		switch(liczba){
			case 0:
				exitTekst = "";
				break;
			case 2:
				exitTekst = "dwadziescia ";
				break;
			case 3:
				exitTekst = "trzydziesci ";
				break;
			case 4:
				exitTekst = "czterdziesci ";
				break;
			case 5:
				exitTekst = "piecdziesiat ";
				break;
			case 6:
				exitTekst = "szescdziesiat ";
				break;
			case 7:
				exitTekst = "siedemdziesiat ";
				break;
			case 8:
				exitTekst = "osiemdziesiat ";
				break;
			case 9:
				exitTekst = "dziewiecdziesiat ";
				break;
			default:
				exitTekst = "blad przy ustalaniu tekstu dla dziesiatek \n";
				break;
		}
		return exitTekst;
}


/*
*	funkcja setkiTekst(int)
*/

string setkiTekst(int liczba){
		
		string exitTekst; 
		
		switch(liczba){
			case 0:
				exitTekst = "";
				break;
			case 1:
				exitTekst = "sto ";
				break;
			case 2:
				exitTekst = "dwiescie ";
				break;
			case 3:
				exitTekst = "trzysta ";
				break;
			case 4:
				exitTekst = "czterysta ";
				break;
			case 5:
				exitTekst = "piecset ";
				break;
			case 6:
				exitTekst = "szescset ";
				break;
			case 7:
				exitTekst = "siedemset ";
				break;
			case 8:
				exitTekst = "osiemset ";
				break;
			case 9:
				exitTekst = "dziewiecset ";
				break;
			default:
				exitTekst = "blad przy ustalaniu tekstu dla setek \n";
				break;
		}
		return exitTekst;
}

/*
*	funkcja tekstDlaTrzechCyfr(int liczba)
*/

string tekstDlaTrzechCyfr(int liczba) {
		
		int c1, c2, c3; // zmienne w których znajda siê cyfry - (np. dla 567) kolejno: pierwsza cyfra = 5, druga cyfra = 6, trzecia cyfra = 7
		
		c3 = liczba % 10;
		liczba /= 10;
		c2 = liczba % 10;
		liczba /= 10;
		c1 = liczba % 10;
		
		string s1, s2, s3; // zmienne w których znajdzie siê tekst odpowiadaj¹cy cyfrom - odpowiednio: c1 -> s1, c2 -> s2, c3 -> s3
		
		s1 = setkiTekst(c1);	// [c]cc
		if (c2 == 1) {
			s2 = nascieTekst(c3);	// c[cc]
		} else {	
			s2 = dziesiatkiTekst(c2);	// c[c]c
			s3 = jednosciTekst(c3);		// cc[c]
		}
		
		string s = s1 + s2 + s3;
		
		return s;
		
}

/*
* test()
*/




int main()
{

	long long int liczbaWczytana;
	
// 	wczytanie z konsoli danych do programu
	
	cout << "Podaj liczbe naturalna z przedzialu 1..1 000 000 000 000: ";
	cin >> liczbaWczytana;
	if ((liczbaWczytana < 1) || (liczbaWczytana > 1000000000000)){	// jezeli niepoprawna liczba
		cout << "Podales liczbe spoza wymaganego przedzialu" << endl;
		return 0; // zakoncz program
	}
	
	//liczbaWczytana = 1123456789123;
	
// ile znaków ma liczba
	int iloscZnakowWczytanejLiczby = ileMaCyfr(liczbaWczytana);	
	cout << "Ilosc znakow w liczbie: " << iloscZnakowWczytanejLiczby << endl; 




	long long int liczba = liczbaWczytana;
	int trzyKoncoweCyfry = 0;
	string s1 = "";
	string s2 = "";
	string s3 = "";
	string s4 = "";
	string s5 = "";


//  dekodowanie ostatnich trzech cyfr -> s1 , liczba zawsze wiêksza od 0 

	trzyKoncoweCyfry = liczba % 1000;
	if (trzyKoncoweCyfry !=  0 ){
			s1 = tekstDlaTrzechCyfr(trzyKoncoweCyfry);
	}


//	skrocenie liczby o trzy ostatnie cyfry i dekodowanie trzech koncowych cyfr nowej liczby = ilosc tys. -> s2
	
	liczba = liczba / 1000;							
	trzyKoncoweCyfry = liczba % 1000;
	if (trzyKoncoweCyfry !=  0 ){
			s2 = tekstDlaTrzechCyfr(trzyKoncoweCyfry) + "tys. ";				
	}
	

//	skrocenie liczby o trzy ostatnie cyfry i dekodowanie trzech koncowych cyfr nowej liczby = ilosc mln. -> s3
	
	liczba = liczba / 1000;					
	trzyKoncoweCyfry = liczba % 1000;
	if (trzyKoncoweCyfry != 0 ){
			s3 = tekstDlaTrzechCyfr(trzyKoncoweCyfry) + "mln. ";
	}
		
	

//	skrocenie liczby o trzy ostatnie cyfry i dekodowanie trzech koncowych cyfr nowej liczby = ilosc mld. -> s4
	liczba = liczba / 1000;					
	trzyKoncoweCyfry = liczba % 1000;
	if (trzyKoncoweCyfry != 0 ){				
			s4 = tekstDlaTrzechCyfr(trzyKoncoweCyfry) + "mld. ";
	}

//	skrocenie liczby o trzy ostatnie cyfry i dekodowanie trzech koncowych cyfr nowej liczby = ilosc bln. -> s5
	liczba = liczba / 1000;					
	trzyKoncoweCyfry = liczba % 1000;
	if (trzyKoncoweCyfry != 0 ){				
			s5 = tekstDlaTrzechCyfr(trzyKoncoweCyfry) + "bln. ";
	}


// wydruk wyniku na konsole
	cout << endl << s5 + s4 + s3 + s2 + s1 << endl;



// testy	
//		cout << tekstDlaTrzechCyfr(123) << endl;
//		cout << tekstDlaTrzechCyfr(456) << endl;
//		cout << tekstDlaTrzechCyfr(789) << endl;
//		cout << tekstDlaTrzechCyfr(111) << endl;
//	

	
	return 0;
	
	
	
}

