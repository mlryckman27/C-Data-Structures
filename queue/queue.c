#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// A Node structure that contains a data element 
// and a reference tovthe next node in the queue.
struct Node {
	int data;
	Node *next;
};

// A Queue structure that works in a FIFO manner.
// Contains information about the queue's max size, 
// number of elements stored in the queue,
// and references to head and tail elements.
typedef struct Queue {
	int maxsize;
	int count;
	Node *head;
	Node *tail;
} Queue;


// initialize a queue with a given size
Queue *queueinit(int size) {
	/*
	 * int size: integer > 0
	 * return: Queue struct
	 */
	Queue *queue = (Queue *)(malloc(sizeof(Queue)));
	queue->maxsize = size;
	queue->count = 0;
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

// push an element into the tail of the queue
void push(Queue *queue, int val) {
	/*
	 * Queue *queue: reference to a Queue struct
	 * int val: any integer value
	 */
	Node *n = (Node *)(malloc(sizeof(Node)));
	n->data = val;
	n->next = NULL;
	
	if (!(queue->head)) {
		queue->head = n;
		queue->tail = n;
		(queue->count)++;
	}
	else {
		queue->tail->next = n;
		queue->tail = n;
		(queue->count)++;
	}	

	// if the queue is full, force out the head element and display its contents
	if (queue->count > queue->maxsize) {
		Node *temp = (Node *)(malloc(sizeof(Node)));
		temp = queue->head;
		queue->head = queue->head->next;
		(queue->count)--;
		printf("Overflow: %d\n", temp->data);
	}
}

// display the contents of the queue from tail to head
void printqueue(Queue queue) {
	/*
	 * Queue queue: any valid Queue struct
	 */
	int vals[queue.count];
	Node *temp = (Node *)(malloc(sizeof(Node)));
	temp = queue.head;
	
	if (queue.count == 0) {
		printf("\n");
		return;
	}

	for (int i = 0; i < queue.count; i++) {
		vals[i] = temp->data;
		temp = temp->next;
	}

	for (int i = queue.count - 1; i >= 0; i--) {
		if (i == 0) {
			printf("%d\n", vals[i]);
		}
		else {
			printf("%d, ", vals[i]);
		}
	}
}


