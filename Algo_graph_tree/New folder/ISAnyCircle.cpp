#include <bits/stdc++.h>
using namespace std;
#define MX 10000
vector<int> G[MX];
bool vis[MX];

bool dfs(int source, int parent)
{
    vis[source] = true;
    bool isLoopExists = false;
    for (int child : G[source])
    {
        if (vis[child] && child == parent)
            continue;
        if (vis[child])
            return true;

        isLoopExists |= dfs(child, source);
    }
    return isLoopExists;
}
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bool isLoopExist = false;
    for (int i = 1; i <= m; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, 0))
            {
                isLoopExist = true;
                break;
            }
        }
    }
     
    if (isLoopExist == true)
        cout << "Cycle Detected" << endl;
    else
        cout
            << "No Cycle" << endl;
    return 0;
}

/*
8 6
1 2 
2 3 
2 4 
3 5 
6 7 
1 5 */