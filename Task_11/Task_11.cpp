#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

double arr[SIZE]{ 0 };

int countBtwArr(int, double, double);
string doubleToStr(double);
int inputNum(string);
void manualInputArr(int, string);
int maxIArr(int);
void randomArrOutput(int, string);
double sumNumArr(int, int);

int main()
{
	int n = inputNum("Input the number of real elements: ");

	//randomArrOutput(n, "Random sequence:\t");
	manualInputArr(n, "Input a sequence of numbers: ");

	double a, b;

	cout << "Input A: ";
	cin >> a;
	cout << "Input B: ";
	cin >> b;

	string answer = "Number of vector elements ranging from";

	if (b < a)
	{
		swap(a, b);
		answer += " B to A: ";
	}
	else
	{
		answer += " A to B : ";
	}

	answer += to_string(countBtwArr(n, a, b))
		+ "\nSum of vector elements located after the maximum element: "
		+ doubleToStr(sumNumArr(maxIArr(n) + 1, n - 1));

	cout << answer << endl;

	system("pause");
	return 0;
}
int countBtwArr(int num, double start, double end)
{
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] >= start && arr[i] <= end)
		{
			count++;
		}
	}
	return count;
}
int countMoreNArr(int num, double more_num)
{
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] > more_num)
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
int maxIArr(int num)
{
	int maxIndex = 0;
	for (int i = 1; i < num; i++)
	{
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}
	return maxIndex;
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
double sumNumArr(int start, int end)
{
	double sum = 0;
	for (int i = start; i <= end; i++)
	{
		sum += arr[i];
	}
	return sum;
}