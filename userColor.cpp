#include "userColor.h"
#include "iostream"
#include <string>
#include <vector>


using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;


userColor::userColor(void){
  delimiter = ",";
}

void userColor::getUserColor(){
  cout << "Enter RGB values individually." << endl << "Enter R value: ";
  cin >> r_value;
  getValidColor(r_value);

  cout << "Enter G value: ";
  cin >> g_value;
  getValidColor(g_value);

  cout << "Enter B value: ";
  cin >> b_value;
  getValidColor(b_value);
}


void userColor::getValidColor(int & color){
  while (color < 0 || color > 255){
     cout << "Invalid, Try Again: ";
     cin >> color;
  } 
}

string userColor::toString(){
   return std::to_string(r_value) + delimiter + std::to_string(g_value) + delimiter + std::to_string(b_value);
}

int userColor::getRValue(){
  return r_value;
}


int userColor::getGValue(){
  return r_value;
}

int userColor::getBValue(){
  return r_value;
}