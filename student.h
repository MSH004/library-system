#ifndef STUDENT_H
#define STUDENT_H

#include "book.h"
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>

using namespace std;
class student
{
private:
    string sName;
    string sUserName;
    string sPassword;
    book currBook;
    bool hasBook;

public:
    student();
    student( string inName,string inUserName, string inPassword);
    ~student();
    void setName(string name);
    void setUserName(string username);
    void setPassword(string password);

    string getName();
    string getUserName();
    string getPassword();
    book getBook();
    bool isAdmin();
    void borrowBook();
    void addBook(book newBook);
    void depositBook(int input=0);
    string toString();
};
#endif