
#include <bits/stdc++.h>
using namespace std;

#define MX 1000000
#define INF 100000
int parent[MX];
stack<int> st;
struct node
{
    int val;
    int cost;
};

// 1 -> {2, 5}, {4, 10}
// 2 -> {5, 40}, {3, 45}

vector<node> G[MX];
bool vis[MX];
int dist[MX];

void reset()
{
    for (int i = 0; i < MX; i++)
    {
        G[i].clear();
        vis[i] = 0;
        dist[i] = INF;
        parent[i] = 0;
    }
}

class cmp
{
public:
    bool operator()(node &A, node &B)
    {
        if (A.cost > B.cost)
            return true;
        return false;
    }
};

void dijkstra(int source)
{
    priority_queue<node, vector<node>, cmp> PQ;
    PQ.push({source, 0});

    parent[source] = -1;

    while (!PQ.empty())
    {
        node current = PQ.top();
        PQ.pop();

        int val = current.val;

        int cost = current.cost;

        if (vis[val] == 1)
            continue; // if visited, then we do not work with that node

        dist[val] = cost; // cost is finalized here
        vis[val] = 1;

       for(int i=0;i<G[val].size();i++)
        {
            int nxt = G[val][i].val;
            int nxtCost = G[val][i].cost;

            if (vis[nxt] == 0)
            {
                parent[nxt] = val;
                PQ.push({nxt, cost + nxtCost});
            }
        }
    }
}

int main()
{

    while (1)
    {
        reset();

        int nodes, edges;
        cin >> nodes >> edges;

        // u v w
        for (int i = 1; i <= edges; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            // G[v].push_back({u, w});
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
        cout << " \n Continue";
    }

    return 0;
}

/*
5 6
1 2 2
1 3 1
1 4 3
2 3 1
4 5 2
5 3 5

*/
