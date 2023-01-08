#include<bits/stdc++.h>

using namespace std;

// tạo 2 stack lưu node mỗi stack sẽ được push theo trình tự khác nhau, một là L to R(add node bên trái trước bên phải) và R to L
// do khi in stack in kiểu LIFO nghĩa là ngược lại với trình tự add(vd: add L to R print R to L)
// mỗi đợt thì phải in hết sạch node trong stack đang thực hiện in

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
    node *newNode = new node(y);
    if(c == 'L') root->left = newNode;
    else root->right = newNode;
}

void insertNode(node *root, int x, int y, char c)
{
    if(root == NULL) return;
    if(root->val == x)
    {
        makeNode(root, y, c);
    }
    else
    {
        insertNode(root->left, x, y, c);
        insertNode(root->right, x, y, c);
    }
}

void spiralOrder(node *root)
{
    stack<node*> addRtoL; //print L to R
    stack<node*> addLtoR; //print R to L
    addLtoR.push(root);
    int direction = 1;
    while(!addRtoL.empty() || !addLtoR.empty())
    {
        if(direction == 1)
        {
            while(!addLtoR.empty())
            {
                node *X = addLtoR.top(); addLtoR.pop();
                cout << X->val << ' ';
                if(X->right) addRtoL.push(X->right);
                if(X->left) addRtoL.push(X->left);
                direction = 0;
            }
        }
        else
        {
            while(!addRtoL.empty())
            {
                node *X = addRtoL.top(); addRtoL.pop();
                cout << X->val << ' ';
                if(X->left) addLtoR.push(X->left);
                if(X->right) addLtoR.push(X->right);
                direction = 1;
            }
        }
    }
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
        int n; cin >> n;
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
        spiralOrder(root);
        cout << endl;
        deleteTree(root);
    }

}
