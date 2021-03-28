#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

double arr[SIZE]{ 0 };

string castDoubleToStr(double value);

int main()
{
	// Number of digits in sequence and protection

	int num;
	do
	{
		system("cls");
		cout << "Input the number of real elements: ";
		cin >> num;
	} while (num <= 0);

	// Random input

	srand(time(0));
	cout << "Random sequence: ";
	for (int i = 0; i < num; i++)
	{
		arr[i] = (double(rand() % 2000) - 1000) / 10;
		cout << arr[i] << "  ";
	}

	// Manual input

	/*cout << "Input a sequence of numbers:\n" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}*/

	// Minimal vector element

	int minIndex = 0;
	for (int i = 1; i < num; i++)
	{
		if (arr[minIndex] > arr[i])
		{
			minIndex = i;
		}
	}

	string strMin = castDoubleToStr(arr[minIndex]);

	// Sum of the vector elements located between the first and last 
	// positive elements

	int firstPosI = -1;
	int lastPosI = -1;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > 0)
		{
			firstPosI = i;
			break;
		}
	}
	for (int i = num - 1; i >= 0; i++)
	{
		if (arr[i] > 0)
		{
			lastPosI = i;
			break;
		}
	}

	string strSum = "Error!!! No positive elements.";

	if (firstPosI != -1 && lastPosI != -1)
	{
		double sum = 0;
		for (int i = firstPosI + 1; i < lastPosI; i++)
		{
			sum += arr[i];
		}
		strSum = castDoubleToStr(sum);
	}
	else if (firstPosI == lastPosI)
	{
		strSum = "Error!!! Only one positive element";
	}
	
	// Answer

	string answer = "\nMinimal vector element: " + strMin
		+ "\nSum of the vector elements located between"
		" the first and last positive elements: " + strSum;

	cout << answer << endl;

	system("pause");
	return 0;
}
string castDoubleToStr(double value)
{
	// Deleting the last zeros in the fractional part of the number
	string str = to_string(value).erase(to_string(value).find_last_not_of('0') + 1);
	if (str[str.size() - 1] == '.')
		str.erase(str.size() - 1, 1);
	return str;
}