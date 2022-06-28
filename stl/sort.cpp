#include <bits/stdc++.h>
using namespace std;
#define MX 100
int num[MX];
vector<int> v;
void random_number_generator(int n)
{
    for (int i = 0; i < n; i++)
    {
        num[i] = rand()%100;
        v.push_back(num[i]);
    }
}
void show_number(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << "\t";
    }
    cout << endl;
}

bool rev(int a, int b)
{
    return (a > b);
}
int main()
{
    int n = 10;
    random_number_generator(n);
    show_number(n);
    sort(num, num + n);
    show_number(n);

   /* {
        int arr[] = {8, 9, 5, 3, 1, 0, 6, 2};
        int s = sizeof(arr) / sizeof(arr[0]); //end(arr)-begin(arr)
        cout << s << endl;
        sort(arr, arr + s, rev);
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << "\t";
        }
    }*/
}