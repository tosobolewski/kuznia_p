#include <iostream>
#include <cstdlib> // srand() , rand(), RAND_MAX
#include <string>
#include <time.h> // srand(time(NULL));
using namespace std;

/*
Zadanie 13.2 Gra w Wojnê - karty

II wersja gry w wojne, 
dodano zmienne globalne - wskazniki do tablicy
dodano dwoch graczy Gracz C , Gracz D

liczba_graczy w niektorych miejscach, przy deklaracji rozmiaru tablic jest przyjeta na sztywno = 4
poniewaz nie mozna bylo zadeklarowac wielkosci tablicy zmienna (np. porownajKartyNaStole() )
*/


/********************************************************************
*
*	zmienne globalne
*
*********************************************************************/

	const int ile_graczy 	= 4;	// WARTOSC STALA ZEBY MOZNA BYLO ZADEKLAROWAC ROZMIAR TABLICY
	const int TALIA 		= 52;

	// glowna tablica gry
		
	// 	lacznie ... elementow, kolumny 0..3 - karty Graczy 'na rece", 4...7 karty Graczy na stole, 8..15 kolumna - 2x4 liczniki
	int tablicaGry [  ile_graczy * TALIA 	/*4 tablice x 52 elementy => karty 4 graczy na rece*/ 
					+ ile_graczy * TALIA 	/*4 tablice x 52 elementy => karty 4 graczy na stole*/
					+ ile_graczy * 1 	/* 4 liczniki wielkosci 'int' => liczba kart na rece*/
					+ ile_graczy * 1 	/* 4 liczniki wielkosci 'int' => liczba kart na rece*/
					+ ile_graczy * 1 	/* 4 komorki wielkosci 'int' => ktory gracz uczestniczy w wojnie*/
					+ ile_graczy * 1 	/* 4 komorki wielkosci 'int' => ktory gracz dalej gra*/] = {0};
						
	int wyniki_gier[ile_graczy] = {0}; // do zapisywania wynikow serii np 1000 rozgrywek
	int remisy_gier[1] = {0};
	int ilosc_gier[1] = {0};
	int ilosc_wylozen[1] = {0};
	
	
	// wskazniki na poczatki odpowiednich fragmentow tablicyGry
	int * pkarty_reka 	= tablicaGry;
	int * pkarty_stol 	= tablicaGry + 		ile_graczy * TALIA; 				// przesuniecie o ilosc graczy x talia dla kazdego gracza = 4 x 52 = 208
		
	int * pile_reka 	= tablicaGry + (2 * ile_graczy * TALIA); 				// przesuniete o 2 zestawy kart, 4x 52 - karty graczy 'na rece' oraz 4 x 52 - karty graczy 'na stole'
	int * pile_stol 	= tablicaGry + (2 * ile_graczy * TALIA) + ile_graczy;
	int * pwojna		= pile_stol + ile_graczy;
	int * pczy_gra		= pwojna + ile_graczy;	// wartosci 0/1 czyli nie gra / gra

	//bool wojna = false; // TODO zamienic typ na 'bool'
	int zglwojna = 0;

/***************************************************************************
*
*	string jakaKarta(int nrKarty)
*
****************************************************************************/

string jakaKarta(int nrKarty)
{
	// argument = numer karty 0 .. 51
	// zwraca string w formacie np. dla 0 => "dwojka trefl"
	
	string karty[13] = {"dwojka", "trojka", "czworka", "piatka", "szostka", "siodemka", "osemka", "dziewiatka", "dziesiatka", "walet", "dama", "krol", "as"};
	string kolor[4] = {"trefl", "karo", "kier", "pik"};	
	
	string sWynik = karty[nrKarty / 4] + " " + kolor[nrKarty % 4];
	
	return sWynik;
	
}

/***************************************************************************
*
*	void wypiszKartyZTablicy(int * tab, int len)
*
****************************************************************************/

void wypiszKartyZTablicy(int * tab, int len)
{
	// wypisuje na konsole karty z tablicy 'int' zamieniajac je na 'string'
	
	for ( int i = len-1 ; i >=0 ; i--)
	{
		
		cout << i << " " << jakaKarta( *(tab+i) ) << endl;
	}

	// dodaj na koncu pusta linie
	cout << endl;
	
}


/***************************************************************************
*
*	void wypiszKarty(int * tab)
*
****************************************************************************/

