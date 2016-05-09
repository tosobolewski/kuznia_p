#include <iostream>
#include <math.h>
#include <string>
using namespace std;

/*
Zadanie 13.4: Ile liter potrzebuje?

Je¿eli liczby 1..5 napisane s¹ s³ownie: jeden dwa trzy cztery piec, to u¿yjemy 5 + 3 + 4 + 6 + 4 = 22 liter, aby je napisaæ. 
Je¿eli chcemy napisaæ s³ownie liczby 1..1000, to ile liter bêdziemy potrzebowaæ? W zadaniu nie liczymy spacji.

Propozycja: warto u¿yæ czêœci kodu z zadania S³ownie z lekcji 9. Powinno to przyœpieszyæ pracê.
*/


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


/*********************************************************
*
*	int ileLiter(int liczba)
*
*********************************************************/

int ileLiter(int liczba){
	
	// zamienia liczbê na tekst i zwraca ilosc liter w tekscie, pod pewnymi warunkami: 
	// 1 zamienia na "jeden' i zwraca 5 (liter)
	// 11 zamienia na 'jedenascie' i zwraca 10
	// 23 zamieni na 'dwadziescia' ( 23/10 = 2 dziesiatki) i zwroci 11 (ilosc liter)
	// 511 zamieni na 'piecset' ( 511/100 = 5 setek) i zwroci 7 (ilosc liter)
	
	string str;
	 
	if (liczba < 10)
	{
		str = jednosciTekst(liczba);
		return str.length();	
	}
	else if ( liczba < 20)
	{
		str = nascieTekst(liczba);
		return str.length();
		
	} 
		else if ( liczba < 100)
	{
		liczba /= 10;
		str = dziesiatkiTekst(liczba); // liczba = cyfra w liczbie na pozycji 10^1 [c]c, dla liczby = 20 bedzie to '2' 
		return str.length();
		
	} 
		else if ( liczba < 1000)
	{
		liczba /= 100;
		str = setkiTekst(liczba);	// liczba - cyfra w liczbie na pozycji 10^2 [c]cc, dla liczby = 500 bedzie to '5'
		return str.length();
		
	} 
}



/*********************************************************
*
*	main
*
*********************************************************/

