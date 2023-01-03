#include<iostream>
#include<algorithm>

using namespace std;

int CH;			//목표 채널
int M;			//고장난 버튼 갯수
int Dif;		//채널과의 거리차이
int NUM;		//가장 가까운 채널
int digit=0;	//채널의 자릿수
int N[10]={0,};	//고장난 버튼 확인
int flag = 1;	//변수가 바뀌었는지 확인

void init();
void Brute(int num,int d);
int CK(int num);

int main(){
	
	init();
	
	
	return 0;
}

/*
만들수있는 버튼 중에서 최적해를 찾는다.
그 최적해와 100번의 경우를 비교한다
나온 최적해를 출력
*/

void init(){
	//고장나지 않은 버튼을 조합하여 최대한 차이가 적은 수를 찾은 다음에 +,-로 이동하는 개수를 센다.
	cin >> CH >> M;
	
	int temp = CH;
	while(temp!=0){
		temp/=10;
		digit++;
	}
		
	for(int i=0;i<M;i++){
		int n;
		cin >> n;
		N[n] = 1;
	}
	
	//현재 보고있는 채널이 100번이므로 100번보다 차이가 적어야하므로 비교한다.
	Dif = (CH-100>0?CH-100:100-CH);
	NUM = 100;
		
	//조합할 수 있는 버튼의 최적해
	Brute(0,1);
	
	digit = 0;
	temp = NUM;
	
	//0인 경우 while문이 안돌아가기때문에 1증가시켜준다.
	if(temp==0)temp++;
	
	//숫자버튼 누르는 것도 고려를 해야한다.
	while(temp!=0){
		digit++;
		temp/=10;
	}
	
	//100과 비교
	if(digit+Dif<(CH-100>0?CH-100:100-CH))cout << digit + Dif << "\n";
	else cout << (CH-100>0?CH-100:100-CH) << "\n";
	
}

void Brute(int num,int d){
	num*=10;
	for(int i=0;i<10;i++){
		
		//고장난 버튼이라면 넘어감
		if(N[i]==1)continue;
		
		//숫자 변경
		num+=i;
		
		//재귀 종료여부 확인
		CK(num);
		if(d>digit)return ;
		
		Brute(num,d+1);
		
		//확인했으면 원래수로 돌림
		num-=i;
	}
}

int CK(int num){
	int temp = (num-CH>0?num-CH:CH-num);
	
	//같다면 더 작은 수를 골라서 숫자 누르는 개수를 줄인다.
	if(temp<Dif||(temp==Dif&&num<NUM)){
		Dif = temp;
		NUM = num;
		flag=0;
		return 1;
	}
	
	return 0;
}
