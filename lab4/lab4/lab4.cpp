// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
float f(float x)
{
	return x - cos(x);
}
float f1(float x)
{
	return cos(x);
}
float f2(float x)
{
	return 1 + sin(x);
}

int main()
{
	setlocale(LC_ALL, "Ru");
	float a = 0, b = 2, c = 0, k = 0; //Способ 1
	while (b - a > 1e-6) {
		k++;
		c = (a + b) / 2;
		if (f(a) * f(c) < 0) {
			b = c;
		}
		else
		{
			a = c;
			c = (a + b) / 2;
		}
	}
	cout << c << " "<< k << endl;

	float x1 = 1000000, x2 = f1(x1), r = 0; //Способ 2
	while (abs(x1 - x2) > 1e-6)
	{
		x1 = x2;
		x2 = f1(x1);
		r++;
	}
	cout << x1 << " " << r << endl;

	float x0 = 1000000, x3 = x0 - f(x0) / f2(x0), t = 0; //Способ 3
	while (abs(x0 - x3) > 1e-6) {
		x0 = x3;
		x3 = x0 - f(x0) / f2(x0);
		t++;
	}
	cout << x3 << " " << t;

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
