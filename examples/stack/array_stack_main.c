#include <stack/array_stack.h>
#include <stdio.h>

int main(void)
{
    // Create array_stack
    struct array_stack * s = new_stack(6);
    unsigned int e;

    int err = pop(s, &e);
    printf("Pop returned: %d\n", err);

    // Push movidas
    push(s, 1U);
    push(s, 9U);
    push(s, 7U);
    push(s, 3U);
    err = push(s, 5U);
    printf("5th push returned: %d\n", err);
    push(s, 3U);
    err = push(s, 2U);
    printf("7th push returned: %d\n", err);
    push(s, 3U);

    // Pop something
    pop(s, &e);
    printf("Just popped: %d\n", e);
    pop(s, &e);
    printf("Just popped: %d\n",e);

    // String
    print_stack(*s);

    // Peek
    peek(*s, &e);
    printf("Top: %d", e);

    // Free array_stack
    free_stack(s);
 
    return 0;
}
