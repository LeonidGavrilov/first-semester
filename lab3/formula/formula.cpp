// formula.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	long double sum = 0, m = 3, n = 1, m2, m3;
	for (; m > pow(10, -5); n++) {
		m2 = n + n;
		m3 = m2 + n;
		m = m / 3 * (m2 + 2) * (m2 + 3) / (m3 + 1) / (m3 + 2);
		sum += m;
		if ((n == 2) || (n == 5) || (n == 8))
			cout <<"Сумма "<< sum << " Частичные сумма при n = " << n << ", равно " << m << endl;
	}
	cout << "Сумма " << sum << " Наименьшая сумма при  n =  " << n << ", равно " << m << endl;
	/*do {
		m2 = n + n;
		m3 = m2 + n;
		m = m / 3 * (m2 + 2) * (m2 + 3) / (m3 + 1) / (m3 + 2);
		sum += m;
		if ((n == 2) || (n == 5) || (n == 8))
			cout << "Сумма " << sum << " Наименьшая сумма при  n =  " << n << ", равно " << m << endl;;
		n++;
	}while (m > pow(10, -5));
	cout << "Сумма " << sum << " Наименьшая сумма при  n =  " << n << ", равно " << m << endl;*/
	/*while (m > pow(10, -5)) {
		m2 = n + n;
		m3 = m2 + n;
		m = m/3 * (m2 + 2) * (m2+ 3) / (m3 + 1) / (m3 + 2);
		sum += m;
		if ((n == 2) || (n == 5) || (n == 8))
			cout << "Сумма " << sum << " Наименьшая сумма при  n =  " << n << ", равно " << m << endl;;
		n++;
	}
	cout << "Сумма " << sum << " Наименьшая сумма при  n =  " << n << ", равно " << m << endl;*/
	
	return 0;
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
