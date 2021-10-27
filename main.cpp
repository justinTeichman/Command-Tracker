/*
Author: Justin Teichman
Description: Contains main method which initiates program
October 4th, 2021
*/

#include "command.h"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[]){

  QApplication app(argc, argv); 
  MainWindow mainWindow;  // initiate GUI
  mainWindow.setFixedSize(QSize(450, 600)); // set size for UI
  mainWindow.show();
  return app.exec();  // app runs forever or until user exits

  

}
