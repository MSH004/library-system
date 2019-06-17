#include "student.h"
#include "book.h"
using namespace std;

student::student(int inId,string inName, book inBook)
{
  setId(inId);
  setName(inName);
  setBook(inBook);
}

student::~student(){}
void student::setId(int inId){
  sId=inId;
}
void student::setName(string inName){
  sName=inName;
}
void student::setBook(book inBook){
  currBook=inBook;
}

int student::getId(){
  return sId;
}

string student::getName(){
  return sName;
}

book student::getBook(){
  return currBook;
}
bool student::isAdmin(){
  return false;
}
