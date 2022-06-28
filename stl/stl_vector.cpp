#include <bits/stdc++.h>
using namespace std;
struct car
{
    string brand;
    double price;
};

void printVector(vector<car> v)
{
    cout << "size" << " " << v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].brand << " " << v[i].price << endl;
    }
    cout << endl;
}

int main()
{
    vector<car> v;
    car c1 = {"SCANIA", 15000000.250};
    car c2 = {"VOLVO", 15250000.50};
    v.push_back(c1);
    v.push_back(c2);
    printVector(v);
    return 0;
}
