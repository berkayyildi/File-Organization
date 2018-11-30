#include <iostream>
#include "computed_chaining.h"
using namespace std;

void ComputedChaining::insert(int key){

    int moddedData = key % data.size();  // Take mod of the data with table size

    if (data[moddedData].valid == false){   //--------------------------------------------------------------------->MODDED BOS ISE ORAYA YERLESTIR
        data[moddedData].key = key;
        data[moddedData].valid = true;
        data[moddedData].plink = -1;
        cout << "\nNumber " << key << " Placed to index " << moddedData << " (Space Free)" << endl;
    }else{                                  //--------------------------------------------------------------------->MODDED DOLU ISE (VALID ISE) PLINK BOS ISE


        if (data[moddedData].key % data.size() == moddedData)  {//---------------------------------------------------------------------> O YERDE BULUNAN KEY KENDI EVINDEYSE

            //Find the first number which null offset to place key
            int quatient = data[moddedData].key / data.size();
            if (quatient == 0){quatient = 1;}

            int freeplink;
            if (data[moddedData].plink == -1){  //PLINK BOS ISE
                    freeplink = moddedData;
            }else{                              //PLINK DOLU ISE
                    freeplink = ((data[moddedData].key % data.size()) + data[moddedData].plink * quatient) % data.size();  //modofplacednumber + (plink * arttirimsayisi) sonra mod table size
            }

            while(data[freeplink].plink != -1){  //Bos plink bulana kadar dön
                freeplink = (freeplink + (data[moddedData].plink * quatient)) % data.size();
            }

            //Şimdi PLINK BOS ISE kısmı gibi davran ve sayiyi yerlestir (freeflink i kullan)

            int quotientOfPlacedNum = data[freeplink].key / data.size();  //Eklenecek olan konumdaki anahtarin arttirim degeri
            int freeplace = freeplink;
            int kacKezDondum = 0;
            while(data[freeplace].valid == true){   //Boş yer bulana kadar dön
                freeplace = (freeplace + quotientOfPlacedNum) % data.size();
                kacKezDondum ++;
            }

            //Datayi yerine koy
            data[freeplace].key = key;
            data[freeplace].valid = true;
            data[freeplace].plink = -1;

            //Onu gösteren linki set et

            data[freeplink].plink = kacKezDondum;

            cout << "\nNumber " << key << " Placed to index " << freeplace << " (Own Home)" << endl;

        }else{                          //---------------------------------------------------------------------------------------------> KENDI EVINDE DEGILSE

            //Find the index mod and numbers comes after this key (find them with trace plink)
            vector<int> removed_keys;
            int removedKeyIndex = moddedData;
            while(data[removedKeyIndex].plink != -1){  //Bos plink bulana kadar dön

                cout << "Number " << data[removedKeyIndex].key << " added to removed_keys()" << endl;
                removed_keys.push_back(data[removedKeyIndex].key);
                data[removedKeyIndex].valid = false;                //REMOVE NUMBER
                int removedPlink = data[removedKeyIndex].plink;     //Store Keys Plink
                data[removedKeyIndex].plink = -1;                   //REMOVE NUMBER

                int quatient = data[removedKeyIndex].key / data.size();
                if(quatient == 0){quatient = 1;}

                removedKeyIndex =  (removedKeyIndex +(removedPlink * quatient)) % data.size();

            }

            cout << "Number " << data[removedKeyIndex].key << " added to removed_keys()" << endl;
            removed_keys.push_back(data[removedKeyIndex].key);  //Add last number to the removed_keys here
            data[removedKeyIndex].key = 999;                    //REMOVE NUMBER
            data[removedKeyIndex].valid = false;                //REMOVE NUMBER
            data[removedKeyIndex].plink = -1;                   //REMOVE NUMBER


            //Sayiyi mod degerine koy (orasi bosaltilmisti)

            data[moddedData].key = key;
            data[moddedData].valid = true;
            data[moddedData].plink = -1;
            cout << "\nNumber " << key << " Placed to index " << moddedData << " (Unplaced Mod)" << endl;

            //Silinen Sayilari Bos Yerlere Tekrar Yerlestir

            int position = removed_keys[0] % data.size();           //Silinen ilk keyin quatienti
            int old_position = position;

            for (int i=0 ; i < removed_keys.size() ; i++){

                int startquatient = data[position].key / data.size();
                int kacKezDondum = 0;
                position = (position + (kacKezDondum * startquatient)) % data.size();   //ilk seferinde 0 gelicek position = position olacak sonra hep ustune ekleyerek gidicek

                while(data[position].valid == true){   //Boş yer bulana kadar dön
                    position = (position + startquatient) % data.size();
                    kacKezDondum ++;
                    cout << " | " << position;
                }

                //Datayi yerine koy
                data[position].key = removed_keys[i];
                data[position].valid = true;
                data[position].plink = -1;

                //Onu gösteren linki set et

                data[old_position].plink = kacKezDondum;

                //Eski datanin linkini koy ve positionu guncelle
                old_position = position;

                cout << "\nNumber " << removed_keys[i] << " Placed to index " << position << " (Removed Key Placed)" << endl;

            }

        }
    }

}
