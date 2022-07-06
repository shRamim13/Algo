#include <bits/stdc++.h>

using namespace std;

const int MAX_SZ = 1001;

vector<int> adj[MAX_SZ], path;
vector<vector<int>> ham;
bool vis[MAX_SZ];

int n, m;

// Nodes shall start from 1

void dfs(int u)
{
    vis[u] = true;
    if(path.size() == n)
    {
        ham.push_back(path);
        vis[u] = false;
        return;
    }

    for(int v : adj[u])
    {
        if(!vis[v])
        {
            path.push_back(v);
            dfs(v);
            path.pop_back();
        }
    }
    vis[u] = false;
}

void Hamilton()
{

    for(int i = 1; i <= n; ++i)
    {
        path.push_back(i);
        dfs(i);
        path.pop_back();
    }

}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Hamilton();

    if(ham.empty())
        cout << "There are no Hamilton Paths for the given graph\n";
    else
    {
        cout << "A Hamilton Path for the given graph is: \n";
        for(auto x : ham.front())
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

/**
4 3
1 2
2 3
1 4

4 4
1 2
1 3
2 3
3 4

4 4
1 2
1 4
2 3
3 4
*/
