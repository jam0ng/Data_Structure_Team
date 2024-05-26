#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight) {	// 노드를 만드는 함수
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));		// 메모리 할당
	root->data = data;												// 데이터 입력
	root->left = leftNode;											// 왼쪽 주소 입력
	root->right = rightNode;										// 오른쪽 주소 입력
	root->isThreadRight = isThreadRight;							// 오른쪽 주소값이 스레드인지 아닌지 판별하는 숫자 입력
	return root;													// 반환
}

treeThNode* findThreadSuccessor(treeThNode* p) {	// 중요 isThreadRight(태그 필드)를 통해 후속자가 있다는걸 확인함
	treeThNode* q = p->right;						// 입력 받은 주소의 오른쪽 값을 q에 저장
	if (q == NULL) return q;						// q가 NULL이다. 자식node가 없음을 의미 그대로 q값, NULL을 return
	if (p->isThreadRight == 1) return q;			// isTheradRight가 1이다. 스레드로서 주소값 q를 반환
	while (q->left != NULL) q = q->left;		// (위 경우가 아닌데 오른쪽에 주소가 있으면 자식 노드임을 의미)자식 노드가 가지고 있는 하위 노드를 전부 탐색하기 위해 q->left != NULL을 사용 q의 위치를 오른쪽 맨 왼쪽으로 보냄
	return q;	// 오른쪽 자식 노드의 가장 왼쪽을 반환
}

void threadInorder(treeThNode* root) {		// 출력 함수
	treeThNode* q;							// 임시 포인터 q를 생성
	q = root;								// root 저장
	while (q->left) q = q->left;			// 트리 처음 시작 부분부터 가장 왼쪽 노드까지 이동 q->left가 NULL이면 아래로
	do										// 일단 가장 왼쪽 노드의 데이터를 먼저 찍고 그 후 findThreadSuccessor를 이용하여 q를 스레드 또는 트리 오른쪽 자식 노드 왼쪽 끝에 주소를 받음 
	{
		printf("%3c", q->data);
		q = findThreadSuccessor(q);
	} while (q);							// q가 NULL 즉 오른쪽 끝을 만날때까지 반복
}