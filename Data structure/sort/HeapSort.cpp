#include <iostream>

using namespace std;

void AdjustHeap(int a[], int p, int size)
{
	int parent, child;
	int data;
	data = a[p];
	parent = p;
	child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1 < size) && (a[child + 1] > a[child]))
			child++;
		if (data < a[child]){
			a[parent] = a[child];
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
		
	}
	a[parent] = data;
}
int main()
{
	int a[] = { 48, 77, 55, 38, 41, 85, 27, 31 };
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = size / 2 - 1; i >= 0; i--)
		AdjustHeap(a, i, size);
	
	for (int i = size - 1; i >= 0; i--)
	{
		int max = a[0];
		a[0] = a[i];
		a[i] = max;
		AdjustHeap(a, 0, i);
	}
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;

}