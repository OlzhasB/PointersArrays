#include<iostream>
using namespace std;

void printArray(const int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void fillArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = -2 + rand() % 40;
	}
}

void allocateArray(int *&a, int n)
{
	a = new int[n];
}

int sumArray(int *a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

void expansionArray(int *&a, int &n)
{
	int *tmp;
	tmp = new int[n + 2];
	for (int i = 0; i < n; i++)
	{
		tmp[i + 1] = a[i];
	}
	tmp[n + 1] = sumArray(a, n);
	tmp[0] = 0;
	delete[] a;
	a = tmp;
	n += 2;
}

int* delete0(int *a, int n, int &newsize)
{
	int *tmp, count = 0, ind = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			count++;
		}
	}
	tmp = new int[count];
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			tmp[ind] = a[i];
			ind++;
		}
	}
	newsize = ind;
	return tmp;
}

int* deleteMultipleOf3(int *a, int n, int &m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 3 == 0)
		{
			count++;
		}
	}
	int *tmp = new int[count];
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 3 == 0)
		{
			tmp[count++] = a[i];
		}
	}
	m = count;
	return tmp;
}

int* more20(int *a, int n, int &m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 20)
		{
			count++;
		}
	}
	int *tmp = new int[count];
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 20)
		{
			tmp[count++] = a[i];
		}
	}
	m = count;
	return tmp;
}

void newElementArray(int *&a, int &n)
{
	int *tmp, ind = -1, c;
	cout << "which number you want to add?: ";
	cin >> c;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			ind = i;
			break;
		}
	}
	tmp = new int[n + 1];
	for (int i = 0; i <= ind; i++)
	{
		tmp[i] = a[i];
	}
	tmp[ind + 1] = c;
	for (int i = ind + 1; i < n; i++)
	{
		tmp[i + 1] = a[i];
	}
	
	delete[] a;
	a = tmp;
	n++;
}

void DecToBin(int a)
{
	int num, count = 0, c = a;
	do
	{
		c = c / 2;
		count++;
	} while (c > 0);

	int *b;
	b = new int[count];
	for (int i = count - 1; i >= 0; i--)
	{
		b[i] = a % 2;
		a = a / 2;
	}
	printArray(b, count);
}

void task1()
{
	int n, *a;
	cout << "Enter the size of array: ";
	cin >> n;
	allocateArray(a, n);
	fillArray(a, n);
	printArray(a, n);

	expansionArray(a, n);
	printArray(a, n);
	delete[] a;
}

void task2()
{
	int n, *a, m, *b;
	cout << "Enter the size of array: ";
	cin >> n;
	allocateArray(a, n);
	fillArray(a, n);
	printArray(a, n);

	b = delete0(a, n, m);
	printArray(b, m);
	delete[] a;
	delete[] b;
}

void task3()
{
	int n, *a, m, *b;
	cout << "Enter the size of array: ";
	cin >> n;
	allocateArray(a, n);
	fillArray(a, n);
	printArray(a, n);

	b = deleteMultipleOf3(a, n, m);
	printArray(b, m);
	delete[] a;
	delete[] b;
}

void task4()
{
	int n, *a, m, *b;
	cout << "Enter the size of array: ";
	cin >> n;
	allocateArray(a, n);
	fillArray(a, n);
	printArray(a, n);

	b = more20(a, n, m);
	printArray(b, m);
	delete[] a;
	delete[] b;
}

void task5()
{
	int *a, n;
	cout << "Enter the size of array: ";
	cin >> n;
	allocateArray(a, n);
	fillArray(a, n);
	printArray(a, n);

	newElementArray(a, n);
	printArray(a, n);
	delete[] a;
}

void task6()
{
	int a;
	cout << "Enter any number: ";
	cin >> a;
	DecToBin(a);
}

int main()
{
	int a, flag;
	do
	{
		cout << "Write the number of task: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			task1();
			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		case 4:
		{
			task4();
			break;
		}
		case 5:
		{
			task5();
			break;
		}
		case 6:
		{
			task6();
			break;
		}
		} 
	cout << "Do you want to continue? 1 / 0: ";
	cin >> flag;
	} while (flag == 1);
	system("pause");
}