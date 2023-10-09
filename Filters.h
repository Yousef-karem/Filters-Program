
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