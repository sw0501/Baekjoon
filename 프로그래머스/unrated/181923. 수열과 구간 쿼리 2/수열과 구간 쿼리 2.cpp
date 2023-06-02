#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(int i=0;i<queries.size();i++){
        int s = queries[i][0];
        int e = queries[i][1];
        int k = queries[i][2];
        
        int num = -1;
        for(int j=s;j<=e;j++){
            if(arr[j]>k){
                if(num==-1){
                    num = arr[j];
                }
                else if(num>arr[j]){
                    num = arr[j];
                }
            }
        }
        
        answer.push_back(num);
    }
    
    return answer;
}