void wypiszKartyGry(int * tab)
{
	// wypisuje na konsole karty wszystkich graczy i karty na stole 
	// 'int' zamieniajac je na 'string'
	

	int  ilemakart[ile_graczy] = {0}; // deklaracja tablicy z iloscia kart
	
	string strA="", strB="", strC="", strD=""; // domyslnie string drukowany w tabeli jest pusty ="";
	
	printf("\n-----------------------------------------------------------------------------\n");
	
	
	// --- karty na stole ---
	
	
	printf("  %18s %18s %18s %18s \n\n", "Stol_A", "Stol_B", "Stol_C" , "Stol_D");	// drukuj naglowek tabeli 


	strA=""; // domyslnie string drukowany w tabeli jest pusty ="";
	strB="";
	strC="";
	strD=""; 
		
	for ( int gracz = 0; gracz < ile_graczy ; gracz++)
	{
		ilemakart[gracz] = *(pile_stol + gracz); // ile kart na stole ma gracz 'i'
		//cout << *(pile_stol + gracz) << endl;
		
	}
	
	int ileMax = 0; // ktory gracz ma najwiecej kart na stole do wydrukowania i 'ileMax' wynosi
	
	for ( int gracz = 0; gracz < ile_graczy ; gracz++)
	{
		ileMax = max(ileMax, ilemakart[gracz]); // najwieksza ilosc kart = ile trzeba wydrukowac linii w tabeli
				
	}	
		

	for ( int i = ileMax-1; i >=0 ; i--) 
	{

		if( i < ilemakart[0] )  strA = jakaKarta( *(pkarty_stol + (0*TALIA) + i)); // wartosci tabeli dla graczy A, B, C, D
		if( i < ilemakart[1] )  strB = jakaKarta( *(pkarty_stol + (1*TALIA) + i));
		if( i < ilemakart[2] )  strC = jakaKarta( *(pkarty_stol + (2*TALIA) + i));
		if( i < ilemakart[3] )  strD = jakaKarta( *(pkarty_stol + (3*TALIA) + i));
			
		printf(" %18s %18s %18s %18s \n",  strA.c_str(), strB.c_str(), strC.c_str(), strD.c_str());	// drukuj nzawartosc tabeli 
			
	}	
	// dodaj 2 puste linie
	cout << endl << endl;

	// --- karty graczy ---
	
	//ile[ile_graczy] = {0}; // deklaracja tablicy z iloscia kart // kompilartor  zglasza zastrzezenai do takiego zerowania tablicy
	ilemakart[ile_graczy];
	
	for ( int i = 0; i < ile_graczy ; i++)
	{
		ilemakart[i] = *(pile_reka + i); // ile kart ma gracz 'i'
		//cout << *(pile_stol + i) << endl;
	}
	
	ileMax = 0; // ktory gracz ma najwiecej kart do wydrukowania i 'ileMax' wynosi
	
	for ( int i = 0; i < ile_graczy ; i++)
	{
		ileMax = max(ileMax, ilemakart[i]); // najwieksza ilosc kart = ile trzeba wydrukowac linii
		
	}	
	

	printf("  %18s %18s %18s %18s \n\n", "Gracz_A", "Gracz_B", "Gracz_C" , "Gracz_D");	// drukuj naglowek tabeli 


	strA=""; // domyslnie string drukowany w tabeli jest pusty ="";
	strB="";
	strC="";
	strD=""; 
		
	for ( int i = ileMax-1; i >=0 ; i--) 
	{

		if( i < ilemakart[0] )  strA = jakaKarta( *(pkarty_reka + (0*TALIA) + i)); // wartosci tabeli dla graczy A, B, C, D
		if( i < ilemakart[1] )  strB = jakaKarta( *(pkarty_reka + (1*TALIA) + i));
		if( i < ilemakart[2] )  strC = jakaKarta( *(pkarty_reka + (2*TALIA) + i));
		if( i < ilemakart[3] )  strD = jakaKarta( *(pkarty_reka + (3*TALIA) + i));
			
		printf(" %18s %18s %18s %18s \n",  strA.c_str(), strB.c_str(), strC.c_str(), strD.c_str());	// drukuj nzawartosc tabeli 
			
	}	

	// dodaj na koncu pusta linie
	cout << endl;
	
	
//	wypiszKartyZTablicy(pkarty_stol+ (0*TALIA),10);
//	wypiszKartyZTablicy(pkarty_stol+ (1*TALIA),10);
//	wypiszKartyZTablicy(pkarty_stol+ (2*TALIA),10);
//	wypiszKartyZTablicy(pkarty_stol+ (3*TALIA),10);
}

/***************************************************************************
*
*	void zamienKartyMiejscami(int *tabTalia, int *karta_1, int * karta_2)
*
****************************************************************************/

void zamienKartyMiejscami(int *tabTalia, int *pKarta_1, int *pKarta_2)
{
	// zamienia miejscami  2 karty wskazane w argumencie w talii np. 52 karty
	// pierwszy argument wywolania nie jest aktualnie wykorzystywany
	
	cout << __FUNCTION__ << endl;
	
	int temp = 0;
	
	temp= *(pKarta_1);
	*(pKarta_1) = *(pKarta_2);
	*(pKarta_2) = temp;

}

/*********************************************************
*
*	void tasujTalie(int *tabTalia, int len)
*
*********************************************************/

