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

void Push_back(int *&arr, int &size, int const value)
{
	int* NewArray = new int[size + 1];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i];
	delete[] arr;
	arr = NewArray;
	NewArray[size] = value;
	size++;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	int value;
	cout << "Введите размер массива:" << endl;
	cin >> size;
	cout << "Введите число которое необходимо передать в конец массива:" << endl;
	cin >> value;
	int* arr = new int[size];
	FillRand(arr,size);
	Print(arr, size);
	cout << endl;
	Push_back(arr, size, value);
	Print(arr, size);
	delete[] arr;
}
