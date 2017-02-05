     
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

/*****************************************
 *
 * Queue
 *
 *****************************************/

/* Story 8
 * As a programmer, I want to be able to print a queue, so I can see
 * what is in it.
*/

void pq(q_node q)
{  if(q==NULL)
	printf("queue is empty!\n");
   else
	while(q!=NULL){
	printf ("%c  ", q->value); 	
q=q->next;
	}
}

void print_queue(char *msg, queue q)
{
  printf("%s front: ", msg);
  fflush(stdout);
  pq(q.front);
  printf(":rear\n");
  fflush(stdout);
}

void print_queue_plus(char *before, queue q, char *after)
{
  printf("%s front: ", before);
  fflush(stdout);
  pq(q.front);
  printf(":rear %s", after);
  fflush(stdout);
}

/* Story 9
 * As a programmer, I want to be able to enqueue a character in a
 * queue, so I can learn how queues work.
*/

queue enqueue(queue q, char val)
{ q_node a=(q_node)malloc(sizeof(q_node));
  	a->value=val;
	//a->next=NULL;
	if(q.rear==NULL){
		q.rear=a;
		q.front=a;
	}
else
	{ 
	q.rear->next=a;
	q.rear=a;
	}
q.rear->next=NULL;
return q;
}

/* Story 10
 * As a programmer, I want to dequeue an item from a queue so I can
 * learn to use queues.
 */

char dequeue(queue *q)
{	q_node a;
	char b;
	if((*q).front==NULL) printf("QUEUE UNDERFLOW");
	else
	{
	a=(*q).front;
	(*q).front=(*q).front->next;
	b=a->value;
	a->next=NULL;
	free(a);
	}
return b;
}   
