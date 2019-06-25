#include "student.h"
#include "book.h"
#include "iostream"
using namespace std;

student::student(int inId, string inName,string inUserName, string inPassword)
{
  setId(inId);
  setName(inName);
  setUserName(inUserName);
  setPassword(inPassword);
}

student::~student(){}
void student::setId(int inId){
  sId=inId;
}
void student::setName(string inName){
  sName=inName;
}
void student::setUserName(string inUserName){
  sUserName=inUserName;
}
void student::setPassword(string inPassword){
  sPassword=inPassword;
}

int student::getId(){
  return sId;
}

string student::getName(){
  return sName;
}
string student::getUserName(){
  return sUserName;
}
string student::getPassword(){
  return sPassword;
}

book student::getBook(){
  return currBook;
}
bool student::isAdmin(){
  return false;
}
void student::borrowBook(book inBook){
  if(hasBook){
    cout<<"Sorry!! you already borrowed a book. To borrow a new book you need to deposit the previous one first"<<endl;
    return;
  }else{
  currBook=inBook;
  hasBook=true;
  }   
}
void student::depositBook(){
  char choice;
  cout<<"The book you have now is: "<<currBook.getName()<<endl;
  cout<<"Deposit the book(y/n): ";
  while(true){
    cin>>choice;
    if(choice=='y'||choice=='Y'){
      hasBook=false;
      break;
    }else if(choice=='n'|| choice=='N'){
      break;
    }else{
      cout<<"Please Enter 'y' for yes or 'n' for No : ";
    }
  }
}
