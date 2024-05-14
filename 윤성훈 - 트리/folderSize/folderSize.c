#include <stdlib.h>
#include "folderSize.h"

treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode) {	// Size�� ��Ʈ ����� ������ �ʵ�� �Ͽ� ���ʰ� ������ ���� Ʈ���� �����ϴ� ����
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->size = size;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

int postorder_FolderSize(treeNode* root) {	// �� ���� ũ�⸦ ����ϱ� ���� ���� ��ȸ ����
	if (root) {
		postorder_FolderSize(root->left);		// ������ ���� ����
		postorder_FolderSize(root->right);		// �������� �� ��
		FolderSize += root->size;				// size���� ���ض�
	}
	return FolderSize;
}