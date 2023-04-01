#include <iostream>
#include<vector>

using namespace std;

void FillRand(int * const arr, int const size);
void FillRand(double* const arr, int const size);
void FillRand(char* const arr, int const size);

template<typename T> void Print(T* const arr, int const size);
template<typename T> void Push_back(T*& arr, int& size, int  value);
template<typename T> void Push_front(T*& arr, int& size, int value);
template<typename T> void Pop_buck(T*& arr, int& size);
template<typename T> void Pop_front(T*& arr, int& size);
template<typename T> void Insert(T*& arr, int& size, int value,int index);
template<typename T> void Erase(T*& arr, int& size, int index);

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

void FillRand(int* arr, int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 100;
}
void FillRand(double* arr, int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 100;
}
void FillRand(char* arr, int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 100;
}

template<typename T>
void Print(T* const arr, int const size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";
}

template<typename T>
void Push_back(T*& arr, int& size, int  value)
{
	T* NewArray = new T[size + 1];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i];
	delete[] arr;
	arr = NewArray;
	NewArray[size] = value;
	size++;
}

template<typename T>
void Push_front(T*& arr, int& size, int value)
{
	T* NewArray = new T[size + 1];
	for (int i = 0; i < size; i++) NewArray[i + 1] = arr[i];
	delete[] arr;
	arr = NewArray;
	NewArray[0] = value;
	size++;
}

template<typename T>
void Pop_buck(T*& arr, int& size)
{
	T* NewArray = new T[--size];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i];
	delete[] arr;
	arr = NewArray;
}

template<typename T>
void Pop_front(T*& arr, int& size)
{
	T* NewArray = new T[size];
	for (int i = 0; i < size; i++) NewArray[i] = arr[i + 1];
	delete[] arr;
	arr = NewArray;
	size--;
}

template<typename T>
void Insert(T*& arr, int& size, int value,int index)
{
	T* NewArray = new T[size + 1];
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

template<typename T>
void Erase(T*& arr, int& size, int index)
{
	T* NewArray = new T[size];
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
