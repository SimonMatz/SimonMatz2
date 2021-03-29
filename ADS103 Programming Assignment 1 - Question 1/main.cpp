#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "functions.h"

using namespace std;

void main()
{
	//reading from input file
	ifstream readFile;
	readFile.open("input-a1q1.txt");

	// creating a variable for each line of the text file to store value
	int ascendingDescending;
	int sortedUnsorted;
	int amountOfElements;

	//reading from file and storing in variables from above
	readFile >> ascendingDescending;
	readFile >> sortedUnsorted;
	readFile >> amountOfElements;

	//using pointers to create dynamic size array
	int* numbersToSort = new int[amountOfElements];
	//variable for looping through array
	int count1 = 0;

	//looping through line 4 and storing numbers in array
	while (!readFile.eof())
	{
		readFile >> numbersToSort[count1];
		count1++;
	}
	readFile.close();

	// calling error output function
	errorOutput(ascendingDescending, sortedUnsorted, amountOfElements, count1);

	//Bubblesort in ascending order
	//Takes starting time, runs the sorting algorythm, takes end time, stores value in time1 and outputs to file
	if (ascendingDescending == 0 && sortedUnsorted == 0)
	{
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		bubbleSortAsc(numbersToSort, count1);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		float time1 = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
		
		//write time recorded into file
		ofstream  writeFile;
		writeFile.open("output-a1q1.txt");
		writeFile << time1 << "ms" << endl;

		// FROM: https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file/22190167
		for (int count = 0; count < amountOfElements; count++)
		{
			writeFile << numbersToSort[count] << " ";
		}
		writeFile.close();

		cout << "Bubble Sorted Asc" << endl;
	}

	//Bubblesort in descending order
	//Takes starting time, runs the sorting algorythm, takes end time, stores value in time1 and outputs to file
	if (ascendingDescending == 1 && sortedUnsorted == 0)
	{
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		bubbleSortDesc(numbersToSort, count1);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		float time1 = chrono::duration_cast<chrono::milliseconds>(end - begin).count();

		//write time recorded into file
		ofstream  writeFile;
		writeFile.open("output-a1q1.txt");
		writeFile << time1 << "ms" << endl;

		// FROM: https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file/22190167
		for (int count = 0; count < amountOfElements; count++)
		{
			writeFile << numbersToSort[count] << " ";
		}
		writeFile.close();

		cout << "Bubble Sorted Desc" << endl;
	}

	//Quicksort in ascending order
	//Takes starting time, runs the sorting algorythm, takes end time, stores value in time1 and outputs to file
	if (ascendingDescending == 0 && sortedUnsorted == 1)
	{
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		quickSort(numbersToSort, 0, amountOfElements);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		float time1 = chrono::duration_cast<chrono::milliseconds>(end - begin).count();

		//write time recorded into file
		ofstream  writeFile;
		writeFile.open("output-a1q1.txt");
		writeFile << time1 << "ms" << endl;

		// FROM: https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file/22190167
		for (int count = 0; count < amountOfElements; count++)
		{
			writeFile << numbersToSort[count] << " ";
		}
		writeFile.close();

		cout << "Quick Sorted Asc" << endl;
	}

	//Quicksort in descending order
	//Takes starting time, runs the sorting algorythm, takes end time, stores value in time1 and outputs to file
	if (ascendingDescending == 1 && sortedUnsorted == 1)
	{
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		quickSort(numbersToSort, 0, amountOfElements);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		float time1 = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
		

		//write time recorded into file
		ofstream  writeFile;
		writeFile.open("output-a1q1.txt");
		writeFile << time1 << "ms" << endl;

		// FROM: https://stackoverflow.com/questions/22190048/how-to-write-the-content-of-an-array-into-a-text-file/22190167
		for (int count = amountOfElements; count > 0; count--)
		{
			writeFile << numbersToSort[count-1] << " ";
		}
		writeFile.close();

		cout << "Quick Sorted Desc" << endl;
	}

	//deleting the temp array to avoid memory leak
	delete[] numbersToSort;
}