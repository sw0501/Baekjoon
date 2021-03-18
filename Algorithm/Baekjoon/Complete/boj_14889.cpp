#include<iostream>
#include<algorithm>

using namespace std;
int N;		//인원수  4이상 20이하, 짝수
int *S;		//능력치
int Temp=1;	//첫 시도 확인
int dif;	//능력치 차이
int *t1;	//조합 배열 1
int *t2;	//조합 배열 2
int sum1;
int sum2;

int Differnce();
void init();
void com(int n);

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	//입력
	cin >> N;
	S = new int[N*N];
	t1 = new int [N];
	t2 = new int [N];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>S[i*N+j];
		}
	}
	
	//능력치 차이 계산 후 출력
	com(0);
	cout << dif << "\n";
	
	delete[]S;
	delete[]t1;
	delete[]t2;
}

//n=N/2일때까지 조합을 찾고 능력치 차이가 최소이면 저장
void com(int n){
	for(int i=0;i<N;i++){
		//첫번째 재귀가 절반을 넘어가면 다음 결과부터는 모두 중복이므로 종료
		if(n==0&&i>N/2-1)break;
		int flag=1; //확인 변수
		
		//이미 넣은 조합인지 확인  (앞의 수보다 무조건 크게 설정해서 조합의 중복 최소화)
		for(int j=0;j<n;j++){
			if(t1[j]==i||t1[j]>i){
				flag=0;
				break;
			}
		}
		//가능한 조합이면 배열에 저장
		if(flag){
			t1[n]=i;
			//조합이 완성됐다면 차이값 구함
			if(n==N/2-1){
				//반대 조합 생성
				int num=0;
				for(int i=0;i<N;i++){
					int flag2=1;
					for(int j=0;j<N/2;j++){
						if(t1[j]==i){
							flag2=0;
							break;
						}
					}
					if(flag2)t2[num++]=i;
				}
				/*cout<<"t1"<<"\n";
				for(int k=0;k<N/2;k++){
					cout << t1[k] << " ";
				}
				cout<<"\n";
				cout<<"t2"<<"\n";
				
				for(int k=0;k<N/2;k++){
					cout << t2[k] << " ";
				}
				cout<<"\n";*/
				//차이 계산
				int temp = Differnce();
				//cout<<temp<<"\n";
				if(Temp){
					dif=temp;
					Temp=0;
				}
				else if(dif>temp)dif=temp;
			}
			else com(n+1);
		}
		//배열값 초기화
		t1[n]=-1;
	}
	
}

//팀별 점수 구하기
int Differnce(){
	int sum=0;
	for(int i=0;i<N/2;i++){
		for(int j=0;j<N/2;j++){
			if(i==j)continue;
			//첫번째 팀 점수
			sum+=S[t1[i]*N+t1[j]];
		}
	}
	for(int i=0;i<N/2;i++){
		for(int j=0;j<N/2;j++){
			if(i==j)continue;
			//두번째 팀 점수
			sum-=S[t2[i]*N+t2[j]];
		}
	}
	//절대값으로 변환
	if(sum<0)sum = 0-sum;
	return sum;
}


