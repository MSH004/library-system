#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;
class book{
    private:
        string bId;
        string bName;
        string bAuthor;

    public:
        book();
        book(string id,string name,string author);
        ~book();
        void setId(string id);
        void setName(string name);
        void setAuthor(string author);
        string getId();
        string getName();
        string getAuthor();
        string toString();
};
#endif