#include<stdio.h>
#include "ArrayList.h"	//헤더파일 가져오기

void ListInit(List *plist){
	(plist->numOfData) = 0;		//plist에 저장된 데이터의 수는 0
	(plist->curPosition) = -1;	//plist에서 아무것도 가리키지 않음
}

//데이터를 저장할 리스트, 실제 저장할 데이터 값
void LInsert(List *plist, LData data){
	if(plist->numOfData >=LIST_LEN){	//plist가 가리키는 리스트의 최대개수를 넘겼다면	
		puts("저장이 불가능합니다.");		//오류 메세지 출력
		return ;						//함수 종료
	}

	//최대개수를 넘기지 않았다면
	plist->arr[plist->numOfData] = data;	//비어있는 마지막 공간 = numOfData 에 데이터 저장
	(plist->numOfData)++;	//데이터저장했으니 최대개수 증가
}

//첫번째 데이터를 참조
//데이터를 참조할 리스트, 참조한 데이터를 저장할 
int LFirst(List *plist, LData *pdata){
	//참조할 데이터가 존재하지 않는 경우
	if(plist->numOfData == 0){
		return FALSE;
	}
	
	//현재 참조하는 위치 curPosition = 0으로 설정
	(plist->curPosition) = 0;
	//*pdata에 현재 참조하고있는 = curPosition 데이터를 저장 
	*pdata = plist->arr[0];
	return TRUE;
}

//
int LNext(List *plist,LData *pdata){
	if(plist->curPosition >= (plist->numOfData)-1){
		return FALSE;
	}
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}


LData LRemove(List *plist){
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];
	
	for(i=rpos;i<num-1;i++){
		plist->arr[i] = plist->arr[i+1];
	}
	
	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}


int LCount(List *plist){
	return plist->numOfData;
}