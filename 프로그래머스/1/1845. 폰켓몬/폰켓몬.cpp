#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int arr[200001] = {0,};
    int N = nums.size();
    for(int i=0;i<N;i++){
        arr[nums[i]]++;
        if(arr[nums[i]]==1){
            answer++;
        }
        if(answer==N/2)break;
    }
    
    return answer;
}