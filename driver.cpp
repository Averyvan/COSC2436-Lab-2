// Author: Avery VanAusdal
// Assignment Number: Lab 2
// File Name: Driver.cpp
// Course/Section: COSC 1337 Section 3
// Date: 9/16/2018
// Instructor: Bernard Ku

#include <iostream>
#include <string>
#include "ArrayBag.h"
using namespace std;

template <class ItemType>
void displayBag(ArrayBag<ItemType>& bag)
{ //displays contents of bag passed in arguments
	cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
   vector<ItemType> bagItems = bag.toVector();
   sort(bagItems.begin(), bagItems.end());
   
   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displayBag

int getIntInput(string prompt)
{ //captures user input for number of items to be added to a bag
	int numItems = 0;
	while (!(cout<< prompt)||
	!(cin>>numItems) || numItems > 12 || numItems < 0)
	{ //loops until valid input is captured
		cout<<"Error: Please enter a valid number between 0 and 12.\n";
		cin.clear(); //Error clearing
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Clears any leftover in cin stream
	}
	return numItems; //Returns number of items to be added
} //end getIntInput

template <class ItemType>
void bagTest(ArrayBag<ItemType>& bagOne, ArrayBag<ItemType>& bagTwo)
{ //Runs bags through all new member functions, bagUnion, bagIntersection, and bagDifference.
	cout<<"\nUnion contains:\n";
	ArrayBag<ItemType> bagResults = bagOne.bagUnion(bagTwo);
	displayBag(bagResults); //display Union of bags
	cout<<"\nIntersection contains:\n";
	bagResults = bagOne.bagIntersection(bagTwo);
	displayBag(bagResults); //display Intersection of bags
	cout<<"\nDifference contains:\n";
	bagResults = bagOne.bagDifference(bagTwo);
	displayBag(bagResults); //display Difference of bags
	cout<<"Clearing all bag contents...\n\n";
	bagOne.clear(); bagTwo.clear(); bagResults.clear(); //Clears bags
} //end bagTest

template <class ItemType>
void getBagInputDigit(ArrayBag<ItemType>& bag, int numItems)
{ //retrieves user input numItems times and checks for valid input
	for (int i = 0; i < numItems; i++) //loops through user desired number of times
	{
		string userInput = "";
		cout<<" Enter a single integer character: ";
		cin>>userInput;
		if (userInput.length() != 1 || !isdigit(userInput[0]))
		{
			cout<<"  Error: Invalid input.\n";
			i--; //takes the counter back one, to redo the item
		}
		else bag.add(userInput[0]); //adds user 
	}
} //end getBagInputDigit

template <class ItemType>
void getBagInputAlpha(ArrayBag<ItemType>& bag, int numItems)
{ //retrieves user input numItems times and checks for valid input
	for (int i = 0; i < numItems; i++) //loops through user desired number of times
	{
		string userInput = "";
		cout<<" Enter a single letter character: ";
		cin>>userInput;
		if (userInput.length() != 1 || !isalpha(userInput[0]))
		{
			cout<<"  Error: Invalid input.\n";
			i--; //takes the counter back one, to redo the item
		}
		else bag.add(userInput[0]);
	}
} //end getBagInputAlpha

template <class ItemType>
void getBagInputString(ArrayBag<ItemType>& bag, int numItems)
{ //retrieves user input numItems times and checks for valid input
	for (int i = 0; i < numItems; i++) //loops through user desired number of times
	{
		string userInput = "";
		cout<<" Enter a string: ";
		cin>>userInput;
		bag.add(userInput); 
	} //adds user defined strings as many times as needed
} //end getBagInputString

template <class ItemType>
void getBagInputInteger(ArrayBag<ItemType>& bag, int numItems)
{ //retrieves user input numItems times and checks for valid input
	bool isDigit = true;
	for (int i = 0; i < numItems; i++) //loops through user desired number of times
	{
		string userInput = "";
		cout<<" Enter an integer: ";
		cin>>userInput;
		for (int i = 0; i < userInput.length(); i++)
		{ //Checks if any character in userInput is NOT a digit
			if (!isdigit(userInput[i])) isDigit = false;
		}
		if (!isDigit)
		{ //if it's not a digit, retry.
			cout<<"  Error: Invalid input.\n";
			i--; //takes the counter back one, to redo the item
		}
		else bag.add(stoi(userInput)); //stoi means String to Int
	}
} //end getBagInputInteger

int main()
{
	cout<<"This program tests user defined type ArrayBags, and tests Union, Intersection, \
and Difference method functions."<<endl;
	ArrayBag<char> bagOne;
	ArrayBag<char> bagTwo;
	ArrayBag<string> bagOneString;
	ArrayBag<string> bagTwoString;
	ArrayBag<int> bagOneInt;
	ArrayBag<int> bagTwoInt;
	string userInput;
	while (true)
	{
		cout<<"1) Digit Char Array\n2) Alpha Char Array\n3)\
 String Name Array\n4) Integer Array\n5) Exit\n\n";
		cout<<"Please enter your choice: ";
		string choice;
		cin>>choice; //picking a menu option
		cout<<endl;
		if (choice == "1") //Digit Char Array option
		{
			getBagInputDigit(bagOne, getIntInput("How many items for the first bag? (Between 0 and 12): "));
			getBagInputDigit(bagTwo, getIntInput("How many items for the second bag? (Between 0 and 12): "));
			//retrieves user input for # of items, then asks # many times for bag input for both bags
			bagTest(bagOne, bagTwo);
		}
		else if (choice == "2") //Alpha Char Array option
		{
			getBagInputAlpha(bagOne, getIntInput("How many items for the first bag? (Between 0 and 12): "));
			getBagInputAlpha(bagTwo, getIntInput("How many items for the second bag? (Between 0 and 12): "));
			bagTest(bagOne, bagTwo);
		}
		else if (choice == "3") //String Array option
		{
			getBagInputString(bagOneString, getIntInput("How many items for the first bag? (Between 0 and 12): "));
			getBagInputString(bagTwoString, getIntInput("How many items for the second bag? (Between 0 and 12): "));
			bagTest(bagOneString, bagTwoString);
		}
		else if (choice == "4") //Integer Array option
		{
			getBagInputInteger(bagOneInt, getIntInput("How many items for the first bag? (Between 0 and 12): "));
			getBagInputInteger(bagTwoInt, getIntInput("How many items for the second bag? (Between 0 and 12): "));
			bagTest(bagOneInt, bagTwoInt);
		}
		else if (choice == "5")
		{
			cout<<"Thank you, goodbye!";
			return 0;
		}
		else
		{
			cout<<"Invalid input. Please enter 1-5 to select an option.";
		}
	}
	
	return 0;
}	// end main

/* Sample output:
This program tests user defined type ArrayBags, and tests Union, Intersection, and Difference method functions.
1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please enter your choice: 1

How many items for the first bag? (Between 0 and 12): 1
 Enter a single integer character: 2
How many items for the second bag? (Between 0 and 12): 3
 Enter a single integer character: 1
 Enter a single integer character: 2
 Enter a single integer character: 3

Union contains:
The bag contains 4 items:
1 2 2 3


Intersection contains:
The bag contains 1 items:
2


Difference contains:
The bag contains 0 items:


Clearing all bag contents...

1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please enter your choice: 2

How many items for the first bag? (Between 0 and 12): 2
 Enter a single letter character: a
 Enter a single letter character: l
How many items for the second bag? (Between 0 and 12): 5
 Enter a single letter character: a
 Enter a single letter character: t
 Enter a single letter character: x
 Enter a single letter character: y
 Enter a single letter character: o

Union contains:
The bag contains 7 items:
a a l o t x y


Intersection contains:
The bag contains 1 items:
a


Difference contains:
The bag contains 1 items:
l

Clearing all bag contents...

1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please enter your choice: 3

How many items for the first bag? (Between 0 and 12): John
Error: Please enter a valid number between 0 and 12.
How many items for the first bag? (Between 0 and 12): 1
 Enter a string: John
How many items for the second bag? (Between 0 and 12): 3
 Enter a string: Todd
 Enter a string: Mary
 Enter a string: John

Union contains:
The bag contains 4 items:
John John Mary Todd


Intersection contains:
The bag contains 1 items:
John


Difference contains:
The bag contains 0 items:


Clearing all bag contents...

1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please enter your choice: 4

How many items for the first bag? (Between 0 and 12): 2
 Enter an integer: 4
 Enter an integer: 6
How many items for the second bag? (Between 0 and 12): 4
 Enter an integer: 6
 Enter an integer: 2
 Enter an integer: 1
 Enter an integer: 1

Union contains:
The bag contains 6 items:
1 1 2 4 6 6


Intersection contains:
The bag contains 1 items:
6


Difference contains:
The bag contains 1 items:
4

Clearing all bag contents...

1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please enter your choice: 5

Thank you, goodbye!
--------------------------------
Process exited after 86.75 seconds with return value 0
Press any key to continue . . .
 */
