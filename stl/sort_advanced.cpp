#include <bits/stdc++.h>
using namespace std;
#define MX 100
struct B_Info
{
    int id;
    string name;
    int merit_position;
};

bool cmp(B_Info p, B_Info q)
{
    if (p.id < q.id)
        return p.id < q.id;
    else if (p.id == q.id && p.merit_position > q.merit_position)
        return p.merit_position > q.merit_position;
    else if (p.id == q.id && p.merit_position == q.merit_position && p.name < q.name)
        return p.name < q.name;
    else
        return false;
}
int n;
B_Info info[10];

void inputFile()
{
    for (int i = 0; i < n; i++)
    {
        cin >> info[i].id >> info[i].name >> info[i].merit_position;
    }
}
void outputFile()
{
    for (int i = 0; i < n; i++)
    {
        cout << info[i].id << " " << info[i].name << " " << info[i].merit_position << endl;
    }
    cout << endl;
}

int main()
{
    freopen("i.txt", "r", stdin);
    cin >> n;
    inputFile();
    sort(info, info + n, cmp);
    outputFile();
    return 0;
}