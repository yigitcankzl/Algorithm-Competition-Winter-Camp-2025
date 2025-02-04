#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n,dont_want1,dont_want2;
    cin >> n;  
    cin >> dont_want1;  
    cin >> dont_want2;  


    vector<int> a(n);

  
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int anw=0;
    int i=0;
    
    int dont_want1_count = 0;
    int dont_want2_count = 0;
    

    for (int k = 0; k < n; k++){
        if (a[k] == 1){
            dont_want1_count++;
        }
        if (a[k] == 2){
            dont_want2_count++;
        }
        while (dont_want1_count > dont_want1 || dont_want2_count> dont_want2){
            if (a[i] == 1){
                dont_want1_count--;
            }
            if (a[i] == 2){
                dont_want2_count--;
            }
            i++;
        }

        anw = max(anw, k - i + 1);
        
    }

    cout<< anw<<endl;

    return 0;
}
