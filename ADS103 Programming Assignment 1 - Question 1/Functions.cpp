#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "Functions.h"

using namespace std;

void errorOutput(int line1, int line2, int line3, int numberCount)
{
	if (line1 != 1 && line1 != 0)
	{
		cout << "Line 1 - Invalid number!\n";
		cout << "You can only choose 0 or 1\n" << "Please go back to input file and change value." << endl;
		exit(1);
	}

	if (line2 != 1 && line2 != 0)
	{
		cout << "Line 2 - Invalid number!\n";
		cout << "You can only choose 0 or 1\n" << "Please go back to input file and change value." << endl;
		exit(1);
	}

	if (line3 < 0)
	{
		cout << "line 3 - Invalid number!\n";
		cout << "Can't be negative.\n" << "Please go back to input file and change value." << endl;
		exit(1);
	}


	if (line3 != numberCount)
	{
		cout << "Line 4 - Invalid amount of numbers!\n";
		cout << "Has to match amount specified in line 3\n" << "Please go back to input file and change values." << endl;
		exit(1);
	}
}

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void displayArr(int arr[], int arrSize)
{
	for (int i = 0; i <= arrSize - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubbleSortAsc(int arr[], int arrSize)
{
	bool sorted = false;
	while (!sorted) //loop while not sorted
	{
		sorted = true;
		for (int i = 0; i <= arrSize - 1 - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr, i, i + 1);
				sorted = false;
			}
		}
	}
}

void bubbleSortDesc(int arr[], int arrSize)
{
	bool sorted = false;
	while (!sorted) //loop while not sorted
	{
		sorted = true;
		for (int i = 0; i <= arrSize - 1 - 1; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				swap(arr, i, i + 1);
				sorted = false;
			}
		}
	}
}

int partition(int arr[], int low, int high)
{
	//can decide pivot selection in different ways e.g, median of index, random, high's value
	//we'll use the value in the array at low index's position
	int pivot = arr[low];
	int i = low, j = high;
	//loop until i and j cross paths
	while (i < j)
	{
		//i looks for value in array which is BIGGER then pivot value
		//moving RIGHT
		do {
			i++;
		} while (arr[i] <= pivot);//stop loop once value in a[i] > pivot

		//j looks for value in array which is SMALLER then pivot value
		//moving LEFT
		do {
			j--;
		} while (arr[j] > pivot);
		//IF i and j haved crossed paths, then we can assume we've found
		//a value bigger with i and a value smaller with j, so swap them
		if (i < j)
			swap(arr[i], arr[j]);
	}
	//once done, swap pivot value with wherever j ended up
	swap(arr[low], arr[j]);

	//return j, so that new quicksort's can partition work into 2 loads
	//one left of j and one right of j
	return j;

}

void quickSort(int arr[], int low, int high)
{
	/// <summary>
	/// quicksort is a recursive divide and conquer algorithm
	/// </summary>
	/// <param name="arr">array of unsorted numbers</param>
	/// <param name="low">start index of array part to work on</param>
	/// <param name="high">end index to work between</param>
	
		//look up towers of hanoi algorithm
		//look up recursive power of 
		if (low < high)
		{
			int partitionIndex = partition(arr, low, high);
			quickSort(arr, low, partitionIndex);
			quickSort(arr, partitionIndex + 1, high);
		}
	
}


