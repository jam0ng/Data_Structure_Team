#include <stdio.h>
#include "node.h"

void displayInorder(treeNode* root) {	// 중위 순회 출력 함수
	if (root) {
		displayInorder(root->left);		// 왼쪽 찍고
		printf("%c_", root->key);		// 가운데 찍고
		displayInorder(root->right);	// 오른쪽 찍어
	}
}