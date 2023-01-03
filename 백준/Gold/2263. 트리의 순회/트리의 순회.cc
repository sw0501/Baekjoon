#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int index[100001];
int inorder[100001];
int postorder[100001];

int N;

void preorder(int inorderS, int inorderE, int postorderS, int postorderE);

int main() {

	

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &inorder[i]);
		index[inorder[i]] = i;
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &postorder[i]);
	}

	preorder(1, N, 1, N);

	return 0;
}

void preorder(int inorderS, int inorderE, int postorderS, int postorderE) {
	if (inorderS > inorderE || postorderS > postorderE) {
		return;
	}

	//후위 표기를 통해서 얻은 해당 트리의 루트 노드 구함
	int rootindex = index[postorder[postorderE]];

	//중위 표기에서 루트 노드를 기준으로 양옆 서브 트리의 길이를 구함
	int leftsize = rootindex - inorderS;
	int rightsize = inorderE - rootindex;

	//전위 표기이므로 루트 노드 출력 후 왼쪽 서브트리부터 다시 전위 탐색 시작
	printf("%d ", inorder[rootindex]);

	//왼쪽 서브트리 탐색 inoder 기준 inorderS 부터 왼쪽 길이 -1 (루트 노드 탐색 제외)
	//postorder 기준 postorderS 부터 왼쪽 길이 - 1 (루트 노드 탐색 제외)
	preorder(inorderS, inorderS + leftsize - 1, postorderS, postorderS + leftsize - 1);

	//오른쪽 서브트리 탐색 inorder 기준 inoderS + leftsize +1 부터 inorderE까지 (루트 노드 탐색 제외)
	//postorder 기준 postorderS + leftsize부터 postorderE-1 (맨끝 루트노드 제외)
	preorder(inorderS + leftsize + 1, inorderE, postorderS + leftsize, postorderE-1);
}