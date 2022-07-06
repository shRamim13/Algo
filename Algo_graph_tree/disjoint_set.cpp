#include <bits/stdc++.h>
using namespace std;
#define MX 100
int parent[MX];

void init()
{
    for (int i = 1; i <= 8; i++)
    {
        parent[i] = i;
    }
}
// bool flag = false;

int __find(int u)
{
    /*  if (flag == true)
          cout << " callled with " << u << endl;*/
    if (parent[u] == u)
        return u;
    return parent[u] = __find(parent[u]);
}

void __Union(int u, int v)
{
    int p = __find(u);
    int q = __find(v);

    if (p != q)
        parent[q] = p;
}

bool isFriend(int u, int v)
{
    int p = __find(u);
    int q = __find(v);
                                               // if (p == q)
    return(p==q);                              //     return true;
                                               //  return false;
}

int main()
{
    init();
    /*for (int i = 1; i < 8; i++)
    {
        cout << "Parent of " << i << " is " << parent[i] << endl;
    }
    cout << endl;*/

    __Union(1, 2);
    __Union(2, 3);
    __Union(3, 4);
    __Union(4, 5);
    __Union(5, 6);
    __Union(6, 7);
    __Union(7, 8);

   // flag = true;

    /*  __find(8);
      cout << "-----" << endl;
      __find(2);
      cout << "-----" << endl;
      __find(4);
      cout << "-----" << endl;
  */
    if (isFriend(2, 8))
    {
        cout << " Friends " << endl;
    }
    else
        cout << "Not Friend " << endl;
}