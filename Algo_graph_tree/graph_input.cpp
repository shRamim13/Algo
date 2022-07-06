#include <bits/stdc++.h>
using namespace std;
vector<int> v[100];
void print_graph(vector<int> v[], int n)
{
    cout << "The graph is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
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
    print_graph(v, 7);
    return 0;
}


/*
5 4
0 1
1 2
1 3
3 4*/