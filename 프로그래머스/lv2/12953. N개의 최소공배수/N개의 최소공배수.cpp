#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int LCM(int a,int b){
    while(1){
        int r = a%b;
        if(r==0)return b;
        
        a = b;
        b = r;
    }
}

int solution(vector<int> arr) {
    sort(arr.begin(),arr.end());
    
    int num = arr[0];
    for(int i=1;i<arr.size();i++){
        num = num * arr[i] / LCM(max(num,arr[i]),min(num,arr[i]));
    }
    
    
    return num;
}