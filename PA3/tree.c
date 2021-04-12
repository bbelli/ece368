#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tree.h"
extern FILE *output1;
extern FILE *output2;
extern FILE *output3;


Tnode* createNode(int id, int width, int height){
   Tnode* n = (Tnode*) calloc(1, sizeof(Tnode));
   //Tnode* n = (Tnode*) malloc(sizeof(Tnode));
   n->id = id;
   n->x = 0;
   n->y = 0;
   n->width = width;
   n->height = height;
   return n;
}

int isMax(int n1, int n2){
   if(n1 > n2){
      return n1;
   } else{
      return n2;
   }
}

// void ogPostorder(Tnode *node)
// {
//    if (node == NULL) 
//       return;
//    ogPostorder(node->left);
//    ogPostorder(node->right);
//    if(node->id == 86 || node->id == 72){
//       fprintf(output2, "%c\n", node->id);
//    } else {
//       fprintf(output2, "%d(%d,%d)\n", node->id, node->width, node->height);
//    }
//    if(node->right == NULL && node->left == NULL){
//       return;
//    }
// }


void postorder(Tnode *node)
{
   int max;
   if (node == NULL) 
      return;
   postorder(node->left);
   postorder(node->right);
   if((node->id == 86 || node->id == 72) && node->width == INT_MAX){
      if(node->id == 72){
         node->flag = 1;
         if(node->right == NULL && node->left == NULL){
            return;
         } else if(node->right == NULL && node->left != NULL){
            max = isMax(0, node->left->width);
            node->width = max;
            node->height = node->left->height;
         } else if(node->left == NULL && node->right != NULL){
            max = isMax(0, node->right->width);
            node->width = max;
            node->height = node->right->height;
         } else{
            max = isMax(node->right->width, node->left->width);
            node->width = max;
            node->height = node->right->height + node->left->height;
         }
      } else if(node->id == 86){
         node->flag = 2;
         if(node->right == NULL && node->left == NULL){
            return;
         } else if(node->right == NULL && node->left != NULL){
            max = isMax(0, node->left->height);
            node->height = max;
            node->width = node->left->width;
         } else if(node->left == NULL && node->right != NULL){
            max = isMax(0, node->right->height);
            node->height = max;
            node->width = node->right->width;
         } else{
            max = isMax(node->right->height, node->left->height);
            node->height = max;
            node->width = node->right->width + node->left->width;
         }
      }
      fprintf(output2, "%c(%d,%d)\n", node->id, node->width, node->height);
   } else {
      fprintf(output2, "%d(%d,%d)\n", node->id, node->width, node->height);
   }
}

void preorderCoordinates(Tnode *node){
   if (node == NULL) 
      return;
   if((node->flag == 0)){
      fprintf(output3, "%d((%d,%d)(%d,%d))\n", node->id, node->width, node->height, node->x, node->y);
   } 
   preorderCoordinates(node->left);
   preorderCoordinates(node->right);
}

void preorder(Tnode *node)
{
   if (node == NULL) 
      return;
   if((node->id == 86 || node->id == 72) && node->height == INT_MAX){
      fprintf(output1, "%c\n", node->id);
   } else {
      fprintf(output1, "%d(%d,%d)\n", node->id, node->width, node->height);
   }
   if(node->right == NULL && node->left == NULL){
      return;
   }
   preorder(node->left);
   preorder(node->right);
}

void Destroy_tree(Tnode *node)
{
   if (node == NULL)
      return;
   Destroy_tree(node->left);
   Destroy_tree(node->right);
   free(node);
}

