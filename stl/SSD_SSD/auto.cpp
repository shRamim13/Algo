#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    for (int &x : v)
    {
        x++;
    }
    for (int x : v)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    cout<<endl;
    vector<pair<int,int>>v_p={{1,2},{3,4},{5,6},{7,8}};
    for (pair<int,int> it: v_p)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
   cout<<endl;
   for (auto &x:v_p)
   {
    cout<<x.first<<" "<<x.second<<endl;
}
return 0;
}