#ifndef STACK_H
#define STACK_H

#define MaxStackSize 5

typedef struct Stack
{
    int Items[MaxStackSize];
    int top;

}Stack;

void Push(Stack *s, int data)
{
    if(s->top == MaxStackSize - 1)
        return;

    s->top++;
    s->Items[s->top] = data;
}

int Pop(Stack *s, int *data)
{
    if(s->top == -1)
    {
        return 0;
    }

    *data = s->Items[s->top];
    s->top--;

    return 1;
}

#endif // STACK_H
