#include "student.h"
using namespace std;

student::student(){}

student::student( string inName,string inUserName, string inPassword)
{

  setName(inName);
  setUserName(inUserName);
  setPassword(inPassword);
  hasBook=false;
}

student::~student(){}

void student::setName(string inName){
  sName=inName;
}
void student::setUserName(string inUserName){
  sUserName=inUserName;
}
void student::setPassword(string inPassword){
  sPassword=inPassword;
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
void student::addBook(book inBook){
  currBook=inBook;

}
void student::borrowBook(){
  if(hasBook){
    cout<<"Sorry!! you already borrowed a book. To borrow a new book you need to deposit the previous one first"<<endl;
    usleep(2000000);
    return;
  }else{
    int lineCounter=0;
    string line;
    int input;
    char reply;
    
    //borrow a book
    ifstream booksListFile("bookFiles/booksList.txt",ios::in);
    while(!booksListFile.eof()){
        getline(booksListFile,line);
        lineCounter++;
    }
    booksListFile.close();
    book booksListArray[lineCounter];
    booksListFile.open("bookFiles/booksList.txt", ios::in);

    string bstring;
    int position;
    for (int counter = 0;counter<lineCounter;counter++)
    {
        getline(booksListFile, line);
        ifstream bookFile("bookFiles/"+line+".txt", ios::in);
        if(bookFile.is_open()){
            getline(bookFile,bstring);
            book newBook;
            position=bstring.find(":");
            bstring=bstring.substr(position+1);
            newBook.setId(bstring);

            getline(bookFile, bstring);
            position=bstring.find(":");
            bstring=bstring.substr(position+1);
            newBook.setName(bstring);

            getline(bookFile, bstring);
            position=bstring.find(":");
            bstring=bstring.substr(position+1);
            newBook.setAuthor(bstring);

            booksListArray[counter]=newBook;
        }
    }

    booksListFile.close();

    system("clear");
    cout<<"Choose one of the following books"<<endl;
    for(int i=0;i<lineCounter;i++){
        cout<<"["<<i+1<<"] "<<booksListArray[i].getName()<<endl;
    }
    cin>>input;
    cout<<"Borrow "<<booksListArray[input-1].getName()<<" (y/n) :";
    cin>>reply;
    if(reply=='y'|| reply=='Y'){
        currBook=booksListArray[input-1];
        cout<<"book has been added to your account"<<endl;
        usleep(2000000);
    }else if(reply=='n'|| reply=='N'){
        cout<<"action was cancelled"<<endl;
        usleep(2000000);
    }
    hasBook=true;
  }   
  ofstream outputFile("logFiles/"+student::getUserName()+".txt",ios::out);
  outputFile<<student::toString();
  outputFile.close();
}
void student::depositBook(int input){
  char choice;
  if(input==1){
    hasBook=false;
  }else{
    if(!hasBook){
      cout<<"Sorry you don't have a book to deposit"<<endl;
      usleep(2000000);
    }else{
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
      ofstream outputFile("logFiles/"+student::getUserName()+".txt",ios::out);
      outputFile<<student::toString();
      outputFile.close();
    }
    
  }
}

string student::toString(){
  string output;
  output="accountType:student";
  output+="\nname:"+student::getName();
  output+="\nusername:"+student::getUserName();
  output+="\npassword:"+student::getPassword();
  output+="\n"+student::getBook().toString();
  if(hasBook)
    output+="\nhasBook:true";
  else
    output+="\nhasBook:false";
  
  return output;
}