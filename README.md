# Project for creating a Linux terminal using C++ programming language

Authors/Coders: Saurjya Mukhopadhyay & Gustavo Gonzalez 

## Introduction

In this project, we will be developing a basic command shell. Some features that this command shell should have are the ability to send out a command prompt and the ability to read a line of input from the user. The shell will use the input from the user and execute certain commands using waitpid, fork, and execvp. In addition, the command shell should also be able to run multiple commands simultaneously. We designed code that will determine what commands to carry out based on the appearance of specific character symbols (||, &&, ;, [ ], ( ), <, >, >>, or |) in the user input. Run with make, then ./rshell.
)


## Classes
### Cmd
 - Cmd() is a constructor
 - ~Cmd() is a destructor
 - Cmd(const string &full_command) is also a constructor
 - virtual bool execute() will carry out actions involving getting the user input or exitting out the terminal

### Class: Exit
 - Exit() is a constructor
 - ~Exit() is a destructor
 - bool execute() will carry out the proper commands to allow the user to exit out of the command shell 

### Base Class: Composite Function/ Connector 
 - Connector() is a constructor
 - ~Connector() is a destructor
 - Connector (Base* left, Base* right) is also a constrcutor
 - bool execute() = 0 (pure virtual function)


### Class: And (should have this class for Or & Semi also)
 - And() is a constructor
 - ~And() is a destructor
 - And(Base* left, Base* right) is also a constructor
 - bool execute() will carry out actions if the symbol && is detected




## Prototypes/Research:

Execvp() is a function that passes in the name of the files that should be used.

Waitpid() is a function that delays the parent program.

Fork() is a function that clones new child processes.

Small prototype code using waitpid(), execvp(), and fork():

``` 
int run ( int argc, char * argv[]){
  char* argv[MAX_ARGS];
  pid child_pid;
  int child_status;
  child_pid = fork();
  if(child_pid == 0) {
    execvp(argv[0], argv);
    exit(0);
  }
  else {
     do {
       pid  tpid = waitpid(&child_status); } while(tpid != child_pid);
     return child_status;
  }
}
```

This code will execute certain commands and return the termination status of the commands. As a team, my partner and I have to parse everything in the command strings and then run it through the code. Depending on whether or not those executed correctly, the next command will be executed. 
e
