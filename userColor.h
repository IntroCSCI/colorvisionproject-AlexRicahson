#ifndef USERCOLOR_H
#define USERCOLOR_H
#include <string>
#include <vector>

using std::string;
using std::vector;


class userColor{

  private:
  int r_value;
  int g_value;
  int b_value;
  string delimiter;

  
  public:
  void getUserColor();
  void getValidColor(int &);
  string toString();
  userColor();
  //int getModifiedColor(int);
  int getRValue();
  int getGValue();
  int getBValue();

  
};
#endif