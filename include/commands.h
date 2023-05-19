#ifndef COMMANDS_H
#define COMMANDS_H

// Command: cd
// Change the current working directory
int cd_command(char* arguments[]);

// Command: exit
// Exit the minishell
int exit_command(char* arguments[]);

// Command: export
// Set an environment variable
int export_command(char* arguments[]);

// Command: echo
// Print the value of an environment variable
int echo_command(char* arguments[]);

// Function to handle commands
int handle_command(char* name, char* arguments[]);

#endif /* COMMANDS_H */
