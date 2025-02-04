#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int artists_num, guitar_num;



    cin >> artists_num;
    vector<int> artists(artists_num);

    for (int i = 0; i < artists_num; i++) {
        cin >> artists[i];
    }

    cin >> guitar_num;  
    vector<int> guitars(guitar_num);


    for (int j= 0; j< guitar_num; j++) {
        cin >> guitars[j];
    }
    sort(artists.begin(), artists.end());
    sort(guitars.begin(), guitars.end());

    int count =0;

    // for (int i = 0; i < artists_num; i++) {

    //     auto degeri = lower_bound(guitars.begin(), guitars.end(),artists[i]);

    //     int index = degeri- guitars.begin();
    //     if (degeri != guitars.end()) {  
    //         guitars.erase(degeri);
    //         count++;
    //     }   

    // }
    int i=0;
    int j=0;
    while (i< artists_num & j<guitar_num){
        if (artists[i] <= guitars[j]){
            i++;
            j++;
            count++;

        }else if (artists[i] > guitars[j]){
            j++;
        }else{
            i++;
        }
    }


    cout<< count;

    return 0;
}
