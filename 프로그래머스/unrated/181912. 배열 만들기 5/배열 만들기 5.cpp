#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    
    for(int t=0;t<intStrs.size();t++){
        int num = 0;
        for(int i=s;i<s+l;i++){
            num *=10;
            num += (int)(intStrs[t][i]-'0');
        }
        if(num>k)answer.push_back(num);
    }
    
    
    
    return answer;
}