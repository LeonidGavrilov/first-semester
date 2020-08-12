// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <iostream> 
#include <string> 
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int size = 0, sizek = 0, sizet = 0, sum = 0, slova = 0, l = 0, codT;
	char st, sk;
	//Ключ 
	ifstream textk("D:\\ВУЗ\\lab7\\lab7\\key.txt");
	while (!textk.eof())
	{
		textk.get(sk);
		sizek++;
		if (sk == ' ')
			slova++;
	}
	textk.close();
	ifstream textk1("D:\\ВУЗ\\lab7\\lab7\\key.txt");
	char *mask1 = new char[sizek];
	int *mask = new int[slova + 1];
	for (int i = 0; i < slova + 1; i++)
		mask[i] = 0;
	for (int i = 0; i < sizek - 1; i++) {//Ключ 
		textk1.get(mask1[i]);
		if (mask1[i] != ' ')
			mask[l] += int(mask1[i]);
		else {
			mask[l] %= 256;
			l++;
		}
	}
	mask[l] %= 256;
	textk1.close();
	ofstream tk("D:\\ВУЗ\\lab7\\lab7\\shifr.txt");
	for (int i = 0; i < slova + 1; i++)
		tk << mask[i] << " ";
	//Шифруем текст 
	char ch;
	fstream text, iText, TextDecoder;
	text.open("D:\\ВУЗ\\lab7\\lab7\\Text.txt");
	iText.open("D:\\ВУЗ\\lab7\\lab7\\iText.txt", fstream::in | fstream::out | fstream::binary | fstream::trunc);
	TextDecoder.open("D:\\ВУЗ\\lab7\\lab7\\TextDecoder.txt", fstream::out | fstream::trunc);

	int i = 0;
	char q;
	while (text.get(ch)) {
		iText.put(ch + mask[++i%l]);
	}

	iText.seekg(0, ios::beg);         
	int k = 0;
	while (iText.get(ch))
		TextDecoder.put(ch - mask[++k%l]);
	text.close();
	TextDecoder.close();
	iText.close();
	////////////////////////////////////////////
	//Статистика
	////////////////////////////////////////////
	int arr[256][256] = { 0 };
	for (int n = 0; n < 256; n++)
		for (int m = 0; m < 256; m++)
			arr[n][m] = 0;
	/*text.open("D:\\ВУЗ\\lab7\\lab7\\Text.txt");
	iText.open("D:\\ВУЗ\\lab7_1\\lab7\\iText.txt");*/
	//text.open("D:\\ВУЗ\\lab7\\lab7\\Text.txt");
	//iText.open("D:\\ВУЗ\\lab7_1\\lab7\\iText.txt", fstream::in | fstream::out | fstream::binary | fstream::trunc);
	while (!text.eof())
	{
		char f = text.get();
		char q = iText.get();
		arr[int(f)][int(q)]++;
		/*text.get(st);
		sizet++;*/
	}
	/*for (int p = 0; p < sizet; p++) {
		unsigned char q = text.get(), w = iText.get();
		arr[int(q)][int(w)]++;
	}*/
	for (int n = 0; n < 256; n++) {
		for (int m = 0; m < 256; m++) {
			if (arr[n][m] != 0)
				cout << "Bukva " << char(n) << "codiruetsy codom " << char(m) <<"raz:" << arr[n][m] << endl;
		}
	}


	/*int len; unsigned char s; char ch;
	fstream text, iText, TextDecoder;
	text.open("D:\\ВУЗ\\lab7\\lab7\\Text.txt");
	iText.open("D:\\ВУЗ\\lab7\\lab7\\iText.txt");
	TextDecoder.open("D:\\ВУЗ\\lab7\\lab7\\TextDecoder.txt");
	text.seekg(0, ios::end);
	len = text.tellg();
	text.seekg(0, ios::beg);
	for (int i = 0; i < len; i++) {
		text.get(ch);
		iText.put(char((mask[i % l] + int(ch)) % 256));
	}
	text.close();
	iText.seekg(0, ios::beg);
	for (int i = 0; i < len; i++) {
		iText.get(ch);
		TextDecoder.put(char(int(ch) - mask[i % l]));
	}
	TextDecoder.close();
	iText.close();*/
	delete[] mask;
	delete[] mask1;
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
