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
        
    int num = arr[0];
    for(int i=1;i<arr.size();i++){
        //유클리드 호제법
        num = num * arr[i] / LCM(max(num,arr[i]),min(num,arr[i]));
    }
    
    
    return num;
}