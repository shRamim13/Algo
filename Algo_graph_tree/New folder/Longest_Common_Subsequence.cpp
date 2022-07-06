#include <bits/stdc++.h>
using namespace std;
#define MX 1005

int dp[MX][MX];

int _LCS(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = _LCS(i - 1, j, s1, s2);
    ans = max(ans, _LCS(i, j - 1, s1, s2));
    ans = max(ans, _LCS(i - 1, j - 1, s1, s2)) + (s1[i] == s2[j]); // if true ans++else escape
    return dp[i][j] = ans;
}

void _Longest_Common_Subsequence(string s1, string s2)
{
    int answer;
    int m = s1.size();
    int n = s2.size();
    memset(dp, -1, sizeof(dp));
    answer = _LCS(m - 1, n - 1, s1, s2);

    cout << "Longest_Common_Subsequence ==> " << answer << endl;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    _Longest_Common_Subsequence(s1, s2);
}