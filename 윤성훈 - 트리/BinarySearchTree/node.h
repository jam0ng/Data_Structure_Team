#pragma once
typedef char element;			// ������ Ÿ�� ����

typedef struct treeNode {		// ����ü
	element key;				// ������
	struct treeNode* left;		// ���� ��ũ �ʵ�
	struct treeNode* right;		// ������ ��ũ �ʵ�
}treeNode;

void displayInorder(treeNode* root);	