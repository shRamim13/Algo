#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};
node *head;
void print()
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}
void insert_beginning(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->link = head;
    head = temp;
}

void insert_last(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *t = head;
        while (t->link != NULL)
        {
            t = t->link;
        }
        t->link = temp;
    }
}

/*
void insert(int data, int n)

{
    node *t1 = new node();
    t1->data = data;
    t1->link = NULL;
    if (n == 1)
    {
        t1->link = head;
        head = t1;
    }
    else
    {
        node *t2 = head;
        for (int i = 1; i <= n - 2; i++)
        {
            t2 = t2->link;
        }
        t1->link = t2->link;
        t2->link = t1;
    }
}*/

void delete_nthNode(int n)
{
    if (n == 1)
    {
        node *temp = head;
        head = head->link;
        free(temp);
    }
    else
    {
        node *temp1 = head;

        for (int i = 1; i <= n - 2; i++)
        {
            temp1 = temp1->link;
        }
        node *temp2;
        temp2 = temp1->link;
        temp1->link = temp2->link;
        free(temp2);
    }
}

int main()
{
    head = NULL;
    insert_beginning(4);
    insert_last(7);
    insert_beginning(1);
    insert_last(9);
    delete_nthNode(2);
    insert_beginning(5);
    print();
    delete_nthNode(1);
    insert_last(9);
    insert_last(13);
    print();
    insert_beginning(2);
    delete_nthNode(2);
    insert_last(10);
    print();
    delete_nthNode(3);
    print();
    /* head->data = 2;
     head->link = new node();
     head->link->data = 5;
     head->link->link = NULL;
     print();*/
    /*insert(1, 7);
    insert(2, 5);
    insert(1, 1);
    insert(2, 2);
    print();*/
}