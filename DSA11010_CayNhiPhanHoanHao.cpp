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

void makeNode(node *root, int y, char c)
{
    if(root == NULL) return;
    node *newNode = new node(y);
    if(c == 'L') root->left = newNode;
    else root->right = newNode;
}

void insertNode(node *root, int x, int y, char c)
{
    if(root == NULL) return;
    if(root->val == x) makeNode(root, y, c);
    else
    {
        insertNode(root->left, x, y, c);
        insertNode(root->right, x, y, c);
    }
}

void _delete(node *root)
{
    if(root == NULL) return;
    _delete(root->left);
    _delete(root->right);
    delete root;
}

int depth(node *root)
{
    int d = 0;
    while(root != NULL)
    {
        ++d;
        root = root->left;
    }
    return d;
}

bool perfectTree(node *root, int d)
{
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return d == 1;

    if(root->left && root->right)
    {
        if(!perfectTree(root->left, d - 1)) return false;
        if(!perfectTree(root->right, d - 1)) return false;
        return true;
    }

    return false;
}

void inorder(node *root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        node *root = NULL;
        while(n--)
        {
            int x, y; char c;
            cin >> x >> y >> c;
            if(root == NULL)
            {
                root = new node(x);
                makeNode(root, y, c);
            }
            else insertNode(root, x, y, c);
        }
        int d = depth(root);
        if(perfectTree(root, d)) cout << "Yes" << endl;
        else cout << "No" << endl;
        _delete(root);
    }
}
