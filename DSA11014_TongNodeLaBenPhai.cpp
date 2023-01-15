#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    char side;
    node *left, *right;
    node(int v, char s)
    {
        side = s;
        val = v;
        left = NULL;
        right = NULL;
    }
};

node *connect(node *r, int b, char c)
{
    if(r == NULL) return r;
    node* newNode = new node(b, c);
    if(c == 'L') r->left = newNode;
    else r->right = newNode;
    return newNode;
}

int sumRightLeaves(node *root)
{
   queue<node*> q;
   q.push(root);
   int sum = 0;
   while(!q.empty())
   {
       node *x = q.front(); q.pop();
       if(x == NULL) continue;
       if(x->left == NULL && x->right == NULL)
       {
           if(x->side == 'R') sum += x->val;
       }
       else
       {
           q.push(x->left);
           q.push(x->right);
       }
   }
   return sum;
}



int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<int, node*> mp;
        node *root = NULL;
        while(n--)
        {
            int a, b; char c;
            cin >> a >> b >> c;

            map<int, node*>::iterator k = mp.find(a);
            if(root)
            {
                if(k != mp.end())
                {
                    node* newNode = connect(mp[a], b, c);
                    mp[b] = newNode;
                }
            }
            else
            {
                root = new node(a, 'R');
                mp[a] = root;
                node* newNode = connect(mp[a], b, c);
                mp[b] = newNode;
            }
        }
        cout << sumRightLeaves(root) << endl;
        mp.clear();
    }
}
