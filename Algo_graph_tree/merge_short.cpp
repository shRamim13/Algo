#include <bits/stdc++.h>
using namespace std;
#define MX 100000
// int arr[MX];

void merge(int arr[], int l, int r, int mid)
{
    int l_sz = mid - l + 1;
    int r_sz = r - mid;
    int L[l_sz + 1];
    int R[r_sz + 1];
    for (int i = 0; i < l_sz; ++i)
    {
        L[i] = arr[i + l];
    }
    for (int i = 0; i < r_sz; ++i)
    {
        R[i] = arr[i + mid + 1];
    }
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i = 0;
    int r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            arr[i] = L[l_i];
            l_i++;
        }
        else
        {
            arr[i] = R[r_i];
            r_i++;
        }
    }
}
void merge_sort(int arr[], int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, r, mid);
}

int main()
{
    /*int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }*/
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
#define MX 100000
// int arr[MX];
int arr[] = {12, 11, 13, 3, 9, 5, 6, 10, 4, 1, 2, 8, 7};
int n = sizeof(arr) / sizeof(arr[0]);

void merge(int l, int r, int mid)
{
    int l_sz = mid - l + 1;
    int r_sz = r - mid;
    int L[l_sz + 1];
    int R[r_sz + 1];
    for (int i = 0; i < l_sz; ++i)
    {
        L[i] = arr[i + l];
    }
    for (int i = 0; i < r_sz; ++i)
    {
        R[i] = arr[i + mid + 1];
    }
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i = 0;
    int r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            arr[i] = L[l_i];
            l_i++;
        }
        else
        {
            arr[i] = R[r_i];
            r_i++;
        }
    }
}
void merge_sort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, r, mid);
}

int main()
{
   

    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}*/