#include <bits/stdc++.h>
using namespace std;
const int MXN = 1010;

vector<int> edge[MXN], rev[MXN];
int numNode, numEdge, depends_on[MXN], taken[MXN];

void init()
{
    for (int i = 0; i < MXN; i++)
    {
        edge[i].clear();
        rev[i].clear();
        depends_on[i] = 0;
        taken[i] = 0;
    }
}

vector<int> order;

void printOrder()
{
    cout << "->> ";
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    cout << endl;
}

void backtrack(string pre = "")
{
    cout << pre;
    printOrder();
    cout << pre;
    for (int u = 0; u < numNode; u++)
        printf("%d(%d) ", u, depends_on[u]);
    printf("\n");

    if (order.size() == numNode)
    {
        // printf("HIT");
        printOrder();
        return;
    }

    for (int u = 0; u < numNode; u++)
    {
        if (taken[u] == 1)
            continue;
        if (depends_on[u] != 0)
            continue;
        // cout<<pre;
        // printf("trying to take %d\n", u);
        order.push_back(u);
        taken[u] = 1;
        for (int i = 0; i < rev[u].size(); i++)
        {
            int v = rev[u][i];
            // cout<<pre;
            // printf("decreasing dependency >> %d -> %d\n", v, u);
            depends_on[v]--;
        }

        backtrack(pre + "   ");

        order.pop_back();
        taken[u] = 0;
        for (int i = 0; i < rev[u].size(); i++)
        {
            depends_on[rev[u][i]]++;
        }
    }
}

// a --> b means that (a) depends on (b), ie (b) must be taken before (a)
int main()
{
    freopen("00_inp.txt", "r", stdin);
    while (scanf("%d%d", &numNode, &numEdge) == 2)
    {
        init();

        cout << numNode << " " << numEdge << endl;

        int a, b;
        for (int i = 0; i < numEdge; i++)
        {
            scanf("%d%d", &a, &b);
            cout << a << " --> " << b << endl;
            edge[a].push_back(b);
            depends_on[a]++;
            rev[b].push_back(a);
        }
    }

    // cout<<numNode<<" "<<numEdge<<endl;
    // for(int i = 0; i<numNode; i++){
    //     printf("%d ==> ", i);
    //     for(int j = 0; j<rev[i].size(); j++) printf(" %d", rev[i][j]);
    //     printf("\n");
    // }

    backtrack();

    return 0;
}