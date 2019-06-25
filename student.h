#ifndef STUDENT_H
#define STUDENT_H

#include "book.h"
#include <string>
using namespace std;
class student
{
private:
    string sName;
    string sUserName;
    string sPassword;
    int sId;
    book currBook;
    bool hasBook;

public:
    student(int inId, string inName,string inUserName, string inPassword);
    ~student();
    void setId(int id);
    void setName(string name);
    void setUserName(string username);
    void setPassword(string password);

    string getName();
    string getUserName();
    string getPassword();
    int getId();
    book getBook();
    bool isAdmin();
    void borrowBook(book inBook);
    void depositBook();
};
#endif