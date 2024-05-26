#pragma once
typedef struct treeThNode {		// 구조체
	char data;					// 데이터
	struct treeThNode* left;	// 왼쪽 주소
	struct treeThNode* right;	// 오른쪽 주소 - 아래 isThreadRight 값이 0이라면 자식 노드의 주소 1이라면 스레드(순회 순서상 다른 노드를 가르키는 링크 필드) 
	int isThreadRight;			// 0 = 자식 노드 주소, 1 = 스레드
} treeThNode;

treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight);
treeThNode* findThreadSuccessor(treeThNode* p);
void threadInorder(treeThNode* root);