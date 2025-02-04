#include <bits/stdc++.h>
using namespace std;

#define int long long
int anw = 0;
class Node {
public:
    int val;
    vector<Node*> childs;

    Node(int key) {
        val = key;
    }
};

void printInorder(Node *root) {
    if (!root) return;

    for (auto child : root->childs) {
        printInorder(child);
    }

    anw++;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, Node*> node_map;
    Node* root = new Node(1);
    node_map[1] = root;

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;

        Node* parent = node_map[a];
        Node* newNode = new Node(i);
        parent->childs.push_back(newNode);
        node_map[i] = newNode;
    }

    int number;
    cin >> number;


    printInorder(node_map[number]);
    cout << anw << "\n";
    return 0;
}
