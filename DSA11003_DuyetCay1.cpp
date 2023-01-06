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

int linearSearch(int x,int in[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        if(in[i] == x) return i;
    }
    return -1;
}

node* treeBuild(int in[], int pre[], int n)
{
    node *root = new node(pre[0]);
    int m = linearSearch(pre[0], in, n);
    if(m != 0)root->left = treeBuild(in, pre + 1, m);
    if(m != n - 1) root->right = treeBuild(in + m + 1, pre + m + 1, n - m - 1);

    return root;
}

/*

shortcut way without building a tree.

void postorder2(int in[], int pre[], int n)
{
    int m = linearSearch(pre[0], in, n);
    if(m != 0) postorder2(in, pre + 1, m);
    if(m != n - 1) postorder2(in + m + 1, pre + m + 1, n - m - 1);
    cout << pre[0] << ' ';
}
*/

void postorder(node* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

void deleteTree(node* root)
{
    if(root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int in[n], pre[n];
        for(int i = 0; i < n; ++i) cin >> in[i];
        for(int i = 0; i < n; ++i) cin >> pre[i];
        node *root = treeBuild(in, pre, n);
        postorder(root);
        deleteTree(root);
        cout << endl;
    }
}
