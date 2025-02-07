#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   

    int m, n;
    cin >> n >> m;
    
    vector<pair<int, int>> people;
    int element;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> element;
            people.push_back({element, i});
        }
    }

    sort(people.begin(), people.end());

    int min_diff = INT_MAX;

    int left = 0, right = 0;
    int unique_countries = 0;

    unordered_map<int, int> country_count; 

    while (right < people.size()) { 
        int current_country = people[right].second;
        int current_score = people[right].first;

        if (country_count[current_country] == 0) {
            unique_countries++;
        }
        country_count[current_country]++;

        while (unique_countries == n) { 
            int current_min = people[left].first; 
            int current_max = people[right].first; 
            
            min_diff = min(min_diff, current_max - current_min);

            int left_country = people[left].second;
            country_count[left_country]--;

            if (country_count[left_country] == 0) {
                unique_countries--;
            }

            left++;
        }

        right++;
    }

    cout << min_diff << endl;
    return 0;
}
