#include <bits/stdc++.h>
using namespace std;

void _Parmutation(string Str, int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i < Str.size(); i++)
        {
            cout << Str[i] << " ";
        }
        cout << endl;
    }
    for (int i = l; i <= r; i++)
    {
        swap(Str[l], Str[i]);
        _Parmutation(Str, l + 1, r);
        swap(Str[l], Str[i]);
    }
}

int main()
{
    while (1)
    {

        string str;
        cout << "Enter any String --> ";
        cin >> str;
        int length = str.size();
        _Parmutation(str, 0, length - 1);
    }
    return 0;
}