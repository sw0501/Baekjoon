#include <stdio.h>
#include "ArrayList.h"

int main(void) {

	char  data;
	int str_index = 0;
	List list;
	ListInit(&list);
	
	//데이터 삽입
	for (str_index = 0; str_index < 10; str_index++) {
		LInsert(&list, 'A'+str_index);
	}

	printf("현재 데이터의 수: %d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%c ", data);

		while (LNext(&list, &data)) {
			printf("%c ", data);
		}
	}
	printf("\n\n");

	//문자 B를 탐색하여 모두 삭제
	if (LFirst(&list, &data)) {
		if (data == 'B')
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 'B')
				LRemove(&list);
		}
	}

	//문자 F를 탐색하여 모두 삭제
	if (LFirst(&list, &data)) {
		if (data == 'F')
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 'F')
				LRemove(&list);
		}
	}

	//삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%c ", data);

		while (LNext(&list, &data)) {
			printf("%c ", data);
		}
	}
	printf("\n\n");

	return 0;
}
