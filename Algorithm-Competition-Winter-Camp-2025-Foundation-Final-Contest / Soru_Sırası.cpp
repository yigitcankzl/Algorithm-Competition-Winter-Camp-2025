//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
// write your code here

    int q;
    cin >> q;
    int student = 1;
    
    unordered_map<int, bool> solved;
    queue<pair<int, int>> s;
    priority_queue<pair<int, int>, vector<pair<int,int>>> pq;

    while (q--)
    {
        
        int event;
        cin >> event;

        if(event == 1){

            int level; cin >> level;
            pq.push(make_pair(level, student));
            s.push(make_pair(level, student));
            student++;

        }
        else if(event == 2){

            int solve;
            cin >> solve;

            for(int i = 0; i < solve; i++){

                int id = s.front().second;
                while (solved[id])
                {
                    s.pop();
                    id = s.front().second;
                }
                
                solved[id] = true;
                cout << id << " ";
                s.pop();

            }

        }
        else{

            int solve;
            cin >> solve;

            for(int i = 0; i < solve; i++){

                int id = pq.top().second;
                while (solved[id])
                {
                    pq.pop();
                    id = pq.top().second;
                }
                solved[id] = true;
                cout << id << " ";
                pq.pop();

            }

            

        }

    }
    

	return 0;
}
