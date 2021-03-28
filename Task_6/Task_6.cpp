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


	// Index maximum abs element

	int maxIndex = 0;
	for (int i = 1; i < num; i++)
	{
		if (abs(arr[maxIndex]) < abs(arr[i]))
		{
			maxIndex = i;
		}
	}
	string strMax = to_string(maxIndex + 1);

	// Sum of vector elements located after the first positive element: 

	int firstPosNumI = -1;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > 0)
		{
			firstPosNumI = i;
			break;
		}
	}

	string strSum;

	if (firstPosNumI != -1)
	{
		double sum = 0;
		for (int i = firstPosNumI + 1; i < num; i++)
		{
			sum += arr[i];
		}
		strSum = castDoubleToStr(sum);
	}

	// Answer

	string answer = "\nIndex maximum abs element: " + strMax 
		+ "\nSum of vector elements located after the first positive element: "
		+ strSum;

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