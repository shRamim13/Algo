#include <bits/stdc++.h>
using namespace std;
int main()
{
    {
        set<pair<string, string>> s;
        set<pair<string, string>>::iterator it;
        s.insert(make_pair("sabbir", "CSE"));
        s.insert(make_pair("dipta", "PHY"));
        s.insert(make_pair("miraj", "IT"));
        s.insert(make_pair("akanda", "GEB"));
        s.insert(make_pair("jahin", "STAT"));
        s.insert(make_pair("dipu", "PHARM"));
        s.insert(make_pair("jahin", "STAT"));
        for (it = s.begin(); it != s.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;
    }

    set<int> s;
    set<int>::iterator it;
    for (int i = 0; i < 200; i++)
    {
        s.insert(rand() % 10);
    }
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << "\t";
    }

    cout << endl;

    {
        set<int> s;
        set<int>::iterator it;
        for (int i = 0; i < 200; i++)
        {
            s.insert(rand() % 10);
        }
        it = s.find(5);
        s.erase(it);
        s.insert(2);
        s.insert(3);
        for (it = s.begin(); it != s.end(); it++)
        {
            cout << *it << "\t";
        }
        cout << endl;
    }
}