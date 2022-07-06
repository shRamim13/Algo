#include <bits/stdc++.h>
using namespace std;
#define RUN_FAST ios::sync_with_stdio(false);

vector<int> ssd(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        nge[st.top()] = -1; 
        st.pop();
    }
    return nge;
}
int main()
{
    RUN_FAST;
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> _nextGreater = ssd(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " nextGreater --> " << (_nextGreater[i] == -1 ? -1 : v[_nextGreater[i]]) << endl;
    }
    return 0;
}