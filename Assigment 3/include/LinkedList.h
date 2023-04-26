#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

Node *head = NULL, *tail = NULL;

//void Add(LinkedList *myList, int data)

void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
    }
}

void Display()
{
    Node* current = head;

    while(current != NULL)
    {
        printf("%d   ", current->Data);
        current = current->Next;
    }
}

int GetCount()
{
    Node *current = head;
    int counter = 0;
    while (current != NULL) {
        counter++;
        current = current->Next;
    }
    return counter;
}
int GetDataByIndex(int index)
{
    Node *current = head;
    int counter = 0;
    while (current != NULL) {
        if (counter == index){
            return (current->Data);
        }else{
            counter++;
            current = current->Next;
        }
    }
    printf( "not found\n" );
}


#endif // LINKEDLIST_H
