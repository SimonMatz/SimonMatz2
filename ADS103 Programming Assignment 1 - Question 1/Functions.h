#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

using namespace std;

// Reads file and tells user if their input is correct or not and why
void errorOutput(int line1, int line2, int line3, int numberCount);

void swap(int arr[], int i, int j);

void displayArr(int arr[], int arrSize);

void bubbleSortAsc(int arr[], int arrSize);

void bubbleSortDesc(int arr[], int arrSize);

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);



