#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;

    stack<char> stack;
    
    for (char c : n) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else {
            if (stack.empty()) {
                cout << "NO";
                return 0;
            }
            char top = stack.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                stack.pop();
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    if (stack.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
