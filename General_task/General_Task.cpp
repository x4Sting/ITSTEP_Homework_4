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
		cout << "How many numbers are in the sequence? ";
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

	// Extreme elements of a given sequence
	int maxIndex = 0;
	int minIndex = 0;
	
	for (int i = 1; i < num; i++)
	{
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}	
		if (arr[minIndex] > arr[i])
		{
			minIndex = i;
		}
	}

	string extrElements = "\nMin value: " + castDoubleToStr(arr[minIndex])
		+ "\nMax value: " + castDoubleToStr(arr[maxIndex]);

	// Counts the number of positive, negative and zero elements of the sequence
	int countPositive = 0;
	int countNegative = 0;
	int countZero = 0;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > 0)
		{
			countPositive++;
		}
		else if (arr[i] < 0)
		{
			countNegative++;
		}
		else 
		{
			countZero++;
		}
	}

	string countElements = 
		"\nNumber of positive numbers: " + to_string(countPositive)
		+ "\nNumber of negative numbers: " + to_string(countNegative)
		+ "\nNumber of zeros: " + to_string(countZero);

	// Swap extreme elements
	string swapElements = "\nSequence before swap:\t";
	for (int i = 0; i < num; i++)
	{
		swapElements += castDoubleToStr(arr[i]) + "  ";
	}

	double temp = arr[minIndex];
	arr[minIndex] = arr[maxIndex];
	arr[maxIndex] = temp;
	
	swapElements += "\nSequence after swap:\t";

	for (int i = 0; i < num; i++)
	{
		swapElements += castDoubleToStr(arr[i]) + "  ";
	}	

	// Answer
	string answer = extrElements + countElements + swapElements;
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