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

	const int ile_graczy 	= 2;	// WARTOSC STALA ZEBY MOZNA BYLO ZADEKLAROWAC ROZMIAR TABLICY
	const int TALIA 		= 52;

	// glowna tablica gry
		
	// 	lacznie ... elementow, kolumny 0..3 - karty Graczy 'na rece", 4...7 karty Graczy na stole, 8..15 kolumna - 2x4 liczniki
	int tablicaGry [  ile_graczy * TALIA 	/*4 tablice x 52 elementy => karty 4 graczy na rece*/ 
					+ ile_graczy * TALIA 	/*4 tablice x 52 elementy => karty 4 graczy na stole*/
					+ ile_graczy * 1 	/* 4 liczniki wielkosci 'int' => liczba kart na rece*/
					+ ile_graczy * 1 	/* 4 liczniki wielkosci 'int' => liczba kart na rece*/
					+ ile_graczy * 1 	/* 4 komorki wielkosci 'int' => ktory gracz uczestniczy w wojnie*/
					+ ile_graczy * 1 	/* 4 komorki wielkosci 'int' => ktory gracz dalej gra*/] = {0};
						
	// wskazniki na poczatki odpowiednich fragmentow tablicyGry
	int * pkarty_reka 	= tablicaGry;
	int * pkarty_stol 	= tablicaGry + 		ile_graczy * TALIA; 				// przesuniecie o ilosc graczy x talia dla kazdego gracza = 4 x 52 = 208
		
	int * pile_reka 	= tablicaGry + (2 * ile_graczy * TALIA); 				// przesuniete o 2 zestawy kart, 4x 52 - karty graczy 'na rece' oraz 4 x 52 - karty graczy 'na stole'
	int * pile_stol 	= tablicaGry + (2 * ile_graczy * TALIA) + ile_graczy;
	int * pwojna		= pile_stol + ile_graczy;
	int * pczy_gra		= pwojna + ile_graczy;	// wartosci 0/1 czyli nie gra / gra

	//bool wojna = false;
	int wojna = 0;

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
	
	printf("\n-------------------------------------------------------------------------\n");
	
	
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
*	void wylozKarteNaStol( int gracz)
*
*********************************************************/

void wylozKarteNaStol( int gracz)
{
	// zdejmuje jedna karte z puli gracza i doklada ja do puli na stole, 
	// w obu przypadkach aktualizujac odpowiednie liczniki kart
	// jezeli nie ma kart, to 'pczy_gra" danego  gracza = -1
	
	// UWAGA: 
	// trzeci argument wywolania 'ile_graczy' powinien byc dostepny w inny sposob - temat do dyskusji /np. zm. globalna, elememt tablicyGry/ /TOASK/
	// podobnie wartosc 'TALIA"
	cout << __FUNCTION__ << endl;

	if ( *(pile_reka+gracz) > 0 ) // jezeli gracz ma przynajmniej jedna karte
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
	else
	{
		*(pczy_gra + gracz) = 0; // gracz zakonczy³ gre
	}
		
}

/*********************************************************
*
*	void porownajKartyNaStole(int * tab, int ile_graczy)
*
*********************************************************/

