#include "Filters.h"
#include <unistd.h>
#include "bmplib.h"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image_RGB[SIZE][SIZE][RGB];
int start_massage()
{
    const char* message = R"(
Please select a filter to apply or 0 to exit:

1-Invert Image
2-Rotate Image
3-Black & white
4-Flip Image
5-merge images
6-darken or lighten image
7-Skew image
8-shuffle image
9-shrink_image
10-enlarge_image
11-Blur_Image
12-detect_image
13-mirror_image
14-crop_image
15-Save the image to a file
0- Exit)";
    cout << message << std::endl;
    int Choice_filter;cin>>Choice_filter;
    return Choice_filter;
}
void load_image()
{
    cout<<"Enter the image name : ";
    string imageName;
//    get the gray image file name
    cin>>imageName;
//  add the current working directly and folder name images
    char cwd[PATH_MAX];
    //current working directly +imageName + ".bmp"
    imageName+=".bmp";
    string path='\\'+imageName;
    readGSBMP(strcat(getcwd(cwd,sizeof(cwd)),path.c_str()),image);
}
void load_image_RGB()
{
    cout<<"Enter the image_RGB name : ";
    string imageName;
//    get the gray image_RGB file name
    cin>>imageName;
//  add the current working directly and folder name images
    char cwd[PATH_MAX];
    //current working directly +imageName + ".bmp"
    imageName+=".bmp";
    string path='\\'+imageName;
    readRGBBMP(strcat(getcwd(cwd,sizeof(cwd)),path.c_str()), image_RGB);
}
void save_image()
{
    string imageName;
//    get the name of the new image
    cout<<"Enter the name of the new image: ";
    cin>>imageName;
//  add the current working directly and folder name images
    char cwd[PATH_MAX];
    //current working directly + imageName + ".bmp"
    imageName+=".bmp";
    string path='\\'+imageName;
    writeGSBMP(strcat(getcwd(cwd,sizeof(cwd)),path.c_str()),image);
    cout<<"the image saved successfully in your current working directly  ("<<strcat(getcwd(cwd,sizeof(cwd)),path.c_str())<<")."<<'\n';
}

void save_image_RGB()
{
    string imageName;
//    get the name of the new image_RGB
    cout<<"Enter the name of the new image_RGB: ";
    cin>>imageName;
//  add the current working directly and folder name images
    char cwd[PATH_MAX];
    //current working directly + imageName + ".bmp"
    imageName+=".bmp";
    string path='\\'+imageName;
    writeRGBBMP(strcat(getcwd(cwd,sizeof(cwd)),path.c_str()), image_RGB);
    cout<<"the image_RGB saved successfully in your current working directly  ("<<strcat(getcwd(cwd,sizeof(cwd)),path.c_str())<<")."<<'\n';
}


void invert_filter()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            image[i][j]=255-image[i][j];
        }
    }
    showGSBMP(image);
}
void invert_filter_RGB()
{
    for(int r=0;r<RGB;r++)
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image_RGB[i][j][r] = 255 - image_RGB[i][j][r];
            }
        }
    }
    showRGBBMP(image_RGB);
}

void Rotate_Image()
{
    const char* message = R"(
Please select the degree
1- 90 degrees
2- 180 degrees
3- 270 degrees
0- save and exit
)";
    cout<<message<<'\n';
    int x;cin>>x;
    if(!x){
        save_image();
        return;
    }
    unsigned char new_image[SIZE][SIZE];
    switch ( x)
    {
        case 1:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    new_image[j][SIZE - i - 1] = image[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    new_image[SIZE-i-1][SIZE - j - 1] = image[i][j];
                }
            }
            break;
        case 3:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    new_image[j][i] = image[i][j];
                }
            }
            break;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j]=new_image[i][j];
        }
    }
    showGSBMP(image);
}
void Rotate_Image_RGB()
{
    const char* message = R"(
Please select the degree
1- 90 degrees
2- 180 degrees
3- 270 degrees
0- save and exit
)";
    cout<<message<<'\n';
    int x;cin>>x;
    if(!x){
        save_image();
        return;
    }
    unsigned char new_image[SIZE][SIZE][RGB];
    switch ( x)
    {
        case 1:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        new_image[j][SIZE - i - 1][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        case 2:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        new_image[SIZE - i - 1][SIZE - j - 1][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        case 3:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        new_image[j][i][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
    }
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image_RGB[i][j][r] = new_image[i][j][r];
            }
        }
    }
    showRGBBMP(image_RGB);

}
void Black_white()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(image[i][j]>110){
                image[i][j]=255;
            }
        }
    }
    showGSBMP(image);
}
void Black_white_RGB()
{
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (image_RGB[i][j][r] > 110) {
                    image_RGB[i][j][r] = 255;
                }
            }
        }
    }
    showRGBBMP(image_RGB);
}
void Flip_Image()
{
    const char* message = R"(
Please select the degree
1- Vertically
2- Horizontally
0- exit
)";
    cout<<message<<'\n';
    int x;cin>>x;
    if(!x){
        return;
    }
    unsigned char new_image[SIZE][SIZE];
    switch ( x)
    {
        case 1:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    new_image[SIZE -i -1][SIZE -j - 1] = image[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< (SIZE); j++) {
                    new_image[i][SIZE-j-1]=image[i][j];
                }
            }
            break;

    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j]=new_image[i][j];
        }
    }
    showGSBMP(image);
}
void Flip_Image_RGB()
{
    const char* message = R"(
Please select the degree
1- Vertically
2- Horizontally
0- exit
)";
    cout<<message<<'\n';
    int x;cin>>x;
    if(!x){
        return;
    }
    unsigned char new_image[SIZE][SIZE][RGB];
    switch ( x)
    {
        case 1:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        new_image[SIZE - i-1][SIZE - j-1][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        case 2:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < (SIZE); j++) {
                        new_image[i][SIZE - j-1][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;

    }
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image_RGB[i][j][r] = new_image[i][j][r];
            }
        }
    }
    showRGBBMP(image_RGB);
}

