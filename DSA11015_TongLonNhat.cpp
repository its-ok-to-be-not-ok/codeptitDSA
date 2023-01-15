#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *left, *right;
    node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

void connectNode(node *root, int b, char c)
{
    if(root == NULL) return;
    if(c == 'L') root->left = new node(b);
    else root->right = new node(b);
}

void insertNode(node *root, int a, int b, char c)
{
    if(root == NULL) return;
    if(root->val == a)
    {
        connectNode(root, b, c);
    }
    insertNode(root->left, a, b, c);
    insertNode(root->right, a, b, c);
}

void clean(node *root)
{
    if(root == NULL) return;
    clean(root->left);
    clean(root->right);
    delete root;
}

int maxSum;

int Try(node *root)
{
    if(!(root->left || root->right)) return root->val;
    if(root->left && root->right)
    {
        int a = Try(root->left), b = Try(root->right);
        maxSum = max(maxSum, a + b + root->val);
        root->val = max(a, b) + root->val;
        return root->val;
    }
    else
    {
        if(root->left)
        {
            root->val = Try(root->left) + root->val;
            return root->val;
        }
        else
        {
            root->val = Try(root->right) + root->val;
            return root->val;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        node *root = NULL;
        maxSum = INT_MIN;
        while(n--)
        {
            int a, b; char c;
            cin >> a >> b >> c;
            if(root == NULL)
            {
                root = new node(a);
                connectNode(root, b, c);
            }
            else insertNode(root, a, b, c);
        }
        Try(root);
        cout << maxSum << endl;
        clean(root);
    }
}
















