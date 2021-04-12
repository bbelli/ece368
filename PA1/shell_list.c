#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_list.h"
//shell_list.h 
// typedef struct _Node {
//    long value;
//    struct _Node *next;
// } Node;




static int valReturn(Node *list, int index){
    Node *temp = list;
    for(int i=0;i < index; i++){
        temp = temp->next;
    }
    return temp->value;
}


static void swapVal(Node *list, int val, int index){
    Node *temp = list;
    for(int i=0;i < index; i++){
        temp = temp->next;
    }
    temp->value = val;
}


Node *List_Load_From_File(char *filename){
    FILE *fptr = fopen(filename, "rb");
    Node *head = NULL;
    long var = 0;
    while (fread(&var, sizeof(long), 1, fptr) == 1){
      Node *temp = malloc(sizeof(Node)); //alloc size of 1  node
      temp->value = var; //set the value of temp to be what is read from the file  
      temp->next = head; //temp -> head
      head = temp;
    }
    fclose(fptr);
    return head;
}


int List_Save_To_File(char *filename, Node *list){
    
    FILE *optr = fopen(filename, "wb");
    Node *temp = list;
    int counter = 0;
    while(temp->next != NULL){
        fwrite(&temp->value, sizeof(long), 1, optr);
        temp = temp->next;
        counter++;
    }
    fclose(optr);
    return counter;
}

Node *List_Shellsort(Node *list, long *n_comp){
    int counter = 0;
    int ListSize = 0;
    //printf("%d\n", array[3]);
    Node *temp = list;
    while(temp->next != NULL){
        //printf("Node passed: %ld\n", temp->value);
        temp = temp->next;
    }
    temp = list;

    while(temp->next != NULL){
        ListSize++;
        temp = temp->next;
    }

    for(int h=1;h < ListSize; h = 3*h +1){
        counter++; //To determine the size of the array
    }
    
    int x = 1;
    //int arr[counter];
    int *arr = malloc(counter);
    
    //Assign the sequence values to array. 
    for(int i=0; i < counter; i++){
        arr[i] = x;
        x = 3*x + 1; //h(i+1) = h(i)*3 + 1
    }
    
    int k = counter-1;
    int i =0;
    int temp_r = 0;
    int retVal = 0;
    int flag = 0;
    // Node *loopNode = NULL;
    // Node *loopNode2 = NULL;
    //Outer loop for the sequence "gap" values
    for(k = arr[k]; k > 0; k--){
        for(int j=k; j < ListSize; j++){ //increment j by j++ or j += k ? 
            //loopNode = indexReturn(list,j);
            temp_r = valReturn(list,j);
            i = j;  
            while(((i >= k)) && (valReturn(list, i-k)) > temp_r){
                retVal = valReturn(list, i-k);
                swapVal(list, retVal, i);
                i = i-k;
                flag = 1;
            }
            if (flag) {
                swapVal(list, temp_r, i);
                (*n_comp)++;
                flag = 1;
            }
            
        }
    }
    return list;
}
