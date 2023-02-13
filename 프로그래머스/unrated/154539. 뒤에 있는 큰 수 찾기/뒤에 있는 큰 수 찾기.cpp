#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    answer.push_back(-1);
    
    int N = numbers.size()-1;
    
    int big = numbers[N];
    
    for(int i=numbers.size()-2;i>=0;i--){
        //i번째 수가 i+1번째 수보다 큰 경우
        if(numbers[i]>numbers[i+1]){
            int j = i+1;
            int flag = 1;
            while(j<numbers.size()){
                //j번째 수보다 작은 경우
                if(numbers[i]<numbers[j]){
                    //j 추가
                    answer.push_back(numbers[j]);
                    flag = 0;
                }
                //j의 뒷 큰수보다 작은 경우
                else if(numbers[i]<answer[N-j]){
                    //j의 뒷 큰수 추가
                    answer.push_back(answer[N-j]);
                    flag = 0;
                }
                //뒷 큰 수가 존재하지 않는 경우
                else if(numbers[i]>=numbers[j] && answer[N-j] == -1){
                    break;
                }
                
                if(!flag){
                    break;
                }
                j++;
                
            }
            //뒷 큰수가 존재하지 않는 경우 -1 추가
            if(flag){
                answer.push_back(-1);
            }
        }
        //같은 경우 해당 수의 뒷 큰수 추가
        else if(numbers[i]==numbers[i+1]){
            answer.push_back(answer[N-(i+1)]);
        }
        //더 큰 경우 numbers[i+1] 추가
        else{
            answer.push_back(numbers[i+1]);
        }
    }
    
    //정순으로 정렬
    reverse(answer.begin(),answer.end());
    
    return answer;
}