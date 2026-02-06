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



void leftPrint(Node* root)
{
    if(root == NULL) 
        return ;
    if(root->left != NULL) leftPrint(root->left);
    else leftPrint(root->right);
    cout << root->val << " ";
}
void rightPrint(Node* root)
{
    if(root == NULL) 
        return ;
    cout << root->val << " ";
    if(root->right != NULL) rightPrint(root->right);
    else rightPrint(root->left);


}





int main()
{
    Node* root = inputBinaryTree();
    leftPrint(root->left);
    cout << root->val << " ";
    rightPrint(root->right);



    return 0;
}