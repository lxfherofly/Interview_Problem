#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int* compute_prefix(char pattern[])
{
    int n = strlen(pattern);
    cout << "the pattern length " << n << endl;

    int* pre = new int[n];

    pre[0] = 0;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        k = pre[i-1];
        while (k > 0 && pattern[k] != pattern[i])
            k = pre[k-1];
        if (pattern[k] == pattern[i])
            k++;
        pre[i] = k;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout<<pre[i]<<endl;
    // }
    return pre;

}

int kmp(char s[], char pattern[], int* pre)
{
    int n = strlen(s);
    int m = strlen(pattern);
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        cout<<"i = "<<i<<endl;
        cout<<"k = "<<k<<endl;
        while (k > 0 && pattern[k] != s[i])
        {
            k = pre[k-1];
            cout<<" k = "<<k<<endl;
        }
        if (pattern[k] == s[i])
            k++;
        if (k == m)
            return i - m + 1;
    }
    return -1;
}

int main(void)
{
    char s[] = "abcdiacfabcdiabejij";
    char pattern[] = "abcdiabe";
    int* pre = compute_prefix(pattern);
    int index = kmp(s, pattern, pre);
    cout << index << endl;

}
