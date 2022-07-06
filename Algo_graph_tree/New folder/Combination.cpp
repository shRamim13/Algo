#include <bits/stdc++.h>
using namespace std;
#define MX 10000

int number[MX];

int n, k;

void __combination(int at, int left)
{
    if (left > n - at + 1)
        return;
    if (at == n + 1)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << number[i] << " ";
        }
        cout << "\n";
        return;
    }

    if (left)
    {
        number[k - left + 1] = at;
        __combination(at + 1, left - 1);
    }
    __combination(at + 1, left);
}

int main()
{
    cin >> n >> k;
    __combination(1, k);
    return 0;
}