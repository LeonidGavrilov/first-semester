// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
void sortV(double* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void sortU(double* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void vvod(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 20 - 1;
		//cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
double logika(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				for (int p = j; p < n - 1; p++) {
					arr[p] = arr[p + 1];
				}
				n--;
					if (arr[i] == arr[j]) {
						j--;
				}
			}
		}
	}
	return n;
}
//void logika(double* arr, int n) {
//	double s = 0;
//	for (int i = 0; i < n; i++) 
//		s += arr[i];
//	cout << "Summ = " << s << endl;
//	s /= n;
//	
//	cout << s << endl;
//}
void vivod(double* arr, int n) {
	//for (int i = 0; i < n; i++)
	sortV(arr, n);
	for(int i = 0; i < logika(arr,n); i++)
		cout << arr[i] << " ";
}
void main()
{
	int n;
	do
	{
		cin >> n;
	} while (n < 0);
	double *arr = new double[n];
	//string *arr = new string[n];
	srand(time(NULL));
	vvod(arr, n);
	//logika(arr, n);
	vivod(arr, n);
	delete[] arr;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
