#include<iostream>
#include<conio.h>
using namespace std;
class doubly_linked_list
{
private:
    struct node
    {
        int item;
        node *prev;
        node *next;
    };
    node *start;
public:
    doubly_linked_list()
    {
        start=NULL;
    }
    ~doubly_linked_list()
    {
        while(start)
        {
            delete_first();
        }
    }
    void insert_first(int data);
    void insert_last(int data);
    void insert_afterElement(int element,int data);
    void viewListItems();
    void delete_first();
    void delete_last();
    void delete_element(int element);
};
void doubly_linked_list::insert_first(int data)
{
    node *temp=new node;
    temp->item=data;
    temp->prev=NULL;
    temp->next=start;
    if(start!=NULL)
    {
        start->prev=temp;
    }
        start=temp;
}
void doubly_linked_list::viewListItems()
{
    node *temp=start;
    while(temp)
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
}
void doubly_linked_list::insert_last(int data)
{
    node *temp=new node;
    temp->item=data;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        start->prev=NULL;
    }
    else
    {
        node *n=start;
        while(n->next)
        {
            n=n->next;
        }
        n->next=temp;
        temp->prev=n;
    }
}
void doubly_linked_list::insert_afterElement(int element,int data)
{
    node *temp=start;
    while(temp)
    {
        if(temp->item==element)
        {
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout<<"OPERATION FAILED:ELEMENT NOT FOUND!"<<endl;
    }
    else
    {
        node *n=new node;
        n->item=data;
        n->next=temp->next;
        n->prev=temp;
        if(temp->next)
        {
            temp->next->prev=n;
        }
        temp->next=n;
    }
}
void doubly_linked_list::delete_first()
{
    if(start==NULL)
    {
        cout<<"OPERATION FAILED:DOUBLY LINKED LIST IS EMPTY!"<<endl;
    }
    else
    {
        node *temp=start;
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        delete temp;
    }
}
void doubly_linked_list::delete_last()
{
    if(start==NULL)
    {
        cout<<"OPERATION FAILED:DOUBLY LINKED LIST IS EMPTY!"<<endl;
    }
    else
    {
        node *t1,*t2;
        t1=start;
        t2=NULL;
        while(t1->next)
        {
            t2=t1;
            t1=t1->next;
        }
        if(t2==NULL)
        {
            start=NULL;
            delete t1;
        }
        else
        {
            delete t1;
            t2->next=NULL;
        }
    }
}
void doubly_linked_list::delete_element(int element)
{
    node *t1=start,*t2=NULL;
    while(t1)
    {
        if(t1->item==element)
        {
            break;
        }
        t2=t1;
        t1=t1->next;
    }
    if(t1==NULL)
    {
        cout<<"OPERATION FAILED:ELEMENT NOT FLOUND!"<<endl;
    }
    else
    {
        if(t2==NULL)
        {
            start=t1->next;
        }
        else
        {
            t2->next=t1->next;
            if(t1->next!=NULL)
            t1->next->prev=t2;
        }
        delete t1;
    }
}
