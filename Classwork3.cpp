#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер матрицы" << endl;
	cin >> n;
	int**mas = new int* [n];
	for (int i = 0; i < n; ++i)
		mas[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Заполните матрицу ";
			cin >> mas[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas[i][j] << " \t";
		}
		cout << endl;
	}
	for (int j = 0; j < n; j++)
	{
		int sum1 = 0;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			sum1 += mas[i][j];
			if (mas[i][j] < 0) { flag = false; }
		}
		if (flag == true)

		{
			cout << "Сумма " << " в столбце " << j + 1 << " = " << sum1<<endl;
		}
	}
		int summin;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j <= i; j++)
			{
				sum += abs(mas[i - j][j]);
				if ((i == 0) || (summin > sum))summin = sum;
			}
		}
		for (int i = 1; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n - i; j++)sum += abs(mas[i + j][n - i - j]);
			if (summin > sum)summin = sum;
		}
		cout << "Минимум среди сумм модулей элементов диагоналей параллельных побочной диагонали матрицы = "<<summin;

	
	return 0;
}