void Merge_images()
{
    unsigned char image1[SIZE][SIZE],image2[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image1[i][j]=image[i][j];
        }
    }
    load_image();
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image2[i][j]=image[i][j];
        }
    }
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            image[i][j]= (image1[i][j]+image2[i][j])/2;
        }
    }
    showGSBMP(image);
}
void Merge_images_RGB()
{
    unsigned char image1[SIZE][SIZE][RGB],image2[SIZE][SIZE][RGB],new_image[SIZE][SIZE][RGB];
    for (int r = 0; r < RGB; ++r) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image1[i][j][r] = image_RGB[i][j][r];
            }
        }
    }
    load_image();
    for (int r = 0; r < RGB; ++r) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image2[i][j][r] = image_RGB[i][j][r];
            }
        }
    }
    for (int r = 0; r < RGB; ++r) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i][j][r] = (image1[i][j][r] + image2[i][j][r]) / 2;
            }
        }
    }
    showRGBBMP(new_image);
}
void Darken_lighten_image()
{
    const char* message = R"(
"Do you want to Darken or lighten ?\n"
1- Darken
2- lighten
)";
    cout<<message<<'\n';
    int choice;cin>>choice;

    switch (choice)
    {
        case 1:
            for(int i=0;i<SIZE;i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] =image[i][j]/2;
                }
            }
            break;
        case 2:
            for(int i=0;i<SIZE;i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] =image[i][j]+(255-image[i][j])/2;
                }
            }
    }
    showGSBMP(image);
}
void Darken_lighten_image_RGB()
{
    const char* message = R"(
"Do you want to Darken or lighten ?\n"
1- Darken
2- lighten
)";
    cout<<message<<'\n';
    int choice;cin>>choice;

    switch (choice)
    {
        case 1:
            for(int r=0;r<RGB;r++)
            {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image_RGB[i][j][r] = image_RGB[i][j][r] / 2;
                    }
                }
            }
            break;
        case 2:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        image_RGB[i][j][r] = image_RGB[i][j][r] + (255 - image_RGB[i][j][r]) / 2;
                    }
                }
            }
    }

    showRGBBMP(image_RGB);
}
void Skew_image()
{
    int shift=SIZE;
    unsigned char new_image[2*SIZE][2*SIZE];
    const char* message = R"(
Please select the degree
1- Vertically
2- Horizontally
0-exit
    )";
    cout<<message<<'\n';
    int choice;cin>>choice;
    switch (choice)
    {
        case 0:
            return;
        case 1:
        {
            memset(new_image,255,sizeof (new_image));
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    new_image[i][j + shift] = image[i][j];
                }
                shift --;
            }
            memset(image,255,sizeof (image));
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < 2*SIZE ; ++j) {
                    image[i][j / 2] = new_image[i][j];
                }
            }
            break;
        }
        case 2:
        {
            memset(new_image,255,sizeof (new_image));
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    new_image[i + shift][j] = image[i][j];
                    shift--;
                }
                shift = SIZE;
            }
            memset(image,255,sizeof (image));
            for (int i = 0; i < 2*SIZE; ++i) {
                for (int j = 0; j < SIZE ; ++j) {
                    image[i/2][j] = new_image[i][j];
                }
            }
            break;
        }

    }
    showGSBMP(image);
}
void Skew_image_RGB()
{
    int shift=SIZE;
    unsigned char new_image[2*SIZE][2*SIZE][RGB];
    const char* message = R"(
Please select the degree
1- Vertically
2- Horizontally
0-exit
    )";
    cout<<message<<'\n';
    int choice;cin>>choice;
    switch (choice)
    {
        case 0:
            return;
        case 1:
        {
            memset(new_image,255,sizeof (new_image));
            for(int r=0;r<RGB;r++)
            {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        new_image[i][j + shift][r] = image_RGB[i][j][r];
                    }
                    shift--;
                }
                shift=SIZE;
            }
            memset(image_RGB, 255, sizeof (image_RGB));
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; ++i) {
                    for (int j = 0; j < 2 * SIZE; ++j) {
                        image_RGB[i][j / 2][r] = new_image[i][j][r];
                    }
                }
            }
            break;
        }
        case 2:
        {
            memset(new_image,255,sizeof (new_image));
            for(int r=0;r<RGB;r++) {
                {
                    for (int i = 0; i < SIZE; ++i) {
                        for (int j = 0; j < SIZE; ++j) {
                            new_image[i + shift][j][r] = image_RGB[i][j][r];
                            shift--;
                        }
                        shift = SIZE;
                    }
                }
            }
            memset(image_RGB, 255, sizeof (image_RGB));
            for(int r=0;r<RGB;r++)
            {
                for (int i = 0; i < 2 * SIZE; ++i) {
                    for (int j = 0; j < SIZE; ++j) {
                        image_RGB[i / 2][j][r] = new_image[i][j][r];
                    }
                }
            }
            break;
        }

    }
    showRGBBMP(image_RGB);
}
void shuffle_image()
{
    const char *message=R"(
New order of quarters ? )";
    cout<<message<<'\n';
    int order[4];
    for (int i = 0; i < 4; ++i) {
        cin>>order[i];
        order[i]--;
    }
    unsigned char new_image[4][SIZE][SIZE];
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            new_image[0][i][j] = image[i][j];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = SIZE / 2,k=0; j < SIZE; j++,k++) {
            new_image[1][i][k] = image[i][j];
        }
    }
    for (int i =  SIZE / 2,k=0; i <SIZE; i++,k++) {
        for (int j = 0; j < SIZE / 2; j++) {
            new_image[2][k][j] = image[i][j];
        }
    }
    for (int i =  SIZE / 2,k=0; i < SIZE ; i++,k++) {
        for (int j =  SIZE / 2,m=0; j < SIZE ; j++,m++) {
            new_image[3][k][m] = image[i][j];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image[i][j] = new_image[order[0]][i][j];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
            image[i][j] = new_image[order[1]][i][k];
        }
    }
    for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image[i][j] = new_image[order[2]][k][j];
        }
    }
    for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
        for (int j = SIZE / 2, m = 0; j < SIZE; j++, m++) {
            image[i][j] = new_image[order[3]][k][m];
        }
    }
    showGSBMP(image);
}
void shuffle_image_RGB()
{
    const char *message=R"(
New order of quarters ? )";
    cout<<message<<'\n';
    int order[4];
    for (int i = 0; i < 4; ++i) {
        cin>>order[i];
        order[i]--;
    }
    unsigned char new_image[4][SIZE][SIZE][RGB];
    for(int r=0;r<RGB;r++)
    {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                new_image[0][i][j][r] = image_RGB[i][j][r];
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                    new_image[1][i][k][r] = image_RGB[i][j][r];
                }
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = 0; j < SIZE / 2; j++) {
                new_image[2][k][j][r] = image_RGB[i][j][r];
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = SIZE / 2, m = 0; j < SIZE; j++, m++) {
                new_image[3][k][m][r] = image_RGB[i][j][r];
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    image_RGB[i][j][r] = new_image[order[0]][i][j][r];
                }
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                image_RGB[i][j][r] = new_image[order[1]][i][k][r];
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = 0; j < SIZE / 2; j++) {
                image_RGB[i][j][r] = new_image[order[2]][k][j][r];
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
            for (int j = SIZE / 2, m = 0; j < SIZE; j++, m++) {
                image_RGB[i][j][r] = new_image[order[3]][k][m][r];
            }
        }
    }
    showRGBBMP(image_RGB);
}
void enlarge_image()
{
    unsigned char new_image[SIZE][SIZE],new_image2[SIZE][SIZE];
    memset(new_image,255, sizeof(new_image));
    const char* message = R"(
Which quarter to enlarge 1, 2, 3 or 4 ?
)";
    cout<<message<<'\n';
    int choice;cin>>choice;
    switch (choice) {
        case 1:
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    new_image[i][j] = image[i][j];
                }
            }

            break;
        case 2:
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = SIZE / 2,k=0; j < SIZE; j++,k++) {
                    new_image[i][k] = image[i][j];
                }
            }
            break;
        case 3:
            for (int i =  SIZE / 2,k=0; i <SIZE; i++,k++) {
                for (int j = 0; j < SIZE / 2; j++) {
                    new_image[k][j] = image[i][j];
                }
            }
            break;
        case 4:
            for (int i =  SIZE / 2,k=0; i < SIZE ; i++,k++) {
                for (int j =  SIZE / 2,m=0; j < SIZE ; j++,m++) {
                    new_image[k][m] = image[i][j];
                }
            }
            break;
        case 0:
            return;

    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = new_image[i / 2][j / 2];
        }
    }

    showGSBMP(image);
}
void enlarge_image_RGB()
{
    unsigned char new_image[SIZE][SIZE][RGB],new_image2[SIZE][SIZE][RGB];
    memset(new_image,255, sizeof(new_image));
    const char* message = R"(
Which quarter to enlarge 1, 2, 3 or 4 ?
)";
    cout<<message<<'\n';
    int choice;cin>>choice;
    switch (choice) {
        case 1:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        new_image[i][j][r] = image_RGB[i][j][r];
                    }
                }
            }

            break;
        case 2:
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = SIZE / 2, k = 0; j < SIZE; j++, k++) {
                        new_image[i][k][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        case 3:
            for(int r=0;r<RGB;r++) {
                for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
                    for (int j = 0; j < SIZE / 2; j++) {
                        new_image[k][j][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        case 4:
            for(int r=0;r<RGB;r++) {
                for (int i = SIZE / 2, k = 0; i < SIZE; i++, k++) {
                    for (int j = SIZE / 2, m = 0; j < SIZE; j++, m++) {
                        new_image[k][m][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        case 0:
            return;

    }
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image_RGB[i][j][r] = new_image[i / 2][j / 2][r];
            }
        }
    }

    showRGBBMP(image_RGB);
}
void shrink_image()
{
    unsigned char new_image[SIZE][SIZE];
    memset(new_image,255, sizeof(new_image));
    const char* message = R"(
Shrink to (1/2), (1/3) or (1/4)?
1- 1/2
2- 1/3
3- 1/4
0-exit
)";
    cout<<message<<'\n';
    int choice;cin>>choice;
    int shrink=choice+1;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            new_image[i/shrink][j/shrink]=image[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=new_image[i][j];
        }
    }
    showGSBMP(image);
}
void shrink_image_RGB()
{
    unsigned char new_image[SIZE][SIZE][RGB];
    memset(new_image,255, sizeof(new_image));
    const char* message = R"(
Shrink to (1/2), (1/3) or (1/4)?
1- 1/2
2- 1/3
3- 1/4
0-exit
)";
    cout<<message<<'\n';
    int choice;cin>>choice;
    int shrink=choice+1;
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_image[i / shrink][j / shrink][r] = image_RGB[i][j][r];
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image_RGB[i][j][r] = new_image[i][j][r];
            }
        }
    }
    showRGBBMP(image_RGB);
}
void Blur_Image() {
    for (int i = 0; i < SIZE; i++){
        for (int j =0 ; j <SIZE; j++){
            image[i][j]= (image[i][j-1]+image[i-1][j]+image[i-1][j-1]+image[i+1][j-1]
                          +image[i+1][j]+image[i+1][j+1]+image[i][j+1]+image[i-1][j+1])/8;
        }
    }
    for (int i = 0; i < SIZE; i++){
        for (int j =0 ; j <SIZE; j++){
            image[i][j]= (image[i][j-1]+image[i-1][j]+image[i-1][j-1]+image[i+1][j-1]
                          +image[i+1][j]+image[i+1][j+1]+image[i][j+1]+image[i-1][j+1])/8;
        }
    }
    showGSBMP(image);
}
void Blur_Image_RGB() {
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image_RGB[i][j][r] = (image_RGB[i][j - 1][r] + image_RGB[i - 1][j][r] + image_RGB[i - 1][j - 1][r] + image_RGB[i + 1][j - 1][r]
                                      + image_RGB[i + 1][j][r] + image_RGB[i + 1][j + 1][r] + image_RGB[i][j + 1][r] + image_RGB[i - 1][j + 1][r]) / 8;
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image_RGB[i][j][r] = (image_RGB[i][j - 1][r] + image_RGB[i - 1][j][r] + image_RGB[i - 1][j - 1][r] + image_RGB[i + 1][j - 1][r]
                                      + image_RGB[i + 1][j][r] + image_RGB[i + 1][j + 1][r] + image_RGB[i][j + 1][r] + image_RGB[i - 1][j + 1][r]) / 8;
            }
        }
    }
    showRGBBMP(image_RGB);
}
void detect_image() {
    unsigned char new_image[SIZE][SIZE];
    memset(new_image, 255, sizeof(new_image));
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(image[i][j]>110){
                image[i][j]=255;
            }
        }
    }
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
            d1 = (image[i][j] - image[i][j + 1]);
            d2 = (image[i][j] - image[i][j - 1]);
            d3 = (image[i][j] - image[i + 1][j]);
            d4 = (image[i][j] - image[i - 1][j]);
            if (d1 > 50 || d3 > 50 || d2 > 50 || d4 > 50) {
                new_image[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j]=new_image[i][j];
        }
    }
    showGSBMP(image);
}
void detect_image_RGB() {
    unsigned char new_image[SIZE][SIZE][RGB];
    memset(new_image, 255, sizeof(new_image));
    for(int r=0;r<RGB;r++)
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                if(image_RGB[i][j][r] > 110){
                    image_RGB[i][j][r]=255;
                }
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
                d1 = (image_RGB[i][j][r] - image_RGB[i][j + 1][r]);
                d2 = (image_RGB[i][j][r] - image_RGB[i][j - 1][r]);
                d3 = (image_RGB[i][j][r] - image_RGB[i + 1][j][r]);
                d4 = (image_RGB[i][j][r] - image_RGB[i - 1][j][r]);
                if (d1 > 50 || d3 > 50 || d2 > 50 || d4 > 50) {
                    new_image[i][j][r] = 0;
                }
            }
        }
    }
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image_RGB[i][j][r] = new_image[i][j][r];
            }
        }
    }
    showRGBBMP(image_RGB);
}

