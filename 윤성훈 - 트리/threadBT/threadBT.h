#pragma once
typedef struct treeThNode {		// ����ü
	char data;					// ������
	struct treeThNode* left;	// ���� �ּ�
	struct treeThNode* right;	// ������ �ּ� - �Ʒ� isThreadRight ���� 0�̶�� �ڽ� ����� �ּ� 1�̶�� ������(��ȸ ������ �ٸ� ��带 ����Ű�� ��ũ �ʵ�) 
	int isThreadRight;			// 0 = �ڽ� ��� �ּ�, 1 = ������
} treeThNode;

treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight);
treeThNode* findThreadSuccessor(treeThNode* p);
void threadInorder(treeThNode* root);