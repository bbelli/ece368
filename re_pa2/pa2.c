#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h> 
#include "stack.h"

FILE *output1;
FILE *output2;
FILE *output3;
FILE *output4;
FILE *output5;

void byte_to_bits(int byte, char *bits);
int byte_to_char(char *topology, Snode** stack, int size, Tnode* node, Tnode* node1, Tnode* node2);
Tnode* buildTree(Tnode* root, Snode** stack);

void byte_to_bits(int byte, char *bits){

   unsigned char bitmask = 1;
   //unsigned char bits[8];
   for(int i=0; i < 8; i++){
      bits[i] = (byte & (bitmask << i)) != 0;
   }
}

void remove_zeroes(Snode** stack){

    Tnode *t = NULL;
    if(isEmpty(*stack)){
        return;
    }
    int val;
    val = peek(stack);
    if(val == 48){
        t = pop(stack);
        free(t);
    } else{
        return;
    }
}



void decode(char* filename, char* bits, Tnode* root, int size_original, int size, int* ascii){
    
    int charCount = 0;
    int id;
    Tnode* treeRoot = root;
    Tnode* tmp = NULL;

    output2 = fopen(filename, "w");

    for(int i=0; i< size; i++){
        if(bits[i] == 0){
            tmp = root->left;
            root = tmp;
        } else{
            tmp = root->right;
            root = tmp;
        }

        if(tmp->flag != 0){
            fprintf(output2, "%c", tmp->id);
            id = tmp->id;
            //printf(" a %d\n", id);
            ascii[id] = ascii[id] + 1;
            charCount++;
            root = treeRoot;
        }

        if(charCount == size_original){
            break;
        }
    }
    printf("%d\n", charCount);
    fclose(output2);
    return;
}


int byte_to_char(char *topology, Snode** stack, int size, Tnode* node, Tnode* node1, Tnode* node2){
    int numOfBytes = 0;
    char ascii_concat[8]; 
    unsigned char ascii_val = 0;  
    int countChar =0;
    //char char_top[80];
    for(int i=0; i < size; i++){
        if(topology[i] == 0){
            //char_top[i] = 48; //ASCII Value of 0
            node = createNode(48, 0);
            //node = NULL;
            push(stack, node);
            //free(node);
            numOfBytes++;
        } else{
            ascii_val = 0xff;
            //char_top[i] = 49; //ASCII Value of 1
            //node1 = createNode(49, 1);
            //push(stack, node1);
            //free(node1);
            numOfBytes++;
            i++; //skip the leaf node indicator
            countChar++;  
            for(int j=0; j<8; j++){
                ascii_concat[j] = topology[i++];
            }
            i--;
            for(int j=0; j<8; j++){
                if(ascii_concat[j] == 0){
                    ascii_val = (1 << (j)) ^ ascii_val;
                }
            }
            //printf("%c\n", ascii_val);
            //Create leaf node
            //char_top[i] = ascii_val;

            //byte_to_char (pa2.c:73)
            node2 = createNode(ascii_val, 2);
            //node2 = NULL;
            push(stack, node2);
            //free(node2);
            numOfBytes = numOfBytes + 8;
            //count characters in header
        }
        countChar++;
    }

    // printf("chars\n");
    // for(int i=0;i < 24; i++){
    //    printf("%c", char_top[i]);
    // }
    //free(node);
    return numOfBytes;
    
}

void writePreorder(char* filename, Tnode *node){
    if (node == NULL) 
      return;
    output1 = fopen(filename, "w");
    if(output1 == NULL){
      //printf("FPTR is NULL\n");
      return;
    }
    preorder(node);
    fclose(output1);
}

void writeCount(char *filename, int* ascii){

    output3 = fopen(filename, "wb");
    char tmp = 0;
    for(int i=0; i < 257; i++){
        tmp = ascii[i];
        fwrite(&ascii[i], 1, sizeof(long), output3);
    }

    // int g = 0;
    // for(int i=0; i< 256; i++){
    //     printf("%d) %d\n", g, ascii[i]);
    //     g++;
    // }
    // printf("exit");

    fclose(output3);
    return;
}

Tnode* buildTree(Tnode* root, Snode** stack){

    if(isEmpty(*stack)){
        printf("Stack is empty!\n");
        return NULL;
    }
    Tnode *tmp = NULL;
    tmp = pop(stack);
    if(tmp->flag != 0){
        return tmp;
    } else{
        root = tmp;
        root->left = buildTree(root, stack);
        root->right = buildTree(root, stack);
        return root;
    }

}


