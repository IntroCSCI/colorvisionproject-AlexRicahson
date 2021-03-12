# !!!Replace with your unique project name!!!

## Description

My program prompts the user to input a file name and then asks to input rgb values. 
Then it does some limited checking of the user input(it assumes the user input is a numeric value and checks if it is between 0 - 255). 
Next it creates a string out of the user input and prints it to the file.
Finally it uses a while loop to generate 5 random R, G, B values. It compares them to the user input values and if not equal, uses them to create a new color. The new color is also printed to the output file.


### v0.2 Updates

*Coming soon*

### v1.0 Updates

*Coming soon*


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
Invalid R, Try Again: 32
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

### Arrays/Vectors

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
