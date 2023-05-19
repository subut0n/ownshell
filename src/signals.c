#include "signals.h"
#include <stdio.h>
#include <signal.h>
#include <curses.h>

// Signal handler for SIGINT (Ctrl+C)
void handle_sig_int(int signum) {
    printf("\nownshell $ "); // Print the prompt on a new line
    fflush(stdout); // Flush the output buffer
}
