//compilar ---> g++ BitStream.cpp encoder.cpp -o ex7encoder
//         ---> ./ex7encoder ex7.txt ex7convertido.bin
#include <iostream>
#include <fstream>
#include "BitStream.h"

using namespace std;


int main(int argc, char *argv[])
{
    //Command line arguments processing
    if(argc != 3){
        cout << "\033[1;31mError: Usage sintax is ./p2 <input filename> <output filename>\033[0m" << endl;
        return 0; 
    }

    //Filename variables definition and atribution
    char *ifilename = argv[1];
    char *ofilename = argv[2];

    BitStream inputFile(ifilename,'r');
    BitStream outputFile(ofilename,'w');

    int n=45;
    char array[n];
    char array2[45];
    int j = 0;
    int c;

    printf("valores do conteúdo do ficheiro ex7.txt em binário: \n");
    while(!inputFile.eof()){
        array[j] = inputFile.readBit();
        c++;
        array2[j] = array[j];
        if(j%8 == 0 && j!=0){
            printf("\n");
        }
        printf("%d", array[j]);
        j++;
    }
    printf("\n");
    inputFile.close();

    
    // for (int i=0; i<j;i++){
    //     printf("%d", array2[i]);
    // }
    // printf("\n");
    //não sei se isto está bem, pq n sei ir ver o conteúdo de um arquivo em binário 
    //escrever os bits lidos num arquivo binário
    ofstream out;
    out.open(ofilename);
    if(!out.good()){
            return -1;
    }
    else{
        cout << "Arquivo Criado";
        printf("\n");
    }
    for(int i=0; i<j;i++){
        out << array[i];
    }
    

    out.close();



    return 0;
}