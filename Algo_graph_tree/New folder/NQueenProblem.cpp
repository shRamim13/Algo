#include <bits/stdc++.h>
using namespace std;
int Queen[100];
int Column[200], Digonal11[400], Digonal12[400];
int n;
void NQueen(int at, int n)
{
    if (at == n + 1)
    {
        cout << "( Row,Column ) = " << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "(" << i << "," << Queen[i] << ")" << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (Column[i] || Digonal11[i + at] || Digonal12[n - at + i])
            continue;
        Queen[at] = i;
        Column[i] = Digonal11[i + at] = Digonal12[n - at + i] = 1;
        NQueen(at + 1, n);
        Column[i] = Digonal11[i + at] = Digonal12[n - at + i] = 0;
    }
}
int main()
{
    while (1)
    {
        cin >> n;
        NQueen(1, n);
    }
    return 0;
}