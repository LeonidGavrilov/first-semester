// lab6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;
void insertionSort(int *arrPtr, int length);
void bub(int* arr, int n);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Ru");
	int arr[100], n, size = 0;
	cout << "Введите размер массива: ";
	cin >> n;
	/*for (int i = 0; i < n; i++) {
		arr[i] = 1 + rand() % 100;
	}
	for (int i = 0; i < arr[i]; i++) {
		cout << arr[i] << " ";
	}*/
	for (int i = 0; i < n; i++) {
		arr[i] = 1 + rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "puzirka\n";
	bub(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	bub(arr, n);
	cout << "\nVstavka" << endl;
	insertionSort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	insertionSort(arr, n);

	cout << "\npuzirka\n";
	bub(arr, n);
	for (int i = 0; i < n; i++) {
		cout << -arr[i] << " ";
	}
	cout << endl;
	bub(arr, n);
	cout << "\nVstavka" << endl;
	insertionSort(arr, n);
	for (int i = 0; i < n; i++) {
		cout << -arr[i] << " ";
	}
	cout << endl;
	insertionSort(arr, n);
	return 0;
}
