#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n, sum = 0;
	char ch;
	do {
		cin >> n;
		for (int i = 1; i < n; i++) {
			cout << i << " ";
			if (i % 5 == 0)
				sum += i;
		}
		cout << "\nРезультат равен: " << sum;
		cout << "\nПродолжить ввод (y/n?!)";
		cin >> ch;
	} while (ch != 'n');
	return 0;
}