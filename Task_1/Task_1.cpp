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

	// Sum of negative elements of a vector

	double sum = 0;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] < 0)
		{
			sum += arr[i];
		}
	}

	//Product of vector elements located between the maximum and minimum elements

	int minIndex = 0;
	int maxIndex = 0;
	for (int i = 1; i < num; i++)
	{
		if (arr[minIndex] > arr[i])
		{
			minIndex = i;
		}
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}

	string strProduct = "none";

	if (maxIndex != minIndex && abs(minIndex - maxIndex) != 1)
	{
		double product = 1;
		int start = maxIndex > minIndex ? minIndex : maxIndex;
		int end = maxIndex > minIndex ? maxIndex : minIndex;
		for (int i = start + 1; i < end; i++)
		{
				product *= arr[i];			
		}
		strProduct = castDoubleToStr(product);
	}

	// Answer

	string answer = "\nSum of negative elements: " + castDoubleToStr(sum)
		+ "\nMin value: " + castDoubleToStr(arr[minIndex])
		+ "\nMax value: " + castDoubleToStr(arr[maxIndex])
		+ "\nProduct of elements between the max and min: " + strProduct;

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