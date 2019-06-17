#ifndef STUDENT_H
#define STUDENT_H

#include "book.h"
#include <string>
using namespace std;
class student
{
private:
    string sName;
    int sId;
    book currBook;
public:
    student(int inId, string inName,book inBook);
    ~student();
    void setId(int id);
    void setName(string name);
    void setBook(book inBook);

    string getName();
    int getId();
    book getBook();
    bool isAdmin();
};
#endif