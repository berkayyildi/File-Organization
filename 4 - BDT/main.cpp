#include <iostream>

#include "bdt.h"

using namespace std;

int main()
{
    BDT my_BDT(11);

    /*
    my_BDT.insert(27);
    my_BDT.insert(18);
    my_BDT.insert(29);
    my_BDT.insert(28);
    my_BDT.insert(39);
    my_BDT.insert(13);
    my_BDT.insert(16);
    */
    my_BDT.insert(9);
    my_BDT.insert(26);
    my_BDT.insert(6);
    my_BDT.insert(50);
    my_BDT.insert(28);
    my_BDT.insert(1);
    my_BDT.insert(64);
    my_BDT.insert(32);

    cout << endl;
    for (int i = 0 ; i < my_BDT.data_vec.size() ; i++){
        if (!my_BDT.data_vec[i].valid) {cout << i << "\t" << "---" << "\t " << 0 << endl; continue;}
        cout << i << "\t" << my_BDT.data_vec[i].data << "\t " << my_BDT.data_vec[i].valid << endl;
    }
    cout << endl;
    cout << "AVG PROBE:" << my_BDT.find_average_num_probes() << endl;
}
