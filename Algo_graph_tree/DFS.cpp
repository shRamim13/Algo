#include <bits/stdc++.h>
using namespace std;
#define MX 100000
vector<int> v[MX];
bool vis[MX];
void dfs(int source)
{
    vis[source] = 1;
    for (int i = 0; i < v[source].size(); i++)
    {
        int nxt = v[source][i];
        if (vis[nxt] == 0)
        {
            dfs(nxt);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, w;
        cin >> u >> w;
        v[u].push_back(w);

        v[w].push_back(u);
    }
    int component = 1;
    int source;
    cout<<"Enter Source --> ";
    cin>>source;
    dfs(source);
    for (int i = 0; i < nodes; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            component++;
        }
    }
    cout << " Total component   " << component << endl;
    ;
    for (int i = 0; i < nodes; i++)
    {
        if (vis[i] == 0)
            cout << " node " << i << " is not visited" << endl;
        else
            cout << " node " << i << " is visited" << endl;
    }

    return 0;
    
}

/*
5 4
0 1
1 2
1 3
3 4
*/

/*
7 5
0 1
1 2
1 3
3 4
5 6
*/