#include <bits/stdc++.h>
using namespace std;
vector<int> v[105];
vector<int> result;
bool vis[105];

void dfs_topo(int source)
{
    vis[source] = 1;
    for (int i = 0; i < v[source].size(); i++)
    {
        int nxt = v[source][i];
        if (vis[nxt] == 0)
        {
            dfs_topo(nxt);
        }
    }
    result.push_back(source);
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1; i <= edges ; i++)
    {
        int u, w;
        cin >> u >> w;
        v[u].push_back(w);
    }
    for (int i = 1; i <= nodes; i++)
    {
        if (vis[i] == 0)
            dfs_topo(i);
    }
    reverse(result.begin(), result.end());
    cout << "Topologiacal Order :->  ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

/*

5 4
1 2
3 2
2 4
2 5

*/