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
{
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
{
	int numItems = 0;
	while (!(cout<< prompt)||
	!(cin>>numItems) || numItems > 12 || numItems < 0)
	{
		cout<<"Error: Please enter a valid number between 0 and 12.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}
	return numItems;
}

template <class ItemType>
void bagTest(ArrayBag<ItemType>& bagOne, ArrayBag<ItemType>& bagTwo)
{
	cout<<"\nUnion contains:\n";
	ArrayBag<ItemType> bagResults = bagOne.bagUnion(bagTwo);
	displayBag(bagResults);
	cout<<"\nIntersection contains:\n";
	bagResults = bagOne.bagIntersection(bagTwo);
	displayBag(bagResults);
	cout<<"\nDifference contains:\n";
	bagResults = bagOne.bagDifference(bagTwo);
	displayBag(bagResults);
	cout<<"Clearing all bag contents...\n\n";
	bagOne.clear(); bagTwo.clear(); bagResults.clear();
}

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
		cin>>choice;
		cout<<endl;
		if (choice == "1") //Digit Char Array option
		{
			int numItems = getIntInput("How many items for the first bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter a single integer character: ";
				cin>>userInput;
				if (userInput.length() != 1 || !isdigit(userInput[0]))
				{
					cout<<"  Error: Invalid input.\n";
					i--;
				}
				else bagOne.add(userInput[0]);
			}
			numItems = getIntInput("How many items for the second bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter a single integer character: ";
				cin>>userInput;
				if (userInput.length() != 1 || !isdigit(userInput[0]))
				{
					cout<<"  Error: Invalid input.\n";
					i--;
				}
				else bagTwo.add(userInput[0]);
			}
			bagTest(bagOne, bagTwo);
		}
		else if (choice == "2") //Alpha Char Array option
		{
			int numItems = getIntInput("How many items for the first bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter a single letter character: ";
				cin>>userInput;
				if (userInput.length() != 1 || !isalpha(userInput[0]))
				{
					cout<<"  Error: Invalid input.\n";
					i--;
				}
				else bagOne.add(userInput[0]);
			}
			numItems = getIntInput("How many items for the second bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter a single letter character: ";
				cin>>userInput;
				if (userInput.length() != 1 || !isalpha(userInput[0]))
				{
					cout<<"  Error: Invalid input.\n";
					i--;
				}
				else bagTwo.add(userInput[0]);
			}
			bagTest(bagOne, bagTwo);
		}
		else if (choice == "3") //String Array option
		{
			int numItems = getIntInput("How many items for the first bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter a string: ";
				cin>>userInput;
				bagOneString.add(userInput);
			}
			numItems = getIntInput("How many items for the second bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter a string: ";
				cin>>userInput;
				bagTwoString.add(userInput);
			}
			bagTest(bagOneString, bagTwoString);
		}
		else if (choice == "4") //Integer Array option
		{
			bool isDigit = true;
			int numItems = getIntInput("How many items for the first bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter an integer: ";
				cin>>userInput;
				for (int i = 0; i < userInput.length(); i++)
				{
					if (!isdigit(userInput[i])) isDigit = false;
				}
				if (!isDigit)
				{
					cout<<"  Error: Invalid input.\n";
					i--;
				}
				else bagOneInt.add(stoi(userInput)); //stoi means String to Int
			}
			numItems = getIntInput("How many items for the second bag? (Between 0 and 12): ");
			for (int i = 0; i < numItems; i++)
			{
				userInput = "";
				cout<<" Enter an integer: ";
				cin>>userInput;
				for (int i = 0; i < userInput.length(); i++)
				{
					if (!isdigit(userInput[i])) isDigit = false;
				}
				if (!isDigit)
				{
					cout<<"  Error: Invalid input.\n";
					i--;
				}
				else bagTwoInt.add(stoi(userInput));
			}
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

/*
 Testing the Array-Based Bag:
 The initial bag is empty.
 isEmpty: returns 1; should be 1 (true)
 The bag contains 0 items:
 
 
 Add 6 items to the bag:
 The bag contains 6 items:
 one two three four five one
 
 isEmpty: returns 0; should be 0 (false)
 getCurrentSize: returns 6; should be 6
 Try to add another entry: add("extra") returns 0
 contains("three"): returns 1; should be 1 (true)
 contains("ten"): returns 0; should be 0 (false)
 getFrequencyOf("one"): returns 2 should be 2
 remove("one"): returns 1; should be 1 (true)
 getFrequencyOf("one"): returns 1 should be 1
 remove("one"): returns 1; should be 1 (true)
 remove("one"): returns 0; should be 0 (false)
 
 The bag contains 4 items:
 five two three four
 
 After clearing the bag, isEmpty: returns 1; should be 1 (true)
 All done!
 */