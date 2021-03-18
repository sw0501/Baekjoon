/*
덱 특징
FIFO 구조
앞과 뒤 두곳에서 삽입 및 삭제 가능
중간 데이터 삽입 및 삭제 힘듬
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Deque{
	private:
	vector<int>arr;
	
	int size=0;
	
	public:
	void push_front(int x){
		vector<int>::iterator iter = arr.begin();
		arr.insert(iter,x);
		size++;
	}
	void push_back(int x){
		arr.push_back(x);
		size++;
	}
	int pop_front(){
		if(size==0)return -1;
		int temp = arr[0];
		size--;
		vector<int>::iterator iter = arr.begin();
		arr.erase(iter);
		return temp;
	}
	int pop_back(){
		if(size==0)return -1;
		int temp = arr[size-1];
		size--;
		arr.pop_back();
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
	Deque deck;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string str;
		int n;
		cin >> str;
		if(str=="push_front"){
			cin >> n;
			deck.push_front(n);
		}
		else if(str=="push_back"){
			cin >> n;
			deck.push_back(n);
		}
		else if(str=="pop_back"){
			cout << deck.pop_back() << "\n";
		}
		else if(str=="pop_front"){
			cout << deck.pop_front() << "\n";
		}
		else if(str=="size"){
			cout << deck.Size() << "\n";
		}
		else if(str=="empty"){
			cout << deck.empty() << "\n";
		}
		else if(str=="front"){
			cout << deck.front() << "\n";
		}
		else if(str=="back"){
			cout << deck.back() << "\n";
		}
	}
}
