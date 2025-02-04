#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> marketler(n);
    for (int i = 0; i< n; i++)
        cin >> marketler[i];  //marketlerin olsutur

    
    vector<int> esyalar(k);
    for (int i = 0; i< k; i++)
        cin >> esyalar[i];  //esyalar olsutur



    int market_point = 0;
    int esya_point = 0;
    int counter = 0;

    while (market_point<n && esya_point<k)
    {   
        if (esyalar[esya_point]==0){
            esya_point++;
            continue;
        }
        if (marketler[market_point] == esyalar[esya_point])
        {
            market_point++;
            esya_point++;
            counter++;

        }else{
            market_point++;
            counter++;

            // esya_point=0;
        }
        
        if(market_point==n){
            cout << "-1";
            return 0;
        }
        
        
    }
    

    cout << counter;
	return 0;
}