void tasujTalie(int *tabTalia, int len)
{
	// tasuje talie 52 kart
	// tasowanie polega na losowaniu pary kart i zamienianiu ich miejscami
	// losowanie odbywa sie 52 razy, tak, aby kazda karta miala statystycznie jedna mozliwosc zmiany miejsca
	// *tab - wskaznik na tablice, 'len' - ilosc kart/dlugosc tablicy
	
	cout << __FUNCTION__ << endl;
	
	int kartaRandom = 0; // pozycja losowo wybranej karty w tablicy
	int *pKarta_1 = NULL;
	int *pKarta_2 = NULL;
	
	srand(1);
	
	// losuj tyle razy ile kart jest w talii
	for (int i = 0; i < len ; i++)
	{
		kartaRandom = (rand()*52)/(RAND_MAX+1); // losowe wartosci 0..51
		pKarta_1 = tabTalia + kartaRandom;
		
		kartaRandom = (rand()*52)/(RAND_MAX+1); // losowe wartosci 0..51
		pKarta_2 = tabTalia + kartaRandom;
		
		// zamien wylosowane karty
		zamienKartyMiejscami(tabTalia, pKarta_1, pKarta_2);
	}
	
	// koniec-talia potasowana
}

/*********************************************************
*
*	void tasujTalie_2(int *tabTalia, int len)
*
*********************************************************/

void tasujTalie_2(int *tabTalia, int len)
{
	// tasuje talie 52 kart
	// tasowanie polega na losowaniu pary kart i zamienianiu ich miejscami
	// losowanie odbywa sie 52 razy, tak, aby kazda karta miala statystycznie jedna mozliwosc zmiany miejsca
	// *tab - wskaznik na tablice, 'len' - ilosc kart/dlugosc tablicy
	
	cout << __FUNCTION__ << endl;
	
	int kartaRandom = 0; // pozycja losowo wybranej karty w tablicy
	int *pKarta_1 = NULL;
	int *pKarta_2 = NULL;
	
	int zakres = 0;
	
	srand(time(NULL));
	
	// losuj , i = 0..50
	for (int i = 0; i < len - 2 ; i++)
	{
		
		
		// (rand / (RAND_MAX+1)) * ((zakres+1))
		zakres = 51-i; // 51..1
		kartaRandom = i + ( rand() * (zakres+1)) / (RAND_MAX+1); // druga karta 0..51
		
		pKarta_1 = tabTalia + i; // pierwsza karta 0..50
		pKarta_2 = tabTalia + kartaRandom;
		
		// zamien wylosowane karty
		zamienKartyMiejscami(tabTalia, pKarta_1, pKarta_2);
	}
	
	// koniec-talia potasowana
	wypiszKartyZTablicy(tabTalia, 52);
}



/*********************************************************
*
*	void utworzTalie(int *tab, int len)
*
*********************************************************/

void utworzTalie(int *tabTalia, int len)
{
	// tworzy talie talie 52 kart, z kartami u³o¿onymi w kolejnosci 0...51
	// 0..3 - 4 x dwojki, 4..7 - 4 x trojki itd. , 48..51 - 4 x asy 
	// *tab - wskaznik na tablice, 'len' - ilosc kart/dlugosc tablicy
	
	cout << __FUNCTION__ << endl;
	
	for (int i = 0; i < len ; i++)
	{
		*(tabTalia + i) = i;
	}
	
	// koniec-talia utworzona
}



/*********************************************************
*
*	int iluGraczyPrzyStole()
*
*********************************************************/

int iluGraczyPrzyStole()

{
	// zlicza aktywnych graczy przy stole, *pczygra[] = 1;
	int wynik = 0;
	for(int gracz = 0; gracz < ile_graczy; gracz++)
	{
		if ( *(pczy_gra + gracz) > 0 ) wynik++;  
	}
	
	cout << __FUNCTION__ << ": " << wynik << endl;
	
	return wynik;
}

/*********************************************************
*
*	bool czyGraTrwaDalej()
*
*********************************************************/

bool czyGraTrwaDalej()
{
	// sprawdza ilu graczy zosta³o przy stole
	
	if( iluGraczyPrzyStole() > 1) 
	{
		// jezeli conajmniej 2 graczy
		return true;	
	}
	else
	{
		// jezeli tylko 1 gracz
		return false;
	}

}

/*********************************************************
*
*	bool czyGra(int gracz)
*
*********************************************************/

