#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    map<int,int>m;
    
    for(int i=1;i<=8;i++){
        int score;
        cin >>score;
        m.insert({score,i});
    }
    
    int sum = 0;
    int ck = 0;
    int arr[5];
    for(auto it : m){
        ck++;
        if(ck>=4){
            sum += it.first;
            arr[ck-4] = it.second;
        }
    }
    cout << sum << "\n";
    sort(arr,arr+5);
    for(auto it: arr){
        cout << it << " ";
    }
}