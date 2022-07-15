#include <bits/stdc++.h>
using namespace std;
#define MX 10000
#define White 1
#define Gray 2;
#define Black 3;
int adj[MX][MX];
int color[MX];
int discovery_time[MX];
int finishing_time[MX];

int Time = 1;
int nodes, edges;

void dfsCall(int x)
{
    color[x] = Gray;
    discovery_time[x] = Time;
    ++Time;
    for (int i = 0; i < nodes; i++)
    {
        if (adj[x][i] == 1)
        {
            if (color[i] == White)
            {
                dfsCall(i);
            }
        }
    }
    color[x] = Black;
    finishing_time[x] = Time;
    ++Time;
}

void dfs(int source)
{
    for (int i = 0; i < nodes; i++)
    {
        color[i] = White;
    }
    /*for (int i = 0; i < nodes; i++)
    {
        if (color[i] == White)
            dfsCall(i);
    }*/
    dfsCall(source);
}

int main()
{
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    int source;
    cin >> source;
    dfs(source);

    for (int i = 0; i < nodes; i++)
    {
        cout << "Node : " << (char)('A' + i) << " discovery time --> " << discovery_time[i] << " finishing time --> " << finishing_time[i] << endl;
    }
    return 0;
}

/*
5 7
2 0
2 3
0 1
1 4
3 4
3 1
0 3
*/