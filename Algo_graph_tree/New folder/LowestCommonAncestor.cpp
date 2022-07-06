#include <bits/stdc++.h>
using namespace std;
#define MX 1000

vector<int> g[MX];
int par[MX];

void dfs(int v, int p = -1)
{
    par[v] = p;
    for (int child : g[v])
    {
        if (child == p)
            continue;
        dfs(child, v);
    }
}

vector<int> _path(int v)
{
    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    int u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << "Enter 2 vertex -> ";
    cin >> u >> v;

    dfs(1);
    vector<int> path_u = _path(u);
    vector<int> path_v = _path(v);

    int minln = min(path_u.size(), path_v.size());

    int lca = -1;

    for (int i = 0; i < minln; i++)
    {
        if (path_u[i] == path_v[i])
            lca = path_u[i];
        else
            break;
    }
    cout << "Lowest Common Ancestor of " << u << " and " << v << " ==> " << lca << endl;
    
    return 0;
}


/*13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11*/
