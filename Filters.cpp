#include "Filters.h"
#include <unistd.h>
#include "bmplib.h"
using namespace std;
int start_massage()
{
    const char* message1 = R"(
Welcome in our project
First, Please select a filter to apply or 0 to exit:)";
    cout << message1 << std::endl;
    const char* message2 = R"(
1- Invert Filter
2- Rotate Image
0- Exit)";
    cout << message2 << std::endl;
    int Choice_filter;cin>>Choice_filter;
    return Choice_filter;
}
void load_image(unsigned char image [SIZE][SIZE])
{
    string imageName;
//    get the gray image file name
    cin>>imageName;
//  add the current working directly and folder name images
    string path="\\images\\";
    char cwd[PATH_MAX];
    //current working directly + \images +imageName+".bmp"
    imageName+=".bmp";
    path+=imageName;
    readGSBMP(strcat(getcwd(cwd,sizeof(cwd)),path.c_str()),image);
}
void save_image(unsigned char out_image[][SIZE])
{
    string imageName;
//    get the name of the new image
    cout<<"Enter the name of the new image: ";
    cin>>imageName;
//  add the current working directly and folder name images
    string path="\\tmp\\";
    char cwd[PATH_MAX];
    //current working directly + \images +imageName+".bmp"
    imageName+=".bmp";
    path+=imageName;
    writeGSBMP(strcat(getcwd(cwd,sizeof(cwd)),path.c_str()),out_image);
}
void invert_filter()
{
    unsigned char image[SIZE][SIZE];
    cout<<"Enter the source image file name to invert it: ";
    load_image(image);
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            image[i][j]=255-image[i][j];
        }
    }
    save_image(image);
    showGSBMP(image);
}
void Rotate_Image()
{
    unsigned char image[SIZE][SIZE];
    cout<<"Enter the source image file name to Rotate it : ";
    load_image(image);
    const char* message = R"(
Please select the degree
1- 90 degrees
2- 180 degrees
3- 270 degrees
0-exit
)";
    cout<<message<<'\n';
    int x;cin>>x;
    if(!x)return;
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
    save_image(image);
    showGSBMP(image);
}
