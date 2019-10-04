#include <iostream>
#include <vector>

using namespace std;

void enterTable(int rowAmount, int columnAmount, vector <vector <double>>& indexArr);
void printTable(int rowAmount, int columnAmount, vector <vector <double>>& indexArr);

int main()
{
	int aIndAmount = 0; // количество индексов a
	int rowAmount = 0; // количество строк
	int columnAmount = 0; // количество столбцов

	cout << ">> Enter the number of monomials: " << endl;
	cin >> aIndAmount;

	rowAmount = aIndAmount + 1;
	columnAmount = aIndAmount / 2 + aIndAmount % 2;

	vector <double> rCoefs(rowAmount - 2); // массив для r
	vector <vector <double>> indexArr(rowAmount, vector <double> (columnAmount)); // двумерный массив для c[i][j]

	enterTable(rowAmount, columnAmount, indexArr); // ввести четные и нечетные элементы уравнения
	printTable(rowAmount, columnAmount, indexArr); // по сути бесполезная функция, делал для проверки
	// Дальше расчеты по формулам
	return 0;
}

void enterTable(int rowAmount, int columnAmount, vector <vector <double>>& indexArr)
{
	cout << ">> Enter the table (2x" << columnAmount << "), in the first even indices, in the second odd indices." << endl;
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < columnAmount; j++)
		{
			cin >> indexArr[i][j];
		}
	}
}

void printTable(int rowAmount, int columnAmount, vector <vector <double>>& indexArr)
{
	cout << endl << "You entered: " << endl;
	for (size_t i = 0; i < rowAmount; i++)
	{
		for (size_t j = 0; j < columnAmount; j++)
		{
			cout << indexArr[i][j] << " ";
		}
		cout << endl;
	}
}