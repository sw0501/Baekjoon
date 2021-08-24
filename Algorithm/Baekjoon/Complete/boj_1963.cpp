#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int T;
int decimal[10000]={0,};
void init();
int BFS(int a,int b);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	//에라토스테네스의 체를 이용하여 소수를 미리 판별한다음 BFS로 너비우선탐색
	cin >> T;
	int a,b;
	
	//에라토스테네스의 체
	for(int i=2;i<10000;i++){
		decimal[i] = i;
	}
	for(int i=2;i<10000;i++){
		//이미 체크된 수의 배수는 확인안함
		if(decimal[i]==0)continue;
		for(int j = i*2;j<10000;j+=i){
			decimal[j] = 0;
		}
	}
	
	for(int i=0;i<T;i++){
		cin >> a >> b;
		//같은 수라면 결과 출력 후 다음 케이스
		if(a==b){
			cout << 0 << "\n";
			continue;
		}
		int answer = BFS(a,b);
		if(answer>0)cout << answer << "\n";
		else cout << "impossible" << "\n";
	}
	
	
	
}


int BFS(int a,int b){
	int CK[10000]={0,};
	queue<int>q;
	q.push(a);
	
	int answer = 1;	//최소횟수
	int C = 1;		//계층의 너비
	int B = 0;		//계층의 너비 임시 저장
	while(!q.empty()){
		int node = q.front();
		//q가 비지 않을때까지 반복하면서 찾고 불가능한 경우에는 큐에 들어있는 마지막원소가 b와 같지 않을 때다.
		if(CK[node]==0){
			//방문 기록
			CK[node] = 1;
			//큐에 들어있던 원소 제거
			//i = 자릿수, j = 자릿수에 해당하는 수
			for(int i = 10;i<=10000;i*=10){
				for(int j=0;j<10;j++){
					//바꾸려는 숫자가 기존의 숫자와 같은 경우
					if(node%i/(i/10) == j)continue;
					int num = node-node%i+j*i/10+node%(i/10);
					if(num==b){
						return answer;
					}
					//이미 방문한 노드이거나,소수가 아니거나 1000이하일 경우
					if(CK[num]==1||decimal[num]==0||num<1000)continue;
					q.push(num);
					B++;
					
				}
			}
		}
		//탐색 끝낸 원소 제거
		q.pop();
		C--;
		//그동안 저장된 다음계층의 너비 C에 저장
		if(C==0){
			C=B;
			B=0;	//초기화
			answer++;
		}
	}
	
	return -1;
}
