#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE		1
#define FALSE		0

#define	LIST_LEN	100
typedef	int LData;

typedef struct	__ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;			//저장된 데이터의 수
	int curPosition;		//데이터 참조위치 기록
}ArrayList;

typedef ArrayList List;	

void ListInit(List *plist);				//초기화
void LInsert(List *plist,LData data);	//데이터 삽입
int LFirst(List *plist,LData *pdata);	//첫 데이터를 참조
int LNext(List *plist,LData *pdata);	//다음 데이터 참조
LData LRemove(List *plist);				//데이터 삭제 -> LData 쓴 이유 = 삭제한 데이터(LData) 반환
int LCount(List *plist);				//데이터 개수 반환

#endif