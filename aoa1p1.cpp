//
//  BLG335E, Analysis of Algorithms I, Fall 2018
//  Project1
//
//  HUMA KALAYCI
//
//
//  COMPILING
//
//  g++ -std=c++11 aoa1p1.cpp
//
//  ./a.out -algo algorithmType -feature criterion -size N
//
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>

using namespace std;


string** insertionSort(string *arr[42], int n, int feature, string top[42]){
    //TIME SATMP                                        //  COST    TIME
    if(feature==0){
        int i, j, k;                                    //  c1      1
        string key;                                     //  c2      1
        string keyarr[42];                              //  c3      1
        for (i = 1; i < n; i++){                        //  c4      n
            key = arr[i][feature];                      //  c5      n-1
            //
            for(k=0;k<42;k++){                          //  c6      (n-1).43
                keyarr[k]= arr[i][k];                   //  c7      (n-1).42
            }
            j = i-1;                                    //  c8      n-1
            while (j >= 0 && arr[j][feature] > key){    //  c9      S
                arr[j+1][feature] = arr[j][feature];    //  c10     S-(n-1)
                //
                for(k=0;k<42;k++){                      //  c11     (S-(n-1)).43
                    arr[j+1][k] = arr[j][k];            //  c12     (S-(n-1)).42
                }
                j = j-1;                                //  c13     S-(n-1)
            }
            arr[j+1][feature] = key;                    //  c14     n-1
            //
            for(k=0;k<42;k++){                          //  c15      (n-1).43
                arr[j+1][k] = keyarr[k];                //  c16      (n-1).42
            }
        }
    }
    //S in worst case, n(n+1)/2-1
    //T(n) = c1+ c2+ c3+ c4.n+ c5(n-1)+ c6(n-1)43+ c7(n-1)43+ c8(n-1)+ c9S+ c10(S-(n-1))+ c11(S-(n-1))43+ c12(S-(n-1))42+ c13(S-(n-1))+ c14(n-1)+ c15((n-1)43)+ c16((n-1)42)
    //T(n) =  an2 + bn + c is a quadratic function in worst case
    //  -    O(n2)

    //LAST PRICE
    if(feature==2){
        int i, j, k;
        string key;
        string keyarr[42];
        for (i = 1; i < n; i++){
            key = arr[i][feature];
            //
            for(k=0;k<42;k++){
                keyarr[k]= arr[i][k];
            }
            j = i-1;
            float fkey  = stof(key);
            float farr = stof(arr[j][feature]);
            //            while (j >= 0 && arr[j][feature] > key){
            while (j >= 0 && farr > fkey){
                arr[j+1][feature] = arr[j][feature];
                //
                for(k=0;k<42;k++){
                    arr[j+1][k] = arr[j][k];
                }
                j = j-1;
                if(j>=0)
                    farr = stof(arr[j][feature]);
            }
            arr[j+1][feature] = key;
            //
            for(k=0;k<42;k++){
                arr[j+1][k] = keyarr[k];
            }
        }
    }



    return arr;
}





void merge(string *arr[], int l, int m, int r, int feature)
{
    int i, j, c;
    long int k;
    long int n1 = m - l + 1;
    long int n2 =  r - m;

    //TIME SATMP
    if(feature==0){
        string* L= new string[n1];
        string* R= new string[n2];
        string** Larr;
        string* templ = new string[42 * (n1)];
        Larr = new string*[(n1)];
        for (int i = 0; i < (n1); ++i)
            Larr[i] = (templ + i * 42);
        string** Rarr;
        string* tempr = new string[42 * (n2)];
        Rarr = new string*[(n2)];
        for (int i = 0; i < (n2); ++i)
            Rarr[i] = (tempr + i * 42);
        for (i = 0; i < n1; i++){
            L[i] = arr[l + i][0];
            //
            for(c=0;c<42;c++){
                Larr[i][c] = arr[l + i][c];
            }
        }
        for (j = 0; j < n2; j++){
            R[j] = arr[m + 1+ j][0];
            //
            for(c=0;c<42;c++){
                Rarr[j][c] = arr[m + 1+ j][c];
            }
        }
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2){
            if (L[i] <= R[j]){
                arr[k][0] = L[i];
                //
                for(c=0;c<42;c++){
                    arr[k][c] = Larr[i][c];
                }
                i++;
            }
            else{
                arr[k][0] = R[j];
                //
                for(c=0;c<42;c++){
                    arr[k][c] = Rarr[j][c];
                }
                j++;
            }
            k++;
        }
        while (i < n1){
            arr[k][0] = L[i];
            //
            for(c=0;c<42;c++){
                arr[k][c] = Larr[i][c];
            }
            i++;
            k++;
        }
        while (j < n2){
            arr[k][0] = R[j];
            //
            for(c=0;c<42;c++){
                arr[k][c] = Rarr[j][c];
            }
            j++;
            k++;
        }
    }

    //PRICE
    if(feature==2){
        float fL, fR;
        string* L= new string[n1];
        string* R= new string[n2];
        string** Larr;
        string* templ = new string[42 * (n1)];
        Larr = new string*[(n1)];
        for (int i = 0; i < (n1); ++i)
            Larr[i] = (templ + i * 42);
        string** Rarr;
        string* tempr = new string[42 * (n2)];
        Rarr = new string*[(n2)];
        for (int i = 0; i < (n2); ++i)
            Rarr[i] = (tempr + i * 42);
        for (i = 0; i < n1; i++){
            L[i] = arr[l + i][2];
            //
            for(c=0;c<42;c++){
                Larr[i][c] = arr[l + i][c];
            }
        }
        for (j = 0; j < n2; j++){
            R[j] = arr[m + 1+ j][2];
            //
            for(c=0;c<42;c++){
                Rarr[j][c] = arr[m + 1+ j][c];
            }
        }
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2){
            fL  = stof(L[i]);
            fR  = stof(R[j]);
            if (fL <= fR){
                arr[k][2] = L[i];
                //
                for(c=0;c<42;c++){
                    arr[k][c] = Larr[i][c];
                }
                i++;
            }
            else{
                arr[k][2] = R[j];
                //
                for(c=0;c<42;c++){
                    arr[k][c] = Rarr[j][c];
                }
                j++;
            }
            k++;
        }
        while (i < n1){
            arr[k][2] = L[i];
            //
            for(c=0;c<42;c++){
                arr[k][c] = Larr[i][c];
            }
            i++;
            k++;
        }
        while (j < n2){
            arr[k][2] = R[j];
            //
            for(c=0;c<42;c++){
                arr[k][c] = Rarr[j][c];
            }
            j++;
            k++;
        }
    }
}


