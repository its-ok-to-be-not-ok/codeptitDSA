#include<bits/stdc++.h>

using namespace std;

//tìm depth của node lá bất kỳ ở đây ta chọn node lá trái cùng
//check cây một lượt xem node lá nào có độ sâu khác với node lá ta vừa tìm không

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

void insertNode(node *root, int v, int u, char c)
{
    if(root == NULL) return;
    if(root->val == v)
    {
        if(c == 'L') root->left = new node(u);
        else root->right = new node(u);
    }
    else
    {
        insertNode(root->left, v, u, c);
        insertNode(root->right, v, u, c);
    }
}

int findadepth(node *root)
{
    int d = 0;
    while(root != NULL)
    {
        ++d;
        root = root->left;
    }
    return d;
}

bool check(node *root, int d)
{
    if(root == NULL) return true;

    if(root->left == NULL && root->right == NULL) return d == 1;

    if(!check(root->left , d - 1)) return false;
    if(!check(root->right, d - 1)) return false;

    return true;

}

void deleteTree(node *root)
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
        int n;
        cin >> n;
        node *root = NULL;
        while(n--)
        {
            int v, u; char c;
            cin >> v >> u >> c;
            if(root == NULL)
            {
                root = new node(v);
                node *newNode = new node(u);
                if(c == 'L') root->left = newNode;
                else root->right = newNode;
            }
            else insertNode(root, v, u, c);
        }
        int arbitraryDepth = findadepth(root);
        cout << check(root, arbitraryDepth) << endl;
        deleteTree(root);
    }
}
