#include "Filters.h"
#include <unistd.h>
#include "bmplib.h"
using namespace std;
unsigned char image[SIZE][SIZE];

int start_massage()
{
    const char* message = R"(
Hello
Welcome in our program
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
11-Save the image to a file
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
void save_image()
{
    unsigned char out_image[SIZE][SIZE];
    string imageName;
//    get the name of the new image
    cout<<"Enter the name of the new image: ";
    cin>>imageName;
//  add the current working directly and folder name images
    char cwd[PATH_MAX];
    //current working directly + imageName + ".bmp"
    imageName+=".bmp";
    string path='\\'+imageName;
    writeGSBMP(strcat(getcwd(cwd,sizeof(cwd)),path.c_str()),out_image);
    cout<<"the image saved successfully in folder tmp with the new name ("<<imageName<<")."<<'\n';
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
void Flip_Image()
{
    const char* message = R"(
Please select the degree
1- Vertically
2- Horizontally
0-save and exit
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
                    new_image[SIZE -i][SIZE -j ] = image[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j< (SIZE); j++) {
                    new_image[i][SIZE-j]=image[i][j];
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
void Merge_images()
{
    unsigned char image1[SIZE][SIZE],image2[SIZE][SIZE],new_image[SIZE][SIZE];
    load_image();
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
            new_image[i][j]= (image1[i][j]+image2[i][j])/2;
        }
    }
    showGSBMP(new_image);
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
