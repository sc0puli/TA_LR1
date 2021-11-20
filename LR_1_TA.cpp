//#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <Windows.h>
#include <intrin.h>

using namespace std; 

void phi_less_3(int phi[100], int phi_num, int phi_max)
{
	cout << endl << "Вывод чисел: ";

	for (int i = 0; i < phi_num; i++)
	{
		cout << phi[i] << " ";
	}

	if (phi_max < phi_num)
		{
			phi_max = phi_num;
		}

	cout << endl; 
}

long long phi_calc(int phi[100], int phi_num, int pn_prev, long long newphi_start, long long newphi_end, long long newphi_res)
{
	
		newphi_start = __rdtsc();

	for (int i = pn_prev; i < phi_num; i++)
	{
		phi[i] = phi[i - 1] + phi[i - 2];		
	}

		newphi_end = __rdtsc(); 
		newphi_res = newphi_end - newphi_start;
		
	
	return newphi_res; 
}

void phi_print(int phi[100], int phi_num, int pn_prev, int phi_max, long long newphi_res)
{
	cout << endl << "Вывод чисел: ";

	if (pn_prev == 0)
	{

		if (phi_max < phi_num)
		{
			phi_max = phi_num;
		}

		for (int i = 0; i < phi_num; i++)
		{
			cout << phi[i] << " ";
		}

		cout << endl << "Тактов для вычисления новых чисел: " << newphi_res;
	}

	if (pn_prev != 0)
	{ 

		if (phi_num > phi_max)
		{
			for (int i = 0; i < phi_max; i++)
			{
				cout << phi[i] << " ";
			}
		}
		else 
		{
			for (int i = 0; i < pn_prev; i++)
			{
				cout << phi[i] << " ";
			}
		}
		
		if (pn_prev <= phi_max)
		{
			cout << "Новые числа: ";
			for (int i = phi_max; i < phi_num; i++)
			{
				cout << phi[i] << " ";
			}
		}

		if (pn_prev > phi_max)
		{
			cout << "Новые числа: ";
			for (int i = phi_max; i < phi_num; i++)
			{
				cout << phi[i] << " ";
			}
		}

		cout << endl << "Тактов для вычисления новых чисел: " << newphi_res;
	}

	cout << endl; 
}

int main()
{
	setlocale(LC_ALL, "Rus");

	long long alltime_start = 0, alltime_end = 0;
	long long newphi_start = 0, newphi_end = 0, newphi_res = 0;
	int phi[100]; 
	long phi_num = 0;
	int pn_prev = 0; 
	int phi_max = 0;
	int count = 0;
	phi[0] = 0;
	phi[1] = 1;
	phi[2] = 1;

	alltime_start = GetTickCount64();

	cout << "Введите количество выводимых чисел Фибоначчи: ";
	cin >> phi_num;
	if (phi_num < 0)
	{
		cout << endl << "Введено недопустимое значение.";
		cout << endl << "Введите количество выводимых чисел Фибоначчи: ";
		cin >> phi_num;
	}

	do
	{
		if ((phi_num < 3)&&(pn_prev==0))
			{
				phi_less_3(phi, phi_num, phi_max);
				count++;
			}

		if ((phi_num >= 3)&&(pn_prev==0))
			{
				newphi_res = phi_calc(phi, phi_num, 3, newphi_start, newphi_end, newphi_res);
				phi_print(phi, phi_num, pn_prev, phi_max, newphi_res);
				count++;
			}

		if ((pn_prev != 0)&&(count != 0))
			{
				newphi_res = phi_calc(phi, phi_num, pn_prev, newphi_start, newphi_end, newphi_res);
				phi_print(phi, phi_num, pn_prev, phi_max, newphi_res);
			}

		if (phi_max < phi_num)
		{
			phi_max = phi_num;
		}
		cout << endl << "Введите количество выводимых чисел Фибоначчи: ";
		pn_prev = phi_num;
		cin >> phi_num;

		if (pn_prev > phi_num)
		{
			pn_prev = phi_num; 
		}

		if (phi_num < 0)
			{
				cout << endl << "Введено недопустимое значение."; 
				cout << endl << "Введите количество выводимых чисел Фибоначчи: ";
				cin >> phi_num;
			}

	} while (phi_num != 0);

	alltime_end = GetTickCount64();
	cout << endl << "Время выполнения процесса: " << (alltime_end - alltime_start) / 1000 << " секунд";
	return 0;
}