#include <iostream>
#include <string>
#include <math.h>
#include <clocale>
#include <cstdlib>

using namespace std;

// ����� ���� �������
char choiceTypeAll()
{
	cout << "�������� ��� �������: \n1) �������� �������\n2) ������������ �������\n3) ������-�������� �������" << endl;
	char functType = 0;
	cin >> functType;
	return functType;
}

// �������� �������
//=================================================================================================================================

// ��� �������� ������� 
char choiceTypeLinear()
{
	cout << "\n�������� ��� �������� �������:\n1) y = mx + n\n2) y = mx" << endl;
	char linearFunctType = 0;
	cin >> linearFunctType;
	return linearFunctType;
}

// ����������� ����������� m
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

// ���� � ��������� �������� ������

// 1 ���
double* linearType1()
{
	cout << "������� ������� ����� �������: ";
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

// 2 ���
double* linearType2()
{
	cout << "������� ������� ����� �������: ";
	char symbolY = 0, symbolEqual = 0;
	string m_x;
	cin >> symbolY >> symbolEqual >> m_x;
	double num_m = linearM(m_x);
	double m_n[2] = { num_m };
	return m_n;
}

// �������� ������� - ��������� ���������
void linearFinale(double* arrM_N)
{
	double m = arrM_N[0];
	double n = arrM_N[1];
	cout << "������� �������� x: ";
	double x;
	cin >> x;
	double y = m * x + n;
	cout << "f(" << x << ") = " << y << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "���������� ������� �����. � ��� ����. � ��� ������ ��� ������ � ��������������� ����������." << endl;
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