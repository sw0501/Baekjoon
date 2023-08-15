#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    for(int i=0;i<query.size();i++){
        if(i%2==0){
            for(int j=arr.size()-1;j>query[i];j--){
                arr.erase(arr.begin()+j);
            }
        }
        else {
            for(int j=0;j<query[i];j++){
                arr.erase(arr.begin()+0);
            }
        }
    }
    
    return arr;
}