#include <stdio.h>
#include <stdlib.h>
#include "queueS.h"

QueueType* createQueue() {		//공백 순차 큐를 생성하는 연산
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType)); //구조체의 메모리를 할당하고 그 주소값을 Q에 저장
	Q->front = -1;	//front 초깃값 설정
	Q->rear = -1;	//rear 초깃값 설정
	return Q;
}

int isQueueEmpty(QueueType* Q) {	//순차 큐가 공백 상태인지 검사하는 연산
	if (Q->front == Q->rear) {		//Q에 front 와 rear가 같으면 공백
		printf(" Queue is empty! \n\t ");
		return 1;		//true
	}
	else return 0;	//false
}
int isQueueFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf(" Queue is full! \n\t "); // FULL이 되는 조건을 찾아 봐라
		return 1;
	}
	else return 0;
}
void enQueue(QueueType* Q, element item) {	//순차 큐의 rear에 원소를 삽입하는 연산
	if (isQueueFull(Q)) return; //포화 상태이면, 삽입 연산 중단
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}
element deQueue(QueueType* Q) {		//순차 큐의 front에서 원소를 삭제하는 연산
	if (isQueueEmpty(Q)) return;	//공백 상태이면, 삭제 연산 중단
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}
element peekQ(QueueType* Q) {	//순차 큐의 가장 앞에 있는 원소를 검색하는 연산
	if (isQueueEmpty(Q)) return; //공백 상태이면 연산 중단
	else return Q->queue[Q->front + 1];
}
void printQ(QueueType * Q) {	//순차 큐의 원소를 출력하는 연산
		int i;
		printf(" Queue : [");
		for (i = Q->front + 1; i <= Q->rear; i++)
			printf("%3c", Q->queue[i]);
		printf(" ]");
}