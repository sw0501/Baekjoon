#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    int x = 1;
    
    vector<int>temp;
    
    for(int i=0;i<arr.size();i++){
        temp.push_back(arr[i]);
    }
    
    while(1){
        for(int i=0;i<temp.size();i++){
            if(temp[i]>=50 && temp[i]%2==0)temp[i]/=2;
            else if(temp[i]<50 && temp[i]%2==1)temp[i] = temp[i]*2 + 1;
        }
        int flag = 1;
        for(int i=0;i<temp.size();i++){
            if(temp[i] != arr[i]) flag = 0;
        }
        if(flag == 1){
            answer = x-1;
            break;
        }
        for(int i=0;i<temp.size();i++){
            arr[i] = temp[i];
        }
        x++;
    }
    
    return answer;
}