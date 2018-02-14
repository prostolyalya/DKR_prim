#include "stdafx.h"
#include "MetodSimpsona.h"
#include "windows.h" //Необхідно для використання функцій SetConsoleCP() та SetConsoleOutputCP()
#include <iostream> //Бібліотека вводу/виводу
using std::ofstream; using std::cout; using std::cin; using std::endl;
int main()
{
	SetConsoleCP(1251); //Необхідно для виведення в консолі української мови
	SetConsoleOutputCP(1251); //Необхідно для виведення в консолі української мови
	float a, b, eps; char txt;
	while (true)
	{
		cout << "Розрхунок інтеграла I(x є [a,b]) = ln(x^2 + 0.9)dx/(x-1) методом сімпсо-на:" << endl;
		cout << "Вводити всі вхідні данні? [y]/[n]  "; cin >> txt;
		cout << "Введінть нижню межу інтегрування: а = "; cin >> a; //Введення нижньої межі інтегрування 'a'
		do //Цикл перевірки правильності вводу верхньої межі інтегрування 'b'
		{
			cout << "Введінть верхню межу інтегрування (b > a): b = "; cin >> b; //Введення верхньої межі інтегрування 'b'
			if (b <= a) { cout << "Верхня межа інтегрування менше або дорівнює нижній (b <= a)!" << endl; }
		} while (b <= a);
		if (txt == 'y') //Перевірка умови на вивід проміжних розрахунків
		{
			do //Цикл перевірки правильності вводу точності розрахунків 'eps'
			{
				cout << "Введіть точність розрахунків (eps > 0): eps = "; cin >> eps; //Введення точності розрахунків 'eps'
				if (eps <= 0) { cout << "Tочність розрахунків задано не вірно (eps <= 0)!" << endl; }
			} while (eps <= 0);
			cout << endl;
			MetodSimpsona Rozrahynok(a, b, eps); //Передача всіх введених даних користу-вачем
			Rozrahynok.Metod(); //Клас без параметрів
		}
		else
		{
			MetodSimpsona Rozrahynok(a, b); //Передача введених даних інтервалу інте-грування
			Rozrahynok.Metod(); //Клас без параметрів
		}
		cout << endl << "Запустити розрахунок ще раз? [y]/[n]  "; cin >> txt; cout << endl;
		if (txt == 'n')
		{
			break;
		}
	}
	return 0;
