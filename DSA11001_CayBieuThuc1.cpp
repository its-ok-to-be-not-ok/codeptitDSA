#include<bits/stdc++.h>

using namespace std;

// construct a tree with every leaf node as operand and middle node as operator.
// create a stack to save operand every time we traversal over it.
// when meet a operator we make a node contain it and 2 nodes to contain 2 top operands in stack, pop them after take out.
// make right pointer of the operator node point at 1st taken-out operand and left pointer point at 2nd taken-out operand.
// print the tree in inorder.

struct node
{
    string val;
    node *left, *right;
    node(string x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void deleteTree(node *root)
{
    if(root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void inorder(node *root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        stack<node*> st;
        cin >> s;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                node *newNode = new node(string(1, s[i]));
                st.push(newNode);
            }
            else
            {
                node *root = new node(string(1, s[i]));
                node *r = st.top(); st.pop();
                node *l = st.top(); st.pop();
                root->left = l;
                root->right = r;
                st.push(root);
            }
        }
        node *root = st.top();
        st.pop();
        inorder(root);
        cout << endl;
        deleteTree(root);
    }
}
















