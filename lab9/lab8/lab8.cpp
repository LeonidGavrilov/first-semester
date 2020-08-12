// lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double m = 20, n = 20;
	double** matrix = new double*[m];
	//double matrix[15][15];
	int k;
	cout << "Введите n - кол-во строк и столбцов: ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		matrix[i] = new double[n];
		matrix[1] = new double[n];
		for (int j = 0; j < k; j++)
		{
			matrix[0][j] = 1;
			matrix[i][0] = 1;
			matrix[1][j] = 1;
		}
	}
	for (int i = 2; i < k; i++)
	{
		matrix[i][1] = matrix[i - 1][1] / i;
		for (int j = 2; j < k; j++)
		{
			matrix[i][j] = matrix[i][j - 1] * matrix[i][1];
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << left << setw(81 / k) << scientific << setprecision(81 / k - 8) << showpoint << matrix[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < k; i++)
	{
		delete matrix[i];
		matrix[i] = NULL;
	}
	delete[] matrix;
	system("pause");
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
