#include <stdio.h>
#include "node.h"

void displayInorder(treeNode* root) {	// ���� ��ȸ ��� �Լ�
	if (root) {
		displayInorder(root->left);		// ���� ���
		printf("%c_", root->key);		// ��� ���
		displayInorder(root->right);	// ������ ���
	}
}