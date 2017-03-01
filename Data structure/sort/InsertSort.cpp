#include <iostream>
using namespace std;

void InsertSort(int a[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int tmp = a[i];
		int j;
		for ( j = i - 1; j>=0 ; j--)
		{
			if (a[j] > tmp)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j+1] = tmp;
	}
}
int main(void)
{

	int a[] = { 10, 7, 9, 6, 4, 5, 3, 2, 1, 8 };

	InsertSort(a, 10);
	
	for (int i = 0; i <10; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}