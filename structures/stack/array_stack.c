#include <stack/array_stack.h>
#include <stdio.h>
#include <stdlib.h>

struct array_stack * new_stack(unsigned int size)
{
    // Allocate array
    unsigned int * items = malloc(sizeof(int) * size);
    struct array_stack * s = malloc(sizeof(struct array_stack));
    s->items = items;
    s->top = -1;
    s->size = size;
    return s;
}

void free_stack(struct array_stack * s)
{
    // Free array
    free(s->items);
    free(s);
}

char is_empty(struct array_stack s)
{
    if(s.top == -1)
        return 1;
    else
        return 0;
}

int pop(struct array_stack * s, unsigned int * e)
{
    if(is_empty(*s))
        return -1;

    *e = s->items[s->top];
    s->top--;
    return 0;
}

int push(struct array_stack * s, unsigned int e)
{
    if(s->top == s->size-1)
        return -1;

    s->top++;
    s->items[s->top] = e;
    return 0;
}

int peek(struct array_stack s, unsigned int * e)
{
    if(is_empty(s))
        return -1;
    *e = s.items[s.top];
    return 0;
}

void print_stack(struct array_stack s)
{
    printf("[");
    if(s.top > -1) {
        for (int i = 0; i < s.top; i++) {
            printf("%d, ", s.items[i]);
        }
        printf("%d", s.items[s.top]);
    }
    printf("]\n");
}
