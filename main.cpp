#include "iostream"
#include "student.h"
#include "book.h"
#include "admin.h"
#include <fstream>
using namespace std;
struct userCredits{
    string name;
    string password;
    int type;
};
void introList();
void logIn(int accType);
bool verifyUser(string userName, string passWord, int type);

int main(){
    introList();
    return 0;
}
void introList(){
    int accType=0;
    system("cls");
    cout<<"=============================="<<endl;
    cout<<"Welcome to Library System"<<endl;
    cout<<"Choose your account type: "<<endl;
    cout<<"[1] admin\n[2] student"<<endl;
    cout<<"=============================="<<endl;
    cin>>accType;
    if(accType!=0){
        logIn(accType);
    }
}

void logIn(int accType){
    string userName;
    string userPassword;

    cout<<"Enter username: ";
    cin>>userName;

    cout<<"Enter password: ";
    cin>>userPassword;
    verifyUser(userName, userPassword, accType);



}

bool verifyUser(string userName, string passWord, int type){
    ifstream inputFile("userCredit.txt",ios::in);
    string line;
    int pos;
    string fuserName;
    string fuserPassWord;
    string ftype;
    
    if (inputFile.is_open())
  {
    while ( getline (inputFile,line) )
    {
        fuserName=line.substr(0,10);
        pos=line.find(" ");
        fuserPassWord=line.substr(pos,10);
        pos=pos+11;
        ftype=line.substr(pos);

        cout<<"username: "<<fuserName<<"\nuser password: "<<fuserPassWord<<"\ntype: "<<ftype<<endl;

        

    }
  }
  return true;
}