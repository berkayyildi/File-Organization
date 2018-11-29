#include <iostream>
#include <fstream>
#include "computed_chaining.h"

using namespace std;

int main()
{
    ComputedChaining chain(103);


    int i;
    std::ifstream file("numbers_small");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {

            sscanf(line.c_str(), "%d", &i);
            chain.insert(i);

        }
        file.close();
    }

    /*
    chain.insert(27);
    chain.insert(18);
    chain.insert(29);
    chain.insert(28);
    chain.insert(39);
    chain.insert(13);
    chain.insert(16);
    chain.insert(38);
    chain.insert(53);
    */
    cout << chain;

    return 0;
}
