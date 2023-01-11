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

void makenode(node *root, int b, char c)
{
    if(root == NULL) return;
    if(c == 'L') root->left = new node(b);
    else root->right = new node(b);
}

void insertnode(node *root, int a, int b, char c)
{
    if(root == NULL) return;
    if(root->val == a) makenode(root, b, c);

    insertnode(root->left, a, b, c);
    insertnode(root->right, a, b, c);
}

bool full(node *root)
{
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    if(root->left && root->right) return full(root->left) && full(root->right);
    return false;
}


void deletetree(node *root)
{
    if(root == NULL) return;
    deletetree(root->left);
    deletetree(root->right);
    delete root;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        node *root = NULL;
        while(n--)
        {
            int a, b; char c;
            cin >> a >> b >> c;
            if(root == NULL)
            {
                root = new node(a);
                makenode(root, b, c);
            }
            else insertnode(root, a, b, c);
        }
        cout << full(root);
        deletetree(root);
    }
}
