#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int s = -1;
    int e = -1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==2){
            if(s==-1)s = i;
            else e = i;
        }
    }
    
    if(s==-1){
        answer.push_back(-1);
        return answer;
    }
    
    if(e==-1)e = s;
    for(int i=s;i<=e;i++){
        answer.push_back(arr[i]);
    }
    
    return answer;
}