bool czyGra(int gracz)
{
	// sprawdza czy gracz jest aktywny ( uczestniczy w grze)

	if ( gracz < ile_graczy)
	{
		if ( *( pczy_gra + gracz) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}


/*********************************************************
*
*	int ileMaKartReka(int gracz)
*
*********************************************************/

int ileMaKartReka(int gracz)
{
	// sprawdza ile gracz ma kart 'na rece'

	if (czyGra(gracz) == true)
	{
		return *( pile_reka + gracz);
	}
	else
	{
		return 0;
	}
	
}

/*********************************************************
*
*	int ileMaKartStol(int gracz)
*
*********************************************************/

int ileMaKartStol(int gracz)
{
	// sprawdza ile gracz ma kart 'na stole'

	if (czyGra(gracz) == true)
	{
		return *( pile_stol + gracz);
	}
	else
	{
		return 0;
	}
	
}

/*********************************************************
*
*	int zakoncz(int gracz)
*
*********************************************************/

void zakoncz(int gracz)
{
	// konczy aktywny status gracza

	// jezeli nie ma kart 
	//*( pile_reka + gracz ) = -1; // zakonczyl gre
	
	*( pczy_gra + gracz ) = 0;		// gracz nieaktywny	
	*( pwojna + gracz) = 0;			// nie bierze udzia³u w wojnie
	
	cout << __FUNCTION__ << ": " << gracz << " [0..3]" << endl;
}






/*********************************************************
*
*	void wylozKarteNaStol( int gracz)
*
*********************************************************/

void wylozKarteNaStol( int gracz)
{
	// zdejmuje jedna karte z puli gracza i doklada ja do puli na stole, 
	// w obu przypadkach aktualizujac odpowiednie liczniki kart
	// jezeli nie ma kart, to 'pczy_gra" danego  gracza = 0 ( to w funkcji zakoncz(gracz) )
	
	// UWAGA /TOASK/: 
	// trzeci argument wywolania 'ile_graczy' powinien byc dostepny w inny sposob - temat do dyskusji /np. zm. globalna, elememt tablicyGry/ 
	// podobnie wartosc 'TALIA"
	
	cout << __FUNCTION__ << endl;

	if ( ileMaKartReka(gracz) > 0 ) // jezeli gracz ma przynajmniej jedna karte
	{
	
		int * pdokartynastole =  pkarty_stol + (gracz*TALIA) + *( pile_stol + gracz ) - 1;
		int * pdokartynarece  =  pkarty_reka + (gracz*TALIA) + *( pile_reka + gracz ) - 1 ;
		
		// poluz na stol karte z reki
		*( pdokartynastole + 1 ) = *pdokartynarece;
		*pdokartynarece = 0; // TODO docelowo zamienic na (-1) bo 0 to karta dwojka, aktualnie problem rozwi¹zuje licznik kart na rece
		
		// zmien ilosci kart
		*( pile_stol + gracz ) +=1;
		*( pile_reka + gracz ) -=1;
 	}
	// jezeli nie ma kart
	else
	{
		zakoncz(gracz); // gracz zakonczy³ gre, zabraklo mu kart
	}
		
}

/*********************************************************
*
*	void porownajKartyNaStole()
*
*********************************************************/

int porownajKartyNaStole()		// TODO: DOSZEDL PATRAMETR ILE GRACZY BO LICZBA MOZE BYC = 4
{
	// zwraca numer Gracza ktory wyglral 
	// lub (-1) jezeli wojna 
	// w tablicy 'pwojna' zapisuje graczy ktorzy uczestnicza w wojnie
	
	
	// ---obliczanie punktow kart ---
	// punkty karty obliczane s¹ dziel¹c jej numer kolejny w posortowanej talii przez 4 ( nr / 4 )
	// dwojki = 0pkt, trojki = 1pkt, itd.
	// nr/4 bo punktacja nie zalezy od koloru karty
	// 4 dwojki ( karty o numerach 0,1,2,3) maja taka sam¹ ilosc punktow = 0 np. 3/4 = 0;
	// 4 trojki ( karty o numerach 4,5,6,7) maja taka sama ilosc punktow = 1, np. 6/4 = 1;
	// 4 asy ( karty o numerach 48,49,50,51) maj¹ taka sama ilosc punktow = 12 np. 50/4 = 12;
	// numery do 51 bo liczymy od zera do 51 = 52 karty
	

	cout << __FUNCTION__ << endl;
	
	// tablica z punktacja (zmienna lokalna)
	int punkty[4] = {-1}; 	// bo wartosc 0 jest zarezerwowana dla karty 'dwojka'
							// UWAGA: przyjeto ilosc_graczy = 4 bo nie mozna zainicjowac tablicy zmienn¹
	
	int maksimumpunktow = -1;
	int iluzdobylomaksimum = 0;
	
	
	// je¿eli nie ma wojny 
	if ( zglwojna != 1 )
	{
					// ile punktow zdobyli gracze
					maksimumpunktow = -1;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						if ( czyGra(gracz) == true)
						{
							punkty[gracz] = *( pkarty_stol + ( gracz * TALIA ) + *(pile_stol + gracz)-1 ) / 4;
						 													
							maksimumpunktow = max( maksimumpunktow, punkty[gracz]); // ile wynosi maksimum punktow kart na stole
						}
							
					}
					
		
					iluzdobylomaksimum = 0;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						if ( punkty[gracz] == maksimumpunktow) 
						{
							iluzdobylomaksimum++;	// ilu zdobylo maksimum punktow		
						}	
					}		
		
	}
	else //  wojna
	{
					// ile punktow zdobyli gracze uczestniczacy w wojnie
					maksimumpunktow = -1;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						
						if (( czyGra(gracz) == true) &&  (*( pwojna + gracz) == 1 )) 
						{
							
							punkty[gracz] = *( pkarty_stol + ( gracz * TALIA ) + *(pile_stol + gracz) -1) / 4;	
								
							maksimumpunktow = max( maksimumpunktow, punkty[gracz]);	 	// ile wynosi maksimumpunktow kart na stole
						}
					}
					
					
					iluzdobylomaksimum = 0;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						if (( czyGra(gracz) == true) &&  (*( pwojna + gracz) == 1 ))
						{
							if ( punkty[gracz] == maksimumpunktow) 
							{
								iluzdobylomaksimum++;	//  ilu zdobylo maksimum punktow 	
							}	
						}
					}			
					
					
					// jezeli koniec wojny
					if ( iluzdobylomaksimum <= 1)
					{

						for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
						{		
							*( pwojna + gracz) = 0;  // wyzeruj cala tablice			
						}	
							
										 			// wyzerowanie zm. globaln¹ 'wojna' ni¿ej
					}	
	}
	// tu punkty policzone, wiemy ilu graczy zdobylo max punktow

	
	// jezeli nie ma wojny
	if (iluzdobylomaksimum == 1)
	{

			for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
			{		
				
				zglwojna = 0; // zm. globalna wojna
				
				if ( punkty[gracz] == maksimumpunktow) 
				{

					return gracz; // zwroc numer gracza ktory wygral
					
				}
			}	
	}
	// wojna
	else
	{
			zglwojna = 1; // zm. globalna wojna
			
			
			for ( int gracz = 0; gracz < ile_graczy ; gracz++ )	// ktorzy gracze uczestnicza w wojnie
			{		
				if (( punkty[gracz] == maksimumpunktow) && ( czyGra(gracz) == true))
				{
					*( pwojna + gracz ) = 1;					// zapisz 'TAK'w tablicy 'pwojna'			
				}
				else
				{
					*( pwojna + gracz ) = 0;	
				}
			}
	
			return -1;	// i zwroc  (-1)
	}
}


