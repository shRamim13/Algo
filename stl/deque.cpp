#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(1);
    dq.push_front(0);

    cout << dq.back() << endl;
    cout << dq.front() << endl;
    /*while (!dq.empty())
    {
        cout << dq.front() << "\t";
        dq.pop_front();
    }*/

    cout << dq.size() << endl;

    while (!dq.empty())
    {
        cout << dq.back() << "\t";
        dq.pop_back();
    }
    cout << endl;
    if (dq.empty())
        cout << "empty" << endl;
    else
        cout << "filled" << endl;
    return 0;
}