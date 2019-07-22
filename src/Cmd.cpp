#include "Cmd.h"

Cmd:: Cmd() {}


Cmd:: Cmd(const string &userInput) : CmdBase(userInput) {}


string Cmd ::getCommand()
{
   return *command;
}


bool Cmd::execute() 
{
   if(command != nullptr)
   {
      queue <char*> clflags;
      string *stringPtr = nullptr;

      for(int i = 0; i < arguments.size(); ++i)
      {
         stringPtr = CmdBase::arguments.front();

         clflags.push(const_cast<char*>(stringPtr->c_str())); //since string::c_str() returns a const char* and clflags holds char*, the value returned by string::c_str() had to be const_cast.

         arguments.pop();
         arguments.push(stringPtr);
         stringPtr = nullptr;
      }

      clflags.push(NULL);

      int count = 0;
      char *args[500];
      bool var = true;
      count = count + 1;

      while(clflags.size() > 0 /*|| clflags.size() < 0*/) {
         args[count] = clflags.front();
         clflags.pop();
         count = count + 1;
      }

      char *cmd = const_cast<char*>(CmdBase::command->c_str()); //command is a member variable of CmdBase, and Cmd iherits from CmdBase
      args[0] = cmd; 

      //fork
      pid_t pid = fork();                         
      if(pid == -1 || pid < 0) {                             
         perror("fork failed");                         
      }

      //execvp
      else if (pid == 0) {                        
         if(execvp(args[0], args) == -1) {       
            var = false;
            perror("execvp failed");
            exit(1);
         }
      }

      //waitpid
      else if(pid > 0) {
         int status;
         if(waitpid(pid,&status,0) == -1) { 
            perror("wait ");
         }
         if(WEXITSTATUS(status) != 0) { 
            var = false;
         }
      }

      return var;
   }
   else
   {
      perror("calling execute when command is on nullptr");
      return false;
   }
}

