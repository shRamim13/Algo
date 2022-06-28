#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<string> s;
    s.push("shaymoli");
    s.push("unique");
    s.push("hanif");
    s.push("soudia");
    s.push("ena");

    cout << s.size() << endl;

    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;

    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    return 0;
}