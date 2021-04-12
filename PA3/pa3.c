#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h> 
#include "stack.h"

FILE *output1;
FILE *output2;
FILE *output3;


Tnode* buildTree(Tnode* root, Snode** stack);
void writePreorder(char* filename, Tnode *node);
void writePostorder(char* filename, Tnode *node);
void writeCoordinates(char* filename, Tnode *node);
void findCoord(Tnode *treeRoot, int roomX, int roomY);

void readFile(char* filename, Snode* stack){

    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL){
        return;
    }
    
    char str[60];
    Tnode* node;
    while(fgets(str, 60, fptr) != NULL) {
        if (str[0] == 'V' || str[0] == 'H') {
            node = createNode(str[0], 0, 0); //INT_MAX, INT_MAX
            push(&stack,node);
        } else {
            int id, w, h;
            sscanf(str, "%d(%d,%d)\n", &id, &w, &h);
            node = createNode(id, w, h);
            push(&stack,node);
        }
    }
    fclose(fptr);
    return;
}

Tnode* buildTree(Tnode* root, Snode** stack) {
   if(isEmpty(*stack)) {
      //printf("Stack is empty!");
      return NULL;
   }

   Tnode* node = pop(stack);
   if ((node->width != INT_MAX)){
      //leaf node
      return node;
   } else {
      root = node;
      root->right = buildTree(root, stack);
      root->left = buildTree(root, stack);
      return root;
   }
   //return root;
}

void writePreorder(char* filename, Tnode *node){
    if (node == NULL) 
      return;
    output1 = fopen(filename, "w");
    if(output1 == NULL){
      //printf("FPTR is NULL\n");
      return;
    }
    //fprintf(output1, "%d(%d,%d)\n", node->id, node->width, node->height);
    //fprintf(fptr, "%d(%d,%d)\n", node->left->id, node->left->width, node->left->height);
    //char str[60];
    preorder(node);
    fclose(output1);
}

void writePostorder(char* filename, Tnode *node){
    if (node == NULL) 
      return;
    output2 = fopen(filename, "w");
    if(output2 == NULL){
      //printf("FPTR is NULL\n");
      return;
    }
    //fprintf(output1, "%d(%d,%d)\n", node->id, node->width, node->height);
    //fprintf(fptr, "%d(%d,%d)\n", node->left->id, node->left->width, node->left->height);
    //char str[60];
    postorder(node);
    fclose(output2);
}

void writeCoordinates(char* filename, Tnode* node){
    if(node == NULL){
        return;
    }
    output3 = fopen(filename, "w");
    if(output3 == NULL){
        //printf("FPTR is NULL\n");
        return;
    }
    preorderCoordinates(node);
    fclose(output3);
}

void findCoord(Tnode* root, int roomX, int roomY) {
    if (root == NULL) {
        //printf("Passed node is null");
        return;
    }
    
    if ((root->id == 86) && root->flag == 2){
        int rootx = root->x;
        int rooty = root->y;
        if(root->left == NULL && root->right == NULL){
            return;
        } else if(root->right == NULL && root->left != NULL){
            root->left->x = rootx;
            root->left->y= rooty;
        } else if(root->left == NULL && root->right != NULL){
            root->right->x = root->width + rootx;
            root->right->y= rooty;
        } else{
            root->left->x = rootx;
            root->right->x = root->left->width + rootx;
            root->left->y= rooty; //store dimensions of rooms and pass accordingly
            root->right->y= rooty;
        }
    } else if((root->id == 72) && root->flag == 1) {
        int rootx = root->x;
        int rooty = root->y;
        if(root->left == NULL && root->right == NULL){
            return;
        } else if(root->right == NULL && root->left != NULL){
            root->left->y = root->height + rooty;
            root->left->x = rootx;
        } else if(root->left == NULL && root->right != NULL){
           root->right->y = rooty;
           root->right->x = rootx;
        } else{
        root->right->y = rooty;
        root->left->y = root->right->height + rooty;
        root->left->x = rootx;
        root->right->x = rootx;
        }
    }
    
    findCoord(root->left, roomX, roomY);
    findCoord(root->right, roomX, roomY);
}

//gdb treeRoot->height, width compare with grid for node->id = 1

int main(int argc, char** argv){

    if(argc != 5){
        //printf("Wrong inputs!");
        return EXIT_FAILURE;
    }

    FILE *fptr = fopen(argv[1], "r");
    if(fptr == NULL){
        return EXIT_FAILURE;
    }
    
    char str[60];
    Snode* stack;
    Tnode* node = NULL;
    while(fgets(str, 60, fptr) != NULL) {
        if (str[1] == '\n') {
            node = createNode(str[0], INT_MAX, INT_MAX);
            //push(&stack,node);
        } else {
            int id, w, h;
            sscanf(str, "%d(%d,%d)\n", &id, &w, &h);
            node = createNode(id, w, h);
            //push(&stack,node);
        }
        push(&stack,node);
    }
    fclose(fptr);
    

    //argv[0] : exectuable file

    //argv[1] in_file: 
    // - Stores the binary tree representation of a "packing" of rectangular blocks.
    // -  In format of %d(%d,%d) int1: label, int2: x-coordinate, int3: y-cooordinate
    // - Postorder traversal

    //argv[2] out_file1:
    // - Name of file that stores strictly binary tree in pre-order
    // - Format same with in_file, only the order is pre-order


    //argv[3] out_file2:
    // - Name of file that stores dimensions of rectangular blocks and smallest rectangular rooms
    // - Printed in post order traversal
    
    //argv[4] out_file3:
    // - Name of file that stores the coordinates of the rectangular blocks
    // - %d((%d,%d)(%d,%d))\n format

    Tnode * treeRoot = NULL;
    treeRoot = buildTree(treeRoot, &stack);
    writePreorder(argv[2], treeRoot);
    writePostorder(argv[3], treeRoot);
    int roomX = treeRoot->width;
    int roomY = treeRoot->height;
    findCoord(treeRoot, roomX, roomY);
    writeCoordinates(argv[4], treeRoot);
    //printf("Hey");
    Destroy_tree(treeRoot);

    


}