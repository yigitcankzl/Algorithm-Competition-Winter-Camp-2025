//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;



void mergeSort(vector<int> vec){
    vector<int> vecLeft;
    vector<int> vecRight;

    if(vec.size()==2){
        if(!(vec[0]<vec[1])){
            int temp = vec[0];
            vec[0] = vec[1];
            vec[1] = temp;
            
        }
    }else{

        if(vec.size()%2==0){
            vector<int> vecLeft(0,vec.size()/2-1);
            vector<int> vecRight(vec.size()/2,vec.size());

        }else{
            vector<int> vecLeft(0,vec.size()/2); //left one is bigger
            vector<int> vecRight(vec.size()/2+1,vec.size());
        }
        mergeSort(vecLeft);
        mergeSort(vecRight);
    }



    // merge


}



int main() {
    int N;
    cin >> N;
    cout << N;

    vector<int> vec;
    vec.resize(N,-1);

    for(int i=0;i<N;i++){
        cin >> vec[i];
    }
    mergeSort(vec);
    
	return 0;
}
