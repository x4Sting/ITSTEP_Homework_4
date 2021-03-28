#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

double arr[SIZE]{ 0 };

string doubleToStr(double value);
int findNegIArr(int start, int end, int step);
int inputNum(string str);
void manualInputArr(int num, string str);
void randomArrOutput(int num, string str);
double sumNumArr(int start, int end, int step);

int main()
{
	int n = inputNum("Input the number of real elements: ");

	randomArrOutput(n, "Random sequence:\t");
	//manualInputArr(n, "Input a sequence of numbers: ");

	int firstNegI = findNegIArr(0, n - 1, 1);
	int lastNegI = findNegIArr(n - 1, 0, -1);

	string answer = "Sum of elements of vector with odd numbers: "
		+ doubleToStr(sumNumArr(0, n - 1, 2))
		+ "\nSum of vector elements located between"
		" the first and last negative elements: "
		+ doubleToStr(sumNumArr(firstNegI + 1, lastNegI - 1, 1));

	cout << answer << endl;

	system("pause");
	return 0;
}
string doubleToStr(double value)
{
	string str;
	str = to_string(value).erase(to_string(value).find_last_not_of('0') + 1);
	if (str[str.size() - 1] == '.')
	{
		str.resize(str.size() - 1);
	}
	return str;
}
int findNegIArr(int start, int end, int step)
{
	int index = 0;

	for (int i = start; abs(end - i) >= 0; i += step)
	{
		if (arr[i] < 0)
		{
			index = i;
			break;
		}
	}
	return index;
}
int inputNum(string str)
{
	int num;
	do
	{
		system("cls");
		cout << str;
		cin >> num;
	} while (num <= 0);
	cin.ignore(sizeof num, '\n');
	return num;
}
void manualInputArr(int num, string str)
{
	cout << str << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
}
void randomArrOutput(int num, string str)
{
	srand(time(0));

	cout << str;

	for (int i = 0; i < num; i++)
	{
		arr[i] = (double(rand() % 2000) - 1000) / 10;
		cout << arr[i] << "  ";
	}
	cout << "\n";
}
double sumNumArr(int start, int end, int step)
{
	double sum = 0;
	for (int i = start; i <= end; i += step)
	{
		sum += arr[i];
	}
	return sum;
}