#include <string>
#include <vector>

using namespace std;

int check(int num){
    int flag = 1;
    while(num!=0){
        if(!(num%10==5||num%10==0)){
            flag = 0;
        }
        num/=10;
    }
    return flag;
}

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=l;i<=r;i++){
        if(check(i)==1){
               answer.push_back(i);
        }
    }
    
    if(answer.size()==0){
        answer.push_back(-1);
    }
    return answer;
}