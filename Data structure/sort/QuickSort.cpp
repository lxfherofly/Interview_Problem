#include <iostream>
using namespace std;

void quicksort(int a[], int l, int r)
{
	if (l < r)
	{
		int x = a[l];
		int i = l, j = r;
		while (i < j)
		{
			while ((i < j) && (a[j] >= x))
			        j--;
			a[i] = a[j];
			while((i<j) && (a[i]<=x))
				i++;
			a[j] = a[i];
	        a[i] = x;
	        quicksort(a, l, i - 1);
	        quicksort(a, i + 1, r);
		}
	}
return;
}

int main(void)
{
	int a[] = { 48, 77, 55, 38, 41, 85, 27, 31 };
	int size = sizeof(a) / sizeof(a[0]);
	quicksort(a, 0, size - 1);
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;


	return 0;
}
