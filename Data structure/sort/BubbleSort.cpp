#include <iostream>
using namespace std;

void bubblesort(int a[],int size)
{
	for (int i = size-1; i >=0; i--)
	{
		int flag = 1;
		for (int j = 0; j < i ; j++)
		{
			if (a[j]>a[j + 1]){ int  temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp; flag = 0; }
		}
		if (flag)
			break;
	}
}
int main(void)
{
	int a[] = { 10, 7, 9, 6, 4, 5, 3, 2, 1, 8 };
	int size = 10;
	bubblesort(a,10);
	cout << "----bubble sort----" << endl;
	for (int  i = 0; i <10; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}