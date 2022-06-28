#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int T, n, c0, c1, h, ans;
    cin >> T;
    while (T--)
    {
        cin >> n >> c0 >> c1 >> h >> s;
        ans = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                ans += min(c0, c1 + h);
            else
                ans += min(c0 + h, c1);
        cout << ans << endl;
    }

    return 0;
}