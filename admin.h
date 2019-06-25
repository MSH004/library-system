#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using namespace std;
class admin{
private:
  string adName;
  string adPassword;
  string adUserName;


public:
  admin();
  admin(string inName, string inUserName,string inPass);
  ~admin();

  void setName(string inName);
  void setPassword(string inPass);
  void setUserName(string inUserName);

  string getName();
  string getPassword();
  string getUserName();

  bool isAdmin();

  string toString();

};
#endif