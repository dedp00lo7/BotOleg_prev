#include <iostream>
#include <string>
#include <math.h>
#include <clocale>
#include <cstdlib>

using namespace std;

// Выбор типа функции
char choiceTypeAll()
{
	cout << "Выберите тип функции: \n1) Линейная функция\n2) Квадратичная функция\n3) Дробно-линейная функция" << endl;
	char functType = 0;
	cin >> functType;
	return functType;
}

// Линейная функция
//=================================================================================================================================

// Тип линейной функции 
char choiceTypeLinear()
{
	cout << "\nВыберите тип линейной функции:\n1) y = mx + n\n2) y = mx" << endl;
	char linearFunctType = 0;
	cin >> linearFunctType;
	return linearFunctType;
}

// Определение коефициента m
double linearM(string mx)
{
	if (mx.size() == 1)
	{
		return 1;
	}
	else if (mx.size() == 2 && mx[0] == '-')
	{
		return -1;
	}
	else
	{
		mx.pop_back();
		return atof(mx.c_str());
	}
}

// Ввод и обработка введённых данных

// 1 Тип
double* linearType1()
{
	cout << "Введите формулу вашей функции: ";
	char symbolY = 0, symbolEqual = 0;
	string m_x;
	char oper = 0;
	double coef_N;
	cin >> symbolY >> symbolEqual >> m_x >> oper >> coef_N;
	double m_num = linearM(m_x);
	if (oper == '-')
	{
		coef_N = -coef_N;
	}
	double m_n[2] = { m_num, coef_N };
	return m_n;
}

// 2 Тип
double* linearType2()
{
	cout << "Введите формулу вашей функции: ";
	char symbolY = 0, symbolEqual = 0;
	string m_x;
	cin >> symbolY >> symbolEqual >> m_x;
	double num_m = linearM(m_x);
	double m_n[2] = { num_m };
	return m_n;
}

// Линейная функция - финальный результат
void linearFinale(double* arrM_N)
{
	double m = arrM_N[0];
	double n = arrM_N[1];
	cout << "Введите значение x: ";
	double x;
	cin >> x;
	double y = m * x + n;
	cout << "f(" << x << ") = " << y << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Добрейшего времени суток. Я бот Олег. Я был создан для работы с математическими действиями." << endl;
	bool start = true;
	while (start)
	{
		if (choiceTypeAll() == '1')
		{
			if (choiceTypeLinear() == '1')
				linearFinale(linearType1());

			else if (choiceTypeLinear() == '2')
				linearFinale(linearType2());
		}
		start = false;
	}
	return 0;
}