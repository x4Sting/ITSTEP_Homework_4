#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

double arr[SIZE]{ 0 };

int countEquallyNArr(int num, double equally_num);
string doubleToStr(double value);
int inputNum(string str);
void manualInputArr(int num, string str);
int minIArr(int num);
void randomArrOutput(int num, string str);
double sumNumArr(int start, int end, int step);

int main()
{
	int n = inputNum("Input the number of real elements: ");

	//randomArrOutput(n, "Random sequence:\t");
	manualInputArr(n, "Input a sequence of numbers: ");

	string answer = "Number of vector elements equal to 0: "
		+ doubleToStr(countEquallyNArr(n, 0))
		+ "\nSum of vector elements located after the minimum element: "
		+ doubleToStr(sumNumArr(minIArr(n) + 1, n - 1, 1));

	cout << answer << endl;

	system("pause");
	return 0;
}
int countEquallyNArr(int num, double equally_num)
{
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == equally_num)
		{
			count++;
		}
	}
	return count;
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