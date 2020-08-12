// lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
// Вычисление интегралов различных функций методами прямугольников и трапеций
#include <iostream>
#include <cmath>
#include <iomanip>

#define MAX_EPS 5 //Приближение
#define N_DEFAULT 2
#define N_MULTIPLIFIER 2

#define A -2
#define B 3

//Режим
#define MODE 0

typedef double(*TPF)(double);
typedef double(*EXF)(double, double);

using namespace std;

struct I_print {	//данные для печати результатов интегрирования
	const char* name;//название функции
	double i_sum;	//значение интегральной суммы
	double i_toch;	//точное значение интеграла
	int n;	//число разбиений области интегрирования 
			//при котором достигнута требуемая точность
};


double f1(double); //x
double f2(double); //sin(22x)
double f3(double); //x^4
double f4(double); //arctg(x)

double ex1(double a, double b); //Точный интеграл x
double ex2(double a, double b); //Точный интеграл sin(22x)
double ex3(double a, double b); //Точный интеграл x^4
double ex4(double a, double b); //Точный интеграл arctg(x)

double IntRect(TPF f, double a, double b, double eps, int& n); //Метод прямоугольника
void PrintTabl(I_print i_prn[], int k); //Печать таблицы

int main()
{
	system("color f0");

	const TPF f[] = { f1, f2, f3, f4 };
	const EXF ex[] = { ex1, ex2, ex3, ex4 };
	int size = 4;
	I_print print_data[4];

	print_data[0].name = "y=x       ";
	print_data[1].name = "y=sin(22x)";
	print_data[2].name = "y=x^4     ";
	print_data[3].name = "y=arctg(x)";

	const double eps[] = { 0.01, 0.001, 0.0001, 0.00001, 0.000001 };
	double a = A;
	double b = B;
	int n;
	double dx;

	cout << setprecision(10);

	cout << "a = " << a << ", b = " << b << endl;
	for (int j = 0; j < MAX_EPS; j++)
	{
		cout << "eps = " << eps[j] << endl;
		for (int i = 0; i < 4; i++)
		{
			if (MODE == 0) print_data[i].i_sum = IntRect(f[i], a, b, eps[j], n);
			print_data[i].i_toch = ex[i](a, b);
			print_data[i].n = n;
		}
		PrintTabl(print_data, size);
		cout << "\n";
	}
	return 0;
}

double IntRect(TPF f, double a, double b, double eps, int& n)
{
	double s = 0;
	double s1 = 0;
	double dx;
	double prev_s;
	n = N_DEFAULT;

	dx = abs(a - b) / double(n / 2);

	for (double x = a; x < b; x += dx)
	{
		s += f(x + dx / 2);
	}

	do
	{
		prev_s = s;
		s = 0;
		s1 = 0;
		dx = abs(a - b) / double(n);
		for (double x = a; x < b; x += dx)
		{
			s += f(x + dx / 2);
			s1 += f(x + dx);
		}
		n *= N_MULTIPLIFIER;
	} while (abs(s * dx - prev_s * 2 * dx) / 3.0 >= eps);

	return s * dx;
}

void PrintTabl(I_print i_prn[], int k)
{
	const int m = 4;//число столбцов таблицы
	int wn[m] = { 12,18,18,11 };//ширина столбцов таблицы
	const char *title[m] = { "Function","Integral","IntSum","N  " };
	int size[m];
	for (int i = 0; i < m; i++)
		size[i] = strlen(title[i]);
	//шапка таблицы
	cout << char(218) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(194);
	cout << setw(wn[m - 1]) << char(191) << endl;

	cout << char(179);
	for (int j = 0; j < m; j++)
		cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j]
		<< setw((wn[j] - size[j]) / 2) << char(179);
	cout << endl;

	for (int i = 0; i < k; i++)
	{//заполнение таблицы
		cout << char(195) << fixed;
		for (int j = 0; j < m - 1; j++)
			cout << setfill(char(196)) << setw(wn[j]) << char(197);
		cout << setw(wn[m - 1]) << char(180) << setfill(' ') << endl;

		cout << char(179) << setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' ' << i_prn[i].name
			<< setw((wn[0] - strlen(i_prn[i].name)) / 2) << char(179);
		cout << setw(wn[1] - 1) << setprecision(10) << i_prn[i].i_toch << char(179)
			<< setw(wn[2] - 1) << i_prn[i].i_sum << setprecision(6) << char(179)
			<< setw(wn[3] - 1) << i_prn[i].n << char(179) << endl;
	}
	//низ таблицы
	cout << char(192) << setfill(char(196));
	for (int j = 0; j < m - 1; j++)
		cout << setw(wn[j]) << char(193);
	cout << setw(wn[m - 1]) << char(217) << setfill(' ') << endl;
}


double ex1(double a, double b)
{
	return (b * b - a * a) / 2;
}

double ex2(double a, double b)
{
	return (cos(22.0 * a) - cos(22.0 * b)) / 22.0;
}

double ex3(double a, double b)
{
	return (b * b * b * b * b - a * a * a * a * a) / 5.0;
}

double ex4(double a, double b)
{
	return b * atan(b) - a * atan(a) - (log(b*b + 1) - log(a*a + 1)) / 2.0;
}

double f1(double x)
{
	return x;
}

double f2(double x)
{
	return sin(22 * x);
}

double f3(double x)
{
	return x * x * x * x;
}

double f4(double x)
{
	return atan(x);
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
