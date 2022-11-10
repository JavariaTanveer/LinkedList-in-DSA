#include <iostream>
using namespace std;

class Node
{
public:
    float data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head=NULL;
    }
    void insert(float data)
    {
        Node *t = new Node;
        t->data = data;
        t->next = NULL;

        if(head==NULL)
        {
            head=t;
        }
        else
        {
           Node *temp=head;

           while(temp->next!=NULL)
           {
               temp = temp->next;
           }

           temp->next=t;

        }


    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    LinkedList list;

    list.insert(3.2f);
    list.insert(1.5f);
    list.insert(3.5f);
    list.insert(1.25f);

    list.display();


    return 0;
}