/*********************************************************
*
*	void dopiszStolDoGracza(int gracz);
*
*********************************************************/

int dopiszKartyStoluDoGracza(int gracz)

{
	// dopisuje karty ze stolu do gracza wskazanego w argumencie funkcji
	// w tym celu tworzona jest tymczasowa tablica 'temp' 
	// do ktorej wpisywane s¹ kolejno: karty gracza, karty ze stolu gracza
	// karty wpisywane s¹ od tylu, tak, aby po ponownym przepisaniu na konto gracza zostala zachowana pierwotna kolejnosc
	
	cout << __FUNCTION__ << ": " << gracz << " [0..3]" << endl;

	//int *tab = tablicaGry;
	
	int ile_kart = 0; // zm. lokalna

	
	// zapisz karty gracza do 'temp'
	int licznik_temp = 0;
	static int temp[52]; // zm. lokalna statyczna
	
	// tymczasowo odkladamy karty gracza do tablicy 'temp'
	// odkladamy w kolejnosci od gory do dolu
	ile_kart = *(pile_reka + gracz);
	for (int i = 0 ; i < ile_kart ; i++)
	{
		temp[i] = *(pkarty_reka + (gracz*TALIA) + i); // przepisujemy do 'temp' 
		
		//cout << temp[i] << endl;
		
		licznik_temp++;
		*(pile_reka + gracz) -=1;
	}
	
	//cout << gracz << "  " << ile_kart << endl;
	//wypiszKartyZTablicy(temp, 15);
	
	
	
	for (int g = 0; g < ile_graczy; g++)
	{
				
				ile_kart = *(pile_stol + g); // ile gracz g polozyl kart na stole
				
				
				// dopisujemy karty ze stolu do 'gracza'
				//for (int i = *(pile_reka + gracz); i < ( *(pile_reka + gracz) + ile_kart) ; i++)
				
				for (int i = 0; i < ile_kart; i++)
				{
					*( pkarty_reka + (gracz*TALIA) + *(pile_reka + gracz)) = *(pkarty_stol + (g*TALIA) + i); // przepisujemy karty ze stolu kazdego gracza (g) do 'gracz' 
					*( pile_reka + gracz) +=1;
					*( pile_stol + g ) -=1;
					
					
				}
	
	//wypiszKartyZTablicy(pkarty_reka + (gracz*TALIA), 15);
	
		
	}
	
	
	
	// zapisz karty 'temp' na 'reke' gracza
	ile_kart = licznik_temp;
	
	for ( int i = 0; i < ile_kart; i++)	
	{
	
		*( pkarty_reka + (gracz*TALIA) + *(pile_reka + gracz) ) = temp[i];
		
		*(pile_reka + gracz) +=1;
	}
	
	
	
	// karty zostaly dopisane do konta gracza
	return 0;	
}

/*********************************************************
*
*	void polozDwieKartyNaStole(int gracz)
*
*********************************************************/

void polozDwieKartyNaStole(int gracz)

{
	// dopisuje karty ze stolu do gracza wskazanego w argumencie funkcji
	// w tym celu tworzona jest tymczasowa tablica 'temp' 
	// do ktorej wpisywane s¹ kolejno: karty gracza, karty ze stolu gracza A , karty ze stolu gracza B
	// karty wpisywane s¹ od tylu, tak, aby po ponownym przepisaniu na konto gracza zostala zachowana pierwotna kolejnosc
	
	cout << __FUNCTION__ << endl;
	
	
	if ( ileMaKartReka(gracz) >=2 ) // jezeli gracz ma przynajmniej dwie karty
	{
		wylozKarteNaStol(gracz); // wyloz 2 x 1 karta
		wylozKarteNaStol(gracz);
 	}
	else
	{
		if ( ileMaKartReka(gracz) == 1 ) // jezeli gracz ma jedna karte
		{
			wylozKarteNaStol(gracz); // wyloz 1 karte
		}
		
		zakoncz(gracz); // gracz zakonczy³ gre
	}
}


