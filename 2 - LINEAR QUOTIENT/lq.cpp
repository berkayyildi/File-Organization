#include <iostream>
#include "lq.h"
using namespace std;

LQ::LQ(int table_size){

    for (int i=0; i < table_size ; i++){
        data_vec.push_back (lq_entry()); //Boþ lisch_entry ile doldur
    }

}


void LQ::insert(int new_data){

    int moddedData = new_data % data_vec.size();
    int quotientData = new_data / data_vec.size();

    if (data_vec[moddedData].valid == false){

        data_vec[moddedData].data = new_data;
        data_vec[moddedData].valid = true;
        cout << "Number " << new_data << " Placed to index " << moddedData << " (NP)" << endl;

    }else{

        while (data_vec[moddedData].valid) {    //While found invalid one
            moddedData = (moddedData + quotientData) % data_vec.size(); //Her seferinde quotient kadar arttır eğer vector size aşılırsa mod al
        }

        data_vec[moddedData].data = new_data;
        data_vec[moddedData].valid = true;
        cout << "Number " << new_data << " Placed to index " << moddedData << " (With Quotient)" << endl;

    }

}

int LQ::find_num_probes(int key) const{

    int moddedData = key % data_vec.size();
    int quotientData = key / data_vec.size();
	int probes = 1;
	while (data_vec[moddedData].data != key){

		moddedData = (moddedData + quotientData) % data_vec.size();
		probes++;

	}

	return probes;
}

double LQ::find_average_num_probes() const{

	int totalProbes = 0;
	int totalValid = 0; //Total valid count
	for (int i = 0; i < data_vec.size(); i++){
		if (data_vec[i].valid){	//Data valid ise
            totalValid++; //Total valid count
			totalProbes += find_num_probes(data_vec[i].data);
			cout << "For number " << data_vec[i].data << " Probe: " << find_num_probes(data_vec[i].data) << endl;
		}

	}

	return (double)totalProbes/(double)totalValid;	//Probs toplamını satır sayısına bol

}
