#include<bits/stdc++.h>

using namespace std;

// dùng tập level order để xác định node gốc đầu tiên của cây là phần tử đầu tiên của dãy
// tra vị trí của gốc trong dãy inorder từ đây ta tìm các phẩn tử sẽ ở bên trái gốc và bên phải cũng vậy
// Quy luật: levelorder luôn đi từ trái sang phải nên node tiếp theo trong dãy sau node gốc trước đó có thể sẽ là node bên trái
// rồi node sau nữa mới là node phải, trường hợp là bên phải trước là khi ở dãy inorder bên trái node gốc tìm được trc ko có phần tử nào
// tương tự nếu bên phải node gốc rỗng thì phần tử tiếp sau node gốc trong dãy levelorder sẽ là node trái và node sau nữa cũng là trái
// và là con của node trái trước đó.

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



node *treebuild(int inOrder[], int levelOrder[], int n)
{
    int levelIndex = 0;

    map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        mp[inOrder[i]] = i;
    }

    queue<pair<node*, pair<int, int>>> q;
    node *root = new node(levelOrder[levelIndex++]);
    q.push({root, {0, n - 1}});

    while(!q.empty())
    {
        int m = q.size();
        for(int i = 0; i < m; ++i)
        {
            auto X = q.front();
            q.pop();
            int leftBound = mp[X.first->val] - 1;
            int rightBound = mp[X.first->val] + 1;
            int leftBorder = X.second.first;
            int rightBorder = X.second.second;
            if(leftBorder <= leftBound)
            {
                X.first->left = new node(levelOrder[levelIndex++]);
                q.push({X.first->left, {leftBorder, leftBound}});
            }
            if(rightBound <= rightBorder)
            {
                X.first->right = new node(levelOrder[levelIndex++]);
                q.push({X.first->right, {rightBound, rightBorder}});
            }
        }
    }
    return root;
}

void postorder(node *root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
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
        int inOrder[n], levelOrder[n];
        for(int i = 0; i < n; ++i) cin >> inOrder[i];
        for(int i = 0; i < n; ++i) cin >> levelOrder[i];
        node *root = treebuild(inOrder, levelOrder, n);
        postorder(root);
        cout << endl;
        deleteTree(root);
    }
}
