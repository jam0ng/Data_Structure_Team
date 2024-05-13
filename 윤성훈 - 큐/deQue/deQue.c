#include <stdio.h>
#include <stdlib.h>
#include "deQue.h"

DQueType* createDQue() {	//공백 데크를 생성하는 연산
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

int isDeQEmpty(DQueType* DQ) {			// 공백 확인하는 연산
	if (DQ->front == NULL) return 1;		
	else return 0;
}

void insertFront(DQueType* DQ, element item) {		//앞에 원소를 넣는 함수
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQEmpty(DQ)) {			// 공백이라면 노드 오른쪽 링크와 왼쪽 링크 둘 다 NULL을 넣고 front와 rear을 newNode를 가리키게 만든다.
		DQ->front = newNode;		 
		DQ->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		DQ->front->llink = newNode;		// 기존 front 자리에 노드의 왼쪽 링크 값을 newNode 주소로
		newNode->rlink = DQ->front;		// newNode 오른쪽 주소 값을 전 front가 가리키는 주소로
		newNode->llink = NULL;			// 왼쪽은 새 노드가 맨 앞으로 가는 거기 때문에 NULL
		DQ->front = newNode;			// front를 새 노드로 가리키게 만듦
	}
}

void insertRear(DQueType* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQEmpty(DQ)) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;		// 뒤로 보내는 거기 때문에 기존 rear 자리의 노드 오른쪽 링크 값을 NULL -> newNode
		newNode->rlink = NULL;			// 새 노드 오른쪽을 NULL로 만들고 끝을 만듦
		newNode->llink = DQ->rear;		// 오른쪽 링크 값에 기존 rear자리 주소를 넣고
		DQ->rear = newNode;				// 새 rear 주소로 newnode
	}
}

element deleteFront(DQueType* DQ) {
	DQNode* old = DQ->front;			// 삭제할 노드의 주소를 old에 담는다.
	element item;						// 삭제할 노드 안에 있는 데이터를 담는 변수
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;	// 공백이면 그냥 리턴
	}
	else {
		item = old->data;					// 데이터를 담고
		if (DQ->front->rlink == NULL) {		// 삭제했을 때 맨 앞을 가리키는 노드의 오른쪽 노드가 NULL 없다면 공백 큐가 되므로 rear 값도 NULL
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {								
			DQ->front = DQ->front->rlink;	//front를 기존 front 노드의 오른쪽 노드로 옮기고	
			DQ->front->llink = NULL;		//새 front 노드의 왼쪽 링크에는 기존 front 노드의 값이 있으므로 NULL
		}
		free(old);				
		return item;
	}
}

element deleteRear(DQueType* DQ) {
	DQNode* old = DQ->rear;
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;
	}
	else {
		item = old->data;
		if (DQ->rear->llink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

element peekFront(DQueType* DQ) {
	element item;
	if (isDeQEmpty(DQ)) {
		printf("\n Linked deQue is empty! \n"); return;
	}
	else {
		item = DQ->front->data;
		return item;
	}
}

element peekRear(DQueType* DQ) {
	element item;
	if (isDeQEmpty(DQ)) {
		printf(" \n Linked deQue is empty! \n"); return;
	}
	else {
		item = DQ->rear->data;
		return item;
	}
}

void printDQ(DQueType* DQ) {
	DQNode* temp = DQ->front;
	printf("DeQue ; [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ] ");
}