//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int answer_or = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        answer_or |= x;
    }
    
    int l = 0;
    int r = 2;
    int counter = 0;
    for (int i = 0; i < 32; i++)
    {
        if (answer_or & (1 << i))
        {
            counter++;
            i+=2;
        }
    }
    
    cout << counter;

	return 0;
}