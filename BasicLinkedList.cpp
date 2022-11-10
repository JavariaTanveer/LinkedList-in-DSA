#include <iostream>
using namespace std;

class Node
{
private:
    float cgpa;
    Node* next;
public:
    Node()
    {
        cgpa = 0.0f;
        next = NULL;
    }
    Node(float cgpa)
    {
        this->cgpa = cgpa;
        next = NULL;
    }
    Node* getNext()
    {
        return next;
    }
    void setNext(Node* n)
    {
        next = n;
    }
    float getCGPA()
    {
        return cgpa;
    }

};

class LinkedList
{
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    void addAtEnd(float data)
    {
        Node *N = new Node(data);

        if(head==NULL)
        {
            head = N;
        }
        else
        {
            Node *temp = head;
            while(temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(N);
        }
    }
    void display()
    {
        if(head == NULL)
        {
            cout<<"List is Empty."<<endl;
        }
        else
        {
            Node* temp = head;
            while(temp->getNext() != NULL)
            {
                cout<<temp->getCGPA()<< " -> ";
                temp = temp->getNext();
            }
            cout<<temp->getCGPA()<<endl;
        }
    }

    void addAtStart(float data)
    {
        Node *N = new Node(data);
        N->setNext(head);
        head = N;
    }

};

int main()
{
    LinkedList lst;
    lst.addAtEnd(3.5f);
    lst.addAtEnd(2.11f);
    lst.addAtEnd(3.1f);
    lst.addAtStart(1.5f);
    lst.addAtEnd(4.0f);
    lst.addAtStart(1.11f);
    lst.display();

    return 0;
}






