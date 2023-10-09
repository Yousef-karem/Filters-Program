
#include<bits/stdc++.h>
#include <unistd.h>
#include "bmplib.h"
// output start message to and return the choice integer
int start_massage();
// load image in the variable image
void load_image(unsigned char image [SIZE][SIZE]);
// load save in the variable out_image
void save_image(unsigned char out_image[SIZE][SIZE]);
//Produce the negative of the image (every pixel turned to opposite level)
void invert_filter();
//allows the user to rotate the image clockwise by 90º, 180º or 270º as the user chooses.
void Rotate_Image();
//allows the user to convert the image to black and white
void Black_white();
//allows the user to flip the image vertically or horizontally
void Flip_Image();
//allows the user to merge two images together
void Merge_images();
//allows the user to darken or lighten the image by 50%
void Darken_lighten_image();