#include <iostream>
#include <vector>

using namespace std;

void enterTable(int rowAmount, int columnAmount, vector <vector <double>>& indexArr);

int main()
{
	int aIndAmount = 0; // количество индексов a
	int rowAmount = 0; // количество строк
	int columnAmount = 0; // количество столбцов
	double firstC = 0;

	cout << ">> Enter the number of monomials: " << endl;
	cin >> aIndAmount;

	rowAmount = aIndAmount + 1;
	columnAmount = aIndAmount / 2 + aIndAmount % 2;

	vector <double> rCoefs(rowAmount - 2); // массив для r
	vector <vector <double>> indexArr(rowAmount, vector <double>(columnAmount + 1)); // двумерный массив для c[i][j]

	enterTable(rowAmount, columnAmount, indexArr); // ввести четные и нечетные элементы уравнения

	for (int i = 2; i < rowAmount; i++)
	{
		rCoefs[i - 2] = indexArr[i - 2][0] / indexArr[i - 1][0];
		for (int j = 0; j < columnAmount; j++)
		{
			indexArr[i][j] = indexArr[i - 2][j + 1] - rCoefs[i - 2] * indexArr[i - 1][j + 1];
		}
	}

	firstC = indexArr[0][0];
	for (int i = 1; i < rowAmount; i++)
	{
		if (!(firstC >= 0 && indexArr[i][0] >= 0) || (firstC < 0 && indexArr[i][0] < 0))
		{
			cout << ">> System is unstable!" << endl;
			return 0;
		}
	}
	cout << ">> System is stable!" << endl;
	return 0;
}

void enterTable(int rowAmount, int columnAmount, vector <vector <double>>& indexArr)
{
	cout << ">> Enter the table (2x" << columnAmount << "), in the first even indices, in the second odd indices." << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < columnAmount; j++)
		{
			cin >> indexArr[i][j];
		}
	}
}