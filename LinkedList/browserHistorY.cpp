#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        string val ;
        Node* next;
        Node* pre;
    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }

};

class BrowserHistory {
public:
    Node* head = NULL;
    Node* tail = NULL;

    BrowserHistory(string homepage) {
       Node* newNode = new Node(homepage);
       head = newNode;
       tail = newNode;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);

        head->next = newNode;
        newNode->pre = tail;
        head = newNode;       
    }
    
    string back(int steps) {
        // Node* tem = tail;
        while(steps-- && head->pre!=NULL)
        {
            head = head->pre;
        }
        return head->val;
    }
    
    string forward(int steps) {
        // Node* tem = tail;
        while(steps-- && head->next!=NULL)
        {
            head = head->next;
        }
        return head->val;
    }
            
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */