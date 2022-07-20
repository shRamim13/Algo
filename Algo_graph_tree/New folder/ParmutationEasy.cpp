#include <bits/stdtr1c++.h>
using namespace std;
vector<int> ans;
vector<int> vis(20, false);
void combination(int n, int r)
{
    if ((int)ans.size() == r)
    {
        for (auto i : ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {

            vis[i] = true;
            ans.push_back(i);
            combination(n, r);
            vis[i] = false;
            ans.pop_back();
        }
    }
}
int main()
{

    int n, r;
    cin >> n >> r;

    combination(n, r);
}