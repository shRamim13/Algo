#include <bits/stdc++.h>
using namespace std;
int main()
{
    {
        pair<string, int> p;
        p.first = "sabbir";
        p.second = 94;
        cout << p.first << " " << p.second << endl;
    }
    {
        pair<string, int> p("sabbir", 95);

        cout << p.first << " " << p.second << endl;
    }
    {
        pair<string, int> p;
        p = make_pair("sabbir", 96);

        cout << p.first << " " << p.second << endl;
    }
    {
        vector<pair<string, int>> v;
        v.push_back(make_pair("Sabbir", 97));
        v.push_back(make_pair("Ramim", 98));
        cout << v[0].first << " " << v[0].second << endl;
        cout << v[1].first << " " << v[1].second << endl;
    }
    {
        vector<pair<string, int>> v;
        vector<pair<string, int>>::iterator it;
        v.push_back(make_pair("Sabbir", 97));
        v.push_back(make_pair("Ramim", 98));
        for (it = v.begin(); it != v.end(); it++)
        {

            cout << it->first << " " << it->second << endl;
        }
    }
    
    {
        vector<pair<string, pair<string, int>>> v;
        vector<pair<string, pair<string, int>>>::iterator it;

        v.push_back(make_pair("Sabbir", make_pair("CSE", 19)));
        v.push_back(make_pair("Ramim", make_pair("NDC", 19)));
        for (it = v.begin(); it != v.end(); it++)
        {

            cout << it->first << " " << it->second.first << " " << it->second.second << endl;
        }
    }
    return 0;
}