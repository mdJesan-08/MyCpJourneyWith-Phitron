#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }

};
void insertHead(Node* &head,Node* &tail,int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void print(Node* head)
{
    Node* tem = head;
    while (tem != NULL)
    {
        /* code */
        cout << tem->val << " ";
        tem = tem->next;
    }
    cout << endl;
    
}

int main()
{
    int n;
    cin >> n;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if(val%2 == 0) insertHead(evenHead, evenTail, val);
        else insertHead(oddHead, oddTail, val);
        
    }
    if(evenTail!= NULL) 
    {
        evenTail->next = oddHead;
        print(evenHead);
    }
    else  print(oddHead);
    
    return 0;
}