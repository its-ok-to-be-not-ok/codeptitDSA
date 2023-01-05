#include<bits/stdc++.h>

using namespace std;

struct node
{
    string mark;
    int num;
    node *l, *r;
    node(string m, int n)
    {
        mark = m;
        num = n;
        l = NULL;
        r = NULL;
    }
};

int calculate(int a, string m, int b)
{
    if(m == "+") return a + b;
    if(m == "-") return a - b;
    if(m == "*") return a * b;
    if(m == "/") return a / b;
    return 0;
}

void execute(node *root)
{
    if(root->l == NULL && root->r == NULL) return;
    execute(root->l);
    execute(root->r);

        root->num = calculate(root->l->num, root->mark, root->r->num);
        root->mark = "a";
        root->l = NULL;
        root->r = NULL;

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<node*> ds;
        while(n--)
        {
            string nhap; cin >> nhap;
            if(nhap == "+" || nhap == "-" || nhap == "*" || nhap == "/")
            {
                node *newNode = new node(nhap, -1);
                ds.push_back(newNode);
            }
            else
            {
                int num = stoi(nhap);
                node *newNode = new node("a", num);
                ds.push_back(newNode);
            }
        }
        for(int i = 0; i < ds.size(); ++i)
        {
            int i1 = i * 2 + 1;
            int i2 = i * 2 + 2;
            if(i1 < ds.size())
            {
                ds[i]->l = ds[i1];
            }
            if(i2 < ds.size())
            {
                ds[i]->r = ds[i2];
            }
        }
        node *root = ds[0];
        execute(root);
        cout << root->num << endl;
        ds.clear();
        delete root;
    }
}
