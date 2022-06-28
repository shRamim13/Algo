#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(1);
    q.push(0);

    cout << q.size() << endl;
    q.pop();
    cout << q.size() << endl;

    cout << q.front() << endl;
    cout << q.back() << endl;

    if (q.empty())
        cout << "empty" << endl;
    else
        cout << "filled" << endl;
    while (!q.empty())

    {
        cout << q.front() << "\t";
        q.pop();
    }
}
