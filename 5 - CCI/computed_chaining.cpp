#include <iostream>
#include "computed_chaining.h"
using namespace std;

void ComputedChaining::insert(int key){

    int moddedData = key % data.size();  // Take mod of the data with table size
    int quotientData = key / data.size();

    if (data[moddedData].valid == false){   //--------------------------------------------------------------------->MODDED BOS ISE ORAYA YERLESTIR
        data[moddedData].key = key;
        data[moddedData].valid = true;
        data[moddedData].plink = -1;
       cout << "\nNumber " << key << " Placed to index " << moddedData << " (Space Free)" << endl;
    }else{                                  //--------------------------------------------------------------------->MODDED DOLU ISE (VALID ISE) PLINK BOS ISE

        if (data[moddedData].plink == -1){  //PLINK BOS ISE

            int quotientOfPlacedNum = data[moddedData].key / data.size();  //Eklenecek olan konumdaki anahtarin arttirim degeri

            //Find free place
            int freeplace = moddedData;
            int kacKezDondum = 0;
            while(data[freeplace].valid == true){   //Boþ yer bulana kadar dön
                freeplace = (freeplace + quotientOfPlacedNum) % data.size();
                kacKezDondum ++;
            }

            //Datayi yerine koy
            data[freeplace].key = key;
            data[freeplace].valid = true;
            data[freeplace].plink = -1;

            //Onu gösteren linki set et

            data[moddedData].plink = kacKezDondum;


            cout << "\nNumber " << key << " Placed to index " << freeplace << " (Plink Free)" << endl;

        }else{                                                      //---------------------------------------------------------------------> PLINK DOLU ISE


            if (data[moddedData].key % data.size() == moddedData)  {//---------------------------------------------------------------------> O YERDE BULUNAN KEY KENDI EVINDEYSE

                //Find the null offset to place num

                int KeyinGosterdigiIndex = ((data[moddedData].key % data.size()) + (data[moddedData].plink * data[moddedData].key / data.size())) % data.size();  //modofplacednumber + (plink * arttirimsayisi) sonra mod table size
                int freeplink = KeyinGosterdigiIndex;
                while(data[freeplink].plink != -1){  //Bos plink bulana kadar dön
                    freeplink = ((data[moddedData].key % data.size()) + (data[moddedData].plink * data[moddedData].key / data.size())) % data.size();
                }

                //Þimdi PLINK BOS ISE kýsmý gibi davran ve sayiyi yerlestir (freeflink i kullan)

                //Yukarýdan alinan Fonksiyon

                //---------------------------------------------------------------------------------------

                int quotientOfPlacedNum = data[freeplink].key / data.size();  //Eklenecek olan konumdaki anahtarin arttirim degeri

                //Find free place
                int freeplace = freeplink;
                int kacKezDondum = 0;
                while(data[freeplace].valid == true){   //Boþ yer bulana kadar dön
                    freeplace = (freeplace + quotientOfPlacedNum) % data.size();
                    kacKezDondum ++;
                }

                //Datayi yerine koy
                data[freeplace].key = key;
                data[freeplace].valid = true;
                data[freeplace].plink = -1;

                //Onu gösteren linki set et

                data[freeplink].plink = kacKezDondum;

                //---------------------------------------------------------------------------------------

                cout << "\nNumber " << key << " Placed to index " << freeplace << " (Own Home -> Plink Full -> Plink Free)" << endl;



            }else{                          //---------------------------------------------------------------------------------------------> KENDI EVINDE DEGILSE


                //Find the index mod and numbers comes after this key (find them with trace plink)
                vector<int> removed_keys;
                int removedKeyIndex = moddedData;
                while(data[removedKeyIndex].plink != -1){  //Bos plink bulana kadar dön

                    cout << "Number " << data[removedKeyIndex].key << " added to removed_keys()" << endl;
                    removed_keys.push_back(data[removedKeyIndex].key);
                    data[removedKeyIndex].key = 999;                    //REMOVE NUMBER
                    data[removedKeyIndex].valid = false;                //REMOVE NUMBER
                    data[removedKeyIndex].plink = -1;                   //REMOVE NUMBER


                    removedKeyIndex =  (removedKeyIndex +(data[removedKeyIndex].plink * data[removedKeyIndex].key / data.size())) % data.size();

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

                //Silinen Sayilari Tekrar Yerlestir



                    int rmkey = removed_keys[0];

                    int moddedData_rmkey = rmkey % data.size();  // Take mod of the data with table size
                    int quotientData_rmkey = rmkey / data.size();

                    int kacKezDondum = 0;
                    int placement = data[moddedData_rmkey].key;

                    while(data[placement].valid == true){   //Boþ yer bulana kadar dön
                        placement = (placement + data[moddedData_rmkey].key / data.size()) % data.size();   //Silinen keyin modunda bulunan sayýnýn quatienti kadar arttir hep !!!
                        kacKezDondum ++;

                    }

                    //Datayi yerine koy
                    data[placement].key = rmkey;
                    data[placement].valid = true;
                    data[placement].plink = -1;

                    //Onu gösteren linki set et

                    data[moddedData_rmkey].plink = kacKezDondum;

                    cout << "\nNumber " << rmkey << " Placed to index " << placement << " (Removed Key Type 1)" << endl;


                for (int i=1 ; i < removed_keys.size() ; i++){


                    int quotientOfPlacedNum = data[placement].key / data.size();  //Eklenecek olan konumdaki anahtarin arttirim degeri

                    //Find free place
                    int freeplace = placement;
                    int kacKezDondum = 0;
                    while(data[freeplace].valid == true){   //Boþ yer bulana kadar dön
                        freeplace = (freeplace + quotientOfPlacedNum) % data.size();
                        kacKezDondum ++;
                    }

                    //Datayi yerine koy
                    data[freeplace].key = removed_keys[i];
                    data[freeplace].valid = true;
                    data[freeplace].plink = -1;

                    //Onu gösteren linki set et

                    data[placement].plink = kacKezDondum;


                    cout << "\nNumber " << removed_keys[i] << " Placed to index " << freeplace << " (Removed Key Type 2)" << endl;


                }

            }






        }


    }

}
