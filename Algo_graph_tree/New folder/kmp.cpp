#include <bits/stdc++.h>
using namespace std;

vector<int> _find_lps(string pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < pattern.length();)
    {
        if (pattern[index] == pattern[i])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if (index != 0)
            {
                index = lps[index - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return lps;
}

void _KMP(string text, string pattern)
{
    bool flag = false;
    vector<int> lps = _find_lps(pattern);
    int i = 0, j = 0;
    while (i < (int)text.length())
    {
        if (pattern[j] == text[i])
        {
            i++, j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == (int)pattern.length())
        {
            cout << "Pattern found at := " << (i + 1 - (int)pattern.length()) << endl;
            j = lps[j - 1];
            flag = true;
        }
    }
    if (!flag)
        cout << "Pattern nos found" << endl;
}

int main()
{
    string pattern, text;
    getline(cin, text);
    getline(cin, pattern);
    _KMP(text, pattern);
    return 0;
}