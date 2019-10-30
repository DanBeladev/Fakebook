#include "faceBook.h"
#include "mainFunctions.h"


/*
05/12/2018
EX1 by:
Nave Farjun ID: 312494206 (keren group)
Dan Beladev ID: 205684277 (Amir group)
*/
void main()
{

	FaceBook mainFace;
	cout << "what would you like to do?"<< endl;
	printMenu();
	char c;
	do
	{
		cout << "choose action number:";
		cin >> c;
		if (!cin.fail()) {
			chooseOption(c, mainFace);
		}
		
	} while (c != '0');
	
}

