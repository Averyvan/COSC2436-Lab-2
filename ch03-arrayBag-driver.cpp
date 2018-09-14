//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

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

int main()
{
	ArrayBag<int> bag;
	ArrayBag<int> bag2;
//	for (int i=0; i<6;i++) bag.add(i);
//	for (int i=6; i<10;i++) bag2.add(i);
//	displayBag(bag);
//	displayBag(bag2);
	ArrayBag<int> bag3 = bag.bagUnion(bag2);
//	displayBag(bag3);
//	bag.clear(); bag2.clear();
//	
//	for (int i=0; i<6;i++) bag.add(i);
//	for (int i=4; i<10;i++) bag2.add(i);
//	displayBag(bag);
//	displayBag(bag2);
//	bag3 = bag2.bagIntersection(bag);
//	displayBag(bag3);
	bag.clear(); bag2.clear(); bag3.clear();
	
	for (int i=0; i<6;i++) bag.add(i);
	for (int i=4; i<10;i++) bag2.add(i);
	displayBag(bag);
	displayBag(bag2);
	bag3 = bag.bagDifference(bag2);
	displayBag(bag3);
	bag.clear(); bag2.clear();
	
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
