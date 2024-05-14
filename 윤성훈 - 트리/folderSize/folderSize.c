#include <stdlib.h>
#include "folderSize.h"

treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode) {	// Size를 루트 노드의 데이터 필드로 하여 왼쪽과 오른쪽 서브 트리를 연결하는 연산
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->size = size;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

int postorder_FolderSize(treeNode* root) {	// 각 폴더 크기를 계산하기 위한 후위 순회 연산
	if (root) {
		postorder_FolderSize(root->left);		// 왼쪽을 먼저 들어가고
		postorder_FolderSize(root->right);		// 오른쪽을 간 뒤
		FolderSize += root->size;				// size값을 더해라
	}
	return FolderSize;
}