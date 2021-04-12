#include "tree.h"
#include <stdbool.h> 

typedef struct _Snode {
    struct _Snode* next;
    struct Tnode* tnode;
} Snode;


Snode* newNode(Tnode* tnode);
int isEmpty(Snode* root);
void push(Snode** root, Tnode* tnode);
Tnode* pop(Snode** root);
int peek(Snode** root);