/*********************************************************
*
*	int ktoWygral()
*
*********************************************************/

int ktoWygral()

{
	// jezeli jest jeden aktywny gracz ( pczy_gra[] = 1 ) zwraca nr tego gracza	 
	
	if ( iluGraczyPrzyStole() == 1 )
	{
		
		for (int gracz = 0; gracz < ile_graczy; gracz ++)
		{
			if (czyGra(gracz) == true)
			{
				cout << __FUNCTION__ << ": " <<gracz +1 << endl; 
				return gracz;
			}
		}
	}
	else
	{
		// wywo³anie w sytuacji kiedy kilku graczy jest aktywnych, 
		// i nie ma jednego zwyciêzcy
		//cout << ": remis" << endl;
		return -1;
	}
}


/*********************************************************
*
*	int policzPunkty(int gracz)
*
*********************************************************/

int policzPunkty(int gracz)

{
	
	// wewnatrz programu punktacja wyglada tak, ¿e dwojka ma 0 punktow,
	// dla uzytkownika przyjmujemy, ¿e dwojka ma 2 punkty, czyli wszystkie punkty
	// przesuwamy o 2
	// obliczenie punktow (x/4) wyjasnione w 'jakaKarta()'
	
	int sumapunktow= 0;
	
	if ( czyGra(gracz) == true) // czy gracz jest aktywny = moze miec karty ale nie musi, bo przed koncem oddal ostatnia
	{
		for (int karta = 0; karta < ileMaKartReka(gracz); karta++)
		{
				sumapunktow = sumapunktow + (*( pkarty_reka + (gracz*TALIA) + karta) / 4) + 2; // dodajemy 2 pkt. 
		}
	
		return sumapunktow;
		
	}
	else
	{
		return 0;
	}

}

/*********************************************************
*
*	void zapiszWynik(int gracz)
*
*********************************************************/

void zapiszWynik(int gracz)

{
	
	// zapisuje wynik do globalnych tablic wyniki_gier[ile_graczy] , remisy_gier[1];
	
	
	// wejscie:
	// 0..3 - gracz ktory wygral,
	// -1  	- jezeli nierozstrzygniete
	
	
	
	int wyniki[ile_graczy] = {0};
	int maksimumpunktow = 0;
	int licznik = 0;
	int i = 0;
	
	
	if ( gracz >= 0)
	{
		wyniki_gier[gracz] += 1;
		
	}
	else //kilku zostalo z kartami
	{
		
		for (int gracz = 0; gracz < ile_graczy; gracz ++)
		{
			
			wyniki[gracz] = policzPunkty(gracz);
			
			maksimumpunktow = max( maksimumpunktow, wyniki[gracz]);  // najwyzsza punktacja
			
		}
		
		// jezeli 2 graczy ma maksimum punktow gra zakonczona remisem
		for (int gracz = 0; gracz < ile_graczy; gracz ++)
		{
			
			if ( maksimumpunktow == wyniki[gracz])
			{
				licznik++;				// ilu ma najwyzsza punktacje
				i = gracz;				
			}
	
		}
		
		if (licznik == 1)
		{
			wyniki_gier[i] += 1; // wygra³ gracz i
		}
		else if (licznik > 1)
		{
			remisy_gier[0] += 1; // zalicz remis
		}
		
		
	}

}

/*********************************************************
*
*	void wypiszWyniki()
*
*********************************************************/

void wypiszWyniki()

{
	
	// wypisuje wyniki z globalnych tablic wyniki_gier[ile_graczy] , remisy_gier[1];
	
	
	for (int gracz = 0; gracz < ile_graczy; gracz ++)
	{
		cout << "gracz" << gracz+1 << ": " << wyniki_gier[gracz] << " wygranych" << endl; // info dla kazdego gracza

	}
	
	cout << "remisy: " << remisy_gier[0] << endl;	// info o remisach
	
	cout << "ilosc gier: " << ilosc_gier[0] << endl;	// info o grach

	cout << "srednia ilosc wylozen: " << ilosc_wylozen[0] / ilosc_gier[0] << endl;	// info o wylozeniach


}





/********************************************************************
*
*	void wynikiSymulacjiSeriiRozgrywek(int wygrany, int wylozenia)
*
*********************************************************************/