int porownajKartyNaStole(int * tab, int ile_graczy)		// TODO: DOSZEDL PATRAMETR ILE GRACZY BO LICZBA MOZE BYC = 4
{
	// zwraca numer Gracza ktory wyglral 
	// lub (-1) jezeli wojna 
	// w tablicy 'pwojna' zapisuje ktorzy gracze uczestnicza w wojnie

	cout << __FUNCTION__ << endl;
	
	// tablica z punktacja (zmienna lokalna)
	int punkty[4] = {-1}; 	// bo wartosc 0 jest zarezerwowana dla karty 'dwojka'
							// UWAGA: przyjeto ilosc_graczy = 4 bo nie mozna zainicjowac tablicy zmienn¹
	
	
	int iluzdobylomaksimum = 0;
	int maksimumpunktow = -1;
	
	// porownajKartyNAStole je¿eli nie ma wojny 'wojna == false'
	if ( wojna == 0)
	{
					// ile punktow zdobyli gracze
					maksimumpunktow = -1;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						if ( *( pczy_gra + gracz) == 1)
						{
							punkty[gracz] = *( pkarty_stol + ( gracz * TALIA ) + *(pile_stol + gracz)-1 ) / 4;	// dwojki = 0pkt, trojki = 1pkt, itd.
						 															 	// x/4 bo punktacja nie zalezy od koloru karty
						  																// 4 dwojki ( karty o numerach 0,1,2,3) maja taka sam¹ ilosc punktow = 0
																						// 4 trojki ( karty o numerach 4,5,6,7) maja taka sama ilosc punktow = 1
																						// 4 asy ( karty o numerach 48,49,50,51) maj¹ taka sama ilosc punktow = 12
																						// numery do 51 bo liczymy od zera do 51 = 52 karty
							
							maksimumpunktow = max( maksimumpunktow, punkty[gracz]);
						}
							
					}
					
					// ilu graczy zdobylo maksimum punktow
					iluzdobylomaksimum = 0;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						if ( punkty[gracz] == maksimumpunktow) 
						{
							iluzdobylomaksimum++;	// policz ilu			
						}	
					}		
		
	}
	else // porownajKartyNAStole je¿eli jest 'wojna == true'
	{
					// ile punktow zdobyli gracze uczestniczacy w wojnie
					maksimumpunktow = -1;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						// jezeli gracz uczestniczy w wojnie
						if (( *( pczy_gra + gracz) == 1) &&  (*( pwojna + gracz) == 1 ))
						{
							
							punkty[gracz] = *( pkarty_stol + ( gracz * TALIA ) + *(pile_stol + gracz) -1) / 4;	// dwojki = 0pkt, trojki = 1pkt, itd.
								
							maksimumpunktow = max( maksimumpunktow, punkty[gracz]);	 	// oblicz maksymaln¹ punktacjê 
						}

					}
					
					// ilu graczy zdobylo maksimum punktow
					iluzdobylomaksimum = 0;
					for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
					{		
						// jezeli gracz uczestniczy w wojnie
						if (( *( pwojna + gracz) == 1 ) && (*( pczy_gra + gracz) == 1))
						{
							if ( punkty[gracz] == maksimumpunktow) 
							{
								iluzdobylomaksimum++;	// policz ilu 			
							}	
						}
		
					}			
					
					
					// wyzeruj tablice 'pwojna' jezeli co najwyzej jeden gracz ma max punktow => jest koniec wojny
					if ( iluzdobylomaksimum <= 1)
					{
						for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
						{		
							*( pwojna + gracz) = 0;  // wyzeruj cala tablice			
						}	
					}
	
		
	}


	
	// jezeli wojna - kilku graczy zdobylo maksimumpunktow
	if (iluzdobylomaksimum > 1)
	{
				// ktorzy gracze uczestnicza w wojnie
				for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
				{		
					if (( punkty[gracz] == maksimumpunktow) && (*( pczy_gra + gracz) == 1))
					{
						*( pwojna + gracz ) = 1;	// zapisz 'TAK'w tablicy 'pwojna'			
					}
					else
					{
						*( pwojna + gracz ) = 0;	
					}
				}
				
				return -1;	// i zwroc wartosc -1
	}
	// nie ma wojny, jeden gracz zdobyl maksimumpunktow
	else
	{
				// kto wygra³
				for ( int gracz = 0; gracz < ile_graczy ; gracz++ )
				{		
					if ( punkty[gracz] == maksimumpunktow) 
					{
						
						return gracz; // zwroc numer gracza ktory wygral
										
					}
				}
		
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
	
	cout << __FUNCTION__ << endl;

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
	
	
	if ( *(pile_reka+gracz) >=2 ) // jezeli gracz ma przynajmniej dwie karty
	{
		wylozKarteNaStol(gracz); // wyloz 2 karty
		wylozKarteNaStol(gracz);
 	}
	else
	{
		if ( *(pile_reka+gracz) == 1 ) // jezeli gracz ma jedna karte
		{
			wylozKarteNaStol(gracz); // wyloz 1 karte
		}
		
		*(pczy_gra + gracz) = -1; // gracz zakonczy³ gre
	}
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
	// sprawdza ilu graczy ma jeszcze karty ('pile_reka')
	// czy jest conajmniej dwoch graczy z kartami na rece
	
	
	int sumuj = 0;
	
	for (int gracz = 0; gracz < ile_graczy; gracz++)
	{
		if (*( pile_reka + gracz) > 0) sumuj++;
		if( sumuj > 1) return true;	// jezeli policzono conajmniej 2 graczy == gra trwa dalej
	}
	
	// jezeli tylko 1 gracz
	return false;

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
*	main
*
*********************************************************/

int main()
{
	
	enum gracz { Gracz_A = 0, Gracz_B, Gracz_C, Gracz_D
	};
	enum ktore_karty { reka = 0, stol
	};	

	int talia[TALIA] = {0}; // talia z ktorej beda rozdawane karty, karty od dwojki = 0 do as = 51
	
	//int wojna = -1;
	int graczktorywygral = -1;
	int licznik_wylozen = 0; // zlicza porownania lkart graczy, tak aby rozgrywka nie trwala w nieskonczonosc, ograniczenie do 1000
							
	
	char * wyniknakonsole; // co bedzie wypisane na konsoli po zakonczeniu serii 1000 rozgrywek
	


		
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
	
	
	wypiszKartyGry(talia);
	//return 0;
	
	iluGraczyPrzyStole();
	
	return 0;
	
	// glowna petla rozgrywki
	while (czyGraTrwaDalej() == true )	 // sprawdza ilu graczy ma jeszcze karty ('pile_reka')
	{
		
		licznik_wylozen++;
		
		
		// ka¿dy gracz wyklada po jednej karcie na stol
		for ( int gracz = 0 ; gracz < ile_graczy ; gracz++ )
		{		
			// jezeli gracz uczestniczy w grze
			if ( *( pczy_gra + gracz )  > 0 ) 									// TODO czy zostaly zainicjowane komorki pczy_gra wartosci¹ 1 ?
			{
				if ( *(pile_reka + gracz) >= 1 ) 
				{
					//jezeli gracz ma 1 karte
					wylozKarteNaStol(gracz);		
				}
				else
				{
					// jezeli nie ma kart 
					*( pile_reka + gracz ) = -1; // zakonczyl gre
					*( pczy_gra + gracz ) = 0;		// gracz nieaktywny							
				}
			}
		}
		
		wypiszKartyGry(tablicaGry); // ---------------
		
		
		// po wy³o¿eniu kart porownaj punktacje	
		int wynikporownaj = porownajKartyNaStole(tablicaGry, ile_graczy); // zwraca nr wygranego gracza (0..3) lub (-1) jezeli wojna
		
		
		
		// jezeli wygral jeden gracz
		if (wynikporownaj >= 0 )
		{	
			graczktorywygral = wynikporownaj;
			dopiszKartyStoluDoGracza(graczktorywygral); // dopisz karty ze stolu na konto wygranego gracza
			
		}
		// jezeli jest wojna
		else if (wynikporownaj < 0)		// dekl.: int wojna = -1;
		{
	
			// petla - dopoki jest remis na stole == wojna
			while ( wynikporownaj == -1 ) 
			{
				
					licznik_wylozen++;
					
					for ( int gracz = 0 ; gracz < ile_graczy ; gracz++ )
					{	
						// jezeli gracz uczestniczy w wojnie
						if ( *( pwojna + gracz ) > 0 )
						{		
							//jezeli gracz ma 2 karty	
							if ( *(pile_reka + gracz) >= 2 ) 
							{
								polozDwieKartyNaStole(gracz);	
							}
							else if ( *(pile_reka + gracz) == 1 )
							// jezeli ma 1 karte wyklada i konczy gre
							{
								wylozKarteNaStol(gracz);
								*( pile_reka + gracz ) = -1; 	// zakonczyl gre, ile ma na rece kart = -1 
								*( pczy_gra + gracz ) = 0;															// TODO czy tego nie mozna zrobic prosciej ?
								*( pwojna + gracz ) = 0;	// nie bierze udzialu w wojnie
							} 
							else
							// jezeli nie ma kart konczy gre
							{
								*( pile_reka + gracz ) = -1; 	// zakonczyl gre, ile ma na rece kart = -1 
								*( pczy_gra + gracz ) = 0;															// TODO czy tego nie mozna zrobic prosciej ?
								*( pwojna + gracz ) = 0;	// nie bierze udzialu w wojnie
								
							}
						}
					}
					
					wypiszKartyGry(tablicaGry); // ---------------
					
					// porownaj karty w czasie wojny
					wynikporownaj = porownajKartyNaStole(tablicaGry, ile_graczy);	// zwraca nr gracza (0..3) lub (-1) jezeli dalej wojna
				
				cout << "------------------------wojna------, " << licznik_wylozen << " -----------, " << wynikporownaj << endl;
			}
			// koniec wojny		


			// tu wylozenie zosta³o zakonczone, wygral jeden gracz
			graczktorywygral = wynikporownaj;
			dopiszKartyStoluDoGracza(graczktorywygral);  // dopisz karty wygranemu
			
			wypiszKartyGry(tablicaGry); // ---------------
		
		}
		
		cout << "------------------------------licznik wylozen: " << licznik_wylozen << endl;
		
		// dodatkowy warunek zakonczenia rozgrywki, przed³u¿aj¹ce siê rozdanie konczy siê remisem po np. 1000 wy³o¿eniach kart
		if ( licznik_wylozen > 1000)
		{
			graczktorywygral = -1; // nie ma wygranego, jest remis
			
			cout << licznik_wylozen << endl;
			
			break;
		}
		int a;
		cin >> a;
	}	
	
	
	
	// koniec gry
	if ( graczktorywygral >= 0)
	{
			// tu gra zostala zakonczona w sytuacji, w ktorej tylko jeden gracz pozosta³ z kartami
			cout << "Gra zakonczona. Wygral gracz: " << graczktorywygral + 1 << endl;
			//wyniknakonsole = wynikiSymulacjiSeriiRozgrywek(graczktorywygral, licznik_wylozen);
			wypiszKartyGry(tablicaGry);
		
	}
	else // remis, graczktorywygral=-1;
	{
			// tu gra zosta³¹ zakonczone remisem - brak zwyciêzcy, gracz = -1 - rozgrywka trwa tak dlugo, ze przerywamy gre
			//wyniknakonsole = wynikiSymulacjiSeriiRozgrywek(-1, licznik_wylozen);
			
			cout << "Gra zakonczona. Remis." << endl;
			wypiszKartyGry(tablicaGry);
		
	}

	
	
	
	// zapamietaj wynik
	//wyniknakonsole = wynikiSymulacjiSeriiRozgrywek(graczktorywygral, licznik_wylozen);
	
	// wypisz podsumowanie wynikow
	//cout << wyniknakonsole;




	return 0;

	
}