int main(int argc, char ** argv){     
        if(argc != 7){
            printf("args doesn't match expected value\n");
            return EXIT_FAILURE;
        }

        FILE *fptr = fopen(argv[1], "rb");
        if(fptr == NULL){
            return EXIT_FAILURE;
        }

        long int size_compressed; //size_compressed: Number of bytes in compressed file
        long int size_topology;   //size_topology: Number of bytes topology uses
        long int size_original;   //size_original: Number of bytes in the uncompressed file
    
        fread(&size_compressed, sizeof(long int) , 1, fptr);
        fread(&size_topology, sizeof(long int), 1, fptr);
        fread(&size_original, sizeof(long int), 1, fptr);
        int size = sizeof(char)* sizeof(long int) * size_topology;
        
        unsigned char *buffer;
        int *val; 
        buffer = (unsigned char*) malloc(sizeof(unsigned char) * size_topology);
        size_t bytes_read = fread(buffer, sizeof(unsigned char), size_topology, fptr);
        val = (int*) malloc(size);
    
        if(bytes_read != size_topology){
            printf("Topology size and read bytes don't match!");
        }
    
        for(int i=0; i < size_topology; i++){
          val[i] = buffer[i];
        }
        free(buffer);

        char *toVal; //toVal: char array of 8 to store every bit of a byte
        char *all_topology;  //all_topology: char array of 8 * size_topology to store ALL bits of topology. 
        int j; //j: index for all_topology
        toVal = (char*) malloc(size);
        all_topology = (char*) malloc(size);
    
        //For Loop where conversion of the bytes in val to bits happen, output is stored in all_topology 
        for(int i=0; i < size_topology; i++){
            j = i*8;
            byte_to_bits(val[i], toVal);
            for(int k=0; k< 8;k++){
                all_topology[j] = toVal[k];
                printf("%d", all_topology[j]);
                j++;
            }
            printf("\n");
        }
    
        //-----NO MEMORY ISSUES UP TO HERE-----
        //-----NO MEMORY ISSUES UP TO HERE-----
        //-----NO MEMORY ISSUES UP TO HERE-----

    Snode* stack = NULL;
    Tnode* tmpnode = NULL;
    Tnode* tmpnode1 = NULL;
    Tnode* tmpnode2 = NULL;
    int numOfBytes = byte_to_char(all_topology, &stack, size, tmpnode, tmpnode1, tmpnode2);
    
    remove_zeroes(&stack);

    Tnode* node = NULL;
    Snode* reverse_stack = NULL;
    
    //reverse_stack to construct pre-oreder tree accordingly
    int flag = 1;
    while(flag){
        node = pop(&stack);
        if(node == NULL){
            break;
        }
        printf("%c", node->id);
        printf("\n");
        push(&reverse_stack, node); 
    }

    //construct tree calling buildTree, treeRoot is the root of the tree
    Tnode *treeRoot = NULL;
    treeRoot = buildTree(treeRoot, &reverse_stack);
    writePreorder(argv[2], treeRoot);

    //byte to bit conversion process for decoding
    unsigned char decode_buffer[(size_compressed - size_topology -12)];
    size_t bytes_read2 = fread(&decode_buffer, 1, (size_compressed - size_topology -12), fptr);

    size = sizeof(char)* sizeof(long int) * bytes_read2;
    int toInt[size];

    for(int i=0; i < bytes_read2; i++){
        toInt[i] = decode_buffer[i];
    }

    char *toVal2; //toVal: char array of 8 to store every bit of a byte
    char *all_encode;  //all_topology: char array of 8 * bytes_read to store ALL bits of encode. 
    toVal2 = (char*) malloc(size);
    all_encode = (char*) malloc(size);

    for(int i=0; i < bytes_read2; i++){
        j = i*8;
        byte_to_bits(toInt[i], toVal2);
        for(int k=0; k < 8;k++){
            all_encode[j] = toVal2[k];
            printf("%d", all_encode[j]);
            j++;
        }
        printf("\n");
    }
    
    //initialize array to store occurunces of ASCII values. 
    int ascii[256];
    for(int i=0; i< 256; i++){
        ascii[i] = 0x00000000;
    }

    //decoding
    decode(argv[3], all_encode, treeRoot, size_original, size, ascii);

    int g = 0;
    for(int i=0; i< 256; i++){
        printf("%d) %d\n", g, ascii[i]);
        g++;
    }
    writeCount(argv[4], ascii);    

    //write_topology(argv[5], )

    //FREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    //argv[1] & argv[2]
    free(all_topology);
    free(val);
    free(toVal);
    free(node);
    
    //argv[3]
    free(toVal2);
    free(all_encode);

    //general
    fclose(fptr);
    Destroy_tree(treeRoot);


    return EXIT_SUCCESS;
}



// void encode_to_bit(char* filename, char** decode_buffer){
    
//     FILE* fptr = fopen(filename, "rb");

//     long int size_compressed; //size_compressed: Number of bytes in compressed file
//     long int size_topology;   //size_topology: Number of bytes topology uses
//     long int size_original;   //size_original: Number of bytes in the uncompressed file
    
//     fread(&size_compressed, sizeof(long int) , 1, fptr);
//     fread(&size_topology, sizeof(long int), 1, fptr);
//     fread(&size_original, sizeof(long int), 1, fptr);

//     unsigned char *buffer;
//     buffer = (unsigned char*) malloc(sizeof(unsigned char) * size_topology);
//     size_t bytes_read = fread(buffer, sizeof(unsigned char), size_topology, fptr);
//     size_t bytes_read2 = fread(&decode_buffer, sizeof(unsigned char), 100, fptr);
//     size_t decode_size = sizeof(decode_buffer) / sizeof(decode_buffer[0]); 
//     int *val;
//     val = (int*) malloc(bytes_read2);



//     printf("Size Compressed: %ld\n", size_compressed);
//     printf("Size Topology: %ld\n", size_topology);
//     printf("Size Original: %ld\n", size_original);
//     printf("Bytes Read: %ld\n", bytes_read);
//     printf("Bytes Read2: %ld\n", bytes_read2);
//     //printf("decode size: %d\n", decode_size);
//     for(int k=0; k< 8;k++){
//         printf("%d\n", decode_buffer);
//     }

//     free(buffer);
//     free(val);
//     fclose(fptr);
// }