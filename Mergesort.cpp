/* 
Written By: Chelsey Mitchell
CS340: Assignment 3 - Part II
Mergesort Implementation
*/
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& list, int, int, int);

// Divide the list recursively until it can't be divided anymore
void split(vector<int>& list, int low, int high)
{
	int middle;
	if (low < high) {
		middle = (low + high) / 2;
		split(list, low, middle);
		split(list, middle + 1, high);
		mergeSort(list, low, high, middle);
	}
}

// Merge the divided lists back into one sorted list
void mergeSort(vector<int>& list, int low, int high, int middle)
{
	int i, j, k;
	int size = list.size();
	vector<int>	temp(size);

	i = low;
	k = low;
	j = middle + 1;
	while (i <= middle && j <= high) {
		if (list[i] < list[j]) {
			temp[k] = list[i];
			k++;
			i++;
		}
		else {
			temp[k] = list[j];
			k++;
			j++;
		}
	}
	while (i <= middle) {
		temp[k] = list[i];
		k++;
		i++;
	}
	while (j <= high) {
		temp[k] = list[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		list[i] = temp[i];
	}
}

int main()
{
	int size;
	// get the number of elements from the user
	cout << "Enter the number of integers to be sorted:";
	cin >> size;
	vector <int> list(size);
	// get the list of elements from the user
	cout << "Enter " << size << " integers:";
	for (int i = 0; i < size; i++) {
		cin >> list[i];
	}
	// call the function to split the list 
	split(list, 0, size - 1);
	// output the sorted list
	cout << "Sorted array\n";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
}

