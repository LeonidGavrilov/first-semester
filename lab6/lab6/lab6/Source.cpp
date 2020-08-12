#pragma once
#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;
void insertionSort(int *arrPtr, int length)
{
	int k = 0, kk = 0, f;
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++) {
			kk++;
			if (arrPtr[j] < arrPtr[min]) {
				min = j;
			}
		}
		if (min != i) {
			k++;
			int temp = arrPtr[min];
			arrPtr[min] = arrPtr[i];
			arrPtr[i] = temp;
		}
	}
	cout << "Кол-ов перестановок: " << k << "\nКол-во сравнений: " << kk << endl;
}
void bub(int* arr, int n) {
	int k = 0, kk = 0, f;
	for (int i = n - 1; i > 0; i--)
	{
		f = 0;
		for (int j = 0; j < i; j++) {
			k++;
			if (arr[j] < arr[j + 1])
			{
				kk++;
				f++;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (f == 0) break;
	}
	cout << "Кол-ов сравнений: " << k << "\nКол-во перестановок: " << kk << endl;
}

