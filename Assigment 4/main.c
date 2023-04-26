#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main()
{
    Tree tree;
    tree.Root = NULL;

    Add(&tree, 50);
    Add(&tree, 40);
    Add(&tree, 30);
    Add(&tree, 60);
    Add(&tree, 70);
    Add(&tree, 65);

    Display(tree.Root);
    printf("\n");
int MaxDepth=GetMaxDepth(tree.Root);
printf("%d ",MaxDepth);
    return 0;
}
