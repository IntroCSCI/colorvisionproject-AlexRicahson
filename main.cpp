//Author: Alex Richason
//Theme Completer   
//CSS file type
#include <iostream>
#include <fstream>
using namespace std;

int main(){
ofstream userFile;
string file, color;
string delimiter = ",";
int r_value, g_value, b_value;
//fstream usefile;
//size_t value1, value2, value3;

//Ask for user input
cout << "Enter a file name: ";
cin >> file;
cout << "Enter RGB values individually." << endl << "Enter R value: ";
cin >> r_value;
while (r_value < 0 || r_value > 255){
  cout << "Invalid R, Try Again: ";
  cin >> r_value;
}
//TODO - create method
cout << "Enter G value: ";
cin >> g_value;
while (g_value < 0 || g_value > 255){
  cout << "Invalid G, Try Again: ";
  cin >> g_value;
}
cout << "Enter B value: ";
cin >> b_value;
while (b_value < 0 || b_value > 255){
  cout << "Invalid B, Try Again: ";
  cin >> b_value;
}

color = std::to_string(r_value) + delimiter + std::to_string(g_value) + delimiter + std::to_string(b_value);
//create and write to users file
userFile.open(file, ios::out);
userFile << "user color: " << color << endl;

//TODO - create method
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
} 







//loop when color is a hex value 
  return 0;
}
