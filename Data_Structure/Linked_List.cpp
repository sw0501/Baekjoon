#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;	
	struct Node *next;	//
	struct Node *prev;	//
};

struct Node *pStart = NULL;		//리스트의 첫 노드의 포인터
struct Node *pEnd = NULL;		//리스트의 마지막 노드의 포인터

//노드를 추가하는 함수입니다
void addrear(int val /*노드에 저장할 데이터 값*/){
	struct Node *Current;	//데이터를 저장할 새 노드 생성
	Current = (struct Node *) malloc(sizeof(struct Node));	//노드의 크기만큼 동적할당 해준다.
	Current->data = val;	//새로 생성한 노드에 데이터를 저장
	Current->next = NULL;	//새로 생성한 노드에 다음 주소 저장
	Current->pre = NULL;
	
	//노드를 처음 생성하는 경우
	if(pStart == NULL)
		pStart = pEnd = Current;	//첫 노드의 주소 = 마지막 = 지금 만든 노드의 주소이다
	//노드가 이미 있는 경우
	//지금 생성한 노드 = Current[2]
	else{	//current[0] -> current[1] 
		pEnd->next = Current;	//Current[1]->next = Current[2]
		pEnd = Current;	//마지막 노드 = Current[2]
		Current->prev = pEnd;
	}
}

//출력하는 함수
void printlist(struct Node *Current){
	Current = pStart;
	while(Current != NULL){
		printf("%d\n",Current->data);
		Current = Current->next;
	}
}


//I번째 있는 리스트의 데이터를 출력하고 싶어요
void printI(struct Node *Current,int I){
	int j=0;
	Current = pStart;
	while(Current != NULL){	//Current가 존재할 경우
		if(j==I){
			printf("%d\n",Current->data);
			return ;
		}
		Current = Current->next;
		j++;
	}
}

int main(){
	
	for(int i=0;i<N;i++){
		
	}
	
	
	return 0;
}