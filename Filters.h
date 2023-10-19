
#include<bits/stdc++.h>
#include <unistd.h>
#include "bmplib.h"
//Define all functions
/*********************************************************/
// output start message to and return the choice integer
int start_massage();
// load image in the variable image
void load_image();
void load_image_RGB();
//produce the negative of the image
void invert_filter();
void invert_filter_RGB();
//allows the user to rotate the image clockwise by 90º, 180º or 270º as the user chooses.
void Rotate_Image();
void Rotate_Image_RGB();
//allows the user to convert the image to black and white
void Black_white();
void Black_white_RGB();
//allows the user to flip the image vertically or horizontally
void Flip_Image();
void Flip_Image_RGB();
//allows the user to merge two images together
void Merge_images();
void Merge_images_RGB();
//allows the user to darken or lighten the image by 50%
void Darken_lighten_image();
void Darken_lighten_image_RGB();
//allows the user to skew the image Vertically or Horizontally
void Skew_image();
void Skew_image_RGB();
//allows the user reorder the quarter of the image with any order
void shuffle_image();
void shuffle_image_RGB();
//This function allows the user to shrink the image dimensions to 1/2, 1/3 or 1/4 the original dimensions
void shrink_image();
void shrink_image_RGB();
//allows the user to cut the quarter 1,2,3 or 4 from the select image
void enlarge_image();
void enlarge_image_RGB();
//This filter produces a bury version of the image.
void Blur_Image();
void Blur_Image_RGB();
//finds the edges of the drawings in the image
void detect_image();
void detect_image_RGB();
//This filter mirrors 1/2 of the image
void mirror_image();
void mirror_image_RGB();
//This filter allows entering an x, y position and cutting a square of length and width l, w
void crop_image();
void crop_image_RGB();
//save the image in your cwd with the choice name
void save_image();
void save_image_RGB();
/*********************************************************/

