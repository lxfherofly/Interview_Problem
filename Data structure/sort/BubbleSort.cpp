
#include <iostream>
using namespace std;

void bubblesort(int a[], int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		bool flag = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[j]>a[j + 1]) { 
				int  temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp; 
				flag = 0;
			}
		}
		if (flag)
			break;
		
	}
}
int main(void)
{
	int a[] = { 5,4,2,3,1,6,7,8,9 };
	int size = 9;
	bubblesort(a, 9);
	cout << "----bubble sort----" << endl;
	for (int i = 0; i <9; i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}
