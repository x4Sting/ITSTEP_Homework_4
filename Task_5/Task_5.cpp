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

	// Maximum modulo element of the vector

	int maxIndex = 0;
	for (int i = 1; i < num; i++)
	{
		if (abs(arr[maxIndex]) < abs(arr[i]))
		{
			maxIndex = i;
		}
	}
	string strMax = castDoubleToStr(arr[maxIndex]);

	// Sum of vector elements located between the first and second positive elements

	int firstPosI = -1;
	int secondPosI = -1;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > 0)
		{
			firstPosI = i;
			break;
		}
	}
	for (int i = firstPosI + 1; i < num; i++)
	{
		if (arr[i] > 0)
		{
			secondPosI = i;
			break;
		}
	}

	string strPosNumber = "Error!!! No positive numbers.";

	if (secondPosI != -1)
	{
		double sum = 0;
		for (int i = firstPosI + 1; i < secondPosI; i++)
		{
			sum += arr[i];

		}
		strPosNumber = castDoubleToStr(sum);
	}
	else if (firstPosI != -1)
	{
		strPosNumber = "Error!!! Only one positive number.";
	}

	string answer = "\nMaximum modulo element of the vector: " + strMax 
		+"\nSum of vector elements located between"
		" the first and second positive elements: " + strPosNumber;

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