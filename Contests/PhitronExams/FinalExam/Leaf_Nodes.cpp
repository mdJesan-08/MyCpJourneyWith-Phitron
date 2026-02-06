#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* inputBinaryTree()
{
    int val ;
    cin >> val;
    if(val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* parent = q.front();

        int l,r;
        cin >> l >> r;
        Node* myLeft;
        Node* myRight;

        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);

        if(r == -1) myRight = NULL;
        else myRight = new Node(r);

        // Before putting new left right I have to pop the parent
        q.pop();
        parent->left = myLeft;
        parent->right = myRight;

        if(myLeft) q.push(myLeft);
        if(myRight) q.push(myRight);

    }
    return root;

}



void leafNodePrint(Node* root)
{
    // int sum = 0;
    vector<int> arr;
    if(root->left == NULL && root->right == NULL)
    {
        cout << root->val;
        return;
    } 
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* parent = q.front();
        q.pop();
        if(parent->left)
        {
            q.push(parent->left);
            if(parent->left->left == NULL && parent->left->right == NULL) arr.push_back(parent->left->val);
        } 
        if(parent->right)
        {
            q.push(parent->right);
            if(parent->right->left == NULL && parent->right->right == NULL) arr.push_back(parent->right->val);
        }

    }
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0 ; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    // cout << endl;

}

vector<int> arr;
void print_leafNodes(Node* root)
{
    if(root == NULL)
        return ;
    if(root->left == NULL && root->right == NULL) 
    {
        arr.push_back(root->val);
        return ;
    }
    print_leafNodes(root->left);
    print_leafNodes(root->right);    
}



int main()
{
    Node* root = inputBinaryTree();

    print_leafNodes(root);
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0 ; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}