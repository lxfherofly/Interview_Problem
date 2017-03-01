#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char,int> Shift(string p)
{
    int n = p.size();
    cout<<"pattern size = "<<n<<endl;
    map<char,int> shift;
    for (int i = 0; i <128 ; ++i)
    {
        shift[i] = n;
    }

    for (int i = 0; i < n-1; ++i)
    {
        shift[p[i]] = n-1-i;
    }
     
    // for (map<char,int>::iterator iter = shift.begin(); iter!=shift.end();iter++)
    // {
    //     cout<<iter->first<<"-->"<<iter->second<<endl;   
    // }
    return shift;

}


int bmh(string s, string pattern, map<char,int> shift)
{
    int n = s.size();
    int m = pattern.size();

    for (int i = 0; i < n;)
    {
        int j = m-1;
        while(pattern[j] == s[i+j])
        {
            j =j -1;
            if (j < 0)
                return i;

        }
        i = i + shift[s[i+m-1]];
    }
    return -1;
}

int main(void)
{
    string s = "dete ctive date";
    string pattern = "date";

    map<char,int> shift = Shift(pattern);
    int index = bmh(s,pattern,shift);
    cout <<index<<endl;
}