#include <bits/stdc++.h>
using namespace std;
#define MX 100000
vector<int> adj[MX], rev[MX], components[MX], ssd[MX];
int vis[MX], used[MX], parent[MX];
stack<int> st;

void _DFS(int n)
{
    vis[n] = 1;
    for (int i = 0; i < adj[n].size(); i++)
    {
        if (vis[adj[n][i]] == 0)
            _DFS(adj[n][i]);
    }
    st.push(n);
}

void _DFS_2(int u, int grp)
{
    components[grp].push_back(u);
    //parent[u] = grp;
    used[u] = 1;
    for (int i = 0; i < rev[u].size(); i++)
    {
        if (used[rev[u][i]] == 0)
            _DFS_2(rev[u][i], grp);
    }
}

int _Find_SCC(int n) //  kosaraju Algorithm
{
    int mark = 0, u;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            _DFS(i);
    }
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        if (used[x] == 0)
            _DFS_2(x, mark++);
    }
    return mark;
}

/*void _Find_DAG(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (parent[i] != parent[adj[i][j]])
            {

                ssd[parent[i]].push_back(adj[i][j]);
            }
        }
    }
}*/

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }
    int scc = _Find_SCC(nodes);

    cout << "Total components in Strongly Connected Component --> " << scc << endl;
    for (int i = 0; i < scc; i++)
    {
        cout << i + 1 << " : ";

        for (int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }

    //_Find_DAG(nodes);

    //cout << "Total Node in Directed_Acyclic_Graph = " << scc << endl;
    
    /* for (int i = 0; i < scc; i++)
     {
         cout << i << " --> ";
         if (ssd[i].size() == 0)
         {
             cout << "NULL" << endl;
             continue;
         }
         for (int j = 0; j < ssd[i].size(); j++)
         {

             cout << ssd[i][j];
         }
         cout << endl;
     }*/

    return 0;
}
