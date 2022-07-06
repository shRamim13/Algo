#include <bits/stdc++.h>
using namespace std;
#define MX 10000

int vis[MX];
int number[MX];

void _permutation(int at, int n)
{
    if (at == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << number[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            number[at] = i;
            _permutation(at + 1, n);
            vis[i] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    _permutation(1, n);
    return 0;
}