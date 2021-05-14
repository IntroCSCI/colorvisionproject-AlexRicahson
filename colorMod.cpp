#include "colorMod.h"
#include "iostream"
#include <string>
#include <vector>

using std::string;
using std::vector;

int colorMod::getModifiedColor(int color) {
   int color_new = color;
   if(color < 128){
       color_new = color + 100;
   } else{
       color_new = color - 100;
   }
   return color_new;
}