int main()
{
	// deklaracje
	
	int liczba = 35;
	int mnoznik = 1;
	int wykladnik = 0;
	int ilerazy = 0;
	int ilerazy_nascie = 0;
	int ileliter = 0;
	int ileliter_suma = 0;
	string str;
	
	// program
	
	if (liczba == 1000)	// przypadek szczegolny
	{
		
		str = "jeden";
		ileliter_suma += str.length();
		
		str = "tysiac";
		ileliter_suma += str.length();
		
		cout << "Do zapisania " << liczba << " potrzeba " << ileliter_suma << " liter." << endl;
		
		return 0; // zakoncz
	}
	else if (liczba > 1000)	// liczba poza zakresem
	{
	
		cout << "Liczba poza zakresem obliczen (0..1000)." << endl;
		return 0; // zakoncz		

	}
	
	
	// dla liczb 1..999
	while( (mnoznik / liczba) < 10 )
				{
	
				mnoznik = pow(10, wykladnik);
				
				
				for (int i = 1 ; i < 10; i ++)
					{
				
						if ((liczba - (i*mnoznik)) >= 0)
						{
							// oblicza ile razy wystepuje slowo pomijajac wyjatek '-nascie' w 2 dziesiatce ( korekta w dalszej czesci prgramu
							// 11 - liczy jak dziesiec jeden  (wymaga korekty w dalszej czesci)
							// 21 liczy jak dwadziescia jeden (ok)
							// 31 liczy jak trzydziesci jeden (ok)
							
							ilerazy = 1 + ( liczba - ( i*mnoznik ) ) / ( mnoznik*10 );
							
							// korekta dla liczb w 2 dziesiatce , czyli 'jedenascie' .. 'dziewietnascie'
							// wartosc 'ilerazy' zmniejszana jest o wystapienia slow z koncowka '-nascie'
							// ilosci liter sa liczone dla slow z koncowka'-nascie'
							
							if ( wykladnik == 0) // 'jeden' zastepowany przez 'jedenascie', 'dwa' przez 'dwanascie' itd.
							{
								
								if (ilerazy < 2)
								{
									ilerazy_nascie = 0;
								}
								else if (ilerazy >= 2)
								{
									ilerazy_nascie = 1 + ((ilerazy - 2) / (10 * pow(10,wykladnik) ));
									ilerazy -= ilerazy_nascie;
								}

							}	
							else if ( wykladnik == 1)	// "dziesiec" zastepowany przez "jedenascie" , 'dwanascie' itd.
							{
								if ( i == 1) 		// c[1]c czyli liczby od 10 do 19, z '1' na miejscu 10^1
								// 10-19
								{
									ilerazy -= ilerazy_nascie; // ilerazy_nascie pamietamy z poprzedniego przebiegu petli dla wartosci wykladnika = 0 ( tj. 10^0) 
								}
								else if ( i > 1) 	// c[2-9]c
								//20-99
								{
									ilerazy_nascie = 0;
								}
							} 
							else if ( wykladnik == 2)
							{
								ilerazy_nascie = 0;
							}

						}	
						else
						{
							break; // przerywa petle 'for' bo jestesmy poza zakresem 'liczba'
						}	
	
						
						
						
						
						
						// wypisuj wyniki posrednie
						
						cout << "-----------------------------" << endl;
						cout << "liczba: " << liczba << endl;
						cout << "zmienna i = " << i << endl;
						cout << "mnoznik: " << mnoznik << endl;
						cout << "zmienna ilerazy: " << ilerazy << endl;
						cout << "zmienna ilerazy_nascie: " << ilerazy_nascie << endl;
						
						
						// sumuj obliczone wartosci 
						
						if ( wykladnik == 0) // 'jeden' zastepowany przez 'jedenascie', 'dwa' przez 'dwanascie' itd.
						{
							

									cout << "slowo: " << jednosciTekst(i);
									printf(" %4d (%s) powtarza sie %4d razy \n", i*mnoznik, "-", ilerazy * mnoznik);
									cout << "slowo: " << nascieTekst(i);
									printf(" %4d (%s) powtarza sie %4d razy \n", i*mnoznik, "nascie", ilerazy_nascie * mnoznik);
	
	
							
						}	
						else if ( wykladnik == 1)	// "dziesiec" zastepowany przez "jedenascie" , 'dwanascie' itd.
						{
							
					
									cout << "slowo: " << "dziesiec+nascie";
									printf(" %4d (%s) powtarza sie %4d razy \n", i*mnoznik, "nascie", ilerazy_nascie * mnoznik);
									
									cout << "slowo: " << dziesiatkiTekst(i);
									printf(" %4d (%s) powtarza sie %4d razy \n", i*mnoznik, "-", ilerazy * mnoznik);
									

						
								
						} 
						else if ( wykladnik == 2)
						{
							
									cout << "slowo: " << setkiTekst(i);
									printf(" %4d (%s) powtarza sie %4d razy \n", i*mnoznik, "-", ilerazy * mnoznik);
									
									
						}						
						
						
						//printf("%4d (%s) powtarza sie %4d razy \n", i*mnoznik, "slownie", ilerazy * mnoznik);
						//	cout << "Do zapisania " << setkiTekst(liczba*100) << " potrzeba " << ileliter_suma << " liter." << endl;
						 
						
						
						
						
							
					}







//				
//				// korekta ze wzgledu na koncowke '-nascie'
//				
//				if (( wykladnik % 3 ) == 0) // dla 10^0, 10^3, 10^6, 10^9 ... itd., dla tych wartosci wykladnika jedenascie zastepuje jeden, dwanascie zastepuje dwa itd.
//				{
//					for (int i = 1 ; i < 10; i ++)
//					{
//				
//						if ((liczba - (i*mnoznik)) >= 0)
//						{
//							ilerazy = 1 + ( liczba - ( i*mnoznik ) ) / ( mnoznik*10 );
//							
//							// nascie wystepuje w 2 dziesiatce
//							if (ilerazy >= 2)
//							{
//								ilerazy_nascie = 1 + ((ilerazy - 2) / (10 * pow(10,wykladnik) ));
//							}							
//						}	
//						else
//						{
//							break; // przerywa petle 'for' bo jestesmy poza zakresem 'liczba'
//						}	
//						
//						
//						printf("%4d (%s) powtarza sie %4d razy \n", i*mnoznik, "nascie", ilerazy_nascie);
//						
//					}
//				
//				}
				
			
				
				
				
				
				
				
				
				
				wykladnik ++;
				
				}
	
	return 0;
}

