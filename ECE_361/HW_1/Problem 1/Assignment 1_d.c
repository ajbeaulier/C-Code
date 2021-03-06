#include <stdbool.h>
#include <stdio.h>

typedef struct color {
    int red;
    int green;
    int blue;
} color_t;

color_t makeColor(int red, int green, int blue);
int getRed(color_t c);
bool equalColor(color_t c1, color_t c2);
color_t makeDarkerColor(color_t c);

//##################################################################
int main(){
int redcolor;
bool SameColor;

color_t color_1;
color_t color_2;

color_1.red = 0;
color_1.green = 256;
color_1.blue = 260;

color_2.red = 25;
color_2.green = 256;
color_2.blue = 150;

color_1 = makeColor(color_1.red,color_1.green,color_1.blue);
printf("Red %d, Green %d, Blue %d \n",color_1.red, color_1.green, color_1.blue);

redcolor = getRed(color_1);
printf("Red Color value is %d\n",redcolor);

SameColor = equalColor(color_1,color_2);
printf("Colors are same: %d\n",SameColor);

color_1 = makeDarkerColor(color_1);
printf("Darker colors are: Red %d, Green %d, Blue %d \n",color_1.red, color_1.green, color_1.blue);
}
//##################################################################


// returns a color_t struct containing the specified values
// for the red, green, and blue color members.
// if an argument is < 0 that color member is set to zero.
// if an argument is > 255 that color members is set to 255
color_t makeColor(int red, int green, int blue) {
    struct color a;
    if (red < 0) {
        red = 0;
    }
    else if (red > 255){
        red = 255;
    }
    if (green < 0) {
        green = 0;
    }
    else if (green > 255){
        green = 255;
    }
    if (blue < 0) {
        blue = 0;
    }
    else if (blue > 255){
        blue = 255;
    }
    a.red = red;
    a.blue = blue;
    a.green = green;
    return a;
}


// returns the value of the red member of the
int getRed(color_t c) {
return c.red;
}


// returns true if all of the members of both color_t structs
// are the same
bool equalColor(color_t c1, color_t c2) {
    if (c1.red == c2.red && c1.blue == c2.blue && c1.green == c2.green){
        return true;
    }
    else{
        return false;
    }
}

// returns a color_t struct that represents a darker version of the
// color in to color_t argument c except that each member
// has been multiplied by 0.7 with the result truncated to an integer
color_t makeDarkerColor(color_t c) {
float darkit = .7;
c.red = c.red * darkit;
c.green = c.green * darkit;
c.blue = c.blue * darkit;
return c;//Note this function floors it and eliminates any extra digits. Interpreting truncation as just eliminating extra digits and not rounding to nearest int
}
