#include <iostream>
#include "brent.h"
using namespace std;

Brent::Brent(int table_size){

    for (int i=0; i < table_size ; i++){
        data_vec.push_back (entry()); //Boþ lisch_entry ile doldur
    }

}


void Brent::insert(int new_data){

    int moddedData = new_data % data_vec.size();
    int quotientData = new_data / data_vec.size();

    int costWithoutSwap = 1;

    if (data_vec[moddedData].valid == false){

        data_vec[moddedData].data = new_data;
        data_vec[moddedData].valid = true;
        //cout << "Number " << new_data << " Placed to index " << moddedData << " (Direct)" << endl;

    }else{
        int costCount = 1;
        while (data_vec[moddedData].valid) {    //While found invalid one
            costCount++;
            moddedData = (moddedData + quotientData) % data_vec.size(); //Her seferinde quotient kadar arttır eğer vector size aşılırsa mod al
        }

        int normalAccessProb = costCount;
        //cout << "Number " << new_data << " -------- Normalde erisme hizi --------  " << normalAccessProb << endl;

        //-----------Denenmesi gereken sayilari array e yaz-----------
        moddedData = new_data % data_vec.size();    //MODDEDDATARESET
        int testtable[data_vec.size()][2] = {{0}}; //2 dim array first element sayi 2. element prob count
        int ii = 0;
         //cout << "Number " << new_data << " -------- SIRADAKILER --------  ";
         while (data_vec[moddedData].valid) {    //While found invalid one
                //cout << data_vec[moddedData].data << ",";
                testtable[ii][0] = data_vec[moddedData].data;
                moddedData = (moddedData + quotientData) % data_vec.size(); //Her seferinde quotient kadar arttır eğer vector size aşılırsa mod al
                ii++;
            }
        //cout << endl;

        //Denenmesi gereken her sayiyi dene

        int jj = 0;

        while (1){
            if (testtable[jj][0] == 0) { break; }   //Boş yere denk geldiyse bitir
            //cout << "Number " << new_data << " -------- Test Sonuclari -------- " << " Sayi " << testtable[jj][0] << " Bedel: " << find_moving_cost(testtable[jj][0]) -1 <<  " + " << jj+1<< endl;
            testtable[jj][1] = find_moving_cost(testtable[jj][0]) - 1 + jj+1;
            jj++;
        }


        //En iyi placement i bul

        int kk = 0;
        int isSwapEnabled = 0;
        int swapleneceksayi = 0;
        int minim= normalAccessProb;
        while (1){
            if (testtable[kk][0] == 0) { break; }

            if (testtable[kk][1] < minim){
                isSwapEnabled = 1;
                minim = testtable[kk][1];
                swapleneceksayi = testtable[kk][0];
            }
            kk++;
        }

        //-----------SWAP YAP YADA YAPMA ARTIK-----------

        if (isSwapEnabled){
        int s;
         for (s = 0; s < data_vec.size(); s++){
                if (data_vec[s].data == swapleneceksayi) { break; } //Swaplanacak sayinin indexini tespit et      s        icine yaz
         }

        //cout << "SWAP 1 :Kaldirilan Data: " << swapleneceksayi << " | Yazilan Data: " << s << " indexine " <<  new_data << " yazildi" << endl;
        data_vec[s].data = new_data;    //ILK SWAP


        moddedData = swapleneceksayi % data_vec.size();
        quotientData = swapleneceksayi / data_vec.size();

        int swaplenecekSayiProb;
        int zaa = 0;

        while (1){  // İstenen sayinin probunu bul
                if (testtable[zaa][0] == swapleneceksayi) { swaplenecekSayiProb = testtable[zaa][1]; break; } //Swaplanacak sayinin indexini tespit et      s        icine yaz
                zaa++;
         }

        int yeniYer = (moddedData + ( quotientData * (swaplenecekSayiProb-1) ) ) % data_vec.size();;

        data_vec[yeniYer].data = swapleneceksayi;
        data_vec[yeniYer].valid = 1;
        //cout << "SWAP 2 : Index " << yeniYer << "'e " << swapleneceksayi << " koyuldu" << endl;


        }else{                          //Cost Kotu ise swap yapma direkt koy

            //-----STANDART LQ PLACEMENT PART-----
            while (data_vec[moddedData].valid) {    //While found invalid one
                moddedData = (moddedData + quotientData) % data_vec.size(); //Her seferinde quotient kadar arttır eğer vector size aşılırsa mod al
            }

            data_vec[moddedData].data = new_data;
            data_vec[moddedData].valid = true;
            //cout << "Number " << new_data << " Placed to index " << moddedData << " (They are Equal or worse)" << endl;
            //-------------------------------------

        }


    }

}

int Brent::find_num_probes(int key) const{

    int moddedData = key % data_vec.size();
    int quotientData = key / data_vec.size();
	int probes = 1;
	while (data_vec[moddedData].data != key){

		moddedData = (moddedData + quotientData) % data_vec.size();
		probes++;

	}

	return probes;
}

double Brent::find_average_num_probes() const{

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

int Brent::find_moving_cost(int key) const{

        int quotientData = key / data_vec.size();

         int s;
         for (s = 0; s < data_vec.size(); s++){
                if (data_vec[s].data == key) { break; } //Swaplanacak sayinin indexini tespit et      s        icine yaz
         }


        int costCount = 1;
        while (data_vec[s].valid) {    //While found invalid one
            costCount++;
            s = (s + quotientData) % data_vec.size(); //Her seferinde quotient kadar arttır eğer vector size aşılırsa mod al
        }
return costCount;
}
