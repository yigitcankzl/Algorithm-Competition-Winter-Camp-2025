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


    

    int esya_point = 0;
    int big_count=0;
    for (int market_index = 0; market_index < n; market_index++){
    int counter = 0;
    int market_point = market_index;

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

            }else if(esya_point==k-1){
                market_point; ///biselye yazmak gerek
            }else{
                market_point++;
                counter++;

                // esya_point=0;
            }
            
            if(market_point==n){
                cout << "-1";
                return 0;
            }
            
            big_count = max(counter, big_count);
        }

    }

    // for (int market_point = 0; market_point < n; market_point++){

    //     if (esyalar[esya_point]==0){
    //         esya_point++;
    //     }
        
    //     if (a[k] == 2){
    //         dont_want2_count++;
    //     }
    //     while (dont_want1_count > dont_want1 || dont_want2_count> dont_want2){
    //         if (a[i] == 1){
    //             dont_want1_count--;
    //         }
    //         if (a[i] == 2){
    //             dont_want2_count--;
    //         }
    //         i++;
    //     }

    //     anw = max(anw, k - i + 1);
        
    // }


    cout << big_count;
	return 0;
}