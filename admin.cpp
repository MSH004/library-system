#include "admin.h"

admin::admin(){ }
admin::admin(string inName, string inUserName,string inPass){
    setName(inName);
    setUserName(inUserName);
    setPassword(inPass);
}
admin::~admin(){}

void admin::setName(string inName){
    adName=inName;
}
void admin::setPassword(string inPass){
    adPassword=inPass;
}
void admin::setUserName(string inUserName){
    adUserName=inUserName;
}

string admin::getName(){
    return adName;
}
string admin::getPassword(){
    return  adPassword;
}
string admin::getUserName(){
    return adUserName;
}

bool admin::isAdmin(){
    return true;
}
string admin::toString(){
    string output;
    output="name:"+admin::getName()+"\nusername:"+admin::getUserName()+"\npassword:"+admin::getPassword();
    output+="\naccountType:admin";
    return output;

} 