#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int arr[4000001]={0,};
vector<int> prime;
int answer=0;

void init();
void pnum();	//소수 탐색 함수

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	pnum();
	init();
		
	return 0;
}

void init(){
	
	int *p1=&prime[0];
	int *p2=&prime[0];
	int sum=0;
	
	//N==1인경우 제외
	if(prime.size()>0){
		
		//sum>=N 일때까지 p2를 이동
		//sum>=N 이라면 p1을 이동하며 조건에 맞다면 answer++
		//sum<N 이라면 위에 1,2과정 다시 반복
		while(*p2<=N){
			sum += *p2;
			while(sum>=N){
				if(sum==N)answer++;
				sum -= *p1;
				p1++;
			}
			if(*p2==prime.back())break;
			else p2++;
		}
	}
	
	cout << answer << "\n";
}

void pnum(){
	//사용할 소수 탐색
	arr[0]=1;
	arr[1]=1;
	
	for(int i=2;i<=N;i++){
		//소수가 아닌 경우 continue
		if(arr[i]==1){
			continue;
		}
		//배수를 모두 제외
		else{
			prime.push_back(i);
			int j = 2;
			while(j*i<=N){
				arr[j*i]=1;
				j++;
			}
		}
	}
}