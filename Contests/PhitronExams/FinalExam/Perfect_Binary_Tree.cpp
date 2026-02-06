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

int sumWithOutLeaf(Node* root)
{
    int sum = 0;
    if(root->left == NULL && root->right == NULL) return sum;
    queue<Node*> q;
    q.push(root);
    sum += root->val;
    // cout << root->val << " ";
    while (!q.empty())
    {
        Node* parent = q.front();
        q.pop();
        if(parent->left)
        {
            q.push(parent->left);
            if(parent->left->left != NULL || parent->left->right != NULL) sum += parent->left->val;
            // cout << parent->left->val << " ";
        } 
        if(parent->right)
        {
            q.push(parent->right);
            // cout << parent->right->val << " ";
            if(parent->right->left != NULL || parent->right->right != NULL) sum += parent->right->val;
        }

    }
    // cout << endl;
    return sum ;
    

}

int withOutLeafSum(Node* root)
{
    if(root == NULL) 
        return 0;
    if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    int l_sum = withOutLeafSum(root->left);
    int r_sum = withOutLeafSum(root->right);

    return l_sum + r_sum + root->val;
}

int nodeCount(Node* root)
{
    int cnt = 0;
    if(root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    cnt++;
    // cout << root->val << " ";
    while (!q.empty())
    {
        Node* parent = q.front();
        q.pop();
        if(parent->left)
        {
            q.push(parent->left);
            // cout << parent->left->val << " ";
            cnt++;
        } 
        if(parent->right)
        {
            q.push(parent->right);
            // cout << parent->right->val << " ";
            cnt++;
        }

    }
    return cnt;
    

}


int maxDepth(Node* root)
{
    if(root == NULL) 
        return 0;
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);

    return max(lDepth, rDepth) + 1;
}

int main()
{
    Node* root = inputBinaryTree();
    // levelOrderPrint(root);
    // cout << sumWithOutLeaf(root);
    // cout << withOutLeafSum(root);
    int maxiDepth = maxDepth(root) ;
    int noOfNodes = nodeCount(root);

    cout << ((pow(2,maxiDepth) -1 == noOfNodes)? "YES" : "NO") << endl;
    return 0;
}