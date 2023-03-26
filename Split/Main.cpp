#include <iostream>

using namespace std;

void FillRand(int* const arr, int const size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 50;
}

void Print(int* const arr, int const size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";
}

void Chet(int* const arr, int size,int &Count1)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			Count1++;
		}
	}
	
}

void NeChet(int* const arr, int size, int &Count2)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0)
		{
			Count2++;
		}
	}

}

void Even(int* const arr, int* even, int const size)
{
	for (int i = 0, j = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[j] = arr[i];
			j++;
		}
	}
}

void PrintEven(int* even, int Count2, int const size)
{
	for (int i = 0; i < (size - Count2); i++) cout << even[i] << "\t";
}

void Odd(int* const arr, int* odd, int const size)
{
	for (int i = 0, j = 0; i < size; i++)
	{
		if (arr[i] % 2!=0)
		{
			odd[j] = arr[i];
			j++;
		}
	}
}

void PrintOdd(int* odd, int Count1, int const size)
{
	for (int i = 0; i < (size - Count1); i++) cout << odd[i] << "\t";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int Count1 = 0;
	int Count2 = 0;
	int size;
	cout << "Введите размер массива:" << endl;
	cin >> size;
	int* arr = new int[size];
	FillRand(arr, size);
	cout << endl;
	Print(arr, size);
	cout << endl;
	Chet(arr, size, Count1);
	NeChet(arr, size, Count2);
	int* even = new int[size - Count2];
	int* odd = new int[size - Count1];
	Even(arr, even, size);
	PrintEven(even, Count2, size);
	cout << endl;
	Odd(arr, odd, size);
	PrintOdd(odd, Count1, size);

	delete[] arr;
	delete[] even;
	delete[] odd;
}