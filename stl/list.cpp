#include <bits/stdc++.h>
using namespace std;
int main()
{
    {
        list<int> vec;
        list<int>::iterator it;
        vec.push_back(4);
        vec.push_back(10);
        vec.push_front(34);
        vec.push_back(1);
        vec.push_front(-334);
        vec.push_back(104);
        vec.push_front(384);
        vec.push_back(10);
        vec.push_back(3468);
        vec.push_front(110);
        vec.push_back(-34);
        vec.push_back(101);

        vec.sort();

        vec.reverse();

        cout << vec.size() << endl;

        for (it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << "\t";
        }
        cout << endl;
        vec.clear();
        cout << vec.size() << endl;
        cout << endl;
    }
    {
        int arr[5] = {5, 2, 1, 6, 3};
        list<int> mylist(arr, arr + 5);
        list<int>::iterator it;

        it = find(mylist.begin(), mylist.end(), 6);

        cout << *it << endl;
        mylist.insert(it, 7);
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
    {
        int arr[5] = {5, 2, 1, 6, 3};
        list<int> mylist(arr, arr + 5);
        list<int>::iterator it;

        if (mylist.empty())
            cout << "empty" << endl;
        else
            cout << "filled" << endl;

        cout << mylist.front() << endl;
        cout << mylist.back() << endl;

        for (it = mylist.begin(); it != mylist.end(); it++)
        {
            cout << *it << "\t";
        }
        cout << endl;

        mylist.pop_back();
        mylist.pop_front();
        for (it = mylist.begin(); it != mylist.end(); it++)
        {
            cout << *it << "\t";
        }
        cout << endl;
    }
    return 0;
}