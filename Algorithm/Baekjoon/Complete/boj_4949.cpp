#include<iostream>
#include<stack>
#include<string> 

using namespace std;

string str; //입력받는 문자열을 저장하는 변수
string end_str = "."; //종료 조건
stack<char> braket; //괄호 저장하는 스택
int flag; //괄호가 정확한지 확인

void balance(); //실행 함수

int main(){
	
	balance(); //함수 실행
	
	return 0;
}

void balance(){
	
	//.이 들어올때까지 반복
	do
	{
		flag=1; //디폴트 값 1
		getline(cin,str); //문자열 입력
		if(!str.compare(end_str))break; //종료 조건인 경우에 탈출
		//문자열에 괄호 확인
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='('||str[i]=='{'||str[i]=='[')braket.push(str[i]); //왼쪽 괄호라면 스택에 저장
			//오른쪽 괄호라면 스택이 비어있진 않은지, 비어있지 않다면 스택의 top에 들어있는 괄호와 비교한후 pop
			else if(str[i]==')')
			{
				if(braket.empty()||braket.top()!='(')
				{
					flag=0;
					break;
				}
				braket.pop();
			}
			else if(str[i]=='}')
			{
				if(braket.empty()||braket.top()!='{')
				{
					flag=0;
					break;
				}
				braket.pop();
			}
			else if(str[i]==']')
			{
				if(braket.empty()||braket.top()!='[')
				{
					flag=0;
					break;
				}
				braket.pop();
			}
		}
		//스택이 비어있고 괄호의 비율이 맞다면 yes 출력
		if(flag&&braket.empty())
		{
			cout<<"yes"<<endl;
		}
		//스택이 비어있지 않거나 괄호의 비율이 맞지 않다면 no 출력
		else 
		{
			cout << "no" <<endl;
		}
		while(!braket.empty()){
			braket.pop();
		}
	}
	while(1);
}