void mirror_image(){
    const char* message = R"(
Which quarter to enlarge ?
1-Upper
2-Lower
3-Right
4-Left
)";
    cout<<message<<'\n';
    int choice;cin>>choice;
    switch (choice) {
        case 0:
            return;
        case 1:
        {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < (SIZE); j++) {
                    image[SIZE - i - 1][j] = image[i][j];

                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < SIZE / 2; i++) {
                for (int j = 0; j < (SIZE); j++) {
                    image[i][j] = image[SIZE - i - 1][j];

                }
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < (SIZE / 2); j++) {
                    image[i][j] = image[i][SIZE - j - 1];
                }
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < (SIZE / 2); j++) {
                    image[i][SIZE - j - 1] = image[i][j];
                }
            }
            break;
        }
    }
    showGSBMP(image);
}
void mirror_image_RGB(){
    const char* message = R"(
Which quarter to enlarge ?
1-Upper
2-Lower
3-Right
4-Left
)";
    cout<<message<<'\n';
    int choice;cin>>choice;
    switch (choice) {
        case 0:
            return;
        case 1:
        {
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < (SIZE); j++) {
                        image_RGB[SIZE - i - 1][j][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        }
        case 2:
        {
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE / 2; i++) {
                    for (int j = 0; j < (SIZE); j++) {
                        image_RGB[i][j][r] = image_RGB[SIZE - i - 1][j][r];
                    }
                }
            }
            break;
        }
        case 3:
        {
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < (SIZE / 2); j++) {
                        image_RGB[i][j][r] = image_RGB[i][SIZE - j - 1][r];
                    }
                }
            }
            break;
        }
        case 4:
        {
            for(int r=0;r<RGB;r++) {
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < (SIZE / 2); j++) {
                        image_RGB[i][SIZE - j - 1][r] = image_RGB[i][j][r];
                    }
                }
            }
            break;
        }
    }
    showRGBBMP(image_RGB);
}
void crop_image(){
    const char* message = R"(
Please inter X Y L W
)";
    cout<<message<<'\n';
    int x,y,l,w;
    cin>>x>>y>>l>>w;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i>x&&i<=l+x&&j>y&&j<=w+y){
                continue;
            }else image[i][j]=255;
        }
    }
    showGSBMP(image);
}
void crop_image_RGB(){
    const char* message = R"(
Please inter X Y L W
)";
    cout<<message<<'\n';
    int x,y,l,w;
    cin>>x>>y>>l>>w;
    for(int r=0;r<RGB;r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i > x && i <= l + x && j > y && j <= w + y) {
                    continue;
                } else image_RGB[i][j][r] = 255;
            }
        }
    }
    showRGBBMP(image_RGB);
}









