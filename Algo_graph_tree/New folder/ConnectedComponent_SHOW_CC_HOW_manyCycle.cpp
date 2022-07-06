#include <bits/stdc++.h>
using namespace std;
#define MX 100000
bool vis[MX];
vector<int> G[MX];
vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int source)
{
    vis[source] = 1;
    current_cc.push_back(source);
    for (int child : G[source])
    {
        if (vis[child] == 1)
            continue;
        dfs(child);
    }
}
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        if (vis[i] == 0)
        {
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
            cnt++;
        }
    }
    cout << "Connected Component "<< cnt<<endl;
    for (auto c_cc : cc)
    {
        for (int vertex : c_cc)
        {
            cout << vertex << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*8 5
1 2
2 3
2 4
3 5
6 7
*/