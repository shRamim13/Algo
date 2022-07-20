#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];
vector<int> vis(N, 0);
vector<int> dist(N, INF);
vector<int> parent(N, 0);
stack<int> st;

void dijkstra(int source)
{

    set<pair<int, int>> st; //weight ,node
    st.insert({0, source});
    dist[source] = 0;
    parent[source] = -1;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int dist_v = node.first;
        st.erase(st.begin());

        if (vis[v])
            continue;
        vis[v] = 1;

        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                parent[child_v] = v;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    cout << "enter source: ";
    int source;
    cin >> source;

    dijkstra(source);

    cout << "\n";
    for (int i = 1; i <= nodes; i++)
    {
        cout << "Node: " << i << " Distance: ";
        if (dist[i] == INF)
            cout << "inf"
                 << "\n";
        else
            cout << dist[i] << "\n";
    }

    int destination;

    cout << "Enter destination --> ";
    cin >> destination;
    int n = destination;
    st.push(n);
    int flag = 1;
    while (parent[n] != -1)
    {
        if (parent[n] == 0)
        {
            flag = 0;
            break;
        }
        n = parent[n];
        st.push(n);
    }

    cout << "Path ::: From " << destination << " to source " << source << " -->  ";
    if (flag == 0)
        cout << " There is no path ";
    else
    {
        while (!st.empty())
        {
            cout << st.top() << "(" << dist[st.top()] << ")"
                 << " ";
            st.pop();
        }
    }
}