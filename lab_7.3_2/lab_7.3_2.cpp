// lab_7.3_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** y, const int n, const int Low, const int High, int i, int j)
{
	y[i][j] = Low + rand() % (High - Low + 1);

	if (j < n - 1)
		Create(y, n, Low, High, i, j + 1);
	else
		if (i < n - 1)
			Create(y, n, Low, High, i + 1, 0);
}
void Print(int** y, const int n, int i, int j)
{
	cout << setw(4) << y[i][j];
	if (j < n - 1)
		Print(y, n, i, j + 1);
	else
		if (i < n - 1)
		{
			cout << endl;
			Print(y, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}
int Nulls(int** arr, const int colcount, const int rowcount, int i, int j)
{
	int k = 0;
	cout << setw(4) << arr[i][j];
	if (i < colcount - 1)
		Nulls(arr, colcount, rowcount, j, i + 1);
	else
	 if (j < colcount - 1)
		Nulls(arr, colcount, rowcount, i, j + 1);
	{
		if (arr[i][j] == 0)
				k++;
	}
	return k;
}
void Long(int** b, const int colcount, const int rowcount)
{
	int maxRow = 0;
	int prevElement = 0;
	int maxSequence = 0;
	int i = 0;

	if ( i < rowcount)
	{
		prevElement = b[i][0];
		int itr = 0;
		int maxSequenceInRow = 1;
		int j = 1;
		if ( j < colcount)
		{
			if (prevElement == b[i][j])
			{
				itr++;
				if (maxSequenceInRow < itr)
				{
					maxSequenceInRow = itr;
				}
			}
			else
			{
				itr = 0;
				prevElement = b[i][j];
			}
		}

		if (maxSequenceInRow > maxSequence)
		{
			maxSequence = itr;
			maxRow = i;
		}
	}
	cout << "Row with max sequence - " << maxRow + 1;
}
	int main()
	{
		srand((unsigned)time(NULL));
		int Low = -1;
		int High = 3;
		int n = 5;
		int** y = new int* [n];
		for (int i = 0; i < n; i++)
			y[i] = new int[n];
		Create(y, n, Low, High, 0, 0);
		Print(y, n, 0, 0);
		cout << Nulls(y, n, 0, 0, 0) << endl;
	}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
