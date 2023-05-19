#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the command into arguments
void parseCommand(char* command, char* arguments[]) {
    char* token = strtok(command, " "); // Tokenize the command by spaces
    int i = 0;
    while (token != NULL && i < MAX_ARGUMENTS - 1) {
        arguments[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    arguments[i] = NULL; // Set the last element to NULL
}
