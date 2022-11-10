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
    Node *tail;
public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }

    void insertAtStart(float data)
    {
        Node *N = new Node;
        N->data = data;
        N->next = head;

        if(head==NULL)
        {
            tail = N;
        }
        head = N;
    }

    void insertAtEnd(float data)
    {
        Node *N = new Node;
        N->data = data;
        N->next = NULL;

        if(head == NULL)
        {
            head = N;
            tail = N;
        }
        else
        {
            tail->next = N;
            tail = N;
        }
    }

    void insertSorted(float data)
    {

        if(head==NULL)
        {
            insertAtStart(data);
        }
        else
        {
            if(head->data>data)
            {
                insertAtStart(data);
            }
            else if(data>tail->data)
            {
                insertAtEnd(data);
            }
            else
            {
                // added in the center of list
                Node *prev = head;
                Node *temp = head->next;

                while(temp->data<data)
                {
                    prev = temp;
                    temp = temp->next;
                }

                Node *N = new Node;
                N->data = data;
                N->next = temp;
                prev->next = N;

            }
        }

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

    void deleteFromStart()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            Node *temp = head;

            if(head==tail)
            {
                head=tail=NULL;
                delete temp;
            }
            else
            {
                head = head->next;
                delete temp;
            }
        }
    }

    void deleteData(float data)
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            Node *temp = head;

            if(head->data==data)
            {
                deleteFromStart();
            }
            else if(tail->data==data)
            {
                deleteFromEnd();
            }
            else
            {
                Node* prev = head;
                Node* temp = prev->next;

                bool found=false;

                while(temp->next!=NULL)
                {
                    if(temp->data==data)
                    {
                        prev->next = temp->next;
                        delete temp;
                        found = true;
                        break;
                    }

                    prev = temp;
                    temp=temp->next;
                }

                if(found==false)
                {
                    cout<<"Data not found"<<endl;
                }
                else
                {
                    cout<<"Data deleted successfully"<<endl;
                }
            }
        }
    }


    void deleteFromEnd()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            Node *temp = head;

            if(head==tail)
            {
                head=tail=NULL;
                delete temp;
            }
            else
            {
                while(temp->next!=tail)
                {
                    temp = temp->next;
                }
                tail = temp;
                temp = temp->next;
                delete temp;
                tail->next = NULL;
            }
        }
    }
};

int main()
{
    LinkedList list;
    list.insertSorted(3);
    list.insertSorted(15);
    list.insertSorted(4);
    list.insertSorted(7);
    list.insertSorted(16);

    list.deleteFromStart();
    list.insertSorted(255);
    list.deleteFromEnd();
    list.deleteData(15);
    list.deleteData(7);


    list.display();


    return 0;
}
