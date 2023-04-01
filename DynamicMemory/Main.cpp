#include <iostream>
#include<vector>

using namespace std;

void FillRand(int* const arr, int const size);
void Print(int* const arr, int const size);
void Push_back(int*& arr, int& size, int  value);
void Push_front(int*& arr, int& size, int value);
void Pop_buck(int*& arr, int& size);
void Pop_front(int*& arr, int& size);
void Insert(int*& arr, int& size, int value,int index);
void Erase(int*& arr, int& size, int index);

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	int value, index1, index2;
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
	cout << endl;
	Push_front(arr, size, value);
	Print(arr, size);
	cout << endl;
	Pop_buck(arr, size);
	Print(arr, size);
	cout << endl;
	Pop_front(arr, size);
	Print(arr, size);
	cout << endl;
	cout << "Введите индекс куда необходимо вставить значение:" << endl;
	cin >> index1;
	Insert(arr, size,value,index1);
	Print(arr, size);
	cout << endl;
	cout << "Введите индекс откуда необходимо удалить значение:" << endl;
	cin >> index2;
	Erase(arr, size, index2);
	Print(arr, size);
	delete[] arr;
}

void FillRand(int* const arr, int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 100;
}
void Print(int* const arr, int const size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";
}
void Push_back(int*& arr, int& size, int  value)
{
	int* NewArray = new int[size + 1];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i];
	delete[] arr;
	arr = NewArray;
	NewArray[size] = value;
	size++;
}
void Push_front(int*& arr, int& size, int value)
{
	int* NewArray = new int[size + 1];
	for (int i = 0; i < size; i++) NewArray[i + 1] = arr[i];
	delete[] arr;
	arr = NewArray;
	NewArray[0] = value;
	size++;
}
void Pop_buck(int*& arr, int& size)
{
	int* NewArray = new int[--size];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i];
	delete[] arr;
	arr = NewArray;
}
void Pop_front(int*& arr, int& size)
{
	int* NewArray = new int[size];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i + 1];
	delete[] arr;
	arr = NewArray;
	size--;
}
void Insert(int*& arr, int& size, int value,int index)
{
	int* NewArray = new int[size + 1];
	for (int i = 0; i < size; i++) 
	{ 
		if (i < index) NewArray[i] = arr[i];
		if (i == index)
		{
			NewArray[i] = value;
			NewArray[i + 1] = arr[i];
		}
		if (i > index) NewArray[i+1] = arr[i];
	}
	delete[] arr;
	arr = NewArray;
	size++;
}
void Erase(int*& arr, int& size, int index)
{
	int* NewArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i < index) NewArray[i] = arr[i];
		if (i == index) NewArray[i] = arr[i+1];
		if (i > index) NewArray[i] = arr[i+1];
	}
	delete[] arr;
	arr = NewArray;
	size--;
}