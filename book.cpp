#include "book.h"
#include <string>
using namespace std;

book::book(){}

book::book(string id, string name, string author)
{
    setId(id);
    setName(name);
    setAuthor(author);
}
book::~book() {}

void book::setId(string id)
{
    bId = id;
}
void book::setName(string name)
{
    bName = name;
}
void book::setAuthor(string author)
{
    bAuthor = author;
}
string book::getId()
{
    string rId = bId;
    return rId;
}
string book::getName()
{
    string rName = bName;
    return rName;
}
string book::getAuthor()
{
    string rAuthor = bAuthor;
    return rAuthor;
}
string book::toString()
{
    string output;
    output = "bookId:" + book::getId();
    output += "\nbookTitle:" + book::getName();
    output += "\nbookAuthor:" + book::getAuthor();

    return output;
}