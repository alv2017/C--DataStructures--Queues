#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Initializing a queue
struct queue *initialize_queue(struct queue *q) {
	q->first = NULL;
	q->last = NULL;
	return q;
}

// Display queue
void display_queue(struct queue *q) {
	if (q->first == NULL) {
		printf("The queue is empty.\n");
		return;
	}
	long cnt = 0;
	struct node *ptr;
	ptr = q->first;

	while (ptr != NULL) {
		cnt++;
		printf("Element queue id: %ld, value: %d\n", cnt, ptr->data);
		ptr = ptr->next;
	}
}

// Insert element into queue
struct queue *queue_insert(struct queue *q, int value, short *op_status) {
	*op_status = 0;
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));

	if (new_node == NULL) {
		printf("Unable to insert a new node: Memory allocation failure.\n");
		return q;
	}

	*op_status = 1;
	new_node->data = value;
	new_node->next = NULL;

	// The queue is empty
	if (q->first == NULL) {
		q->first = new_node;
		q->last = new_node;
	} else {
		(q->last)->next = new_node;
		q->last = new_node;
	}
	return q;
}

// Remove element from the queue
struct queue *queue_remove(struct queue *q, short *op_status) {
	*op_status = 0;
	if (q->first == NULL) {
		printf("The queue is empty. There is nothing to remove.\n");
		return q;
	}

	*op_status = 1;
	struct node *ptr = q->first;
	q->first = (q->first)->next;
	free(ptr);

	return q;
}

// Return the value of the top queue element
int queue_get_first(struct queue *q, short *op_status) {
	*op_status = 0;
	int first = 0;
	// Queue is empty
	if (q->first==NULL) {
		printf("The queue is empty. There is nothing to return.\n");
		return first;
	}
    *op_status = 1;
	return (q->first)->data;
}

// Delete queue
struct queue *queue_empty(struct queue *q) {
	// The queue is empty
	if (q->first == NULL) {
		return q;
	}
	struct node *preptr = NULL;
	struct node *ptr = q->first;

	while (ptr != NULL) {
		preptr = ptr;
		ptr = ptr->next;
		free(preptr);
	}
	q = initialize_queue(q);
	return q;
}




