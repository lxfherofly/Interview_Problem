#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int L, int R, int RightEnd)
{
	vector<int> tmp;
	int LeftEnd = R - 1;
	int i = L, j = R;
	while ((i <= LeftEnd) && (j <= RightEnd))
	{
		if (a[i] <= a[j]) {
			tmp.push_back(a[i]); i++;
		}
		else{
			tmp.push_back(a[j]); j++;
		}
	}
	while (i <= LeftEnd) { tmp.push_back(a[i]); i++; }
	while (j <= RightEnd){ tmp.push_back(a[j]); j++; }
	i = L;
	int k = 0;
	for (; i <= RightEnd; i++)
	{
		a[i] = tmp[k];
		k++;
	}
	return;

}
void mergesort(int a[],int L,int RightEnd)
{
	int center;
	if (L < RightEnd){
		 center = (L + RightEnd) / 2;
		 mergesort(a, L, center);
		 mergesort(a, center + 1, RightEnd);
		 merge(a, L, center + 1, RightEnd);
	}
	


}
int main(void)
{
	int a[] = { 48, 77, 55, 38, 41, 85, 27, 31 };
	int size = sizeof(a) / sizeof(a[0]);
	mergesort(a,0,size-1);
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
