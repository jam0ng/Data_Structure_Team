#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

treeNode* searchBST(treeNode* root, element x) {		// search 함수
	treeNode* p;
	p = root;
	while (p != NULL) {		
		if (x < p->key) p = p->left;			// x가 p->key보다 작다면 왼쪽
		else if (x == p->key) return p;			// x가 p->key라면 p주소 반환
		else p = p->right;						// x가 p->key보다 크다면 오른쪽
	}
	printf("\n 찾는 키가 없습니다!");			// 반복을 돌았지만 찾는 원소를 포함한 노드가 없다.
	return p;									// 그 위치를 반환
}

treeNode* insertBSTNode(treeNode* p, element x) {		// (시험)	insert 함수
	treeNode* newNode;
	if (p == NULL) {									// 전달 받은 주소 값이 NULL 이라면
		newNode = (treeNode*)malloc(sizeof(treeNode));	// 메모리 할당
		newNode->key = x;								// 데이터 입력
		newNode->left = NULL;							// 왼쪽 링크 필드 NULL
		newNode->right = NULL;							// 오른쪽 링크 필드 NULL
		return newNode;									// 데이터 노드 리턴
	}
	else if (x < p->key) p->left = insertBSTNode(p->left, x);	// x가 p->key 보다 작다면 왼쪽 링크를 insertBSTNode에 넣고 다시 시도
	else if (x > p->key) p->right = insertBSTNode(p->right, x);	// x가 크다면 오른쪽 링크를 insertBSTNode에 넣고 다시 시도
	else printf("\n 이미 같은 키가 있습니다! \n");				// 이미 생성 되어있는 경우

	return p;													// 리턴
}

void deleteBSTNode(treeNode* root, element key) {		// (시험)	delete 함수
	treeNode* parent, * p, * succ, * succ_parent;		// 트리 중간을 삭제하기 위해 부모 노드의 주소 	
	treeNode* child;

	parent = NULL;
	p = root;

	while ((p != NULL) && (p->key != key)) {		// parent에 p를 담고 그 하위 트리로 내려가면서 삭제할 원소를 포함하고 있는 노드를 찾음
		parent = p;									
		if (key < p->key) p = p->left;				// 찾는 원소가 지금 현재 노드의 데이터 보다 작으면 왼쪽 링크를
		else p = p->right;							// 반대라면 오른쪽 링크를 p값으로 변경한다.
	}

	if (p == NULL) {								// p가 NULL, 끝을 만났다면(트리에 삭제하고 싶은 원소를 가진 노드가 없음)
		printf("\n 찾는 키가 이진 트리에 없습니다!!");	// 출력
		return;
	}

	if ((p->left == NULL) && (p->right == NULL)) {	// p의 왼쪽이 공백인데 오른쪽도 공백인 경우 단말 노드인 경우(차수 = 0)
		if (parent != NULL) {						// 부모 노드가 NULL이 아니라면
			if (parent->left == p) parent->left = NULL;		// 부모노드의 왼쪽이 p라면 부모노드의 왼쪽 링크 필드를 NULL로 바꿈
			else parent->right = NULL;						// 반대라면 오른쪽을 NULL로 바꿈
		}
		else root = NULL;									// 왼쪽도 공백 오른쪽도 공백인데 부모노드도 없다면 root이므로 root를 NULL
	}

	else if ((p->left == NULL) || (p->right == NULL)) {		// 둘 중 하나만 공백이라면 (차수 = 1)
		if (p->left != NULL) child = p->left;				// 왼쪽이 공백이 아니라면 child 에 삭제할 노드 왼쪽 링크 값을 담는다.
		else child = p->right;								// 반대라면 오른쪽

		if (parent != NULL) {								// 그 후 부모노드가 존재한다면
			if (parent->left == p) parent->left = child;	// 부모노드의 왼쪽이면 child를 왼쪽으로, parent->left = p => parent->left = child
			else parent->right = child;						// 반대라면 오른쪽
		}
		else root = child;									// 부모노드가 존재하지 않는다면 root이므로 child가 root가 됨
	}

	else {													//	왼쪽 오른쪽 둘 다 존재(차수 = 2)
		succ_parent = p;									
		succ = p->left;										// 후임을 p->left로 한다.(왼쪽 서브 트리에서 후계자 찾기 - 오른쪽 끝을 찾아야 함)(오른쪽도 가능 대신 왼쪽의 끝을 찾아야 함)
		while (succ->right != NULL) {						// 왼쪽 서브 트리에서 오른쪽 끝을 찾는 반복문
			succ_parent = succ;								// NULL을 만나기 전 노드를 후계자 부모노드로
			succ = succ->right;								// succ에 succ->right를 저장
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;	// 만약 succ_parent의 왼쪽이 succ이라면 왼쪽에 값을 넣어야 함
		else succ_parent->right = succ->left;							// 부모노드 오른쪽에 삭제를 위한 후계자 노드의 오른쪽에 있는 링크를 넣기(우리가 오른쪽 NULL을 찾았기 때문에 왼쪽에만 값이 있음 NULL이 있다면 NULL을 넣는 것)
		p->key = succ->key;												// 원래 삭제하려고 하던 데이터가 포함되어 있는 노드에 데이터 값을 우리가 찾은 후계자 노드 데이터 값으로 변경
		p = succ;														// 후계자 노드를 삭제하기 위해 후계자 노드의 주소를 p에 넣기
	}
	free(p);															// p 메모리 free
}

