#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int i = 0;
    vector<int> stk;
    
    int cnt = 0;
    
    while(i<arr.size()){
        if(stk.size()==0){
            stk.push_back(arr[i++]);
        }
        else if(stk[stk.size()-1]<arr[i]){
            stk.push_back(arr[i++]);
        }
        else{
            stk.erase(stk.begin() + stk.size()-1);
        }
    }
    
    return stk;
}