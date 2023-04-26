#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void Swap(Node *n1, Node *n2)
{
    int temp = n1->Data;
    n1->Data = n2->Data;
    n2->Data = temp;
}

void bubbleSort(int size){
    Node *start = head;
    int sorted=0;
    for(int i=0;i<=size-1 && sorted==0;i++){
        sorted=1;
        for(int j=0;j<size-i-1;j++){
            if(start->Data > start->Next->Data)
            {
                Swap(start, start->Next);
                sorted = 0;
            }
                start = start->Next;
        }
                start = head;
    }
}

int BinarySearch(int data,int size){
    int minIndex=0,maxIndex = size - 1,midIndex;
    while(maxIndex >= minIndex){
        midIndex = (minIndex + maxIndex) / 2;
        int item = GetDataByIndex(midIndex);
        if(data == item){
                return midIndex+1;
        }
        else if(data > item){
            minIndex = midIndex + 1;
        }
        else{
            maxIndex = midIndex - 1;
        }
    }
    return -1;
}
int main()
{
    Add(7);
    Add(5);
    Add(10);
    Add(12);
    Add(4);
    Add(2);
    int size = GetCount();
    bubbleSort(size);
    Display();
    printf("\n");
    int index = BinarySearch(10,size);
    printf("index of the data : %d",index);
    return 0;
}
