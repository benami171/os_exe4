//
// Created by benam on 27/11/2024.
//
/*
 * File: hello.c
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *string = NULL, *string_so_far = NULL;
    int i, length;     length = 0;
    for(i=0; i<argc; i++) {
        length += strlen(argv[i])+1;
        
        char *temp = malloc(length+1);

        if (temp == NULL) {
            free(string_so_far);
            return 1;
        }

        /*  * Copy the string built so far. */
        if(string_so_far != NULL) {
            strcpy(temp, string_so_far);
            free(string_so_far);  // Free previous allocation
        } else {
            *temp = '\0';
        }
        
        strcat(temp, argv[i]);
        if(i < argc-1) strcat(temp, " ");
        string_so_far = temp;
    }
    
    printf("You entered: %s\n", string_so_far);
    free(string_so_far);  // Free final string before exit
    return 0;

}