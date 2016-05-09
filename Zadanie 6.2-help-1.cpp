// Menu Chooser rewrite, p70-1
// Demonstrates the switch statement and enumeration

#include <iostream>

using namespace std;

int main()
{
cout << "Difficulty Levels\n\n";
cout << "1 - Easy\n";
cout << "2 - Normal\n";
cout << "3 - Hard\n\n";

enum level {easy = 1, normal, hard};
int choice;

cout << "Choice: ";
cin >> choice;

switch (choice)
{
case easy:
cout << "You picked Easy." << endl;
break;
case normal:
cout << "You picked Normal." << endl;
break;
case hard:
cout << "You picked Hard." << endl;
break;
default:
cout << "You made an illegal choice." << endl;
}

cout << "Press ENTER to continue...";

//system("pause");

return 0;
}
