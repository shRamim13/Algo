#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // int arr[n];
    vector<int> arr(n);
    // set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        /*int x;
        cin >> x;
        s.insert(x);*/
    }
    int min = *min_element(arr.begin(), arr.end());
    cout << min << endl;
    int max = *max_element(arr.begin(), arr.end());
    cout << max << endl;
    int sum = accumulate(arr.begin(), arr.end() - 2, 0);
    cout << sum << endl;
    int cnt = count(arr.begin(), arr.end(), 2);
    cout << cnt << endl;
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    auto it = find(arr.begin(), arr.end(), 4);
    if (it != arr.end())
    {
        cout << *it << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}