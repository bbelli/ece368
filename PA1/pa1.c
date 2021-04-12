#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_array.h"
#include "shell_list.h"

void printArr(long* arr, int size);

int main(int argc, char *argv[]){
    //FREE MEMORY!
    //FILE * fptr = fopen("1M.b", "r");
    //shell_array temp;
    // shell_array test;
    //use argv[]
    //check if -a or -l
    if(argc != 4){
        return 0;
    }

    int size = 0;
    long comp = 0;

    if(strcmp(argv[1], "-a") == 0){
        //long *a = Array_Load_From_File("/home/shay/a/bbelli/ece368/examples/1M.b", &size);
        long *a = Array_Load_From_File(argv[2], &size);
        if(a == NULL){
            return EXIT_FAILURE;
        }
        //printArr(a, size);
        Array_Shellsort(a, size, &comp);
        
        int b = Array_Save_To_File(argv[3], a, size);
        printf("%ld", comp);
        free(a);
        return b;
    }

    else if(strcmp(argv[1], "-l") == 0){
        Node *a = List_Load_From_File(argv[2]);
        Node *list = List_Shellsort(a, &comp);
        int b = List_Save_To_File(argv[3], list);
        printf("%ld", comp);
        free(a);
        free(list);
        return b;
    }
    //printf("%ld",*a);
    return 0;
}

void printArr(long* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%ld\n", arr[i]);
    }
}

