// Author: Avery VanAusdal
// Assignment Number: Lab 2
// File Name: ArrayBag.cpp
// Course/Section: COSC 1337 Section 3
// Date: 9/16/2018
// Instructor: Bernard Ku

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>
#include <algorithm> //for sort()
using namespace std;

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

//public Advanced Member Functions
/* Returns union of two bags
	@pre	Have two bag items
	@post	Input bags are not changed
			union of bags sorted and returned
	@param	bagB other object to be added
	@return	ArrayBag object containing union of two bags	*/
template <class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag& bagB) const
{
	ArrayBag resultBag; //empty bag to contain union
	for (int i = 0; i < itemCount; i++)
	{
		resultBag.add(items[i]);
	}
	for (int i = 0; i < bagB.itemCount; i++)
	{
		resultBag.add(bagB.items[i]);
	}
	//sort(resultBag.items, resultBag.items+itemCount);
	return resultBag;
}

/* Returns intersection of two bags
	@pre	have two bag items
	@post	Input bags are not changed
			intersection of two bags returned
	@param	bagB other object to be compared with parent
	@return ArrayBag object containing intersection of two bags	*/
template <class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagIntersection(const ArrayBag& bagB) const
{
	ArrayBag resultBag; //empty bag to contain intersection
	for (int i = 0; i < itemCount; i++)
	{
		int need;
		int firstBagCopies = getFrequencyOf(items[i]);
		int secondBagCopies = bagB.getFrequencyOf(items[i]);
		if (firstBagCopies < secondBagCopies) need = firstBagCopies;
		else need = secondBagCopies; //these two lines put need at the lower of the two
		int have = resultBag.getFrequencyOf(items[i]); //amount of i in resultBag
		for (int j = have; j < need; j++)
		{
			resultBag.add(items[i]);
		}
	}
	return resultBag;
}

/* Returns difference of two bags
	@pre	have two bag items
	@post	Input bags are not changed
			difference of two bags returned
	@param	bagB other object to be compared with parent
	@return	ArrayBag object containing difference of two bags
*/
template <class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagDifference(const ArrayBag& bagB) const
{
	ArrayBag resultBag;
	for (int i = 0; i< itemCount; i++) resultBag.add(items[i]);
	for (int i = 0; i < resultBag.itemCount; i++)
	{
		int firstBagCopies = getFrequencyOf(resultBag.items[i]);
		int secondBagCopies = bagB.getFrequencyOf(resultBag.items[i]);
		int resultBagCopies = resultBag.getFrequencyOf(resultBag.items[i]);
		if ((firstBagCopies - resultBagCopies) != secondBagCopies)
		{
			resultBag.remove(resultBag.items[i]);
			i--;
		}
	}
	return resultBag;
}
