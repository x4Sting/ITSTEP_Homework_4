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

	double c;

	cout << "\nInput C: ";
	cin >> c;

	// Number of vector elements larger than C

	int count = 0;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > c)
		{
			count++;
		}
	}

	string strCount = to_string(count);

	// Product of vector elements located after maximum modulo element

	int maxAbsI = 0;

	for (int i = 0; i < num; i++)
	{
		if (abs(arr[maxAbsI]) < abs(arr[i]))
		{
			maxAbsI = i;
		}
	}

	string strProduct;

	double product = 1;
	for (int i = maxAbsI + 1; i < num; i++)
	{
		product *= arr[i];
	}

	strProduct = castDoubleToStr(product);

	for (int i = maxAbsI + 1; i < num; i++)
	{
		if (abs(arr[i]) == abs(arr[maxAbsI]))
		{
			double product = 1;

			for (int j = i + 1; j < num; j++)
			{
				product *= arr[j];
			}
			strProduct += " or " + castDoubleToStr(product);
		}
	}

	// Answer

	string answer = "\nNumber of vector elements larger than C: " + strCount
		+ "\nMaximum modulo element: " + castDoubleToStr(arr[maxAbsI])
		+ "\nProduct of vector elements located after maximum modulo element: "
		+ strProduct;

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