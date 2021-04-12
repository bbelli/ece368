#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "tree.h"

extern FILE *output1;
extern FILE *output2;
extern FILE *output3;
extern FILE *output4;
extern FILE *output5;

Tnode* createNode(char id, int flag){
   Tnode* n = (Tnode*) calloc(1, sizeof(Tnode));
   
   //For safety if you run  out of memory
   //check if NULL

   //Tnode* n = (Tnode*) malloc(sizeof(Tnode));
   n->id = id;
   n->flag = flag;
   return n;
}

Tnode *duplicate_node(const Tnode *src)
{
    Tnode *dest = calloc(sizeof(Tnode), 1);

    memcpy(dest, src, sizeof(Tnode));
    return dest;
}

void preorder(Tnode *node){
   if (node == NULL) 
      return;
   if(node->flag == 0){   
      fprintf(output1, "%c", node->id);
   } else{
      fprintf(output1, "%d", 1);
      fprintf(output1, "%c", node->id);
   }
   preorder(node->left);
   preorder(node->right);
}


void Destroy_tree(Tnode *node){
   if (node == NULL)
      return;
   Destroy_tree(node->left);
   Destroy_tree(node->right);
   free(node);
}

