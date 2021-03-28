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

	// Product of negative vector elements

	int count = 0;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] < 0)
		{
			count++;
		}
	}

	string strProduct = "No negative elements";

	if (count > 0)
	{
		double product = 1;

		for (int i = 0; i < num; i++)
		{
			if (arr[i] < 0)
			{
				product *= arr[i];
			}
		}
		strProduct = castDoubleToStr(product);
	}

	// Sum of positive vector elements up to the maximum element

	int maxI = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[maxI] < arr[i])
		{
			maxI = i;
		}
	}

	double sum = 0;

	for (int i = 0; i < maxI; i++)
	{
		if (arr[i] > 0)
		{
			sum += arr[i];
		}
	}

	string strSum = castDoubleToStr(sum);

	//Answer

	string answer = "\nProduct of negative vector elements: " + strProduct
		+ "\nMaximum element :" + castDoubleToStr(arr[maxI])
		+ "\nSum of positive elements vectors up to the maximum element: "
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