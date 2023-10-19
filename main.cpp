// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:CS213-2023-20220402-20220052-20220396-A1.cpp
// Last Modification Date:	19/10/2023
// Author1 and ID and Group:	Youssef karem wiliam - 20220402
// Author2 and ID and Group:	Arsany nageh attia - 20220052
// Author3 and ID and Group:	Yousef samwel zaied- 20220396
// Purpose: Filers Program to apply some edits for grey and RGB images

#include<bits/stdc++.h>
#include "Filters.h"
using namespace std;
int main()
{
    int op=0;
    string message=
R"(Hello
Welcome in our program
please select the type of image:
1-gray image
2-RGB image)";
    cout<<message<<'\n';
    int Rgb;cin>>Rgb;
    Rgb--;
    while(true)
    {
        int Choice_filter=start_massage();
        if(Choice_filter==0)
        {
            break;
        }
        if(!op)
        {
            (Rgb) ? load_image_RGB(): load_image();
        }
        switch (Choice_filter) {
            case 1:
                (Rgb) ? invert_filter_RGB():invert_filter();
                break;
            case 2:
                (Rgb) ? Rotate_Image_RGB():Rotate_Image();
                break;
            case 3:
                (Rgb) ? Black_white_RGB():Black_white();
                break;
            case 4:
                (Rgb) ? Flip_Image_RGB():Flip_Image();
                break;
            case 5 :
                (Rgb) ? Merge_images_RGB():Merge_images();
                break;
            case 6:
                (Rgb) ? Darken_lighten_image_RGB():Darken_lighten_image();
                break;
            case 7:
                (Rgb) ? Skew_image_RGB():Skew_image();
                break;
            case 8:
                (Rgb) ? shuffle_image_RGB():shuffle_image();
                break;
            case 9:
                (Rgb) ? shrink_image_RGB():shrink_image();
                break;
            case 10:
                (Rgb) ? enlarge_image_RGB():enlarge_image();
                break;
            case 11:
                (Rgb) ? Blur_Image_RGB():Blur_Image();
                break;
            case 12:
                (Rgb) ? detect_image_RGB():detect_image();
                break;
            case 13:
                (Rgb) ? mirror_image_RGB():mirror_image();
                break ;
            case 14:
                (Rgb) ? crop_image_RGB():crop_image();
                break;
            case 15:
                (Rgb) ? save_image_RGB():save_image();
                break;
        }
        op++;
    }
    cout << "Thank you for your time\n";
}