#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "stack.h"


Snode* newNode(Tnode* tnode){
    Snode* snode = (Snode*) malloc(sizeof(Snode));
    snode->tnode = tnode;
    snode->next = NULL;
    return snode;
}

int isEmpty(Snode* root){
    if((root) == NULL){
        return 1;
    } else{
        return 0;
    }
}

int peek(Snode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    return (*root)->tnode->id;
}

void push(Snode** root, Tnode* tnode){
    Snode* snode = newNode(tnode);
    snode->next = *root;
    *root = snode;
    (*root)->tnode = tnode;
}

// void push(Snode** root, Tnode* tnode){
//     Snode* snode = newNode(tnode);
//     snode->next = *root;
//     *root = snode;
// }
Tnode* pop(Snode** root){
    if (isEmpty(*root))
        return NULL;
    Snode* temp = *root;
    Tnode* t = (*root)->tnode;
    *root = (*root)->next;
    //free(t);
    free(temp);
    return t;
}

