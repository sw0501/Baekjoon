#include<stdio.h>

#pragma warning(disable:4996)

int main(){

	int CK[1000001] = { 0, };
	int M, N;

	scanf("%d %d", &M, &N);

	//M ~ N 사이에 있는 소수를 검색
	for (int i = 2; i <= N; i++) {
		//i가 소수인 경우
		if (CK[i] == 0) {
			//i가 M 이상인 경우 출력
			if (i >= M) {
				printf("%d\n", i);
			}
			//i*1 = i이므로 배수를 확인해서 CK에 표시
			for (int j = 2; j * i <= N; j++) {
				CK[i * j] = 1;
			}
		}
	}

	return 0;
}