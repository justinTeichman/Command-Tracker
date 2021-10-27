/*
Author: Justin Teichman
Description: Mainwindow header file. Contains class attributes and functions and c++ libraries
October 4th, 2021
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>  // provides a framework for building an application's user interface
#include <QPushButton>  // push button
#include <QLineEdit>    // line edit box for input
#include <QApplication> // provides functionality for QWidget application
#include <QLabel>       // text label
#include <QTextEdit>    // text box for input and output
#include <QListWidget>  // list box of text
#include <QString>      // string objects for Q objects
#include <vector>
#include "command.h"

 
class MainWindow : public QMainWindow{
  Q_OBJECT

public:
  
  explicit MainWindow(QWidget *parent = nullptr);

private slots:
  
  void usr_cmd();
  void write(QListWidgetItem *line);

private:
  
  QLineEdit *q_line_;
  QLabel *q_label_;
  QLabel *q_label_1;
  QLabel *q_label_2;
  QLabel *q_label_3;
  QLabel *q_line_4;
  QTextEdit *q_text_;
  QListWidget *q_list;
  std::vector<Command> list; // vector contains all command objects
  int list_count; // history list count
};



#endif 