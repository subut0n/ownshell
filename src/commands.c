#include "commands.h"
#include "parser.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

// Command: ls
// List files and directories in the current directory
int ls_command(char* arguments[]) {
    DIR* dir;
    struct dirent* entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("ls");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}

// Command: pwd
// Print the current working directory
int pwd_command(char* arguments[]) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("pwd");
        return 1;
    }
    return 0;
}

// Command: cd
// Change the current working directory
int cd_command(char* arguments[]) {
    if (arguments[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
        return 1;
    } else if (chdir(arguments[1]) != 0) {
        fprintf(stderr, "cd: failed to change directory\n");
        return 1;
    }
    return 0;
}

// Command: exit
// Exit the minishell
int exit_command(char* arguments[]) {
    exit(0);
}

// Command: export
// Set an environment variable
int export_command(char* arguments[]) {
    if (arguments[1] != NULL) {
        char* var = strtok(arguments[1], "=");
        char* value = strtok(NULL, "=");
        if (var != NULL && value != NULL) {
            setenv(var, value, 1);
        } else {
            fprintf(stderr, "export: invalid syntax\n");
            return 1;
        }
    }
    return 0;
}


// Command: echo
// Print the value of an environment variable
int echo_command(char* arguments[]) {
    if (arguments[1] != NULL) {
        char* value = getenv(arguments[1]);
        if (value != NULL) {
            printf("%s\n", value);
        }
    }
    return 0;
}

int handle_command(char* name, char* arguments[]) {
    char* args[MAX_ARGUMENTS];
    int i = 0;

    while (arguments[i] != NULL && i < MAX_ARGUMENTS - 1) {
        args[i] = strdup(arguments[i]);
        i++;
    }
    args[i] = NULL;

    int result = 0;
    if (strcmp(name, "cd") == 0) {
        result = cd_command(args);
    } else if (strcmp(name, "exit") == 0) {
        result = exit_command(args);
    } else if (strcmp(name, "export") == 0) {
        result = export_command(args);
    } else if (strcmp(name, "echo") == 0) {
        result = echo_command(args);
    } else if (strcmp(name, "ls") == 0) {
        result = ls_command(args);
    } else if (strcmp(name, "pwd") == 0) {
        result = pwd_command(args);
    } else {
        printf("Command not found: %s\n", name);
        result = 1;
    }

    free_arguments(args);
    return result;
}


