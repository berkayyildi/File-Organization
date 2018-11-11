#include <iostream>

#include "brent.h"

using namespace std;

int main()
{
    Brent my_brent(11);

    my_brent.insert(27);
    my_brent.insert(18);
    my_brent.insert(29);
    my_brent.insert(28);
    my_brent.insert(39);
    my_brent.insert(13);
    my_brent.insert(16);
    //my_brent.insert(42);
    //my_brent.insert(17);

    for (int i = 0 ; i < my_brent.data_vec.size() ; i++){
        cout << i << " | " << my_brent.data_vec[i].data << " | " << my_brent.data_vec[i].valid << endl;
    }

    cout << "AVG PROBE:" << my_brent.find_average_num_probes() << endl;

    return 0;
}