string** mergeSort(string *arr[], int a, int b,int feature,string top[42]){
    if (a < b){

        int m = a+(b-a)/2;
        mergeSort(arr, a, m, feature, top);
        mergeSort(arr, m+1, b, feature, top);
        merge(arr, a, m, b, feature);
    }
    return arr;
}





int main(int argc, char** argv){

    clock_t t;

    char* algop;
    char* featurep ;
    char* sizec;

    algop=argv[2];
    featurep=argv[4];
    sizec=argv[6];

    char algo = *algop;
    char feature= *featurep;
    int size ;

    size = atoi(sizec);



    ifstream ip("log_inf.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';
    //
    int count=0;
    int i;
    string top[42];

    //    string thing[size+1][42];

    string** thing;

    // Linear memory allocation
    string* temp = new string[42 * (size+1)];

    thing = new string*[(size+1)];


    for (int i = 0; i < (size+1); ++i){
        thing[i] = (temp + i * 42);
    }


    //reading the first line of csv
    for(i=0; i<41;i++){
        getline(ip,top[i],',');
        //cout<<" i:"<<i<<endl;
        //        cout <<i<<"- "<<top[i] << "\t";
    }
    getline(ip,top[41],'\n');
    //    cout <<i<<"- "<<top[41] << "\n";


    //reading the (size) lines except first line of csv
    while( ip.good() && count < (size) && ip.peek()!=EOF){
        //        cout<<"\ncount:"<<count<<endl;
        for(i=0; i<41;i++){
            getline(ip,thing[count][i],',');
            //cout<<" i:"<<i<<endl;
            //            cout <<i<<"- "<<thing[count][i] << "\t";
        }
        //cout<<"     count:"<<count<<"   i:"<<i<<endl;
        getline(ip,thing[count][41],'\n');
        //        cout <<i<<"- "<<thing[count][41] << "\n";

        count++;
    }
    ip.close();


    //  --------------------------------------------
    t = clock();

    //INSERTION SORT
    if( algo == 'i' ){
        if(feature == 't') //timestamp â€˜tâ€™
//            insertionSort(thing, size,0, top);
            thing = insertionSort(thing, size,0, top);
        if(feature == 'p') //last_price â€˜p
//            insertionSort(thing, size,2, top);
            thing = insertionSort(thing, size,2, top);
    }
    //MERGE SORT
    if( algo == 'm' ){
        if(feature == 't') //timestamp â€˜tâ€™
//            mergeSort(thing, 0, size - 1,0, top);
//            int** my2DArray = create2DArray(height, width);
            thing = mergeSort(thing, 0, size - 1,0, top);
        if(feature == 'p') //last_price â€˜p
//            mergeSort(thing, 0, size - 1,2, top);
            thing = mergeSort(thing, 0, size - 1,2, top);
    }

    t = clock() - t;
    //  ---------------------------------------------

    printf ("It took me %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

        ofstream myfile;
        myfile.open ("output.csv");

        for(i=0; i<41;i++){

            myfile <<top[i] << ",";
        }
        myfile <<top[i] << "\n";

        for (int p=0; p < size; p++){
            for(int r=0;r<41;r++)
                myfile<<thing[p][r]<<",";
            myfile<<thing[p][41]<<"\n";
        }
        myfile.close();


    delete[] thing;

    return 0;

}
