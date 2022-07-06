#include <bits/stdc++.h>
#define SZ 10000
using namespace std;

vector<int> adj[SZ];
int _time, vis[SZ], low[SZ], d[SZ];
vector<pair<int, int>> arti_bridge;

void _find_articulation_Bridge(int u, int par)
{
    low[u] = d[u] = ++_time;
    vis[u] = 1;
    int child = 0, v;
    for (int i = 0; i < adj[u].size(); i++)
    {
        v = adj[u][i];
        if (v == par)
            continue;
        if (vis[v])
        {
            low[u] = min(low[u], d[v]);
        }
        else
        {
            _find_articulation_Bridge(v, u);
            low[u] = min(low[u], low[v]);
            if (d[u] < low[v] && par != -1)
            {
                arti_bridge.push_back({u, v});
            }
            else
                child++;
        }
        if (d[v] == low[v] and par == -1)
        {
            arti_bridge.push_back({u, v});
        }
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    _find_articulation_Bridge(0, -1);

    cout << "Node\td[i]\tlow[i]" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << d[i] << "\t" << low[i] << endl;
    }
    cout << "Articulation Bridge == > " << arti_bridge.size() << endl;
    cout << "Articulation Bridge List : " << endl;
    for (auto &k : arti_bridge)
    {
        cout << k.first << " " << k.second << endl;
    }
    return 0;
}