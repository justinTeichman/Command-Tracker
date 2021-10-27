/*
Author: Justin Teichman
Description: Contains mainwindow class that constructs the GUI and provides a series of 
slots and signals and connector methods.
October 4th, 2021
*/

#include "mainwindow.h"
#include "command.h"
using namespace std;

/*
Function Name: MainWindow
Description: Constructor creates Q objects for GUI and connects our signals and slots
Parameter: String command to be executed later
Return:Does not return anything
*/
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){

  list_count = 0;
  
  q_line_ = new QLineEdit("",this);     // Command input line
  q_line_->setGeometry(QRect(QPoint(125,25),QSize(275,25)));

  q_label_ = new QLabel("Command: ", this); // Command label
  q_label_->setGeometry(QRect(QPoint(50,25),QSize(75,25)));

  q_label_1 = new QLabel("Output: ", this); // Output label
  q_label_1->setGeometry(QRect(QPoint(25,65),QSize(75,25)));
  
  q_label_2 = new QLabel("Exit status:", this); // Status label
  q_label_2->setGeometry(QRect(QPoint(25,300),QSize(100,25)));

  q_label_3 = new QLabel("History: ", this);  // History label
  q_label_3->setGeometry(QRect(QPoint(25,350),QSize(75,25)));

  q_line_4 = new QLabel("",this);       // Exit status output label   
  q_line_4->setGeometry(QRect(QPoint(125,300),QSize(25,25)));

  q_text_ = new QTextEdit("",this);     // Command result output text
  q_text_->setGeometry(QRect(QPoint(25,90),QSize(400,200)));
  q_text_->setReadOnly(true);

  q_list = new QListWidget(this);       // History list of Commands
  q_list->setGeometry(QRect(QPoint(25,375),QSize(400,200)));

  connect(q_line_, &QLineEdit::returnPressed,this, &MainWindow::usr_cmd); // connects the cmd input line to usr_cmd slot
  connect(q_list, &QListWidget::itemClicked, this, &MainWindow::write); // connects the history list to write slot

}
 
/*
Function Name: usr_cmd()
Description: Facilitates action after user inputs command
Parameter: No parameters
Return:Does not return anything
*/
void MainWindow::usr_cmd(){

  string s = q_line_->text().toStdString(); // saves input from text line
  
  if(s == "clear"){ // command clears screen

    q_line_->setText("");
    q_text_->setText("");

  }else if(s == ""){  // empty input case 
    
    q_line_->setText("");
    q_text_->append(QString::fromStdString("\n"));

  }else{

  Command cmd(s);
  string msg;
  list_count++;
  cmd.execute();  // calls command::execute class
  list.push_back(cmd);  //push command object on vector

  q_line_->setText(""); // clear line text box
  q_line_4->setText(QString::fromStdString(to_string(cmd.getState()))); // update state label
  q_text_->append(QString::fromStdString(cmd.getResult())); // add result to text box
  msg = to_string(list_count) + ". " + cmd.getCmd() + " (" + to_string(cmd.getState()) +")";  // construct string for history list
  q_list->insertItem(list_count,QString::fromStdString(msg)); // add command infor to history box

  }
  
}

/*
Function Name: write()
Description: Facilitates action after user selects history item
Parameter: No parameters
Return:Does not return anything
*/
void MainWindow::write(QListWidgetItem *line){
  
  int index = line->text().toStdString().at(0) - '0' - 1; // locates item in vector
  Command cmd = list.at(index); // gets command object from vector
  q_text_->append(QString::fromStdString(cmd.getResult())); // add command result to text box
  q_line_4->setText(QString::fromStdString(to_string(cmd.getState()))); // set Result label

}

