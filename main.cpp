// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-20220402-20220052-20220396-A1-Part1.cpp
// Last Modification Date:	15/10/2023
// Author1 and ID and Group:	Youssef karem wiliam - 20220402
// Author2 and ID and Group:	Arsany nageh attia - 20220052
// Author3 and ID and Group:	Yousef samwel zaied- 20220396
// Purpose: Program Filers to apply some edits for images

#include<bits/stdc++.h>
#include "Filters.h"
using namespace std;
int main()
{
    int op=0;
    while(true)
    {
        int Choice_filter=start_massage();
        if(Choice_filter==0)
        {
            break;
        }
        if(!op)
        {
            load_image();
        }
        switch (Choice_filter) {
            case 1:
                invert_filter();
                break;
            case 2:
                Rotate_Image();
                break;
            case 3:
                Black_white();
                break;
            case 4:
                Flip_Image();
                break;
            case 5 :
                Merge_images();
                break;
            case 6:
                Darken_lighten_image();
                break;
            case 7:
                Skew_image();
                break;
            case 8:
                shuffle_image();
                break;
            case 9:
                shrink_image();
                break;
            case 10:
                enlarge_image();
                break;
            case 11:
                Blur_Image();
                break;
            case 12:
                detect_image();
                break;
            case 13:
                mirror_image();
                break ;
            case 14:
                crop_image();
                break;
            case 15:
                save_image();
                break;
        }
        op++;
    }
    cout << "Thank you for your time\n";
}