#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include "parser.h"
#include "executor.h"
#include "utils.h"
#include "commands.h"
#include "signals.h"

int main() {
    char* command;
    char* arguments[MAX_ARGUMENTS];

    // Set up signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, handleSigInt);

    while (1) {
        command = readline("ownshell $ ");
        if (command == NULL) {
            break;
        }

        parseCommand(command, arguments);

        if (arguments[0] != NULL) {
            handleCommand(arguments[0], arguments);
        }

        free(command);
    }

    return 0;
}