char * wynikiSymulacjiSeriiRozgrywek(int gracz, int wylozenia)
{
	// magazynuje dane dotyczace serii np. 1000 rozgrywek
	// podaje koncowe wyniki
	
	
	static int wynikiSeriiRozgrywek[4] = {0};
	static int remisy = 0;
	static int sumaWylozen = 0;
	static int iloscRozgrywek = 0;
	
	// jezeli gracz = 0,1,2,3
	if ( gracz >= 0 )
	{
		wynikiSeriiRozgrywek[gracz] += 1;
		sumaWylozen += wylozenia;
	}
	else 
	{
		// jezeli gracz = -1 => remis
		remisy +=1;
		sumaWylozen += 1;
	}
	
	char * wynik;
	
	for ( int gracz = 0; gracz < ile_graczy; gracz++)
	{
	
		snprintf( wynik, 200, "gracz %d : %d wygrane\n", gracz, wynikiSeriiRozgrywek[gracz] );
		snprintf( wynik, 200,"%s", wynik); // dodaj wynik do wynik: wynik += wynik;
		
	}
	
	snprintf( wynik, 200, "remis %d razy\n", remisy );
	snprintf( wynik, 200, "%s", wynik);
	
	snprintf( wynik, 250, "Rozgrywka zakonczona wygran¹ jednego z zawodnikow zakonczyla siê srednio po %d wylozeniach", (sumaWylozen/(iloscRozgrywek-remisy)));
	snprintf( wynik, 250, "%s", wynik);
	
	
	return wynik;
	
}


/*********************************************************
*
*	int graWojna();
*
*********************************************************/

int graWojna()
{
	
	enum gracz { Gracz_A = 0, Gracz_B, Gracz_C, Gracz_D
	};
	enum ktore_karty { reka = 0, stol
	};	

	int talia[TALIA] = {0}; // talia z ktorej beda rozdawane karty, karty od dwojki = 0 do as = 51
	
	int graczktorywygral = -1;
	int licznik_wylozen = 0; // zlicza porownania lkart graczy, tak aby rozgrywka nie trwala w nieskonczonosc, ograniczenie do 1000
							
	
	char * wyniknakonsole; // co bedzie wypisane na konsoli po zakonczeniu serii 1000 rozgrywek
	
	// wyzeruj zmienne i tablice globalne 
	
	for( int i = 0; i < (2 * ile_graczy*TALIA + 4 * ile_graczy) ; i++)
	{
		tablicaGry[i] = 0;
	}
		
	zglwojna = 0;
	
	// koniec zerowania zmiennych globalnych
	
	
	
	
		
	// utwórz posortowana talie 52 kart w tablicy talia[]
	utworzTalie(talia,TALIA);
	
	// tasuj talie
	tasujTalie_2(talia, TALIA); // wersja 2 tasowania nieaktywna
	
	
	// zainicjuj liczbe graczy
	for ( int gracz=0 ; gracz < ile_graczy; gracz++)
	{
		*( pczy_gra + gracz) = 1; // gracz aktywny;
	}
	
	

	// rozdaj karty Graczom
	for(int i=0; i < TALIA; i++) // od 0 do 51
	{
		 
		
		int ktorygracz = i % ile_graczy;
		int ktorakarta = i / ile_graczy;
		
		int j = TALIA - i; 	// gracze otrzymuja karty w kolejnosci 0 -> 51, tj. wg indeksu [i]
							// z talii zdejmujemy karty w kolejnosci 51 -> 0, tj. wg indeksu [j-1]
							// [0] - karty na spodzie, [51] - karty na gorze
		
		
		*( pkarty_reka + (ktorygracz * TALIA) + ktorakarta ) = talia[j-1]; // [j-1] = 51..0
		*( pile_reka + ktorygracz) +=1;
		
	}
	
	// pierwsze rozdanie - wypisz karty
	wypiszKartyGry(talia);
		
		
		
		
	// glowna petla rozgrywki
	while (czyGraTrwaDalej() == true )	 // sprawdza ilu graczy ma jeszcze karty ('pile_reka')
	{
		
		licznik_wylozen++;
		
		
		// wylozenie po jednej karcie na stol
		for ( int gracz = 0 ; gracz < ile_graczy ; gracz++ )
		{		
			// jezeli gracz uczestniczy w grze
			if ( czyGra(gracz) == true ) 									// TODO czy zostaly zainicjowane komorki pczy_gra wartosci¹ 1 ?
			{
				if ( ileMaKartReka(gracz) >= 1 ) 
				{
					//jezeli gracz ma 1 karte
					wylozKarteNaStol(gracz);	//wyloz		
				}
				else
				{
					// jezeli nie ma kart 
					zakoncz(gracz);				// zakoncz		
				}
			}
		}
		
		//wypiszKartyGry(tablicaGry); // ---------------
		
		
		if (iluGraczyPrzyStole() == 1) break;	// zosta³ 1 gracz = zwyciêzca, przerwij petle gry

		// po wy³o¿eniu kart porownaj punktacje	
		int wynikporownaj = porownajKartyNaStole(); // zwraca nr wygranego gracza (0..3) lub (-1) jezeli wojna
		
		
		
		// jezeli wygral jeden gracz
		if (wynikporownaj >= 0 )
		{	
			graczktorywygral = wynikporownaj;
			dopiszKartyStoluDoGracza(graczktorywygral); // dopisz karty ze stolu na konto wygranego gracza (na spod kart)
			
		}
		// jezeli jest remis
		else if (wynikporownaj < 0)		// dekl.: int wojna = -1;
		{
	
			// wojna
			while ( wynikporownaj == -1 ) 
			{	
					for ( int gracz = 0 ; gracz < ile_graczy ; gracz++ )
					{	
						// jezeli gracz uczestniczy w wojnie
						if ( *( pwojna + gracz ) > 0 )
						{		
							//jezeli gracz ma 2 karty	
							if ( ileMaKartReka(gracz) >= 2 ) 
							{
								polozDwieKartyNaStole(gracz);	
							}
							else if ( ileMaKartReka(gracz) == 1 )
							// jezeli ma 1 karte wyklada i konczy gre
							{
								wylozKarteNaStol(gracz);
								zakoncz(gracz);				// instrukcja zawarta w 'wylozKarteNaStol()" jezeli brakuje kart do wylozenia, mozna tu pomin¹c
																						
								*( pwojna + gracz ) = 0;	// nie bierze udzialu w wojnie (instrukcja zawarta w funkcji zakoncz() ), mo¿na tu pomin¹c
							} 
							else
							// jezeli nie ma kart konczy gre
							{
								zakoncz(gracz);	
							}
						}
					}
					
					if (iluGraczyPrzyStole() == 1) break; // zosta³ 1 gracz = zwyciezca gry
				
					
					//wypiszKartyGry(tablicaGry); // ---------------
					
					// porownaj wylozone karty  /tylko gracze bioracy udzial w wojnie/
					wynikporownaj = porownajKartyNaStole();	// zwraca nr gracza (0..3) lub (-1) jezeli dalej wojna
				
			}
			// koniec wojny		
			
			if (iluGraczyPrzyStole() == 1) break; // zosta³ 1 gracz = zwyciezca gry

			// po wojnie
			// tu wylozenie zosta³o zakonczone, karty zbiera jeden gracz
			graczktorywygral = wynikporownaj;
			dopiszKartyStoluDoGracza(graczktorywygral);  // dopisz karty wygranemu
			
			//wypiszKartyGry(tablicaGry); // ---------------
		
		}
		
		if (iluGraczyPrzyStole() == 1) break; // zosta³ 1 gracz = zwyciezca rozgrywki
			
		
		if ( licznik_wylozen >= 1000)			// dodatkowy warunek zakonczenia rozgrywki
		{

			cout << "licznik wylozen: " << licznik_wylozen << endl;
			
			int a;
			//cin >> a;
			
			break;
		}
		
		int b;
		//cin >> b;
		
	}	
	
	
	
	// koniec gry
	
	// wygrana 1 gracza
	if ( iluGraczyPrzyStole() == 1)
	{
			wypiszKartyGry(tablicaGry);
			cout << "Gra zakonczona. Wygral gracz: " << ktoWygral() + 1 << endl;
			//wyniknakonsole = wynikiSymulacjiSeriiRozgrywek(graczktorywygral, licznik_wylozen);
			
			zapiszWynik(ktoWygral());
	}
	// remis
	else 
	{
			//wyniknakonsole = wynikiSymulacjiSeriiRozgrywek(-1, licznik_wylozen);
			wypiszKartyGry(tablicaGry);
			cout << "Gra zakonczona. Przekroczona ilosc wylozen." << endl;
			
			for ( int gracz = 0 ; gracz < ile_graczy ; gracz++ )
			{	
				cout << "Gracz" << gracz+1 << ": " << policzPunkty(gracz) << "pkt." << endl;
				
			}
			
			zapiszWynik(ktoWygral());  // ktoWygral() zwraca (-1) w przypadku nierozstrzygnietej gry
		
	}

	// zapisz dane do podsumowania serii rozgrywek
	ilosc_gier[0] += 1;
	ilosc_wylozen[0]+= licznik_wylozen;

	return 0;
	
}

