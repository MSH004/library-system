#include "admin.h"

admin::admin(){ }
admin::admin(int inId, string inName, string inPass){
    setId(inId);
    setName(inName);
    setPassword(inPass);
}
admin::~admin(){}

void admin::setId(int inId){
    adId=inId;
}
void admin::setName(string inName){
    adName=inName;
}
void admin::setPassword(string inPass){
    adPassword=inPass;
}

int admin::getId(){
    return  adId;
}
string admin::getName(){
    return adName;
}
string admin::getPassword(){
    return  adPassword;
}

bool admin::isAdmin(){
    return true;
}