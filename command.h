/*
Author: Justin Teichman
Description: Command class header file.Contains class attributes and functions and c++ libraries
October 4th, 2021
*/

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <boost/process.hpp>    // library facilitates the capture of linux commands

class Command{

    private:
        std::string cmd_txt;
        std::string result;
        int state;



    public:
        Command(std::string cmd);
        ~Command();
        std::string getCmd();
        std::string getResult();
        int getState();
        void setCmd(std::string newCmd);
        void execute();

};

#endif
