#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Snode* newNode(Tnode* tnode){
    Snode* snode = (Snode*) malloc(sizeof(Snode));
    snode->tnode = tnode;
    snode->next = NULL;
    return snode;
}

bool isEmpty(Snode* root){
    return root == NULL;
}

void push(Snode** root, Tnode* tnode){
    Snode* snode = newNode(tnode);
    snode->next = *root;
    *root = snode;
}

Tnode* pop(Snode** root)
{
    if (isEmpty(*root))
        return 0;
    Snode* temp = *root;
    Tnode* t = (*root)->tnode;
    *root = (*root)->next;
    free(temp);
    return t;
}

