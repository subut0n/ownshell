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
    signal(SIGINT, handle_sig_int);

    while (1) {
        command = readline("ownshell $ ");
        if (command == NULL) {
            break;
        }

        parse_command(command, arguments);

        if (arguments[0] != NULL) {
            handle_command(arguments[0], arguments);
        }

        free(command);
    }

    return 0;
}
