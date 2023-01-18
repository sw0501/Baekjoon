#include <string>
#include <vector>

using namespace std;

int arr[1000001] = {0,};    //중복 체크용 배열
int answer = 0;             //합 경우의 수

//완전 탐색
void BruteForce(vector<int>&elements, int cons){
    //배열의 모든 원소에서 한 번씩 체크
    for(int i=0;i<elements.size();i++){
        int num = 0;    //부분 수열 합
        //부분 수열 원소 개수만큼 반복
        for(int j=i,k=0;k<cons;k++,j++){
            num += elements[j];     //부분 수열 합에 저장
            //원형 수열이므로 범위 벗어나면 다음 반복 때 j = 0 이 되도록 설정
            if(j==elements.size()-1)j=-1;  
        }
        //부분 수열 합이 중복이 아니라면 arr 표시 후 answer++
        if(arr[num]==0){
            arr[num]=1;
            answer++;
        }
    }
}

int solution(vector<int> elements) {
       
    //연속 부분 수열 원소 개수
    for(int i=0;i<elements.size()-1;i++){
        
        BruteForce(elements, i+1);  //완전탐색 진행
    }   
    
    //자연수라는 조건이 붙어있으므로 전체 수열의 합은 중복 X
    answer++;
        
    return answer;
}