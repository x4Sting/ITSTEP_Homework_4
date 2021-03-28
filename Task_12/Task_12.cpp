#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

double arr[SIZE]{ 0 };

string doubleToStr(double value);
int inputNum(string str);
void manualInputArr(int num, string str);
void randomArrOutput(int num, string str);
double multMoreNArr(int num, double more_num);
int minIArr(int num);
double sumNumArr(int start, int end);

int main()
{
	int n = inputNum("Input the number of real elements: ");

	randomArrOutput(n, "Random sequence:\t");
	//manualInputArr(n, "Input a sequence of numbers: ");

	string answer = "Product of positive vector elements: "
		+ doubleToStr(multMoreNArr(n, 0))
		+ "\nSum of vector elements up to minimum element: "
		+ doubleToStr(sumNumArr(0, minIArr(n) - 1));

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
double multMoreNArr(int num, double more_num)
{
	double mult = 1;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] > more_num)
		{
			mult *= arr[i];
		}

	}

	return mult;
}
int minIArr(int num)
{
	int minIndex = 0;
	for (int i = 1; i < num; i++)
	{
		if (arr[minIndex] > arr[i])
		{
			minIndex = i;
		}
	}
	return minIndex;
}
double sumNumArr(int start, int end)
{
	double sum = 0;
	for (int i = start; i <= end; i++)
	{
		sum += arr[i];
	}
	return sum;
}