#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(a[i], a[j]);
    } while (i < j);
    swap(a[l], a[j]);
    return j;
}

void __quick_sort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        __quick_sort(a, l, j);
        __quick_sort(a, j + 1, h);
    }
}

int main()
{
    // int a[] = {11, 13, 7, 16, 9, 24, 5, 3, 10};
    // int n=9, i;

    int n, i;
    cin >> n;
    int a[n+1];
    for (int i = 0; i < n; i++)
    {
        //cin >> a[i];
        a[i]=rand();
    }

    __quick_sort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
/*1
2
3
4
5
6
7
8
9
10
1
2 
3 
4 
5 
6 
7 
8 
9 
10
1
2 
3 
4 
5 
6 
7 
8 
9 
10
1
2 
3 
4 
5 
6 
7 
8 
9 
10
1
2
3
4
5
6
7
8
9
10
1
2
3
4
5
6
7
8
9
10
1
2
3
4
5
6
7
8
9
10
1
2
3
4
5
6
7
8
9
10
1
2
3
4
5
6
7
8
9
10
1
2
3
4
5
6
7
8
9
10*/