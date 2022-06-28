#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> mp;
    map<int, int>::iterator it;
    for (int i = 0; i < 20; i++)
    {
        mp[rand() % 6]++;
    }

    cout << mp.size() << endl;

    mp[7] = 12;
    mp.insert(make_pair(6, 9));
    for (it = mp.begin(); it != mp.end(); it++)
    {                                                   // first section alaways be unique
        cout << it->first << " " << it->second << "\n"; // sorted in ascending or alphabetical order
    }
    cout << endl;
    map<string, int> m;
    map<string, int>::iterator i;
    m["shyamoli"] = 4;
    m["ena"] = 4;
    m["hanif"] = 5;
    m["unique"] = 2;
    m.insert(make_pair("soudia", 1));
    m["ena"] = 5;

    cout << m.size() << endl;
    for (i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " " << i->second << "\n";
    }

    return 0;
}
