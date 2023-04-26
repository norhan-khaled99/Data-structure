#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"
#include "Queue.h"

int Fact(int num)
{
    if(num == 1)
        return 1;

    int result = num * Fact(num - 1);
    return result;
}

int main()
{
    /*Stack stk = {.top = -1};

    Push(&stk, 10);
    Push(&stk, 20);
    Push(&stk, 30);

    int num;

    if(Pop(&stk, &num))
    {

    }
    else
    {

    }

    while(Pop(&stk, &num))
    {
        printf("%d   ", num);
    }*/

    /*Queue que = {.front = -1, .rear = -1};

    EnQueue(&que, 10);
    EnQueue(&que, 20);
    EnQueue(&que, 30);

    int num;

    while(DeQueue(&que, &num))
    {

    }*/

    int res = Fact(5);

    return 0;
}
