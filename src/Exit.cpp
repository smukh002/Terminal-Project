#include "Cmd.h"
#include "Exit.h"

string Exit::getCommand()
{
   return "Exit";
}

Exit::Exit(){}

bool Exit::execute() {
    exit(0);
}

