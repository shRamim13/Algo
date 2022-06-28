#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1e9
#define mod 1000000007
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    map<pair<string, string>, vector<int>> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int cnt;
        cin >> fn >> ln >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;
            mp[{fn, ln}].push_back(x);
        }
        for (auto &pr : mp)
        {
            auto &full_name = pr.first;
            auto &list = pr.second;
            cout << full_name.first << " " << full_name.second << endl;
            cout << list.size() << endl;
            for (auto &i : list)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}