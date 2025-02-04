#include <bits/stdc++.h>
using namespace std;

#define int long long

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int key)
    {
        val = key;
        left = right = nullptr;
    }
};

void printInorder(Node *root)
{
    if (root)
    {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

void printPostorder(Node *root)
{
    if (root)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->val << " ";
    }
}

void printPreorder(Node *root)
{
    if (root)
    {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->left->left = new Node(9);
    root->right->left->right = new Node(10);

    cout << "Preorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
    
}

int32_t main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}