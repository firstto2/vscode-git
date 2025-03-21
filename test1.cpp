#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
#define LENGTH 100

void ShowMenu()
{
	cout << "1. Insertion Sort" << "\n";
	cout << "2. Bubble Sort" << "\n";
}
void RandomNumber(int A[])
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < LENGTH; i++)
	{
		A[i] = rand() % 100 + 1;
	}
}
void InsertionSort(int A[])
{
	cout << "Insertion Sort" << "\n";
	for (int j = 1; j < LENGTH; j++)
	{
		int key = A[j];
		int i = j - 1;
		while ((i >= 0) && (A[i] > key))
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void BubbleSort(int A[])
{
	cout << "Bubble Sort" << "\n";
	for (int i = 0; i < LENGTH - 1; i++)
	{
		for (int j = LENGTH - 1; j > i; j--)
		{
			if (A[j] < A[j - 1])
			{
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
}
void print(int A[])
{
	for (int i = 0; i < LENGTH; i++)
	{
		cout << setw(3) << A[i] << " ";

		if ((i + 1) % 10 == 0)
		{
			cout << "\n";
		}
	}
	cout << "\n";
}
int main(void)
{
	int choice = 0;
	int NumberArray[LENGTH] = { 0 };

	RandomNumber(NumberArray);
	ShowMenu();
	cout << "선택: "; cin >> choice; cout << "\n";

	if (choice == 1)
	{
		InsertionSort(NumberArray);
	}
	else if (choice == 2)
	{
		BubbleSort(NumberArray);
	}
	print(NumberArray);
	return 0;
}
