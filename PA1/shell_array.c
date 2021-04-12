
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_array.h"

void printA(int* arr, int size);

 long *Array_Load_From_File(char *filename, int *size){

    FILE * fptr = fopen(filename, "rb"); //Open the file as binary file
    long * arr;
    int numOfVal = 0;
    //int value;
    //Return a NULL address(?) and assign 0 to size if the file fails to open.
    if(fptr ==  NULL){
        //arr = malloc(0); //?  
        *size = 0;
        return NULL;  
    } 
    //First iteration to count how many long values there are
    long var = 0;
    int a=0;
    while (fread(&var, sizeof(long), 1, fptr) == 1){
      //printf("arr[%d]: %ld\n", a, var);
      numOfVal++;
      a++;
    }
    //If the file is empty return a array with 0 mem allocated
    if(numOfVal == 0){
        arr = malloc(0);
        return arr;
    }

    //Allocate memory based on the number of values
    *size = numOfVal;
    arr = malloc(sizeof(long) * (*size));
    //Second iteration to assign the values to the array
    int i = 0;
    fseek(fptr,0,SEEK_SET); //fptr back to start
    while (fread(&var, sizeof(long), 1, fptr) == 1){
        //printf("%ld\n", var);
        arr[i] = var;
        i++;
    }
    //fclose, return address of the memory allocated for the long integers
     fclose (fptr);
     return arr;
}


int Array_Save_To_File(char *filename, long *array, int size){
    //The function saves array to an external file specified by file name in binary format.  
    //The output file and the input file have the same format. 
    FILE *fptr = fopen(filename, "wb");
    //The integer returned should be the number of long integers in the 
    //array that have been successfully saved into the file. == numOfVal
    int numOfVal = 0;
    //long value = 0;
    //If array is NULL or size is 0, an empty output file should be created.
    if((fptr == NULL) || size == 0){
        //fprintf(fptr," "); //String????? Change this!!!!!!!!!!
        return 0;
    }
    //int var = 0;
    for(int i=0; i < size; i++){ //size?
        //value = array[i];
        //fwrite(fptr, "%ld\n", value);
        fwrite(&array[i], sizeof(long), 1, fptr); //https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
        numOfVal++;
    }
    //fclose, number of values succesfully written to the file
    fclose(fptr);
    return numOfVal;
}


void Array_Shellsort(long *array, int size, long *n_comp){
    
    int counter = 0;
    //printf("%d\n", array[3]);
    for(int h=1;h < size; h = 3*h +1){
        counter++; //To determine the size of the array
    }
    //printf("%d", counter);
    //counter--; //decrement by one so the first iteration isn't out of bounds. 
    int x = 1;
    int  arrSize = counter;
    //int arr[arrSize];
    int *arr = malloc(sizeof(int) * arrSize);
    
    //Assign the sequence values to array. 
    for(int i=0; i < counter; i++){
        arr[i] = x;
        x = 3*x + 1; //h(i+1) = h(i)*3 + 1
    }
    //printA(arr, counter);

    for (int i = counter - 1; i >= 0; i--) {
        int k = arr[i];
        // printf("\n");
        // printf("%d\n", k);
        for (int j = k; j <= size - 1; j++) {
            long t = array[j];
            int x = j;
            while (x >= k && array[x-k] > t) {
                *(n_comp)++;
                array[x] = array[x-k];
                x = x-k;
            }
            array[x] = t;
        }
    }
    free(arr);
}

// void printA(int* arr, int size) {
//     printf("---%d-----\n", size);
//     for (int i = 0; i < size; i++) {
//         printf("%ld\n", arr[i]);
//     }
// }







