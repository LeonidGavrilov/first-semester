// HomeWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int getSize(unsigned char* arr) {
	int size = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		size++;
	}
	return size;
}

void showArr(unsigned char* arr) {
	for (int j = 0; arr[j] != '\0'; j++) {
		cout << arr[j];
	}
	cout << endl;
}

unsigned char* getLastWord(unsigned char* arr) {
	int i, j = 0;
	unsigned char* word = new unsigned char[80];
	bool flag = false;
	int size = getSize(arr);
	for (i = size - 2; i >= 0; i--) {
		if (arr[i] == ' ') {
				break;
		}
		else
		{
			for (int k = j; k >= 0; k--) {
				word[k] = word[k - 1];
			}
			word[0] = arr[i];
			j++;
		}
	}
	word[j] = '\0';
	return word;
}

unsigned char* withoutLastWord(unsigned char* arr, unsigned char* lastWord) {
	int sizeWord = 0, sizeNewArr = 0;
	unsigned char* word = new unsigned char[80];
	unsigned char* newArr = new unsigned char[80];
	bool flag = false;
	int size = getSize(arr);
	int sizeOfLastWord = getSize(lastWord);
	for (int i = 0; i < size; i++) {
		if ((arr[i] == ' ') || (arr[i] == '.')) {
			word[sizeWord + 1] = '\0';
			if (sizeWord == sizeOfLastWord) {
				for (int ii = 0; ii < sizeWord; ii++) {
					if (word[ii] == lastWord[ii]) {
						flag = true;
					}
					else {
						flag = false;
						break;
					}
				}
				if (flag == false) {
					if (sizeNewArr > 0) {
						newArr[sizeNewArr] = ' ';
						sizeNewArr++;
					}
					for (int ii = 0; ii < sizeWord; ii++) {
						newArr[sizeNewArr] = word[ii];
						sizeNewArr++;
					}
				}
			}
			else {	//Сюда заходим, если временное слово не равно последнему
				if (sizeNewArr > 0) {	//Если слово не первое, то перед ним пишем пробел 
					newArr[sizeNewArr] = ' ';
					sizeNewArr++;
				}
				for (int ii = 0; ii < sizeWord; ii++) {	//Записывыем в новый массив прочитанное слово
					newArr[sizeNewArr] = word[ii];
					sizeNewArr++;	//Размер массива, теперь равен размеру слов и пробелов
				}
			}
			sizeWord = 0;
		}
		else
		{
			word[sizeWord] = arr[i];	//Временно, поэлементно записываем слова в массив word
			sizeWord++;	//Размер временного слова
		}
	}
	newArr[sizeNewArr] = '.';
	sizeNewArr++;
	newArr[sizeNewArr] = '\0';
	return newArr;
}

unsigned char* withoutDoubleLetters(unsigned char* arr) {
	int j = 0, sizeNewArr = 0;
	unsigned char* word = new unsigned char[40];
	unsigned char* newArr = new unsigned char[40];
	bool flag = false;
	int size = getSize(arr);
	for (int i = 0; i < size; i++) {
		flag = false;
		if (arr[i] == ' ') {
			for (int ii = 0; word[ii] != '\0'; ii++) {
				newArr[sizeNewArr] = word[ii];
				sizeNewArr++;
			}
			j = 0;
			newArr[sizeNewArr] = ' ';
			sizeNewArr++;
			newArr[sizeNewArr] = '\0';
		}
		else if (arr[i] == '.') {
			cout << endl;
			for (int ii = 0; word[ii] != '\0'; ii++) {
				newArr[sizeNewArr] = word[ii];
				sizeNewArr++;
			}
			j = 0;
			newArr[sizeNewArr] = '.';
			sizeNewArr++;
			newArr[sizeNewArr] = '\0';
		}
		else
		{
			if (j > 0) {
				for (int ii = 0; word[ii] != '\0'; ii++) {
					if (word[ii] == arr[i]) {
						flag = true;
						break;
					}
				}
			}
			if (flag == false) {
				word[j] = arr[i];
				j++;
				word[j] = '\0';
			}
		}
	}
	return newArr;
}

int main()
{
	unsigned char* arr = new unsigned char[240];
	char a = 's';
	cout << "Please, enter value for string: ";
	bool flag = false;
	int i = 0;
	while (cin.get(a)) {
		if ((a == ' ') && (flag == true))
		{
			flag = false;
			arr[i] = ' ';
			i++;
		}
		else if ((a == ' ') && (flag == false)) {
			continue;
		}
		else if ((int(a) > 96) && (int(a) < 123))
		{
			flag = true;
			arr[i] = a;
			i++;
		}
		else if ((int(a) > 64) && (int(a) < 91))
		{
			flag = true;
			arr[i] = int(a) + 32;
			i++;
		}
		else {
			if (a == '.') {
				if (flag == false) {
					if (i > 0) {
						i--;
					}
				}
				arr[i] = a;
				i++;
				break;
			}
			else if (flag == true)
			{
				flag = false;
			}
		}
	}
	arr[i] = '\0';	//Символ окончания строки
	showArr(arr);	//Показывает введённый текст - массив arr
	unsigned char* lastWord = new unsigned char[80];
	lastWord = getLastWord(arr);	//Получает последнее слово текста и записывает в массив lastWord
	showArr(lastWord);	//Показывает последнее слово
	cout << getSize(lastWord) << endl;	//Возвращаем размер массива
	if (getSize(withoutLastWord(arr, lastWord)) > 1) {
		arr = withoutLastWord(arr, lastWord);	//Возвращает массив без последнего слова
		showArr(arr);
		arr = withoutDoubleLetters(arr);
		showArr(arr);
	}
	else
	{
		cout << "The string is empty!!!";
	}
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
