#include <bits/stdc++.h>
#define SZ 10000
using namespace std;

vector<int> adj[SZ];
int _time, arti_point[SZ], vis[SZ], low[SZ], d[SZ];

void _find_articulation_point(int u, int par)
{
    _time++;
    low[u] = d[u] = _time;
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
            _find_articulation_point(v, u);

            low[u] = min(low[u], low[v]);
            if (d[u] <= low[v] && par != -1)
            {
                arti_point[u] = 1;
            }
            else
                child++;
        }
        if (child > 1 && par == -1)
            arti_point[u] = 1;
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
    _find_articulation_point(0, -1);
    cout << "Node\td[i]\tlow[i]" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << d[i] << "\t" << low[i] << endl;
    }
    cout << "Articulation Point List " << endl;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (arti_point[i])
        {
            count++;
            cout << i << endl;
        }
    }
    cout << "Articulation point => " << count;
    return 0;
}
/** 
7 7
0 1
0 2
2 3
3 4
3 5
5 6
6 2
 * 
 */