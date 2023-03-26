#include <iostream>

using namespace std;


void FillRand(int* const arr, int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 100;
}

void Print(int* const arr, int const size)
{
	for (int i = 0; i < size; i++) cout << arr[i]<<"\t";
}

void AddElement(int *& arr, int &size, int const endElement)
{
	int* NewArray = new int[size + 1];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i];

	NewArray[size] = endElement;
	size++;
	delete[] arr;
	arr = NewArray;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "¬ведите размер массива:" << endl;
	cin >> size;
	int* arr = new int[size];
	FillRand(arr,size);
	Print(arr, size);
	cout << endl;
	AddElement(arr, size, 101);
	Print(arr, size);
	delete[] arr;
}
