#include <bits/stdc++.h>
using namespace std;
#define MX 100000
int dp[MX];
vector<int> arr(MX);
int _LIS(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (arr[i] > arr[j])
            ans = (ans, _LIS(j) + 1);
    }
    return dp[i] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, _LIS(i));
    }

    cout << "Longest Increasing Subsequence ==> " << ans << endl;
    return 0;
}