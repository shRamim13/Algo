#include <bits/stdc++.h>
using namespace std;
#define MX 10000
#define White 1
#define Gray 2
#define Black 3
int adj[MX][MX];
int color[100];
int nodes, edges;

void dfs_visit(int x)
{
    color[x] = Gray;
    for (int i = 0; i < nodes; i++)
    {
        if (adj[x][i] == 1)
        {
            if (color[x] == White)
            {
                dfs_visit(i);
            }
        }
    }
    color[x] = Black;
}

void dfs()
{
    for (int i = 0; i < nodes; i++)
    {
        color[i] = White;
    }
    for (int i = 0; i < nodes; i++)
    {
        if (color[i] == White)
        {
            dfs_visit(i);
        }
    }
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

    dfs();

    for(int i=0; i<nodes; i++)
    {
        if(color[i]==Black)
            cout<<"node "<<i<<" is visited"<<endl;
        else
            cout<<"node "<<i<<" is not visited"<<endl;
    }

    return 0;
}



/*
6 6
0 1
0 2
0 3
2 3
3 4
5 6
*/
