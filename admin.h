#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using namespace std;
class admin{
private:
  int adId;
  string adName;
  string adPassword;

public:
  admin();
  admin(int inId, string inName, string inPass);
  ~admin();

  void setId(int inId);
  void setName(string inName);
  void setPassword(string inPass);

  int getId();
  string getName();
  string getPassword();

  bool isAdmin();

};
#endif