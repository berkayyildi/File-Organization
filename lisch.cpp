#include <iostream>
#include "lisch.h"
using namespace std;

int globTableSize;  //Global variable R means the last free space of vector

LISCH::LISCH(int table_size){
    globTableSize = table_size;   //Shows the index of the first blank space
    for (int i=0; i < table_size ; i++){
        data_vec.push_back (lisch_entry()); //Boþ lisch_entry ile doldur
    }
}


void LISCH::insert(int new_data){

    int moddedData = new_data % globTableSize;  // Take mod of the data with table size

    if (data_vec[moddedData].valid == false){
        data_vec[moddedData].data = new_data;
        data_vec[moddedData].valid = true;
        cout << "\nNumber " << new_data << " Placed to index " << moddedData << " (The Space Was Blank)";

    }else{  //If Index mod of the num is full then find a blank space to link it

        int biggestInvalidIndex = -1;
        for (int i = globTableSize-1 ; i >= 0 ; i--){  //Select the biggest index which is not valid
            if (data_vec[i].valid == false){
                biggestInvalidIndex = i;    //Set biggest invalid index to biggestInvalidIndex
                break;  //Break the for loop which find the biggest index to store data
            }
        }
        //----Place it to the first blank space----
        cout << "\nILK BOS INDEX " << biggestInvalidIndex;
        data_vec[biggestInvalidIndex].valid = true;
        data_vec[biggestInvalidIndex].data = new_data;
        cout << "\n Mod was full so Number " << new_data << " Placed to index " << biggestInvalidIndex;
        //------------------------------------------
        cout << "\n ALOOOOO" << data_vec[moddedData].link;
        //------Set the link of it------
        if (data_vec[moddedData].link == NULL){
            data_vec[moddedData].link = biggestInvalidIndex;
            cout << " | " << moddedData << " Link set to " << biggestInvalidIndex;
        }else{
            cout << "\nLink property is full what should I do? ";
        }
        //------------------------------
    }
}



int LISCH::find_num_probes(int key) const{

}



double LISCH::find_average_num_probes() const{

}


bool LISCH::does_include(int key) const{

}
