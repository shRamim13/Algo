#include <bits/stdc++.h>
using namespace std;
#define MX 10000
vector<int> ac;
vector<int> graph[MX];
bool vis[MX];
int dis[MX];



void bfs(int source)
{
    queue<int> q;
    vis[source] = 1;
    dis[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int node = q.front();
        ac.push_back(node);
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nxt = graph[node][i];
            if (vis[nxt] == 0)
            {
                vis[nxt] = 1;
                dis[nxt] = dis[node] + 1;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    int edges, nodes;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;
    cout << "enter source -> ";
    cin >> source;
    bfs(source);
    cout << "From node " << source << endl;

    for (int i = 1; i <= nodes; i++)
    {
        cout << "Distance of " << i << " is " << dis[i] << endl;
    }

    for (int i = 0; i < ac.size(); i++)
    {
    cout<<ac[i]<<" ";
    }

    return 0;
}

/*

7 9
1 2
1 3
1 7
2 3
3 7
2 4
4 5
3 6
5 6

*/