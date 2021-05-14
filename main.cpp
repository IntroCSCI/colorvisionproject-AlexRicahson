//Author: Alex Richason
//Theme Completer   
//CSS file type
#include <iostream>
#include <fstream>
#include <vector>
#include "userColor.h"
#include "colorMod.h"

//move for loop to method

using namespace std;

void printColorValues();
vector <string> colorValues;
ofstream userFile; 

int main() {
  userColor uColor;
  colorMod cMod;
  string file;
  string delimiter = ",";
   
  cout << "Enter a file name: ";
  cin >> file;
  userFile.open(file, ios::out);

  uColor.getUserColor();
  colorValues.push_back(uColor.toString());
  
  
  for(int i = 0; i < 5; i++){
    int r_new = uColor.getRValue();
    int g_new = uColor.getGValue();
    int b_new = uColor.getBValue();
    if (i == 0) {
      r_new = cMod.getModifiedColor(uColor.getRValue());
    } else if (i == 1) {
      g_new = cMod.getModifiedColor(uColor.getGValue());
    } else if (i == 2) {
      b_new = cMod.getModifiedColor(uColor.getBValue());
    } else if (i == 3) {
      r_new = cMod.getModifiedColor(uColor.getGValue());
      b_new = cMod.getModifiedColor(uColor.getRValue());
    } else {
      r_new = cMod.getModifiedColor(uColor.getBValue());
      g_new = cMod.getModifiedColor(uColor.getBValue());
    }
  
  string newColor = std::to_string(r_new) + delimiter + std::to_string(g_new) + delimiter + std::to_string(b_new);
  colorValues.push_back(newColor);
  }
  printColorValues();

  return 0;
}

void printColorValues(){
  userFile << "<!DOCTYPE html>\n"; userFile << "<html>\n"; userFile << "<head>\n" << "<style>\n";
  
  
  userFile << "h1 {\n"; userFile << "   background-color: rgb(255,255,255);\n"; userFile << "}\n";

  
  
  for(int i=0; i < colorValues.size(); i++){
    if(i < 1){
      userFile << "p" << i+1 << "{\n   background-color:rgb(" <<colorValues[i] << ");\n}\n";
    }else{
      userFile << "p" << i+1 << "{\n   background-color:rgb(" <<colorValues[i] << ");\n}\n";
    }
  }

  userFile << "</style>\n"; userFile << "</head>\n"; userFile << "<body>\n\n";
  userFile << "<h1>Color Blind Project</h1>";

  for(int i=0; i < colorValues.size(); i++){
    if(i < 1){
      userFile << "\n<p" << i+1 << ">"; userFile << "user color" << ":rgb(" <<colorValues[i]<< ")" << "</p" << i+1 << ">" << "<br>" <<endl;
    } else {
      userFile << "\n<p" << i+1 << ">"; userFile << "color " << i+1 << ":rgb(" <<colorValues[i]<< ")" << "</p" << i+1 << ">" << "<br>" <<endl;
    }
  }
  

  userFile << "\n</body>"; userFile << "\n</html>";


/*
  for(int i=0; i < colorValues.size(); i++){
    if(i < 1){
      userFile << "\np {\n"; userFile << "   {background-color:rgb(" <<colorValues[i]<< ");}" << " /** user color **//* \n"; userFile << "}\n";
    } else {
      userFile << "p"; /*userFile << i;*//* userFile << "{\n"; userFile << "    {background-color:rgb(" << colorValues[i]<<");}" << " /** New Color " << i << "**/ /*\n"; userFile << "}\n";
    }
  }

 */ 

  }
  

  

/**

  for(int i=0; i < colorValues.size(); i++){
    if(i > 1){
      userFile << "<p
      {background-color:rgb(" <<colorValues[i]<< ");}" << " /** user color **//* " <<endl;
    } 
  }
}
*/

/*
for(int i=0; i < colorValues.size(); i++){
    if(i < 1){
      userFile << "{background-color:rgb(" <<colorValues[i]<< ");}" << " /** user color **//* " <<endl;
    } else {
      userFile << "{background-color:rgb(" << colorValues[i]<<");}" << endl;
    }
  }
}
*/

  

