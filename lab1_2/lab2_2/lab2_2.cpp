#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	double a, s = 1;
	char ch;
	do {
		cout << "Введите значение a: ";
		cin >> a;
		if (a >= 0) {
			for (int i = 2; i <= 8; i += 2)
				s = s * (i * i);	s -= a;
			cout << "Сумма равна: " << s;
		}
		else {
			for (int i = 3; i <= 9; i += 3)
				s = s * (i - 2);
			cout << "Сумма равна: " << s;
		}
		cin >> ch;
	}	while (ch != 'n');
}