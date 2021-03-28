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

	
	srand(time(0));
	cout << "Random sequence: ";
	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 200 - 100;
		cout << arr[i] << "  ";
	}
	

	// Manual input

	/*cout << "Input a sequence of integer numbers:\n";
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}*/

	// Number of positive vector elements

	int count = 0;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > 0)
		{
			count++;
		}
	}

	string strCount = to_string(count);

	// Sum of vector elements located after last zero element

	int lastZeroI = -1;

	for (int i = num - 1; i >= 0; i--)
	{
		if (arr[i] == 0)
		{
			lastZeroI = i;
			break;
		}
	}

	string strSum = "Error!!! There are no zeros.";

	if (lastZeroI != -1)
	{
		int sum = 0;

		for (int i = lastZeroI + 1; i < num; i++)
		{
			sum += arr[i];
		}
		strSum = to_string(sum);
	}

	// Answer

	string answer = "\nNumber of positive vector elements: " + strCount
		+ "\nSum of vector elements located after last zero element: " + strSum;

	cout << answer << endl;

	system("pause");
	return 0;
}