#include <iostream>
#include <cstdlib> // atoi();
using namespace std;

/*
Zadanie 11.4: Najwiêksza liczba piêciocyfrowa

Napisz funkcjê int greatestNumber(char *c), która zwróci najwiêksz¹ 5-cyfrow¹ liczbê ukryt¹ w ci¹gu cyfr. 
Ci¹g cyfr jest nieznanej d³ugoœci, jednak nie mniejszy ni¿ 5 elementów oraz zawsze koñczy siê znakiem '\0' . 
Przyk³adowo dla poni¿szego ci¹gu tysi¹ca cyfr, najwiêksza liczba w nim ukryta to 99818:
 
 
17409488245517115276142322168576189279543123341138742779319865028602486509006138934460661849637882913598407636154209737260165
75412001460717777335998182660380125094783512016406189841439880877838371073496510996834849925533374380880681989722828907815861
24258626539246182119762952003918195325258677229419698255491250839396799769357665825441616335532825361862146291503649293440596
34288758125744444293077873038252037297534321132535122264070340053106750045495648216831484920706070567384926577457983022367155
40260611173004830129038857708930747837100834501456203566676771916272765139959265324442792373157858324115951064530891347463652
81031552217482363035280722591085079053410485925413958279617719034175332412908745680774313630190429314820559328748143552689295
94505880132227031337095583783793918280184860930087635658394839764586155196454253268266394562535661446268255101517600243362823
43436847398008805143639219823402319898913514253892870148193597980147555092824504405115908387269381033848015413735856908936069

Przyk³adowy kod testuj¹cy:

	char digits[] = "8457683904820389485738";
	int maxNumber = 0;

	maxNumber = greatestNumber(digits);
	cout << maxNumber; // Na ekranie pojawi sie liczba 94857
*/



/*********************************************************
*
*	int greatestNumber(char *c)
*
*********************************************************/

int greatestNumber(char *c) {
	
	/* znajduje najwieksza 5 cyfrowa liczbe ukryta w ciagu cyfr 
	wejscie - wskaznik do tablicy znakow zakonczonej '\0'
	wyjscie - liczba int 5 cyfrowa, najwieksza w tablicy wejsciowej*/
	
	char* pPczatekLiczbyWCiaguCyfr = c;
	char* pLiczbaSzukana = c; 	// poczatkowo liczba szukana i pierwsze 5 cyfr sa sobie rowne
	
	int i=0; 	// i= indeks elementów ciagu liczb i elementow szukanej 5 cyfrowej liczby
	
	
	while ( *(pPczatekLiczbyWCiaguCyfr + 4 ) != '\0'){ 
		
		// dopoki ne zostana 4 cfry od konca ciagu ('\0')
		
		for (int i=0 ; i < 5 ; i++){	
		
			// porownuj 5 kolejnych elementow ciagu liczb z liczba szukana
			
			if (*(pPczatekLiczbyWCiaguCyfr + i ) < *(pLiczbaSzukana + i )){
			
				// -- jezeli mniejsza --
				// jezeli ktoras ze sprawdzanych kolejnych 5-ciu liczba ciagu jest mniejsza niz aktualnie zapisane w liczbie szukanej, 
				// to przerwij sprawdzanie i wykonaj sprawdzanie w petli 'while' dla nastepnego elementu
				
				//pPczatekLiczbyWCiaguCyfr++;
				break;
				
			} else if (*(pPczatekLiczbyWCiaguCyfr + i ) > *(pLiczbaSzukana + i )) {
				
				// -- jezeli wieksza to => znaleziona nowa --
				// znaleziona nowa liczba szukana = pPczatekLiczbyWCiaguCyfr wskazuje na poczatek liczby szukanej
				// uaktualnij wskaznik do liczby szukanej i przerwij sprawdzanie dla tej wartosci
				
				pLiczbaSzukana = pPczatekLiczbyWCiaguCyfr;
				break;
			}
			
			// -- jezeli rowne --
			// jezeli oba ciagi bed¹ rowne, to nic nie robimy, 
			// nie przesuwamy wskaznika pSzukanaLiczba - pozostaje on na poprzednio znalezionej wartosci
		}
		
		// przesun wskaznik o jedno pole do przodu i sprawdzaj nastepna liczbe
		pPczatekLiczbyWCiaguCyfr++; 
	}
	
	// -- zwroc wynik --
	// kopiuj 5 znakow do nowej zmiennej temp, tak aby otrzymaæ ciag w formacie : (5 x char) + ('\0')
	// konwertuj otrzymana wartosc z formatu *char na int i zwroc j¹ jako wynik dzialania funkcji
	char temp[5];
	memcpy(temp, pLiczbaSzukana, sizeof(temp));
	
	int wynik = atoi(temp); //85738

	return wynik;
}



/*********************************************************
*
*	main
*
*********************************************************/

int main()
{
	char digits[] = "8457683904820389485738"; // "845768390482038 94857 38";
	int maxNumber = 0;

	maxNumber = greatestNumber(digits);
	cout << maxNumber; // Na ekranie pojawi sie liczba 94857
	
	cout << endl;
	
	char digits2[] = "1740948824551711527614232216857618927954312334113874277931986502860248650900613893446066184963788291359840763615420973726016575412001460717777335998182660380125094783512016406189841439880877838371073496510996834849925533374380880681989722828907815861242586265392461821197629520039181953252586772294196982554912508393967997693576658254416163355328253618621462915036492934405963428875812574444429307787303825203729753432113253512226407034005310675004549564821683148492070607056738492657745798302236715540260611173004830129038857708930747837100834501456203566676771916272765139959265324442792373157858324115951064530891347463652810315522174823630352807225910850790534104859254139582796177190341753324129087456807743136301904293148205593287481435526892959450588013222703133709558378379391828018486093008763565839483976458615519645425326826639456253566144626825510151760024336282343436847398008805143639219823402319898913514253892870148193597980147555092824504405115908387269381033848015413735856908936069"; // 
	int maxNumber2 = 0;

	maxNumber2 = greatestNumber(digits2);
	cout << maxNumber2; // Na ekranie pojawi sie liczba 99818
	return 0;
}

