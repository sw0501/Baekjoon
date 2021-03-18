//분할 정복 사용
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int num;			//처음에 들어있는 수
long long L;		//왼쪽 인덱스
long long R;		//오른쪽 인덱스
int N;				//반복
long long arr[4];	//1,2,3 개수 저장

void init();
void div(int n,long long idx,int c);		//n:숫자, a:인덱스
void quen(long long a,long long b,long long c,int n);	//1,2,3 계산
int sqrt(long long idx, int c);			//범위 내에 있는지 확인
int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> num >> L >> R >> N;
	
	for(int i=0;i<4;i++){
		arr[i] = 0;
	}
	
	div(num,0,0);
	
	for(int i=1;i<4;i++){
		cout << arr[i] << " ";
	}
}

//분할 정복
//L,R 부분만 검색
//L~R 사이의 부분은 점화식 이용해서 풀기 가능
void div(int n,long long idx,int c){
	//L~R 사이 구간인지 혹은 L보다 작은지 혹은 R보다 큰지 확인
	int flag = sqrt(idx,c);
	//cout << idx << " " << flag << "\n";
	//사이 구간이라면 1,2,3 개수 계산 후 종료
	if(flag==1){
		if(n==1)quen(1,0,0,c);
		else if(n==2)quen(0,1,0,c);
		else quen(0,0,1,c);
		return ;
	}
	//결정할 수 없다면 분할
	else if(flag==-1){
		if(n==1){
			div(1,3*idx,c+1);
			div(3,3*idx+1,c+1);
			div(2,3*idx+2,c+1);
		}
		else if(n==2){
			div(2,3*idx,c+1);
			div(1,3*idx+1,c+1);
			div(1,3*idx+2,c+1);
		}
		else if(n==3){
			div(2,3*idx,c+1);
			div(3,3*idx+1,c+1);
			div(2,3*idx+2,c+1);
		}
	}
	/*
	//마지막 분할 지점까지 왔다면 계산
	else if(c==N){
		//L==R인 경우 단일값 카운트
		if(L==R){
			if(idx==L)arr[n]++;
		}
		//L과 R 사이에 있다면 카운트
		else {
			if(idx>=L&&idx<=R)arr[n]++;
		}
		return ;
	}
	*/
	//좌측이 R보다 크거나, 우측이 L보다 작다면 탐색 X
	else return ;
}

void quen(long long a,long long b,long long c,int n){
	if(n==N){
		arr[1] += a;
		arr[2] += b;
		arr[3] += c;
		return ;
	}
	quen(a+2*b,a+b+2*c,a+c,n+1);
}

int sqrt(long long idx,int c){
	int temp = 1;	//3^(N-c)
	for(int i=c;i<N;i++){
		temp*=3;
	}
	long long left = idx*temp;
	long long right = idx*temp + temp -1;
	if(L<=left&&R>=right)return 1;
	else if(left>R||right<L) return 0;
	return -1;
}

