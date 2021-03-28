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

	// Product of vector elements with even numbers

	int product = 1;

	for (int i = 1; i < num; i += 2)
	{
		product *= arr[i];
	}
	string strProduct = to_string(product);

	//Sum of vector elements located between the first and last zero elements: 

	int firstZeroI, lastZeroI;
	firstZeroI = lastZeroI = -1;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == 0)
		{
			firstZeroI = i;
			break;
		}
	}
	for (int i = num - 1; i >= 0; i--)
	{
		if (arr[i] == 0)
		{
			lastZeroI = i;
			break;
		}
	}

	int sum = 0;

	if (firstZeroI != lastZeroI || firstZeroI != -1)
	{
		for (int i = firstZeroI + 1; i < lastZeroI; i++)
		{
			sum += arr[i];
		}
	}

	string strSum = to_string(sum);
	
	// Answer
	
	string answer = "\nProduct of vector elements with even numbers: "
		+ strProduct + "\nSum of vector elements located between"
		"the first and last zero elements: " + strSum;

	cout << answer << endl;

	system("pause");
	return 0;
}