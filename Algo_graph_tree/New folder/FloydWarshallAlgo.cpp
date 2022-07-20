#include <bits/stdc++.h>
using namespace std;
#define INF 100000
#define N 1000

int dis[N][N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }
    cout << "Enter Nodes & Edges --> ";
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }
    for (int k = 1; k <= nodes; k++)
    {
        for (int i = 1; i <= nodes; i++)
        {
            for (int j = 1; j <= nodes; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    cout << "Printing cost of All path --> \n";
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            if (dis[i][j] == INF)
                cout << "x"
                     << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
*/
