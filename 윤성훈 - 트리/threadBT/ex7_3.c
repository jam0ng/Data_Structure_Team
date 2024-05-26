#include <stdio.h>
#include "threadBT.h"

int main(void) {
	// (A*B-C/D) 수식 이진 트리 만들기 
	treeThNode* n7 = makeRootThNode('D', NULL, NULL, 0);	// n3의 자식 노드
	treeThNode* n6 = makeRootThNode('C', NULL, NULL, 1);	// n3의 자식 노드
	treeThNode* n5 = makeRootThNode('B', NULL, NULL, 1);	// n2의 자식 노드
	treeThNode* n4 = makeRootThNode('A', NULL, NULL, 1);	// n2의 자식 노드
	treeThNode* n3 = makeRootThNode('/', n6, n7, 0);	// n1의 자식 노드
	treeThNode* n2 = makeRootThNode('*', n4, n5, 0);	// n1의 자식 노드
	treeThNode* n1 = makeRootThNode('-', n2, n3, 0);	// 부모가 없는 최상위 노드 root node

	n4->right = n2;				// 오른쪽 링크필드를 스레드로 설정했기에 그 주소값을 넣어주기
	n5->right = n1;				
	n6->right = n3;

	printf("\n 스레드 이진 트리의 중위 순회 : ");
	threadInorder(n1);					

	getchar();  return 0;
}