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


Queue *queueinit(int size);
void push(Queue *queue, int val);
void printqueue(Queue queue);
