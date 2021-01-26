#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// LISTA (moze byc interpretowana jak stos)

struct list {
    int v;
    struct list *next;
};

typedef struct list Tlist;

// Tworzy pusta liste.
void init(Tlist **s)
{
    *s = NULL;
}

// Sprawdza czy lista jest pusta.
bool empty(Tlist *s)
{
    return s == NULL;
}

// Dodaje element o wartosci `x` na poczatek listy.
void push(Tlist **s, int x)
{
    Tlist *tmp;
    tmp = malloc(sizeof(*tmp));
    tmp->next = *s;
    tmp->v = x;
    *s = tmp;
}

// Pobiera element z poczatku listy. Zapisuje go na zmiennej `x`.
void pop(Tlist **s, int *x)
{
    *x = (*s)->v;
    Tlist *tmp = *s;
    *s = (*s)->next;
    free(tmp);
}

// Zapisuje element z poczatku listy na zmiennej `x`.
void top(Tlist **s, int *x)
{
    pop(s, x);
    push(s, *x);
}

// Usuwa koncowke listy.
void clear(Tlist **s)
{
    while (!empty(*s)) {
        int x;
        pop(s, &x);
    }
}

int main()
{
    return 0;
}
