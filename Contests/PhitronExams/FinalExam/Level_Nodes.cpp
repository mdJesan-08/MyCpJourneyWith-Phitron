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

void levelOrderPrint(Node* root)
{
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    cout << root->val << " ";
    while (!q.empty())
    {
        Node* parent = q.front();
        q.pop();
        if(parent->left)
        {
            q.push(parent->left);
            cout << parent->left->val << " ";
        } 
        if(parent->right)
        {
            q.push(parent->right);
            cout << parent->right->val << " ";
        }

    }
    cout << endl;
    

}



void targetLevelPrint(Node* root, int targetLevel)
{
    bool isMatched = false;
    if(root == NULL) return;
    queue< pair<Node* ,int> > q;
    int curLevel = 0;
    q.push({root, curLevel});
    // if(targetLevel == 0) cout << root->val << " ";

    while (!q.empty())
    {
        pair<Node* ,int>  parent = q.front();
        q.pop();
        if(targetLevel == parent.second)
        {
            cout << parent.first->val << " ";
            isMatched = true;
        } 
        if(parent.first->left)
        {
            q.push({parent.first->left, parent.second +1});
            // cout << parent.first->left->val << " ";
        } 
        if(parent.first->right)
        {
            q.push({parent.first->right, parent.second+1});
            // cout << parent->right->val << " ";
        }

    }
    if(isMatched == false) cout << "Invalid";
    cout << endl;
    

}

int main()
{
    Node* root = inputBinaryTree();
    int targetLevel;
    cin >> targetLevel;
    targetLevelPrint(root, targetLevel);


    return 0;
}