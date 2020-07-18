#ifndef QUEUE_H
#define QUEUE_H

// Linked node
struct node {
	int data;
	struct node *next;
};

// Queue
struct queue {
	struct node *first;
	struct node *last;
};

// Operation status
short op_status;

// Create queue
struct queue *initialize_queue(struct queue *);

// Display queue
void display_queue(struct queue *);

// Insert element into the queue
struct queue *queue_insert(struct queue *, int, short *);

// Delete element from the queue
struct queue *queue_remove(struct queue *, short *);

// Return value of the first queue element
int queue_get_first(struct queue *, short *);

// Empty the queue
struct queue *queue_empty(struct queue *);

#endif



