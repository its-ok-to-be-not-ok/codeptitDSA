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

bool confront_2_tree(node *r1, node *r2)
{
    if(r1 == NULL && r2 == NULL) return true;
    else if(r1 && r2)
    {
        if(confront_2_tree(r1->left, r2->left) && confront_2_tree(r1->right, r2->right))
        {
            return r1->val == r2->val;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        node *root[2];
        root[0] = NULL;
        root[1] = NULL;
        for(int i = 0; i <= 1; ++i)
        {
            int n;
            cin >> n;
            while(n--)
            {
                int a, b; char c; cin >> a >> b >> c;
                if(root[i] == NULL)
                {
                    root[i] = new node(a);
                    connectNode(root[i], b, c);
                }
                else insertNode(root[i], a, b, c);
            }
        }
        cout << confront_2_tree(root[0], root[1]) << endl;
        clean(root[0]);
        clean(root[1]);
    }
}
