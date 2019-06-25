#include "iostream"
#include "student.h"
#include "book.h"
#include "admin.h"
#include <fstream>
#include <string>
using namespace std;
struct userCredits{
    string name;
    string password;
    int type;
};
int introList();
userCredits logIn(int accType);
bool verifyUser(userCredits userDetails);
void studentView(userCredits userInfo);
void adminView(userCredits userInfo);
void addAdmin();
void addStudent();
void addBook();

int main(){
    int accType;
    userCredits userDetails;
    accType=introList();
    userDetails=logIn(accType);
    bool verifiedUser=verifyUser(userDetails);
    if(verifiedUser){
        if(accType==1)
            adminView(userDetails);
        else if(accType==2)
            studentView(userDetails);
    }else{
        cout<<"wrong username or password"<<endl;
    }
    return 0;
}
int introList(){
    int accType=0;
    system("clear");
    cout<<"=============================="<<endl;
    cout<<"Welcome to Library System"<<endl;
    cout<<"Choose your account type: "<<endl;
    cout<<"[1] admin\n[2] student"<<endl;
    cout<<"=============================="<<endl;
    cin>>accType;
    if(accType!=0){
        return accType;
    }
}

userCredits logIn(int accType){
    userCredits userDetails;
    while(true){
    cout<<"Enter username: ";
    cin>>userDetails.name;
    if(userDetails.name.length()==10)
        break;
    else
        cout<<"unacceptable length of username\nPlease re-enter your username"<<endl;
    }

    while(true){
    cout<<"Enter password: ";
    cin>>userDetails.password;
    if(userDetails.password.length()==10)
        break;
    else
        cout<<"unacceptable length of password\nPlease re-enter your password"<<endl;
    }
    userDetails.type=accType;
    
    return userDetails;
}

bool verifyUser(userCredits userDetails){
    ifstream inputFile("userCredit.txt",ios::in);
    string line;
    int pos;
    string fuserName;
    string fuserPassWord;
    string ftype;
    int ftypeInt;
    
    if (inputFile.is_open())
  {
    while ( getline (inputFile,line) )
    {
        fuserName=line.substr(0,10);
        if(fuserName==userDetails.name){
        pos=line.find(" ");
        fuserPassWord=line.substr(pos+1,10);
        pos=pos+11;
        ftype=line.substr(pos);
        ftypeInt=stoi(ftype);
        // cout<<"user name: "<<fuserName<<"\npassword: "<<fuserPassWord<<"\n" <<fuserName.length()<<"\n"<<fuserPassWord.length()<<"\ntype: "<<ftype<<endl;
        // cout<<"user name: "<<userDetails.name<<"\npassword: "<<userDetails.password<<"\ntype: "<<userDetails.type<<endl;
        if(fuserPassWord==userDetails.password && ftypeInt==userDetails.type){
            return true;
        }
        }
    }
  }
  return false;
}
void studentView(userCredits userInfo){
    int userInput;
    system("clear");
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
void adminView(userCredits userInfo){
    int choice;
    system("clear");
    cout<<"Choose an action: "<<endl;
    cout<<"[1] add a new admin\n[2] add a new student\n[3] add a new book"<<endl;
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
    }
    

}
void addAdmin(){
    string name;
    string username;
    string password;

    cout<<"Enter admin name: ";
    cin>>name;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    admin* newAdmin=new admin(name,username,password);   

    // cout<<newAdmin.toString()<<endl;
    // ofstream outputFile("adminCredit.txt",ios::out);
    // outputFile<<"{\n"+newAdmin.toString()+"\n}\n";
}
void addStudent(){

}
void addBook(){

}