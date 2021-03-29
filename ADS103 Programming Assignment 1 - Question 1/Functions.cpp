#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "Functions.h"

using namespace std;

//function gets values from the file read, checks for error input and notifies user
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

//swap function for sorting
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//bubble sort in ascending order
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

//bubble sort in descending order
void bubbleSortDesc(int arr[], int arrSize)
{
	bool sorted = false;
	while (!sorted) //loop while not sorted
	{
		sorted = true;
		for (int i = 0; i <= arrSize - 1 - 1; i++)
		{
			//changed from > to < to make descending
			if (arr[i] < arr[i + 1])
			{
				swap(arr, i, i + 1);
				sorted = false;
			}
		}
	}
}

//partition function for quick sort
int partition(int arr[], int low, int high)
{
	//using the value in the array at low index's position for pivot selection
	int pivot = arr[low];
	int i = low, j = high;

	while (i < j)
	{
		//i looks for value in array which is bigger than pivot value (moving right)
		do {
			i++;
		} while (arr[i] <= pivot);

		//j looks for value in array which is smaller than pivot value (moving left)
		do {
			j--;
		} while (arr[j] > pivot);

		//If i and j haved crossed paths, found value bigger with i & a value smaller with j -> swap
		if (i < j)
			swap(arr[i], arr[j]);
	}
	//when finished swap pivot value with j 
	swap(arr[low], arr[j]);

	//returning j for partitioning into 2 loads
	return j;
}

//Quick sort function
void quickSort(int arr[], int low, int high)
{
		if (low < high)
		{
			int partitionIndex = partition(arr, low, high);
			quickSort(arr, low, partitionIndex);
			quickSort(arr, partitionIndex + 1, high);
		}
}


