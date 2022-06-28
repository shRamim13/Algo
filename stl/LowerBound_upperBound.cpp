#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // int arr[n];
    // vector<int> arr(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        // cin >> arr[i];
        int x;
        cin >> x;
        s.insert(x);
    }
    // sort(arr, arr + n);
    //sort(arr.begin(), arr.end());
    /*for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }*/
    cout << endl;
    // auto *ptr = upper_bound(arr, arr + n, 50);
    //auto ptr = lower_bound(arr.begin(), arr.end(), 15);
    auto ptr=s.lower_bound(52);
    if (ptr == (s.end()))
    {
        cout << "Element not found ";
        return 0;
    }
    cout << *ptr << endl;
}