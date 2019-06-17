#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;
class book{
    private:
        int bId;
        string bName;
        string bAuthor;

    public:
        book(){};
        book(int id,string name,string author);
        ~book();
        void setId(int id);
        void setName(string name);
        void setAuthor(string author);
        int getId();
        string getName();
        string getAuthor();
};
#endif