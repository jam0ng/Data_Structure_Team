#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

QueueType* createCQueue() {		//공백 원형 큐를 생성하는 연산 순차와 달리 기본값이 0이다.
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType)); //구조체의 메모리를 할당하고 그 주소값을 Q에 저장
	cQ->front = 0;	//front 초깃값 설정
	cQ->rear = 0;	//rear 초깃값 설정
	return cQ;
}

int isCQueueEmpty(QueueType* cQ) {	//원형 큐가 공백 상태인지 검사하는 연산
	if (cQ->front == cQ->rear) {		//Q에 front 와 rear가 같으면 공백
		printf(" Circular Queue is empty! \n\t ");
		return 1;		//true
	}
	else return 0;	//false
}
int isCQueueFull(QueueType* cQ) {		//원형 큐가 공백 상태인지 검사하는 연산
	if (((cQ->rear + 1)% CQ_SIZE) == cQ->front) {		//원형 큐에서 비교하는 법 (중요)
		printf(" Circular Queue is full! \n\t "); 
		return 1;
	}
	else return 0;
}
void enCQueue(QueueType* cQ, element item) {	//원형 큐의 rear에 원소를 삽입하는 연산
	if (isCQueueFull(cQ)) return; //포화 상태이면, 삽입 연산 중단
	else {
		cQ->rear = (cQ->rear + 1) % CQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}
element deCQueue(QueueType* cQ) {		//원형 큐의 front에서 원소를 삭제하는 연산
	if (isCQueueEmpty(cQ)) return;	//공백 상태이면, 삭제 연산 중단
	else {
		cQ->front = (cQ->front + 1) % CQ_SIZE;
		return cQ->queue[cQ->front];
	}
}
element peekCQ(QueueType* cQ) {	//원형 큐의 가장 앞에 있는 원소를 검색하는 연산
	if (isCQueueEmpty(cQ)) return; //공백 상태이면 연산 중단
	else return cQ->queue[(cQ->front + 1) % CQ_SIZE];
}
void printCQ(QueueType* cQ) {	//원형 큐의 원소를 출력하는 연산
	int i, first, last;
	first = (cQ->front + 1) % CQ_SIZE;
	last = (cQ->rear + 1) % CQ_SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % CQ_SIZE;
	}
	printf(" ] ");
}