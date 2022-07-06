#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define White 1
#define Gray 2
#define Black 3

int adj[10000][10000];
int color[10000];
int parent[10000];
int dis[10000];
int nodes, edges;

void bfs(int source)
{
    for (int i = 0; i < nodes; i++)
    {
        color[i] = White;
        dis[i] = INF;
        parent[i] = -1;
    }
    dis[source] = 0;
    parent[source] = -1;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        color[x] = Gray;
        cout << x << " ";
        for (int i = 0; i < nodes; i++)
        {
            if (adj[x][i] == 1)
            {
                if (color[i] == White)
                {
                    dis[i] = 1 + dis[x];
                    parent[i] = x;
                    q.push(i);
                }
            }
        }
    }
    cout << "\n";
}

int main()
{
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    int source;
    cout << " Enter source --> ";
    cin >> source;
    cout << " path ---> ";
    bfs(source);

    for (int i = 0; i < nodes; i++)
    {
        cout << "From : " << source << " to " << i <<" distance-- > ";
        {
            if (dis[i] == INF)
                cout << " INF " << endl;
            else
                cout << dis[i] << endl;
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        cout << "Parent of " << i << " --> ";
        {
            if (parent[i] == -1)
                cout << "it is the source " << endl;
            else
                cout << parent[i] << endl;
        }
    }

    return 0;
}

/*
8 7
0 1
0 2
1 3
2 4
2 5
3 6
3 7
*/