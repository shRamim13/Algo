#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> q;
    q.push(2);
    q.push(8);
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(3);
    cout << q.top() << endl;
    cout << q.size() << endl;
    q.pop();
    while (!q.empty())
    {
        cout << q.top() << "\t";
        q.pop();
    }

    return 0;
}