#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Stack{
	private:
	vector<int>arr;
	
	public:
	void push(int x){
		arr.push_back(x);
	}
	int pop(){
		if(arr.empty())return -1;
		int n = arr[arr.size()-1];
		arr.pop_back();
		return n;
	}
	int size(){
		return arr.size();
	}
	int empty(){
		if(arr.empty())return 1;
		else return 0;
	}
	int top(){
		if(arr.empty())return -1;
		return arr[arr.size()-1];
	}
	
	
};

void init();

int main(){
	
	init();
	
	
	return 0;
}

void init(){
	Stack S;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string str;
		cin >> str;
		if(str=="push"){
			int x;
			cin >> x;
			S.push(x);
		}
		else if(str=="pop"){
			cout << S.pop() << "\n";
		}
		else if(str=="size"){
			cout << S.size() << "\n";
		}
		else if(str=="empty"){
			cout << S.empty() << "\n";
		}
		else if(str=="top"){
			cout << S.top() << "\n";
		}
	}
}
