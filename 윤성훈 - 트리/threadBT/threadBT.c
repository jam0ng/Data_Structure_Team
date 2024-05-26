#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight) {	// ��带 ����� �Լ�
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));		// �޸� �Ҵ�
	root->data = data;												// ������ �Է�
	root->left = leftNode;											// ���� �ּ� �Է�
	root->right = rightNode;										// ������ �ּ� �Է�
	root->isThreadRight = isThreadRight;							// ������ �ּҰ��� ���������� �ƴ��� �Ǻ��ϴ� ���� �Է�
	return root;													// ��ȯ
}

treeThNode* findThreadSuccessor(treeThNode* p) {	// �߿� isThreadRight(�±� �ʵ�)�� ���� �ļ��ڰ� �ִٴ°� Ȯ����
	treeThNode* q = p->right;						// �Է� ���� �ּ��� ������ ���� q�� ����
	if (q == NULL) return q;						// q�� NULL�̴�. �ڽ�node�� ������ �ǹ� �״�� q��, NULL�� return
	if (p->isThreadRight == 1) return q;			// isTheradRight�� 1�̴�. ������μ� �ּҰ� q�� ��ȯ
	while (q->left != NULL) q = q->left;		// (�� ��찡 �ƴѵ� �����ʿ� �ּҰ� ������ �ڽ� ������� �ǹ�)�ڽ� ��尡 ������ �ִ� ���� ��带 ���� Ž���ϱ� ���� q->left != NULL�� ��� q�� ��ġ�� ������ �� �������� ����
	return q;	// ������ �ڽ� ����� ���� ������ ��ȯ
}

void threadInorder(treeThNode* root) {		// ��� �Լ�
	treeThNode* q;							// �ӽ� ������ q�� ����
	q = root;								// root ����
	while (q->left) q = q->left;			// Ʈ�� ó�� ���� �κк��� ���� ���� ������ �̵� q->left�� NULL�̸� �Ʒ���
	do										// �ϴ� ���� ���� ����� �����͸� ���� ��� �� �� findThreadSuccessor�� �̿��Ͽ� q�� ������ �Ǵ� Ʈ�� ������ �ڽ� ��� ���� ���� �ּҸ� ���� 
	{
		printf("%3c", q->data);
		q = findThreadSuccessor(q);
	} while (q);							// q�� NULL �� ������ ���� ���������� �ݺ�
}