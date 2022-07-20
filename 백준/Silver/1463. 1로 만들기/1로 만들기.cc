#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int c;						//카운트
int visit[1000001] = {0,};	//중복 제거

void init();
void check(int N,int m);	//나누어떨어지는지 확인

int main(){
	
	init();
	
	return 0;
}

void
init(){
	cin >> n;
	c = n;
	check(n,0);
	cout << c << "\n";	
}

//시간 복잡도 해결해야됨
void check(int N,int m){
	//이미 방문한 노드라면 횟수 비교
	//기존 방문한 것보다 더 적은 기록이라면 m에 저장, 아니라면 종료
	if(visit[N]==0)visit[N]=m;
	else if(visit[N]<m)return ;
	else visit[N]=m;
	
	//종료조건이라면 최소값과 비교
	if(N==1){
		c = min(c,m);
		return ;
	}
	//2의 배수라면
	if(N%2==0){
		check(N/2,m+1);
	}
	//3의 배수라면
	if(N%3==0){
		check(N/3,m+1);
	}
	//1을 뺐을 때 다음 수가 나눠진다면 
	check(N-1,m+1);
}

