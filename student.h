#include "book.h"
using namespace std;
class student
{
private:
    string name;
    int id;
    book currBook;
public:
    student();
    ~student();
    void setId(int id);
    void setName(string name);
    void setBook(book inBook);

    string getName();
    int getId();
    book getBook();
};

