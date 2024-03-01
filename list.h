#ifndef LIST_H
#define LIST_H

struct queue;
struct information;

void queue_insert_sorted(struct queue *q, struct information *item);

#endif
