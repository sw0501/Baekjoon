#include <bits/stdc++.h>

using namespace std;

void init();
void pre(int index);	//전위 자식 탐색 전 출력
void in(int index);		//중위 왼쪽 자식 탐색을 마친 경우 출력
void post(int index);	//후위 모든 자식 탐색을 마친 경우 출력

int N;
int I[26] = {0,};
int L;
int R;
char Tree[67108864];	//높이가 N인 이진트리도 가능하기 때문에 크기를 2^26으로 잡아놨음

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> N;
	
	fill(Tree,Tree+67108864,' ');
	Tree[0] = 'A';
	
	for(int i=0;i<N;i++){
		char root, left, right;
		cin >> root >> left >> right;
		if(left!='.'){
			Tree[2*I[(int)(root-'A')]+1]=left;
			I[(int)(left-'A')] = 2*I[(int)(root-'A')]+1;
		}
		if(right!='.'){
			Tree[2*I[(int)(root-'A')]+2]=right;
			I[(int)(right-'A')] = 2*I[(int)(root-'A')]+2;
		}
	}
	
	pre(0);
	cout << "\n";
	in(0);
	cout << "\n";
	post(0);
	
}

//전위 탐색
void pre(int index){
	//비어있는 트리라면 출력하지 않는다.
	if(Tree[index]==' ')return ;
	
	//자식 탐색 전 출력
	cout << Tree[index];
	
	pre(2*index+1);
	pre(2*index+2);
}

//중위 탐색
void in(int index){
	if(Tree[index]==' ')return ;
	
	in(2*index+1);
	//탐색 중간에 출력
	cout << Tree[index];
	in(2*index+2);
}

//후위 탐색
void post(int index){
	if(Tree[index]==' ')return ;
	
	post(2*index+1);
	post(2*index+2);
	//탐색 마친 후에 출력
	cout << Tree[index];
}
