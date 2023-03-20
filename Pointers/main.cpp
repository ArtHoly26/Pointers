#include <iostream>
#include <stdarg.h>

using namespace std;

int Sum(int n...)
{
	int sum = 0;
	int* pa = &n;
	
	while(*pa)
	{
		sum += (*pa);
		pa++;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout <<"Сумма переданных аргументов равна: "<< Sum(200, 300, 400, 0) << endl;
	
}