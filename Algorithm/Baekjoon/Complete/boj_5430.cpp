#include <bits/stdc++.h>

using namespace std;

void init();

int T;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	
	string Oper;
	int len;
	string arr;
	deque<int>DQ;
	
	for(int i=0;i<T;i++){
		cin >> Oper >> len >> arr;
		int num = 0;
		int flag = 1;
		if(len!=0){
			for(int j=1;j<arr.size();j++){
				if(arr[j]==']'||arr[j]==','){
					DQ.push_back(num);
					num=0;
				}
				else{
					num*=10;
					num+=(int)(arr[j]-'0');
				}
			}
		}
		for(int j=0;j<Oper.size();j++){
			if(Oper[j]=='D'){
				//앞에서 버리기
				if(DQ.empty()){
					cout << "error" << "\n";
					flag = -1;
					break;
				}
				else if(flag%2==1){
					DQ.pop_front();
				}
				else if(flag%2==0){
					DQ.pop_back();
				}
			}
			else if(Oper[j]=='R'){
				flag++;
			}
		}
		//에러가 발생하지 않았다면
		if(flag!=-1){
			//정방향일 경우
			if(flag%2==1){
				cout << "[";
				while(!DQ.empty()){
					cout << DQ.front();
					DQ.pop_front();
					if(!DQ.empty())cout << ",";
				}
				cout << "]\n";
			}
			//역방향일 경우
			else{
				cout << "[";
				while(!DQ.empty()){
					cout << DQ.back();
					DQ.pop_back();
					if(!DQ.empty())cout << ",";
				}
				cout << "]\n";
			}
		}
	}
	
}
