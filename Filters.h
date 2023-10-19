
#include<bits/stdc++.h>
#include <unistd.h>
#include "bmplib.h"
//Define all functions
/*********************************************************/
// output start message to and return the choice integer
int start_massage();
// load image in the variable image
//int cont_message();
//to choose another filter to apply
void load_image();
// load save in the variable out_image
void save_image();
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
//allows the user to skew the image Vertically or Horizontally
void Skew_image();
//allows the user reorder the quarter of the image with any order
void shuffle_image();
//This function allows the user to shrink the image dimensions to 1/2, 1/3 or 1/4 the original dimensions
void shrink_image();
//allows the user to cut the quarter 1,2,3 or 4 from the select image
void enlarge_image();
//This filter produces a bury version of the image.
void Blur_Image();
//finds the edges of the drawings in the image
void detect_image();
//This filter mirrors 1/2 of the image
void mirror_image();
//This filter allows entering an x, y position and cutting a square of length and width l, w
void crop_image();
//save the image in your cwd with the choice name
void save_image();
/*********************************************************/