#include <stack/linked_stack.h>
#include <stdio.h>
#include <stdlib.h>


struct linked_stack * new_stack(unsigned int size)
{
    struct linked_stack * s = malloc(sizeof(struct linked_stack));
    s->top = NULL;
    return s;
}

void free_stack(struct linked_stack * s)
{
    struct stack_element * cursor = s->top;

    struct stack_element * aux;
    while(cursor != NULL) {
        // Get prev element
        aux = cursor->prev;
        free(cursor);
        cursor = aux;
    }
    free(s);
}

char is_empty(struct linked_stack s)
{
    if(s.top == NULL)
        return 1;
    else
        return 0;
}

int pop(struct linked_stack * s, unsigned int * e)
{
    if(is_empty(*s))
        return -1;

    // Get top
    struct stack_element * el = s->top;
    *e = el->data;

    // Set top to prev element
    s->top = el->prev;

    // Free element
    free(el);

    return 0;
}

int push(struct linked_stack * s, unsigned int e)
{
    // Create new element
    struct stack_element * element = malloc(sizeof(struct stack_element));

    // Assign data to new element
    element->data = e;

    // Set prev to point to current top
    element->prev = s->top;

    // Point top to new element
    s->top = element;

    return 0;
}

int peek(struct linked_stack s, unsigned int * e)
{
    if(is_empty(s))
        return -1;

    struct stack_element * el = s.top;
    *e = el->data;

    return 0;
}

void print_stack(struct linked_stack s)
{
    struct stack_element * cursor;
    cursor = s.top;
    printf("[");
    while(cursor != NULL) {
        if(cursor->prev != NULL)
            printf("%d, ", cursor->data);
        else
            printf("%d", cursor->data);
        cursor = cursor->prev;
    }
    printf("]\n");
}
