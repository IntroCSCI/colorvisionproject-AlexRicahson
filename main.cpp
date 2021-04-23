//Author: Alex Richason
//Theme Completer   
//CSS file type
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void getValidColor( int & );
int getModifiedColor(int);

int main(){
vector <string> colorValues;
ofstream userFile;
string file, color;
string delimiter = ",";
int r_value, g_value, b_value;


//Ask for user input
cout << "Enter a file name: ";
cin >> file;
cout << "Enter RGB values individually." << endl << "Enter R value: ";
cin >> r_value;
getValidColor(r_value);

cout << "Enter G value: ";
cin >> g_value;
getValidColor(g_value);

cout << "Enter B value: ";
cin >> b_value;
getValidColor(b_value);

color = std::to_string(r_value) + delimiter + std::to_string(g_value) + delimiter + std::to_string(b_value);

//create and write to users file
userFile.open(file, ios::out);
colorValues.push_back(color);

for(int i = 0; i < 5; i++){
  int r_new = r_value;
  int b_new = b_value;
  int g_new = g_value;
  if (i == 0) {
     r_new = getModifiedColor(r_value);
  } else if (i == 1) {
     g_new = getModifiedColor(g_value);
  } else if (i == 2) {
     b_new = getModifiedColor(b_value);
  } else if (i == 3) {
     r_new = getModifiedColor(g_value);
     b_new = getModifiedColor(r_value);
  } else {
     r_new = getModifiedColor(b_value);
     g_new = getModifiedColor(b_value);
  }
  
  string newColor = std::to_string(r_new) + delimiter + std::to_string(g_new) + delimiter + std::to_string(b_new);

  colorValues.push_back(newColor);
}

/*
for(int i = 0; i < 5; i++){
  int r_new = rand() % 255 + 0;
  if (r_new == r_value){
    r_new = rand() % 255+0;
  }
  int g_new = rand() % 255 + 0;
  if (g_new == g_value){
    g_new = rand() % 255+0;
  }
  int b_new = rand() % 255 + 0;
  if (b_new == b_value){
    b_new = rand() % 255+0;
  }
  string newColor = std::to_string(r_new) + delimiter + std::to_string(g_new) + delimiter + std::to_string(b_new);

  userFile << "New Color_" << std::to_string(i+1) << ": " << newColor << endl;
  colorValues.push_back(newColor);
} 
*/

// print to file
for(int i=0; i < colorValues.size(); i++){
  if(i < 1){
    userFile << "{background-color:rgb(" <<colorValues[i]<< ");}" << " /** user color **/ " <<endl;
  } else {
    userFile << "{background-color:rgb(" << colorValues[i]<<");}" << endl;
  }
}
  return 0;
}

void getValidColor( int & color ){
  while (color < 0 || color > 255){
     cout << "Invalid, Try Again: ";
     cin >> color;
  } 
}

// if input color < 128, add 100 else subtract 100
int getModifiedColor(int color ) {

   int color_new = color;
   if(color < 128){
       color_new = color + 100;
   } else{
       color_new = color - 100;
   }
   return color_new;
}