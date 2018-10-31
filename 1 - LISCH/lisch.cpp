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
        data_vec[moddedData].link = -1;
        //cout << "\nNumber " << new_data << " Placed to index " << moddedData << " (The Space Was Blank)" << endl;

    }else{  //If Index mod of the num is full then find a blank space to link it

        int biggestInvalidIndex = -1;
        for (int i = globTableSize-1 ; i >= 0 ; i--){  //Select the biggest index which is not valid
            if (data_vec[i].valid == false){
                biggestInvalidIndex = i;    //Set biggest invalid index to biggestInvalidIndex
                break;  //Break the for loop which find the biggest index to store data
            }
        }
        //----Place it to the first blank space----
        data_vec[biggestInvalidIndex].valid = true;
        data_vec[biggestInvalidIndex].data = new_data;
        data_vec[biggestInvalidIndex].link = -1;
        //cout << "\n Mod " << moddedData << " was full so Number " << new_data << " Placed to index " << biggestInvalidIndex;
        //------------------------------------------

	//Link number it to the first blank link
	while (data_vec[moddedData].link >= 0) {
		moddedData = data_vec[moddedData].link;
	}
        data_vec[moddedData].link = biggestInvalidIndex;
        //cout << " | " << moddedData << " Link set to " << biggestInvalidIndex << endl;

        //------------------------------
    }
}



int LISCH::find_num_probes(int key) const{

	int modNum = key % globTableSize;
	int probes = 1;
	while (data_vec[modNum].data != key){
		modNum = data_vec[modNum].link;

		probes++;
	}
	return probes;
}



double LISCH::find_average_num_probes() const{

	int totalValid = 0;
	for (int i = 0; i < globTableSize; i++){
		if(data_vec[i].valid){
			totalValid ++;
		}
	}

	int totalProbes = 0;
	for (int i = 0; i < globTableSize; i++){
		if (data_vec[i].valid){	//Data valid ise
			totalProbes += find_num_probes(data_vec[i].data);
			//cout << "For number " << data_vec[i].data << " Probe: " << find_num_probes(data_vec[i].data) << endl;
		}

	}
	return (double)totalProbes/(double)totalValid;	//Probs toplamını satır sayısına bol

}


bool LISCH::does_include(int key) const{

	for (int i = 0; i < globTableSize; i++){
		if (data_vec[i].data == key){
			return true;
		}
	}
	return false;

}
