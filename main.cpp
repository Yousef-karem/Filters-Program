// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				Filters.cpp
// Last Modification Date:	10/10/2023
// Author1 and ID and Group:	20220402
// Author2 and ID and Group:	20220052
// Author3 and ID and Group:	20220396
// Purpose: Program Filers to apply some edits for images

#include<bits/stdc++.h>
#include "Filters.h"
using namespace std;
const int N=1e5+5,inf=1e16,mod=998244353;
int main()
{
    int Choice_filter=start_massage();
    switch (Choice_filter)
    {
        case 1:
            invert_filter();
            break;
        case 2:
            Rotate_Image();
            break;
        case 3:
            Black_white();
            break ;
        case 4:
            Flip_Image();
            break;
        case 5 :
            Merge_images();
            break ;
        case 6:
             Darken_lighten_image();
            break;
    }
    cout<<"Thank you for your time\n";
}