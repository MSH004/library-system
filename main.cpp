#include <iostream>
#include "student.h"
#include "book.h"
#include "admin.h"
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
struct userCredits{
    string name;
    string password;
    string type;
};

userCredits logIn();
bool verifyUser(userCredits userDetails);
void studentView();
void adminView();
void addAdmin();
void addStudent();
void addBook();
admin adminData;
student studentData;

int main(){
    userCredits userDetails;
    while(true){
        userDetails=logIn();
        bool verifiedUser=verifyUser(userDetails);
        if(verifiedUser){

            if(userDetails.type=="a"){
                adminView();
            }else if(userDetails.type=="s")
                studentView();
        }else{
            cout<<"wrong username or password"<<endl;
            
        }
    }
    
    return 0;
}


userCredits logIn(){
    userCredits userDetails;
    int input=0;
    string accType;
    system("clear");
    cout<<"=============================="<<endl;
    cout<<"Welcome to Library System"<<endl;
    cout<<"Choose your account type: "<<endl;
    cout<<"[1] admin\n[2] student"<<endl;
    cout<<"=============================="<<endl;
    cin>>input;
    if(input==1){
        accType= "a";
    } else if(input==2){
        accType= "s";
    }
    cout<<"Enter username: ";
    cin>>userDetails.name;

    cout<<"Enter password: ";
    cin>>userDetails.password;

    userDetails.type=accType;
    
    return userDetails;
}

