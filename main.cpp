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
string introList();
userCredits logIn(string accType);
bool verifyUser(userCredits userDetails);
void studentView(userCredits userInfo);
void adminView();
void addAdmin();
void addStudent();
void addBook();
void loadLoginData();
admin adminData;
student studentData;

int main(){
    string accType;
    userCredits userDetails;
    while(true){
        accType=introList();
        userDetails=logIn(accType);
        bool verifiedUser=verifyUser(userDetails);
        cout<<verifiedUser<<"verification results"<<endl;
        if(verifiedUser){
            if(accType=="a")
                adminView();
            else if(accType=="s")
                studentView(userDetails);
        }else{
            cout<<"wrong username or password"<<endl;
            
        }
    }
    
    return 0;
}

string introList(){
    int accType=0;
    // system("clear");
    cout<<"=============================="<<endl;
    cout<<"Welcome to Library System"<<endl;
    cout<<"Choose your account type: "<<endl;
    cout<<"[1] admin\n[2] student"<<endl;
    cout<<"=============================="<<endl;
    cin>>accType;
    if(accType==1){
        return "a";
    } else if(accType==2){
        return "s";
    }
}

userCredits logIn(string accType){
    userCredits userDetails;
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
    cout<<userDetails.name<<endl;
    cout<<userDetails.password<<endl;
    cout<<userDetails.type<<endl;
    
    if(userDetails.type=="a"){
            ifstream adminFile;
            string type;
            adminFile.open("logFiles/"+userDetails.name+".txt",ios::in);
            if (adminFile.is_open()){
                admin adminLog;
                while ( !adminFile.eof() ){
                    getline (adminFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("name")==0){
                        line=line.substr(pos+1);
                        adminLog.setName(line);
                        cout<<line<<endl;
                        cout<<adminLog.getName()<<endl;
                    }
                    

                    getline (adminFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("username")==0){
                        line=line.substr(pos+1);
                        adminLog.setUserName(line);
                        cout<<line<<endl;
                        cout<<adminLog.getUserName()<<endl;
                    }
                    

                    getline (adminFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("password")==0){
                        line=line.substr(pos+1);
                        adminLog.setPassword(line);
                        cout<<line<<endl;
                        cout<<adminLog.getPassword()<<endl;
                    }

                    getline (adminFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("accountType")==0){
                        type=line.substr(pos+1);
                    }
                    

                    adminData=adminLog;
                    cout<<adminData.toString()<<endl<<endl;
                    cout<<adminLog.toString()<<endl;

                    
                    
             
                }
                cout<<"end of file"<<endl;
                adminFile.close();
                
                cout<<userDetails.name<<endl;
                cout<<adminData.getUserName()<<endl;
                cout<<adminData.getPassword()<<endl;
                bool result=userDetails.name.compare(adminData.getUserName());
                cout<<type<<endl;
                if(type.compare("admin")==0){
                    if(userDetails.name.compare(adminData.getUserName())==0){
                        cout<<"name passed"<<endl;
                        if(userDetails.password.compare(adminData.getPassword())==0){
                            cout<<"password passed"<<endl;
                            return true;
                        }
                        else{
                            cout<<"Sorry! Wrong password. "<<endl;
                            return false;
                        }
                    }else{
                        cout<<"Sorry! User name does not exist."<<endl;
                        return false;
                    }
                }
            }else{
                cout<<"username does not exist!!"<<endl;
                return false;
            }
            
            // for(int i=0;i<100;i++){
            //     cout<<adminData[i].toString()<<endl;
            // }
        }else if(userDetails.type=="s"){
            ifstream studentFile;
            string type;
            cout<<"in student"<<endl;
            studentFile.open("logFiles/"+userDetails.name+".txt",ios::in);
            if (studentFile.is_open()){
                student studentLog;
                while ( !studentFile.eof() ){
                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("name")==0){
                        line=line.substr(pos+1);
                        studentLog.setName(line);
                        cout<<line<<endl;
                    }
                                        
                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("username")==0){
                        line=line.substr(pos+1);
                        studentLog.setUserName(line);
                        cout<<line<<endl;
                    }
                    
                    
                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("password")==0){
                        line=line.substr(pos+1);
                        studentLog.setPassword(line);
                        cout<<line<<endl;
                    }
                    
                    getline (studentFile,line);
                    pos=line.find(":");
                    book newBook;
                    if(line.substr(0,pos).compare("bookId")==0){
                        line=line.substr(pos+1);
                        newBook.setId(line);
                        cout<<line<<endl;
                    }                    

                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("bookTitle")==0){
                        line=line.substr(pos+1);
                        newBook.setName(line);
                        cout<<line<<endl;
                    }                    

                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("bookAuthor")==0){
                        line=line.substr(pos+1);
                        newBook.setAuthor(line);
                        cout<<line<<endl;
                        studentLog.borrowBook(newBook);
                    }
                    
                    

                    getline (studentFile,line);
                    pos=line.find(":");
                    if(line.substr(0,pos).compare("accountType")==0){
                        type=line.substr(pos+1);
                        cout<<type<<"::importing"<<endl;
                        
                    }

                    getline (studentFile,line);
                    pos=line.find(":");
                    cout<<line.substr(0,pos)<<endl;
                    if(line.substr(0,pos).compare("hasBook")==0){
                        line=line.substr(pos+1);
                        cout<<line<<endl;
                        if(line.compare("false")==0){
                            studentLog.depositBook(1);
                        }
                        cout<<line<<endl;
                    }
                   
                    
                    studentData=studentLog;
                    cout<<studentData.toString()<<endl;
                    cout<<studentLog.toString()<<endl;
                    


                }
                studentFile.close();
                cout<<userDetails.name.length()<<endl;
                cout<<studentData.getUserName().length()<<endl;
                cout<<studentData.getPassword().length()<<endl;
                bool result=userDetails.name.compare(studentData.getUserName());
                cout<<result<<endl;
                cout<<type<<endl;
                if(type.compare("student")==0){
                    if(userDetails.name.compare(studentData.getUserName())==0){
                        cout<<"name passed"<<endl;
                        if(userDetails.password.compare(studentData.getPassword())==0){
                            cout<<"password passed"<<endl;
                            return true;
                        }
                        else{
                            cout<<"Sorry! Wrong password. "<<endl;
                            return false;
                        }
                    }else{
                        cout<<"Sorry! User name does not exist."<<endl;
                        return false;
                    }
                }
            }else{
                cout<<"username does not exist!!"<<endl;
                return false;
            }           
        }    
}
void studentView(userCredits userInfo){
    int userInput;
    // system("clear");
    cout<<"Welcom, "<<userInfo.name<<"! (student)"<<endl;
    cout<<"\n\n\nChoose one of the following actions:"<<endl;
    cout<<"[1] Borrow a book\n[2] Deposit a book"<<endl;
    cin>>userInput;
    if(userInput==1){
        //borrow a book
        system("clear");
        cout<<"Choose one of the following books"<<endl;

    }else if(userInput==2){
        //deposit a book
        cout<<"to be done"<<endl;


    }
    

}
void adminView(){
    int choice;
    // system("clear");
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
            introList();

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

}