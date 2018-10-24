#include <iostream>

#include "lisch.h"

using namespace std;

int main()
{
    LISCH my_lisch(11); //Create vector space
    cout << "Vector Size:" << my_lisch.data_vec.size();   //Print size of my_lisch vector
    my_lisch.insert(13);
    my_lisch.insert(24);
    return 0;
}
