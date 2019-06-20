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

int main(){
    int accType;
    userCredits userDetails;
    accType=introList();
    userDetails=logIn(accType);
    bool verifiedUser=verifyUser(userDetails);
    if(verifiedUser){
        cout<<"Welcome to the library system"<<endl;
    }else{
        cout<<"wrong username or password"<<endl;
    }
    return 0;
}
int introList(){
    int accType=0;
    system("cls");
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
        //  cout<<"user name: "<<userDetails.name<<"\npassword: "<<userDetails.password<<"\ntype: "<<userDetails.type<<endl;
        if(fuserPassWord==userDetails.password && ftypeInt==userDetails.type){
            return true;
        }
        }
    }
  }
  return false;
}