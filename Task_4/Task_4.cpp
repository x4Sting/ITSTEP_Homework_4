#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

int arr[SIZE]{ 0 };

int main()
{
	// Number of digits in sequence and protection

	int num;
	do
	{
		system("cls");
		cout << "Input the number of integer elements: ";
		cin >> num;
	} while (num <= 0);

	// Random input

	/*
	srand(time(0));
	cout << "Random sequence: ";
	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 200 - 100;
		cout << arr[i] << "  ";
	}
	*/

	// Manual input

	cout << "Input a sequence of integer numbers:\n";
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	// Maximum element index

	int maxIndex = 0;

	for (int i = 1; i < num; i++)
	{
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}

	string strMaxI = to_string(maxIndex + 1);

	for (int i = maxIndex + 1; i < num; i++)
	{
		if (arr[i] == arr[maxIndex])
		{
			strMaxI += " and " + to_string(i + 1);
		}
	}
	// Product of vector elements located between first and second zero elements: 

	int firstZeroI = -1;
	int secondZero = -1;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == 0)
		{
			firstZeroI = i;
			break;
		}
	}
	for (int i = firstZeroI + 1; i < num && firstZeroI != -1; i++)
	{
		if (arr[i] == 0)
		{
			secondZero = i;
			break;
		}
	}

	string strProduct = "Error!!! There are no zeros.";

	if (secondZero != -1)
	{
		int product = 1;

		for (int i = firstZeroI + 1; i < secondZero; i++)
		{
			product *= arr[i];
		}
		strProduct = to_string(product);
	}
	else if (firstZeroI != -1)
	{
		strProduct = "Error!!! Only one zero";
	}

	// Answer

	string answer = "\nMaximum element index: "	+ strMaxI
		+ "\nProduct of vector elements located between"
		" first and second zero elements: " + strProduct;

	cout << answer << endl;

	system("pause");
	return 0;
}