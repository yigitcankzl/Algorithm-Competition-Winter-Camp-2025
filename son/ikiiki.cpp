#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n, esyasay;
    cin >> n >> esyasay;
    
    vector<int> marketler(n);
    for (int i = 0; i< n; i++)
        cin >> marketler[i];  //marketlerin olsutur

    int zeros =0;
    
    vector<int> esyalar(esyasay);
    for (int i = 0; i< esyasay; i++){
    
        cin>>esyalar[i] ;
    }
    for (int i = 0; i< esyasay; i++){
        
        if (esyalar[i]!=0){
            break;

        }else{
            zeros++;
        }
    }
    int anw=0;
    int i=0;
    int esya_point=0;
    int min_anw =INT_MAX;
    bool bulundumu = false;

    for (int k = 0; k < n; k++){
        if(esyalar[esya_point]==0){
            esya_point++;
            anw++;
            // cout<<anw<<"\n";

            i++;
            continue;
        }

        if (marketler[i]==esyalar[esya_point]){
            bulundumu=true;
            anw++;
            // cout<<anw<<"\n";
            

            esya_point++;
            i++;
            if(esya_point==esyasay){
                min_anw = min(anw,min_anw);
                // cout<<min_anw<<"min"<<"\n";
                anw =zeros;
                // cout<<anw<<"\n";
    
                esya_point = zeros;
                i=k;
                bulundumu =false;
                continue;

            }
        }else{


            if(bulundumu){
                anw++;
                // cout<<anw<<"\n";

                
            }
            i++;
        }

        
    }


    if (min_anw==INT_MAX){
        cout<< "-1";
    }else{
        cout<< min_anw<<"\n";

    }


    return 0;
}
