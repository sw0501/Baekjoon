#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string *str; //문자열 배열
int N; //입력 개수
bool operator > (string &s1, string &s2); //연산자 오버로딩
bool Compare(string &s1,string &s2); //sort 비교함수

void init();

int main(){
	
	init();	
	
	return 0;
}

void init(){
	cin >> N;
	str = new string[N];
	string s;
	for(int i=0;i<N;i++){
		cin >> s;
		str[i]=s;
	}
	
	//정렬
	sort(str,str+N,Compare);
	
	//중복 제거 및 출력
	cout << str[0] << "\n";
	for(int i=1;i<N;i++){
		if(str[i].compare(str[i-1])!=0)
		cout << str[i] << "\n";
	}
}

bool operator > (string &s1, string &s2){
	//길이가 같다면 사전순으로
	if(s1.size()==s2.size()){
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i])return s1[i]<s2[i];
		}
		return 0;
	}
	//길이가 더 짧은 것이 크게
	else return s1.size()<s2.size();
}

bool Compare(string &s1,string &s2){
	return s1>s2;
}