#include <iostream>
#include <ctime>
#include "SearchContainer.h"

using namespace std;

int main()
{
	srand(time(0));

	size_t arrSize = 100000;	   // 100; 1000; 10000; 100000
	const int maxNum = 100000;
	const int iterationsCount = 100; 

	srand(time(NULL));
	int IdToFind = rand() % arrSize;					// ziskame randomove cislo bunky
	cout << "ID to Find: " << IdToFind << endl; 	   //  ve kterem je ulozeno cislo pro priklad

	/*
	SearchContainer container(arrSize, maxNum);
	container.PrintData();

	int numForFind = container.GetData(IdToFind);				// Zadejte cislo bunky, abyste ziskali randomni cislo
																// ktere se v ni nachazi pro vyhledavani v cyklech
	cout << "Num for find: " << numForFind << endl;				// ziskame toto cislo, abychom ho nasli v cyklech
	
	auto ret = container.SearchLinear(numForFind);				// pokud se csslo bunky shoduje s tim, co jsme zadali
	printf("Element: %s, on index %d\n", ret.first ? "found" : "not found", ret.second); // proto cyklus funguje spravne a zbyva jen zmerit cas
	*/



	SearchContainer containerBinary(arrSize, maxNum);
	//containerLinear.PrintData();

	int numForFind = containerBinary.GetData(IdToFind);
	cout << "Num for find: " << numForFind << endl;

	containerBinary.SortArray();								// radim pole, ktere je nezbytnou podminkou pro provedeni binarniho vyhledavani
	//containerLinear.PrintData(); 

	auto retLinear = containerBinary.SearchBinary(numForFind);
	printf("Element: %s, on index(in sorted array) %d\n", retLinear.first ? "found" : "not found", retLinear.second);
	
	cout << "\n\nRuntime: " << clock() / 1000.0 << endl;	

	/*	
	* ================================================================================================================
	* arrSize:     	100    1000   10000   100000
	* 
	* SearchLinear:	0.204s 0.246s 0.878s  5.512s  
	*
	* SearchBinary:	0.15s  0.202s 0.209s  0.298s
	*
	* ================================================================================================================
	*	> Binarni vyhledavani je efektivni algoritmus protoze:
	*	   napr. mame mas pole z 1024 prvku
	*		a snazime se najit cislo na 1007 pozice napr. 123
	* 
	* Linear Search prepocita kazdou polozku od zacatku a do konce: 1,2,3,4,5..67,68,69..1231,1232,1234 ODPOVED;
	* ID:		[0] [1] [2] [3] [4] [5]....[1006] [1007] [1008] [1009]
	* Cislo:	41  521 999 765 333  0      876    123    8000   5528
	* 
	* ================================================================================================================
	* 
	* Binarni Search snizuje pocet kroku do log2(1024) = 10 prvku protoze funguje jinak:
	* nejprve jsou vsechna cisla serazena a pak je prijata LEFT(minimalni) a RIGHT(maximalni)
	* MID v takovem pripade bude soucet LEFT a RIGHT
	* 
	* left = 0	   // id [5]
	* right = 8000 // id [1008] rekneme, ze 8000 v poli bylo maximalni a 0 minimalni;
	* mid = 4000  <- (left + right) / 2
	* 
	* cislo se porovnava se vsemi tremi promennymi 
	* a dokud se odpoved dostane promenne se zmeni napr:
	* 
	* left				 midd		    		   right
	* [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] <- index
	* hledame bunku 4  ^
	* 
	* left = 1 ; midd = 6; right = 12
	* left = 1; midd = 3; right = 5;
	* left = 4; midd = 4; right = 5;
	* ================================================================================================================
	*/

	getchar();
	return 0;
}




/*for (size_t i = 0; i < iterationsCount; i++)
	{
		auto ret = container.SearchLinear(i);
		printf("Element i %d, %s, on index %d\n", i, ret.first ? "found" : "not found", ret.second);
	}*/
