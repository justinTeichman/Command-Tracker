/*
Author: Justin Teichman
Description: Command class describes command objects and there methods.
Command objects are used to execute commands and record information (state and result) about those commands.
These command objects will later be stored in vector for organization.
October 4th, 2021
*/

#include "command.h"    //header file
using namespace std;
namespace bp = boost::process;

/*
Function Name: Command
Description: Constructor sets the command and initializes the result and state of the command
Parameter: String command to be executed later
Return:Does not return anything
*/
Command::Command(string cmd){
    
    cmd_txt = cmd;
    result = "";
    state = 0;
    
}

/*
Function Name: ~Command
Description: Deconstructor
Parameter: Does not have any parameters
Return:Does not return anything
*/
Command::~Command(){}

/*
Function Name: ~Command
Description: Deconstructor
Parameter: Does not have any parameters
Return:Does not return anything
*/
string Command::getCmd(){
    return cmd_txt;
}

/*
Function Name: getResult()
Description: getter method for result
Parameter: Does not have any parameters
Return: String of command result
*/
string Command::getResult(){
    return result;
}

/*
Function Name: getState()
Description: getter method for state
Parameter: Does not have any parameters
Return: Integer (0 for completetion and -1 for error)
*/
int Command::getState(){
    return state;
}

/*
Function Name: setCmd()
Description: setter method for command
Parameter: String of command to be executed next 
Return: Does not return anything
*/
void Command::setCmd(string txt_val){
    cmd_txt = txt_val;
}

/*
Function Name: execute()
Description: c++ stream processing executes and captures command. This also updates attributes of
the command object.
Parameter: String of command to be executed next 
Return: Does not return anything
*/
void Command::execute(){    

    try{

        bp::ipstream pipe_stream;
        bp::child c(getCmd(), (bp::std_out & bp::std_err) > pipe_stream);   // sets up stream for process
        string line;

        while(pipe_stream && getline(pipe_stream,line) && !line.empty()){   // filter throught stream until everything is captured
            result = result + line + "\n";                                  // records command output
        }


        c.wait();

        state = 0;

    }catch(bp::process_error &e){   // captures errors that is thrown at the pipe_stream

        result = "COMMAND DOES NOT EXIST\n";
        state = -1;

    }

}

