#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 5, 3, 4};
    next_permutation(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    int arr[] = {1, 2, 5, 4, 3};
    next_permutation(arr, arr + sizeof(arr) / sizeof(arr[0]));
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    
    {
        string s;
        next_permutation(s.begin(), s.end());
        for (char x : s)
        {
            cout << x << " ";
        }
    }

    {
        cout << endl;
        int arr[] = {1, 2, 4, 3};
        prev_permutation(arr, arr + sizeof(arr) / sizeof(arr[0]));
        for (int x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    /*
    {
        cout << endl;
        int arr[] = {2, 1, 4, 5,3};
        nth_element(arr, arr+1, arr + sizeof(arr) / sizeof(arr[0]));
        for (int x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }*/
}