#include <iostream>
using namespace std;


void SortArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}}
		
		
	}
}

int FindNumber(int num, int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			return i;
	}

	return -1;
}


void main()
{
	int size;
	cout << "Enter how many numbers you want to input: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter new number: ";
		cin >> arr[i];
	}

	SortArray(arr, size);

	int num;
	cout << "Enter number you want to locate: ";
	cin >> num;

	cout << "Sorted array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "Item is located at position: " << FindNumber(num, arr, size) << endl;
	delete[] arr;
}