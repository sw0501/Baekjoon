#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int odd = 0;
    int even = 0;
    
    for(int i=0;i<num_list.size();i++){
        if(num_list[i]%2==0){
            even *= 10;
            even += num_list[i];
        }
        else {
            odd *= 10;
            odd += num_list[i];
        }
    }
    
    answer = even + odd;
    return answer;
}