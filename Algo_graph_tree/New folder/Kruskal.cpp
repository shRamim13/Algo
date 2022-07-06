#include <bits/stdc++.h>
using namespace std;
#define MX 100000
int parent[MX];
int sz[MX];

void make_Set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_Parent(int v)
{
    if (parent[v] == v)
        return parent[v];
    return parent[v] = find_Parent(parent[v]);
}

void Union(int a, int b)
{
    a = find_Parent(a);
    b = find_Parent(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int v, w, u;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++)
    {
        make_Set(i);
    }

    int total_Cost = 0;
    cout << "Minimum Spanning tree --> \n";
    for (auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find_Parent(u) == find_Parent(v))
            continue;

        Union(u, v);

        total_Cost += wt;
        cout << u << " --> " << v << " (" << wt <<")"<< endl;
    }
    cout << "Total Cost --> ";
    cout << total_Cost << endl;
    return 0;
}

/***
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7


9 10
1 8 5
1 3 1
8 9 6
3 9 3
3 7 7
4 9 2
9 2 10
4 5 12
4 6 7
7 6 11
*/