bool verifyUser(userCredits userDetails){
    int listSize=100;
    string line;
    int pos;
    
    if(userDetails.type=="a"){
        ifstream adminFile;
        string type;
        adminFile.open("logFiles/"+userDetails.name+".txt",ios::in);
        if (adminFile.is_open()){
            admin adminLog;
            while ( !adminFile.eof() ){
                getline (adminFile,line);
                pos=line.find(":");
                if(line.substr(0,pos).compare("accountType")==0){
                    type=line.substr(pos+1);
                }
                if(type.compare("admin")==0){

                    getline (adminFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("name")==0){
                        line=line.substr(pos+1);
                        adminLog.setName(line);
                    }
                    getline (adminFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("username")==0){
                        line=line.substr(pos+1);
                        adminLog.setUserName(line);
                    }
                    getline (adminFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("password")==0){
                        line=line.substr(pos+1);
                        adminLog.setPassword(line);
                    }
                    adminData=adminLog;
                
                    adminFile.close();
                
                    if(userDetails.name.compare(adminData.getUserName())==0){
                        if(userDetails.password.compare(adminData.getPassword())==0){
                            return true;
                        }
                        else{
                            cout<<"Sorry! Wrong password. "<<endl;
                            usleep(2000000);
                            return false;
                        }
                    }else{
                        cout<<"Sorry! User name does not exist."<<endl;
                        usleep(2000000);
                        return false;
                    }
            
                }else{
                    cout<<"username does not exist!!"<<endl;
                    usleep(2000000);
                    return false;
                }
            }
        }
        
    }else if(userDetails.type=="s"){
        ifstream studentFile;
        string type;
        studentFile.open("logFiles/"+userDetails.name+".txt",ios::in);
        if (studentFile.is_open()){
            student studentLog;
            while ( !studentFile.eof() ){
                getline (studentFile,line);
                pos=line.find(":");
                if(line.substr(0,pos).compare("accountType")==0){
                    type=line.substr(pos+1);
                }
                if(type.compare("student")==0){
                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("name")==0){
                        line=line.substr(pos+1);
                        studentLog.setName(line);
                    }
                                        
                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("username")==0){
                        line=line.substr(pos+1);
                        studentLog.setUserName(line);
                    }
                    
                    
                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("password")==0){
                        line=line.substr(pos+1);
                        studentLog.setPassword(line);
                    }
                    
                    getline (studentFile,line);
                    pos=line.find(":");
                    book newBook;
                    if(line.substr(0,pos).compare("bookId")==0){
                        line=line.substr(pos+1);
                        newBook.setId(line);
                    }                    

                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("bookTitle")==0){
                        line=line.substr(pos+1);
                        newBook.setName(line);
                    }                    

                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("bookAuthor")==0){
                        line=line.substr(pos+1);
                        newBook.setAuthor(line);
                        studentLog.addBook(newBook);
                    }
                    
                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("hasBook")==0){
                        line=line.substr(pos+1);
                        if(line.compare("false")==0){
                            studentLog.depositBook(1);
                        }
                    }
                
                studentData=studentLog;
                }
                studentFile.close();
            
                if(userDetails.name.compare(studentData.getUserName())==0){
                    if(userDetails.password.compare(studentData.getPassword())==0){
                        return true;
                    }
                    else{
                        cout<<"Sorry! Wrong password. "<<endl;
                        usleep(2000000);
                        return false;
                    }
                }else{
                    cout<<"Sorry! User name does not exist."<<endl;
                    usleep(2000000);
                    return false;
                }
            }           
        }else{
                cout<<"username does not exist!!"<<endl;
                usleep(2000000);
                return false;
            }
                
    }    
}
void studentView(){
    int userInput;
    
    while(true){
        system("clear");
        cout<<"Welcome, "<<studentData.getName()<<"! (student)"<<endl;
        cout<<"\n\n\nChoose one of the following actions:"<<endl;
        cout<<"[1] Borrow a book\n[2] Deposit a book\n[3] Logout"<<endl;
        cin>>userInput;
        if(userInput==1){
            studentData.borrowBook();
        }else if(userInput==2){
            //deposit a book
            studentData.depositBook();

        }else if(userInput==3){
            break;
        }
    }
    
    

}
void adminView(){
    int choice;
    system("clear");
    cout<<"Welcome, "<<adminData.getName()<<"! (admin)"<<endl;
    cout<<"Choose an action: "<<endl;
    cout<<"[1] add a new admin\n[2] add a new student\n[3] add a new book\n[4] logout"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            addAdmin();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            addBook();
            break;
        case 4:
            main();

    }
    

}
void addAdmin(){
    string input;
    admin newAdmin;
    cout<<"Enter admin name: ";
    cin.ignore(32767, '\n');
    getline(cin,input);
    newAdmin.setName(input);
    cout<<"Enter username: ";
    cin>>input;
    newAdmin.setUserName(input);
    cout<<"Enter password: ";
    cin>>input;
    newAdmin.setPassword(input);
    cout<<"Confirm? (y/n): ";
    cin>>input;
    if(input=="y" || input=="Y"){
        cout<<newAdmin.toString()<<endl;
        ofstream outputFile("logFiles/"+newAdmin.getUserName()+".txt",ios::out);
        outputFile<<newAdmin.toString();
        outputFile.close();

        ofstream userCreditFile("userCredits.txt",ios::app);
        userCreditFile<<newAdmin.getUserName()+":a\n";
        userCreditFile.close();
    }else
        cout<<"Input was discarded";
    
    usleep(1000000);
    adminView();
    
}
void addStudent(){
    string input;
    student newStudent;
    cout<<"Enter student name: ";
    cin.ignore(32767, '\n');
    getline(cin,input);
    newStudent.setName(input);

    cout<<"Enter username: ";
    cin>>input;
    newStudent.setUserName(input);

    cout<<"Enter password: ";
    cin>>input;
    newStudent.setPassword(input);
    cout<<"Confirm? (y/n): ";
    cin>>input;
     if(input=="y" || input=="Y"){
        string fileName(newStudent.getUserName());
        cout<<newStudent.toString()<<endl;
        ofstream outputFile("logFiles/"+fileName+".txt",ios::out);
        outputFile<<newStudent.toString();
        outputFile.close();

        ofstream userCreditFile("userCredits.txt",ios::app);
        userCreditFile<<newStudent.getUserName()+":s\n";
        userCreditFile.close();
     }else
        cout<<"Input was discarded";
   
    usleep(1000000);
    adminView();

}
void addBook(){

    string input;
    book newBook;
    cout << "Enter book Id: ";
    cin.ignore(32767, '\n');
    getline(cin, input);
    newBook.setId(input);

    cout << "Enter book title: ";
    getline(cin, input);
    newBook.setName(input);

    cout << "Enter book author: ";
    getline(cin, input);
    newBook.setAuthor(input);


    cout << "Confirm? (y/n): ";
    cin >> input;
    if (input == "y" || input == "Y")
    {
        string fileName(newBook.getId());
        cout << newBook.toString() << endl;
        ofstream outputFile("bookFiles/" + fileName + ".txt", ios::out);
        outputFile << newBook.toString();
        outputFile.close();

        ofstream booksListFile("bookFiles/booksList.txt", ios::app);
        booksListFile << newBook.getId()+"\n";
        booksListFile.close();
    }
    else
        cout << "Input was discarded";

    usleep(1000000);
    adminView();
}