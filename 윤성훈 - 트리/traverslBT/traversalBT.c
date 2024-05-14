#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {	//(시험 중요) 트리의 각 노드를 만드는 연산
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));						// 메모리 할당
	root->data = data;				//받은 데이터를 넣고
	root->left = leftNode;			//받은 왼쪽 주소값을 넣고
	root->right = rightNode;		//받은 오른쪽 주소값을 넣고
	return root;					//지금 만든 노드 주소 반환 - 이 코드는 트리 연결을 위해 아래 터미널 노드를 먼저 추가해야 함
}

void preorder(treeNode* root) {
	if (root) {
		printf("%c", root->data);	// 작업D
		preorder(root->left);		// 작업L
		preorder(root->right);		// 작업R
	}
}

void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root) {
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}