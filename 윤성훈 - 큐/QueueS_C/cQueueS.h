#pragma once
#define CQ_SIZE 4
typedef char element;		// 큐 원소(element)의 자료형을 char로 정의

typedef struct {			// 구조체 선언 - front 와 rear을 가지고 있기 위해 구조체로 선언함 이 자료구조의 데이터 타입은 구조체지만 그 안에 데이터는 배열임
	element queue[CQ_SIZE];	// 1차원 배열 큐 선언
	int front, rear;
} QueueType;

QueueType* createCQueue();
int isCQueueEmpty(QueueType* cQ);
int isCQueueFull(QueueType* cQ);
void enCQueue(QueueType* cQ, element item);
element deCQueue(QueueType* cQ);
element peekCQ(QueueType* cQ);
void printCQ(QueueType* cQ);