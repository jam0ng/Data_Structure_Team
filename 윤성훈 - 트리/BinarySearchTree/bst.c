#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

treeNode* searchBST(treeNode* root, element x) {		// search �Լ�
	treeNode* p;
	p = root;
	while (p != NULL) {		
		if (x < p->key) p = p->left;			// x�� p->key���� �۴ٸ� ����
		else if (x == p->key) return p;			// x�� p->key��� p�ּ� ��ȯ
		else p = p->right;						// x�� p->key���� ũ�ٸ� ������
	}
	printf("\n ã�� Ű�� �����ϴ�!");			// �ݺ��� �������� ã�� ���Ҹ� ������ ��尡 ����.
	return p;									// �� ��ġ�� ��ȯ
}

treeNode* insertBSTNode(treeNode* p, element x) {		// (����)	insert �Լ�
	treeNode* newNode;
	if (p == NULL) {									// ���� ���� �ּ� ���� NULL �̶��
		newNode = (treeNode*)malloc(sizeof(treeNode));	// �޸� �Ҵ�
		newNode->key = x;								// ������ �Է�
		newNode->left = NULL;							// ���� ��ũ �ʵ� NULL
		newNode->right = NULL;							// ������ ��ũ �ʵ� NULL
		return newNode;									// ������ ��� ����
	}
	else if (x < p->key) p->left = insertBSTNode(p->left, x);	// x�� p->key ���� �۴ٸ� ���� ��ũ�� insertBSTNode�� �ְ� �ٽ� �õ�
	else if (x > p->key) p->right = insertBSTNode(p->right, x);	// x�� ũ�ٸ� ������ ��ũ�� insertBSTNode�� �ְ� �ٽ� �õ�
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");				// �̹� ���� �Ǿ��ִ� ���

	return p;													// ����
}

void deleteBSTNode(treeNode* root, element key) {		// (����)	delete �Լ�
	treeNode* parent, * p, * succ, * succ_parent;		// Ʈ�� �߰��� �����ϱ� ���� �θ� ����� �ּ� 	
	treeNode* child;

	parent = NULL;
	p = root;

	while ((p != NULL) && (p->key != key)) {		// parent�� p�� ��� �� ���� Ʈ���� �������鼭 ������ ���Ҹ� �����ϰ� �ִ� ��带 ã��
		parent = p;									
		if (key < p->key) p = p->left;				// ã�� ���Ұ� ���� ���� ����� ������ ���� ������ ���� ��ũ��
		else p = p->right;							// �ݴ��� ������ ��ũ�� p������ �����Ѵ�.
	}

	if (p == NULL) {								// p�� NULL, ���� �����ٸ�(Ʈ���� �����ϰ� ���� ���Ҹ� ���� ��尡 ����)
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");	// ���
		return;
	}

	if ((p->left == NULL) && (p->right == NULL)) {	// p�� ������ �����ε� �����ʵ� ������ ��� �ܸ� ����� ���(���� = 0)
		if (parent != NULL) {						// �θ� ��尡 NULL�� �ƴ϶��
			if (parent->left == p) parent->left = NULL;		// �θ����� ������ p��� �θ����� ���� ��ũ �ʵ带 NULL�� �ٲ�
			else parent->right = NULL;						// �ݴ��� �������� NULL�� �ٲ�
		}
		else root = NULL;									// ���ʵ� ���� �����ʵ� �����ε� �θ��嵵 ���ٸ� root�̹Ƿ� root�� NULL
	}

	else if ((p->left == NULL) || (p->right == NULL)) {		// �� �� �ϳ��� �����̶�� (���� = 1)
		if (p->left != NULL) child = p->left;				// ������ ������ �ƴ϶�� child �� ������ ��� ���� ��ũ ���� ��´�.
		else child = p->right;								// �ݴ��� ������

		if (parent != NULL) {								// �� �� �θ��尡 �����Ѵٸ�
			if (parent->left == p) parent->left = child;	// �θ����� �����̸� child�� ��������, parent->left = p => parent->left = child
			else parent->right = child;						// �ݴ��� ������
		}
		else root = child;									// �θ��尡 �������� �ʴ´ٸ� root�̹Ƿ� child�� root�� ��
	}

	else {													//	���� ������ �� �� ����(���� = 2)
		succ_parent = p;									
		succ = p->left;										// ������ p->left�� �Ѵ�.(���� ���� Ʈ������ �İ��� ã�� - ������ ���� ã�ƾ� ��)(�����ʵ� ���� ��� ������ ���� ã�ƾ� ��)
		while (succ->right != NULL) {						// ���� ���� Ʈ������ ������ ���� ã�� �ݺ���
			succ_parent = succ;								// NULL�� ������ �� ��带 �İ��� �θ����
			succ = succ->right;								// succ�� succ->right�� ����
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;	// ���� succ_parent�� ������ succ�̶�� ���ʿ� ���� �־�� ��
		else succ_parent->right = succ->left;							// �θ��� �����ʿ� ������ ���� �İ��� ����� �����ʿ� �ִ� ��ũ�� �ֱ�(�츮�� ������ NULL�� ã�ұ� ������ ���ʿ��� ���� ���� NULL�� �ִٸ� NULL�� �ִ� ��)
		p->key = succ->key;												// ���� �����Ϸ��� �ϴ� �����Ͱ� ���ԵǾ� �ִ� ��忡 ������ ���� �츮�� ã�� �İ��� ��� ������ ������ ����
		p = succ;														// �İ��� ��带 �����ϱ� ���� �İ��� ����� �ּҸ� p�� �ֱ�
	}
	free(p);															// p �޸� free
}