/*********************************************************
*
*	main
*
*********************************************************/

int main()
{

	int start;
	cin >> start;  // zeby nie startowal od razu, czeka na uzytkownika
	
	// zerowanie zmiennych globalnych
	
	for( int i = 0; i < ile_graczy ; i++)
	{
		wyniki_gier[i] = 0;
	}
	
	remisy_gier[0] = 0; 
	ilosc_gier[0] = 0;
	ilosc_wylozen[0] = 0;
	
	// petla n rozgrywek
	
	for ( int i = 0; i < 1000; i++ )
	{
		graWojna();
		cout << "------wyniki posrednie------" << endl;
		wypiszWyniki();
		//cin >> start;
		
	}
	
	// wyniki
	cout << "------wyniki koncowe------" << endl;
	wypiszWyniki();
	
/*
	------wyniki koncowe------
	gracz1: 210 wygranych
	gracz2: 237 wygranych
	gracz3: 261 wygranych
	gracz4: 288 wygranych
	remisy: 4
	ilosc gier: 1000
	srednia ilosc wylozen: 772
	
	------wyniki koncowe------
	gracz1: 227 wygranych
	gracz2: 209 wygranych
	gracz3: 288 wygranych
	gracz4: 265 wygranych
	remisy: 11
	ilosc gier: 1000
	srednia ilosc wylozen: 790
	
*/
}



