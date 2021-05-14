Color Vision Project

## Description

My program prompts the user to input a file name and then asks to input rgb values. 
Then it does some limited checking of the user input(it assumes the user input is a numeric value and checks if it is between 0 - 255). 
Next it creates a string out of the user input and prints it to the file.
Finally it uses a while loop to generate 5 random R, G, B values. It compares them to the user input values and if not equal, uses them to create a new color. The new color is also printed to the output file.


### v0.2 Updates

In this update I added 2 new functions, one for checking user input and one for creating new color values. I also added a vector to store these colors and printed to the file using this vector. In this version I changed the new colors from being random rgb values from 0 to 255 to increasing or decreasing by 100 depending on what the user input is. This makes all 5 colors unique and is closer to being color blind safe but I will have to do a little more reasearch for the next update to make sure they are all distinguishable for people with color blindness.

### v1.0 Updates

In this update I added 2 new classes called userColor and colorMod. User color retrieves an r, g, and b value from the user, checks if the values are between 0 and 255, and then converts it to a string. ColorMod is a class that modifies the users color to create 5 distinct new colors. I also converted the user input and 5 generated colors to a css file  which displays the user color and the 5 new colors highlighted by the color that it is. The format and addition of classes and file type have changed but the program runs the same as it did in the last deliverable.


## Developer

Alex Richason

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
g++ -std=c++11 *.cpp -o cvp; ./cvp
Enter a file name: color.txt
Enter RGB values individually.
Enter R value: 545
Invalid, Try Again: 32
Enter G value: 54
Enter B value: 124

```

## C++ Guide

### Variables and Data Types

I used ints, strings, and ofstream to define my individual colors and then combine them all to make one final RGB value which is then stored in the file and will eventually be used to create 5 more colors that are distinct from it.
```
ofstream userFile;
string file, color;
string delimiter = ",";
```
### Console Input and Output

I used cin and cout statements to collect the users data and print out the questions. First I used the cout statements to prompt the user for a file name and 3 different colors. I used cin statements to get the file name and the color values.

```
cout << "Enter a file name: ";
cin >> file;
cout << "Enter RGB values individually." << endl << "Enter R value: ";
cin >> r_value;
```

### Decisions

I used a few if statements to test if the randomly generated r,g, and b values were the same as the original rgb values that the user inputed to make sure the 5 new colors are not equivalent to the original color. I will implement more if, else, and else if statements futher along in the project. 

In my updated code I used if, else if, and else statements in a for loop to test if my counter i is equal to 0-4 so that each time it loops, a different r,g, or b value will be changed to create a new distinct color.
```
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
```

### Iteration

I used a for loop and a few while loops to 1. Create 5 new rgb values by having a counter count up to 5 and for every time it goes through the loop create a new r, g, and b value which is then combined to make a color and 2. To make sure that the users input was a value between 0 and 255 which are the possible rgb values. The loop tests to make sure that the value the user enters is between 0 and 255 and if it is not it will prompt them to try and enter a number again.
```
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
```
```
while (r_value < 0 || r_value > 255){
  cout << "Invalid R, Try Again: ";
  cin >> r_value;
```
In my updated code I used a while loop in one of my functions to test if the color inputed is between 0 and 255. I also used a for loop to get new r, g and b values that are unique.  (The for loop is in the Iteration section). 
```
int getValidColor( int color ){
  while (color < 0 || color > 255){
  cout << "Invalid, Try Again: ";
  cin >> color;
} return color;
}
```


### File Input and Output

I used a file by having the user enter a name which is then made into a file. The user then writes to the file by entering the RGB value that they choose. I also write to the file later on when picking 5 new colors.
```
cout << "Enter a file name: ";
cin >> file;
```
```
userFile.open(file, ios::out);
userFile << "user color: " << color << endl;
```
```

userFile << "New Color_" << std::to_string(i+1) << ": " << newColor << endl;
```
In my updated code I did the same thing but tried to make the file type css. I was not sure how to do this so I made all colors "background-color". I will do more research for the next deliverable to make sure the format is correct.
```
userFile << "{background-color:rgb(" << colorValues[i]<<");}" << endl;
```
In my most recent update I have convereted the user color and 5 new colors into css format and added them to the file.
```
<!DOCTYPE html>
<html>
<head>
<style>
h1 {
   background-color: rgb(255,255,255);
}
p1{
   background-color:rgb(44,55,66);
}
p2{
   background-color:rgb(144,44,44);
}
p3{
   background-color:rgb(44,144,44);
}
p4{
   background-color:rgb(44,44,144);
}
p5{
   background-color:rgb(144,44,144);
}
p6{
   background-color:rgb(144,144,44);
}
</style>
</head>
<body>

<h1>Color Blind Project</h1>
<p1>user color:rgb(44,55,66)</p1><br>

<p2>color 2:rgb(144,44,44)</p2><br>

<p3>color 3:rgb(44,144,44)</p3><br>

<p4>color 4:rgb(44,44,144)</p4><br>

<p5>color 5:rgb(144,44,144)</p5><br>

<p6>color 6:rgb(144,144,44)</p6><br>

</body>
</html>
```

### Arrays/Vectors

I used a vector to store the users input and the 5 new colors that are generated. Then I printed out the values to the file.
```
vector <string> colorValues;
```
```
for(int i=0; i < colorValues.size(); i++){
  if(i < 1){
    userFile << "{background-color:rgb(" <<colorValues[i]<< ");}" << " /** user color **/ " <<endl;
  } else {
    userFile << "{background-color:rgb(" << colorValues[i]<<");}" << endl;
  }
}
```
### Functions

I used one funtion to test the users R, G, and B values to make sure they are not below 0 or above 255. I used another function to create 5 new colors that are added to the file. The first function I used is pass by reference and the second is pass by value. The reurn type for the first function is void and the return type for the second function is the modified color.
```
void getValidColor( int & color ){
  while (color < 0 || color > 255){
     cout << "Invalid, Try Again: ";
     cin >> color;
  } 
}
```
```
int getModifiedColor(int color ) {

   int color_new = color;
   if(color < 128){
       color_new = color + 100;
   } else{
       color_new = color - 100;
   }
   return color_new;
}
```



### Classes

I used two classes called userColor and colorMod to retrieve the users input and create 5 new colors from it. The first class is called userColor and it gets the users input as 3 seperate integers and then combines them into a string. The second class is called colorMod and contains the function for creating the new color values which is called in main.
```
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
```
