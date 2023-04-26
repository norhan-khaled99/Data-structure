#ifndef CIRCULARARRAY _H
#define CIRCULARARRAY _H
#define MaxSize 5

typedef struct Queue_Arr Queue_Arr;

struct Queue_Arr{
    int Front, Rear;
    int arrOfQueue[MaxSize];
};

void EnQueue_arr(Queue_Arr *arr, int data){
    if(arr->Front == (arr->Rear+1)){
        return;
    }
    if(arr->Front == 0 && arr->Rear == MaxSize-1)
        return;

    if(arr->Front == -1 && arr->Rear == -1){
        arr->arrOfQueue[0] = data;
        arr->Front++;
    }
    else
    {
        arr->arrOfQueue[arr->Rear+1] = data;
    }
    arr->Rear++;
    if(arr->Rear == MaxSize){
        arr->Rear == 0;
    }
}

void Display_ARR(Queue_Arr *arr){
    if(arr->Front == -1 && arr->Rear == -1)
    {
        printf("Empty Queue");
    }
    else
    {
        for(int i=arr->Front;i<=arr->Rear;i++)
        {
            printf("%d   ",arr->arrOfQueue[i]);
        }
    }
}

int DeQueue_arr(Queue_Arr *arr){
    if(arr->Front == -1 && arr->Rear == -1)
    {
        return 0;
    }

    if(arr->Front == arr->Rear){
        arr->Front =-1;
        arr->Rear=-1;
        return 0;
    }

    arr->Front++;
    if(arr->Front == MaxSize){
        arr->Front == 0;
    }
}


#endif // CIRCULARARRAY _H
