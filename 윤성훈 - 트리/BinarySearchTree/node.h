#pragma once
typedef char element;			// 데이터 타입 정의

typedef struct treeNode {		// 구조체
	element key;				// 데이터
	struct treeNode* left;		// 왼쪽 링크 필드
	struct treeNode* right;		// 오른쪽 링크 필드
}treeNode;

void displayInorder(treeNode* root);	