#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        string val;
        Node* next;
        Node* pre;
    Node(string val)
    {
        this->val = val;
        this->next = NULL;
    }

};
void addElementAtEnd(Node* &head, Node* &tail,string val)
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
        newNode->pre = tail;
        tail = newNode;
    }
}
void print(Node* head)
{
    Node* tem = head;
    while (tem!= NULL)
    {
        cout << tem->val << " ";
        tem = tem->next;
    }
    cout << endl;
    
}
int main()
{
    string val;
    Node* head = NULL;
    Node* tail = NULL;
    while(cin >> val && val != "end") {
        
        addElementAtEnd(head, tail, val);
    }
    // print(head);
    int Q;
    cin >> Q;
    Node* curr = head;
    while (Q--)
    {
        string command;
        cin >> command;
        if(command == "prev")
        {
            if(curr->pre == NULL) cout << "Not Available" << endl;
            else
            {
                curr = curr->pre;
                cout << curr->val << endl;
            }
        }
        else if(command == "next")
        {
            if(curr->next == NULL) cout << "Not Available" << endl;
            else
            {
                curr = curr->next;
                cout << curr->val << endl;                
            }
        }
        else
        {
            string website;
            cin >> website;
            Node* tem = head;
            while (tem!= NULL)
            {
                if(tem->val == website) 
                {
                    curr = tem;
                    cout << curr->val << endl;
                    break;
                }
                tem = tem->next;
            }
            if(tem == NULL) cout << "Not Available" << endl;
            
        }
    }
    return 0;
}