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
    }
    cout<<"Thank you for your time\n";
}