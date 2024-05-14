#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {	//(���� �߿�) Ʈ���� �� ��带 ����� ����
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));						// �޸� �Ҵ�
	root->data = data;				//���� �����͸� �ְ�
	root->left = leftNode;			//���� ���� �ּҰ��� �ְ�
	root->right = rightNode;		//���� ������ �ּҰ��� �ְ�
	return root;					//���� ���� ��� �ּ� ��ȯ - �� �ڵ�� Ʈ�� ������ ���� �Ʒ� �͹̳� ��带 ���� �߰��ؾ� ��
}

void preorder(treeNode* root) {
	if (root) {
		printf("%c", root->data);	// �۾�D
		preorder(root->left);		// �۾�L
		preorder(root->right);		// �۾�R
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