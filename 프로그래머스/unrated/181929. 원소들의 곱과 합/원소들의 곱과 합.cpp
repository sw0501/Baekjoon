#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int a = 1;
    int b = 0;
    
    int answer = 0;
    
    for(int i=0;i<num_list.size();i++){
        a*=num_list[i];
        b+=num_list[i];
    }
    if(a<b*b){
        answer = 1;
    }
    
    return answer;
}