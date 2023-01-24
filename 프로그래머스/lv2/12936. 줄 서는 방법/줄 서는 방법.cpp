#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer;	//k번째 방법 저장
int arr[21] = {0,};	//나열 여부 확인

//재귀
void reculse(int n, long long k, int cnt){
    //모든 수가 나열됐다면 함수 종료
    if(answer.size()==n)return;
    
    //팩토리얼 계산
    long long factorial = 1;
    
    //(cnt-1)! 계산
    for(int i=2;i<cnt;i++){
        factorial *= i;
    }
    //덧셈용 변수
    long long tmp = factorial;
    
    //모든 사람 검색
    for(int i=1;i<=n;i++){
        if(arr[i])	//이미 나열된 사람인 경우 continue
            continue;
        //순서가 아니라면 다음 순서로 넘김
        if(factorial<k){
            factorial += tmp;
        }
        //순서가 맞다면 
        else{
            arr[i]=1;				//해당 사람의 번호 arr 표시
            answer.push_back(i);	//answer에 저장
            //다음 사전 순서 검색
            //1 < k-(factorial-tmp) < (cnt-1)! 이므로 다시 순서 탐색 가능
            reculse(n,k-(factorial-tmp), cnt-1);
            //이미 사전에 저장했으므로 반복문 탈출
            break;	
        }
    }
}

vector<int> solution(int n, long long k) {
    
    reculse(n,k,n);
    
    //N명의 사람인 경우
    //k의 크기에 따라 맨 앞 사람의 번호를 알 수 있다.
    //	  번호 : k 크기 
    //case)	1 : 1 ~ (N-1)!
    //case) 2 : (N-1)!+1 ~ 2*(N-1)!
    //case) 3 : 2*(N-1)!+1 ~ 3*(N-1)!
    // -----------------------------
    //case) N : (N-1)*(N-1)!+1 ~ N!
    
    return answer;
}