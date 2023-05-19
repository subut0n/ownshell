# ownshell

ownshell is a minimalist command-line interpreter developed in C. It provides basic features of an interactive shell, allowing users to execute system commands and navigate the file system.

## Features

- Execution of system commands: ownshell supports executing commands such as cd, ls, pwd, echo, and more.
- Basic command parsing: Commands entered by the user are parsed into individual arguments.
- Signal handling: ownshell handles the SIGINT signal (Ctrl+C) to provide a responsive and interruptible shell experience.

## Getting Started

### Prerequisites

- GCC: Make sure you have GCC (GNU Compiler Collection) installed.

### Building ownshell

1. Clone the repository:

git clone https://github.com/your-username/ownshell.git


2. Navigate to the project directory:

cd ownshell


3. Build the project using the provided Makefile:

make

### Running ownshell

Once the project is built, you can run ownshell by executing the following command:

./bin/ownshell


## Usage

ownshell provides a command prompt where you can enter commands. Supported commands include:

- cd: Change the current working directory.
- ls: List files and directories in the current directory.
- pwd: Print the current working directory.
- echo: Print the value of an environment variable.
- exit: Exit the shell.

To execute a command, simply enter it at the command prompt and press Enter.



