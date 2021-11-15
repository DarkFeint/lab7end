// ААААААААА.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;


void ReadCount(int& n, int& m)
{
	ifstream fin0("input0.txt");

	fin0 >> n;

	fin0 >> m;

}

void ReadMatrix(int n, int m, int** mat)
{
	ifstream fin("input.txt");


	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[m];

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fin >> mat[i][j];
		}

	}


}

void FindSumPillar(int n, int m, int** mat, int* sum)
{
	for (int j = 0; j < m; j++)
	{

		for (int i = 0; i < n; i++)
		{
			sum[j] += mat[i][j];
		}

	}

}

void MinSum(int* sum, int& f, int& min, int m)
{
	 min = sum[0];

	for (int j = 0; j < m; j++)
	{
		if (sum[j] < min)
		{
			min = sum[j];

			f = j;

		}

	}

	delete[] sum;


}

void FuncPlus3(int** mat, int n, int m, int f)
{
	for (int i = 0; i < n; i++)
	{

		mat[i][f] += 3;

	}

}

void WriteFile(int n, int m, int** mat)
{

	ofstream fout("output.txt");

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{

			fout << mat[i][j] << " ";

		}

		fout << endl;

		//delete[] mat[i];
	}

	//delete[] mat;

	fout.close();

}

int main()
{

	int n;

	int f = 0;

	int m;

	int min = 0;

	ReadCount(n, m);

	int* sum = new int[m];

	int** mat = new int* [n];

	ReadMatrix(n, m, mat);

	FindSumPillar(n, m, mat, sum);

	MinSum(sum, f, min, m);

	FuncPlus3(mat, n, m, f);

	WriteFile(n, m, mat);

	for (int i = 0; i < n; i++)
	{

		delete[] mat[i];
	}

	delete[] mat;

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
