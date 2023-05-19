#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// Function to free the memory allocated for the arguments
void free_arguments(char* arguments[]) {
    int i = 0;
    while (arguments[i] != NULL) {
        free(arguments[i]);
        i++;
    }
}



// Function to count the number of arguments
int count_arguments(char* arguments[]) {
    int count = 0;
    while (arguments[count] != NULL) {
        count++;
    }
    return count;
}
