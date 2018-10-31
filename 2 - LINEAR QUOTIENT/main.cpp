#include <iostream>

#include "lq.h"

using namespace std;

int main()
{
    LQ my_lq(11);

    my_lq.insert(27);
    my_lq.insert(18);
    my_lq.insert(29);
    my_lq.insert(28);
    my_lq.insert(39);
    my_lq.insert(13);
    my_lq.insert(16);
    my_lq.insert(42);
    my_lq.insert(17);

    for (int i = 0 ; i < my_lq.data_vec.size() ; i++){
        cout << i << " | " << my_lq.data_vec[i].data << " | " << my_lq.data_vec[i].valid << endl;
    }

    cout << "AVG PROBE:" << my_lq.find_average_num_probes() << endl;

    return 0;
}
