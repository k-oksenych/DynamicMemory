#include <iostream>
#include <ctime>

using namespace std;

//Functions for working with dynamic array:

//Function allocates dymnamic memory

int* dynamicMemory(int size)
{
	return new int[size];
}

//Function initializes dynamic array

void initializeArray(int* const ar, int size)
{
	for (int i = 0; i < size; ++i)
	{
		ar[i] = rand() % 10;
	}
}

//Function prints dynamic array

void printArray(int* const ar, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << ar[i] << ' ';
	}
	cout << endl;
}

//Function deletes dynamic array

void deleteArray(int* const ar)
{
	delete[] ar;
}

//Function adds an element to the end of array

int* addValue(int* const ar, int* size, const int value)
{
	int* temp = new int[*size + 1];
	for (int i = 0; i < *size; ++i)
	{
		temp[i] = ar[i];
	}
	temp[*size] = value;
	delete[] ar;
	++(*size);
	return temp;
}

//Function inserts an element at the specified index

int* insert(const int* const ar, int* size, const int index, const int value)
{
	int* temp = new int[*size + 1];

	for (int i = 0; i < index; ++i)
	{
		temp[i] = ar[i];
	}

	temp[index] = value;

	for (int i = index; i < *size; ++i)
	{
		temp[i + 1] = ar[i];
	}
	++*size;
	delete[] ar;
	return temp;
}

//Function deletes an element at the specified index

int* deleteValue(const int* const ar, int* size, const int index)
{
	int* temp = new int[*size - 1];

	for (int i = 0; i < index; ++i)
	{
		temp[i] = ar[i];
	}
	
	for (int i = index; i < *size; ++i)
	{
		temp[i] = ar[i + 1];
	}
	--*size;
	delete[] ar;
	return temp;
}

int main()
{
	int size = 5;
	int* size1 = &size;
	int* ar = dynamicMemory(size);
	initializeArray(ar, size);

	printArray(ar, size);

	int* ar2 = deleteValue(ar, size1, 3);

	printArray(ar2, size);
}