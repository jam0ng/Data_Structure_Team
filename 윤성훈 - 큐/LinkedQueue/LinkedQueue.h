#pragma once
typedef char element;		// 연결 큐 원소(element)의 자료형을 char로 정의	

typedef struct QNode {		// 연결 큐의 노드를 구조체로 정의
	element data;
	struct QNode* link;
} QNode;

typedef struct {			// 연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의 - 배열로 사용했을 때는 인덱스로 위치를 지정했지만 링크는 포인터로 지정함
	QNode* front, * rear;
} LQueueType;

LQueueType* createLinkedQueue();
int isLQEmpty(LQueueType* LQ);
void enLQueue(LQueueType* LQ, element item);
element deLQueue(LQueueType* LQ);
element peekLQ(LQueueType* LQ);
void printLQ(LQueueType* LQ);