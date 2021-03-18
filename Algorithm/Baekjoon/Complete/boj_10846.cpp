#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Queue{
	private:
	vector<int>arr;
	int size=0;
	
	public:
	void push(int x){
		arr.push_back(x);
		size++;
	}
	int pop(){
		if(size==0)return -1;
		int temp = arr[0];
		size--;
		vector<int>::iterator iter = arr.begin();
		arr.erase(iter);
		return temp;
	}
	int Size(){
		return size;
	}
	int empty(){
		if(size==0)return 1;
		return 0;
	}
	int front(){
		if(size==0)return -1;
		return arr[0];
	}
	int back(){
		if(size==0)return -1;
		return arr[size-1];
	}
	
};

void init();

int main(){
	
	init();
	
	return 0;
}

void init(){
	Queue que;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string str;
		int n;
		cin >> str;
		if(str=="push"){
			cin >> n;
			que.push(n);
		}
		else if(str=="pop"){
			cout << que.pop() << "\n";
		}
		else if(str=="size"){
			cout << que.Size() << "\n";
		}
		else if(str=="empty"){
			cout << que.empty() << "\n";
		}
		else if(str=="front"){
			cout << que.front() << "\n";
		}
		else if(str=="back"){
			cout << que.back() << "\n";
		}
	}
}
