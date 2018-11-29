#include <iostream>
#include "bdt.h"
using namespace std;

class node {
	public:
		int index;
		int value;
		node* left;
		node* right;

		node(int getindex, int getvalue) {
			left = NULL;
			right = NULL;
			index = getindex;
			value = getvalue;
		}
	};



BDT::BDT(int table_size) {

    for (int i=0; i < table_size ; i++){
        data_vec.push_back (entry()); //Bos lisch_entry ile doldur
    }

}


void BDT::insert(int new_data) {

    int moddedData = new_data % data_vec.size();
    int quotientData = new_data / data_vec.size();

    if (data_vec[moddedData].valid == false){

        data_vec[moddedData].data = new_data;
        data_vec[moddedData].valid = true;
        cout << "Number " << new_data << " Placed to index " << moddedData << " (Direct)" << endl;

    }else{
        cout << "Number " << new_data << " CRASH " << moddedData << " (Created Tree)" << endl;


        vector<node*> tree_vec;
        int indextutucu = moddedData;
        int sagsol = 0;

        while (1){

            //Ilk node u olustur
            int moddedData = new_data % data_vec.size();
            int quotientData = new_data / data_vec.size();

            node* anaNodum = new node(tree_vec.size(), indextutucu);  //6.index
            cout << "NODE : INDEX: " << tree_vec.size() << "| DATA:" << indextutucu << endl;
            tree_vec.push_back(anaNodum);

               //Saga gidecek ilk seferde 0 oldugundan
                indextutucu += quotientData;                   //quotient kadar arttir
                indextutucu = indextutucu % data_vec.size();                 //Data vec boyutunu asmasin modla onu
                node* newnode = new node(tree_vec.size(), indextutucu);
                cout << "NODE : INDEX: " << tree_vec.size() << "| DATA:" << indextutucu << endl;

                if(sagsol%2){
                    anaNodum->left = newnode;
                }else{
                    anaNodum->right = newnode;
                }

                tree_vec.push_back(newnode);

                if(data_vec[indextutucu].valid == false){
                    cout << "Number " << new_data << " Placed " << indextutucu << " (LEFT FINISH)" << endl;
                    data_vec[indextutucu].valid = true;
                    data_vec[indextutucu].data = new_data;
                    break;

                }else{

                    break;

                }

            }   //While Kapat

        sagsol ++;
    }

}



int BDT::find_num_probes(int key) const {

    int moddedData = key % data_vec.size();
    int quotientData = key / data_vec.size();
	int probes = 1;
	while (data_vec[moddedData].data != key){

		moddedData = (moddedData + quotientData) % data_vec.size();
		probes++;

	}

	return probes;
}



double BDT::find_average_num_probes() const {

	int totalProbes = 0;
	int totalValid = 0; //Total valid count
	for (int i = 0; i < data_vec.size(); i++){
		if (data_vec[i].valid){	//Data valid ise
            totalValid++; //Total valid count
			totalProbes += find_num_probes(data_vec[i].data);
			//cout << "For number " << data_vec[i].data << " Probe: " << find_num_probes(data_vec[i].data) << endl;
		}

	}

	return (double)totalProbes/(double)totalValid;	//Probs toplamýný satýr sayýsýna bol

}
