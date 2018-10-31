#include <iostream>

#include "lisch.h"

using namespace std;

int main()
{
    LISCH my_lisch(11);

    my_lisch.insert(27);
    my_lisch.insert(18);
    my_lisch.insert(29);
    my_lisch.insert(28);
    my_lisch.insert(39);
    my_lisch.insert(13);
    my_lisch.insert(16);
    my_lisch.insert(42);
    my_lisch.insert(17);

    for (int i = 0 ; i < my_lisch.data_vec.size() ; i++){
        cout << i << " | " << my_lisch.data_vec[i].data << " | " << my_lisch.data_vec[i].valid << endl;

    }
    return 0;
}
