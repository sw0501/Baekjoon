#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string N; 	//1,000,000,000 의 크기를 가진 정수형 변수를 한번에 받을 수 없으므로 문자열로 받는다.
int arr[10] = {0,}; //최대 자릿수 10

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	getline(cin,N);
	//문자열로 받은 수를 한자리씩 떼어서 저장
	for(int i=0;i<N.length();i++){
		arr[i]=(int)(N[i]-'0');
	}
	sort(arr,arr+N.length());
	//오름차순으로 정렬된 배열을 끝부터 읽음
	for(int i=N.length()-1;i>=0;i--){
		cout<<arr[i];
	}
}