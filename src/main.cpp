#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

#include "Base.h"
#include "CmdBase.h"
#include "Cmd.h"
#include "CmdTest.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semi.h"
#include "Exit.h"
#include "make_Tree.cpp"
//#include "In.cpp"
//#include "Out.cpp"
//#include "OutTwo.cpp"

using namespace std;

int main(/*int argc, char**argv*/) {

   string command_prompt = "$ ";
   string exit_command = "exit";
   string userInput = "";
   Base *root = nullptr;

   cout << command_prompt;
   getline(cin, userInput);

   while (userInput != exit_command){  
      if(userInput != "")
      {
         root = make_Tree(userInput);
      }

      if(root != nullptr)
      {
         root->execute();
      }
      root = nullptr;
      cout << endl;
      cout << command_prompt;
      getline(cin, userInput);
   }
                

   if(userInput == exit_command) {
      Exit *exitcall = new Exit();
      exitcall->execute();
      cout << "exitting rshell ... " << endl;
   }

   return 0;
}

