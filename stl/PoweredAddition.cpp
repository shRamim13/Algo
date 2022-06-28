#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll mx = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] < v[i - 1])
            {
                mx = max(mx, v[i - 1] - v[i]);
                v[i] = v[i - 1];
            }
        }
        cout << (int)ceil(log2(mx + 1)) << endl;
    }
    return 0;
}