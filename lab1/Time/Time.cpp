#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int h, m, hp;
	do {
		cout << "Введите час не превышая 23 и не меньше 0: ";		cin >> h;
	} while (h < 0 || h >= 24);
	do {
		cout << "Введите минуты не превышая 59 и не меньше 0: ";	cin >> m;
	} while (m < 0 || m >= 60);
	if (h == 12 && m == 0)	{ cout << "полдень"; exit(0); }
	if (h == 0 && m == 0)	{ cout << "полночь"; exit(0); }
	hp = h;
	if (h > 12) h -= 12;
	if (h >= 2 && h <= 4) cout << h << " часа ";
	else if (h >= 5 && h <= 12 || h == 0) cout << h << " часов ";
	else if (h == 1) cout << h << " час ";
	if (m != 0) {
		if (m % 10 == 1 && m != 11) cout << m << " минута ";
		else if ((m >= 2 && m <= 4) || (m >= 22 && m <= 24) || (m >= 32 && m <= 34) || (m >= 42 && m <= 44) || (m >= 52 && m <= 54)) cout << m << " минуты ";
		else cout << m << " минут ";
	}
	if (hp >= 5 && hp < 12) cout << "утра";
	else if (hp >= 12 && hp < 18) cout << "дня";
	else if (hp >= 18 && hp <= 23) cout << "вечера";
	else if (hp >= 0 && hp < 5) cout << "ночи";
	if (m == 0) cout << " ровно";
	cout << endl;
	system("pause");
	return 0;
}