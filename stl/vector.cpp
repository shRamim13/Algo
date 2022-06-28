#include <bits/stdc++.h>
using namespace std;
bool myfunc(int a, int b)
{
    return (a > b);
}
int main()
{
    {
        vector<int> v(5, 13);
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << "\t";
        cout << endl;
        v.clear();
        cout << v.size() << endl;
        cout << endl;
    }
    {
        vector<int> vec = {5, 4, 9, 2, 1, 3, 6, 8, 7, 0};

        cout << vec.size() << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << "\t";
        }
        cout << endl;
    }

    {
        vector<int> vec;
        vector<int>::iterator it;
        vec.push_back(4);
        vec.push_back(10);
        vec.push_back(34);
        vec.push_back(1);
        vec.push_back(-334);
        vec.push_back(104);
        vec.push_back(384);
        vec.push_back(10);
        vec.push_back(3468);
        vec.push_back(110);
        vec.push_back(-34);
        vec.push_back(101);
        sort(vec.begin(), vec.end(), myfunc);
        //sort(vec.begin(),vec.begin()+5);
        reverse(vec.begin(), vec.end());
        for (it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << "\t";
        }
        cout << endl;
    }

    {
        int arr[5] = {5, 2, 1, 6, 3};
        vector<int> mylist(arr, arr + 5);
        vector<int>::iterator it;

        it = find(mylist.begin(), mylist.end(), 6);
        cout << *it << endl;
        cout << *it << endl;
        if (it == mylist.end())
            cout << "not found" << endl;
        else
            cout << "found" << endl;

        mylist.erase(it);
        cout << *it << endl;
        for (it = mylist.begin(); it != mylist.end(); it++)
        {
            cout << *it << "\t";
        }
        cout << endl;
    }
    
    return 0;
}