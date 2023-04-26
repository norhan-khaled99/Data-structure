#ifndef TREE_H
#define TREE_H

typedef struct Node Node;
typedef struct Tree Tree;

struct Node
{
    int Data;
    Node *Left, *Right;
};

struct Tree
{
    Node *Root;
};

void Add(Tree *tree, int data)
{
    Node *node = malloc(sizeof(Node));
    node->Data = data;
    node->Left = node->Right = NULL;

    if(tree->Root == NULL)
    {
        tree->Root = node;
    }
    else
    {
        Node *current = tree->Root;
        Node *parent;

        while(current != NULL)
        {
            parent = current;

            if(data > current->Data)
                current = current->Right;
            else
                current = current->Left;
        }

        if(data > parent->Data)
            parent->Right = node;
        else
            parent->Left = node;
    }
}

Node* GetNodeByData(Tree *tree, int data)
{
    Node* current = tree->Root;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        if(data > current->Data)
            current = current->Right;
        else
            current = current->Left;
    }

    return NULL;
}

Node* GetParent(Tree *tree, Node *node)
{
    Node *parent = tree->Root;

    while(parent != NULL)
    {
        if(parent->Left == node || parent->Right == node)
            return parent;

        if(node->Data > parent->Data)
            parent = parent->Right;
        else
            parent = parent->Left;
    }

    return NULL;
}

Node* GetMaxRight(Node *node)
{
    Node *current = node;

    while(current->Right != NULL)
    {
        current = current->Right;
    }

    return current;
}

void Remove(Tree *tree, int data)
{
    Node *node = GetNodeByData(tree, data);

    if(node == NULL)
        return;

    if(node == tree->Root)
    {
        if(node->Left == NULL && node->Right == NULL)
        {
            tree->Root = NULL;
        }
        else if(node->Right == NULL)
        {
            tree->Root = tree->Root->Left;
        }
        else if(node->Left == NULL)
        {
            tree->Root = tree->Root->Right;
        }
        else
        {
            Node *newRoot = tree->Root->Left;
            Node *maxRight = GetMaxRight(newRoot);

            maxRight->Right = tree->Root->Right;
            tree->Root = newRoot;
        }
    }
    else
    {
        Node *parent = GetParent(tree, node);
        Node *newChild;

        if(node->Left == NULL && node->Right == NULL)
        {
            newChild= NULL;
        }
        else if(node->Right == NULL)
        {
            newChild = node->Left;
        }
        else if(node->Left == NULL)
        {
            newChild = node->Right;
        }
        else
        {
            Node* newParent = node->Left;
            Node*maxRight = GetMaxRight(newParent);

            maxRight->Right = node->Right;

            newChild = newParent;
        }

        if(parent->Left == node)
            parent->Left = newChild;
        else
            parent->Right = newChild;
    }


    free(node);
}

void Display(Node *node)
{
    if(node == NULL)
        return;

    Display(node->Left);
    printf("%d  ", node->Data);
    Display(node->Right);
}

int GetMaxDepth(Node *node)
{
    int LDepth, RDepth;
    if(node == NULL)
        return;

    LDepth = GetMaxDepth(node->Left)+1;
    RDepth = GetMaxDepth(node->Right)+1;

    if(RDepth >= LDepth){
        return RDepth;
        }
    return LDepth;
}

#endif // TREE_H
