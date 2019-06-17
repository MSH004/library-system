#include "book.h"
#include <string>
using namespace std;


book::book(int id, string name, string author){
    setId(id);
    setName(name);
    setAuthor(author);
}
book::~book(){}

void book::setId(int id){
    bId=id;
}
void book::setName(string name){
    bName=name;
}
void book::setAuthor(string author){
    bAuthor=author;
}
int book::getId(){
    int rId=bId;
    return rId;
}
string book::getName(){
    string rName=bName;
    return rName;
}
string book::getAuthor(){
    string rAuthor=bAuthor;
    return rAuthor;
}
