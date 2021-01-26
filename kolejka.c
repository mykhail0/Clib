#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list {
    int v;
    struct list *next;
};

typedef struct list Tlist;

typedef struct {
    Tlist *front;
    Tlist *rear;
} Tqueue;

// Tworzy pusta kolejke.
void initq(Tqueue *q)
{
    q->front = NULL;
    q->rear = q->front;
}

// Sprawdza czy kolejka jest pusta.
bool emptyq(Tqueue q)
{
    return q.front == NULL;
}

// Dodaje element `x` do kolejki.
void pushq(Tqueue *q, int x)
{
    if (q->front) {
	q->rear->next = malloc(sizeof *(q->rear->next));
	q->rear->next->v = x;
	q->rear = q->rear->next;
    } else {
    	q->rear = malloc(sizeof *(q->rear));
	q->rear->v = x;
	q->front = q->rear;
    }
    q->rear->next = NULL;
}

// Pobiera element z kolejki i zapisuje go na zmiennej `x`.
void popq(Tqueue *q, int *x)
{
    *x = q->front->v;
    Tlist *tmp = q->front;
    q->front = q->front->next;
    free(tmp);
}

// Usuwa kolejke.
void clearq(Tqueue *q)
{
    while (!emptyq(*q)) {
	int x;
	popq(q, &x);
    }
}

int main()
{
    return 0;
}
