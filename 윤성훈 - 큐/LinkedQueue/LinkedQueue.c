#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

LQueueType* createLinkedQueue() {	// 공백 연결 큐를 생성하는 연산
	LQueueType* LQ;					// Front와 Rear을 담고 있는 구조체의 포인터를 선언
	LQ = (LQueueType*)malloc(sizeof(LQueueType));	// 메모리 할당 및 주소값을 LQ에 넣기
	LQ->front = NULL;							// Front와 Rear에 각각 NULL을 넣음으로서 공백 만들기
	LQ->rear = NULL;
	return LQ;									// LQ 값 반환
}

int isLQEmpty(LQueueType* LQ) {		// 연결 큐가 공백 상태인지 검사하는 연산
	if (LQ->front == NULL) {			//fornt가 NULL 이라면 공백 
		//- rear은 데이터가 추가 될 때 늘어나고 front는 데이터가 삭제 될 때 줄어듦으로 front가 삭제되다가 NULL이 되었다는 것은 더 이상 데이터가 존재하지 않는다는 것을 의미
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

void enLQueue(LQueueType* LQ, element item) {	// 연결 큐의 rear에 원소를 삽입하는 연산
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;			// data 값 넣기
	newNode->link = NULL;			// 리스트 끝에 NULL을 넣기
	if (LQ->front == NULL) {		// 공백Q인지 확인
		LQ->front = newNode;		// 공백이라면 front, rear 두 포인터 변수에 newNode 주소 넣기
		LQ->rear = newNode;		
	}
	else {							// 아니라면
		LQ->rear->link = newNode;	// 리스트 마지막의 값을 NULL에서 newNode의 주소로 바꾸기;
		LQ->rear = newNode;			// rear의 값을 새로 만든 값으로 바꾸면서 리스트의 끝을 추가하기
	}
}

element deLQueue(LQueueType* LQ) {			// 연결 큐에서 원소를 삭제하고 반환하는 연산
	QNode* old = LQ->front;					// free로 메모리 할당 해제를 하기 위한 변수 old 선언
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = old->data;					// 삭제할 노드의 있는 데이터 저장
		LQ->front = LQ->front->link;		// front를 리스트 다음으로 넘기기
		if (LQ->front == NULL)				// front가 NULL이라면 리스트 끝에 도달한 것이므로 공백 큐가 됨
			LQ->rear = NULL;				// 그렇기에 rear도 NULL로 설정
		free(old);							// 메모리 할당 해제
		return item;						// item 반환
	}
}

element peekLQ(LQueueType* LQ) {		//연결 큐에서 원소를 검색하는 연산 - front의 원소를 반환하는 연산
	element item;							
	if (isLQEmpty(LQ)) return;		// 공백이라면 그냥 리턴
	else {
		item = LQ->front->data;		// front가 가리키는 Q노드의 데이터 값
		return item;		
	}
}

void printLQ(LQueueType* LQ) {			//연결 큐에서 원소를 검색하는 연산
	QNode* temp = LQ->front;			//순회할 temp를 선언
	printf(" Linked Queue : [");		
	while (temp) {						//리스트 처음부터 끝까지 돌면서 데이터를 출력함
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}