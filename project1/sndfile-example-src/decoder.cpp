//compilar ---> g++ BitStream.cpp decoder.cpp -o ex7decoder
//         ---> ./ex7decoder ex7convertido.bin ex7desconvertido.txt
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

    int i=0;
    int j=0;
    int var=7;
    unsigned char array[1000];
    unsigned char array2[1000];
    
    //lê o ficheiro binário e mete os bits num array
    while(!inputFile.eof()){
        array[i] = inputFile.readBit();
        // print
        if(i==var){
            array2[j] = array[i];
            var = var + 8;
            j++;
        }
        // if(i % 8 == 0 && i != 0)
        //     printf("\n");
        // printf("%d", array[i]);
        i++;
    }

    printf("\n");
    inputFile.close();

    // for (int i=0; i<j;i++){
    //     printf("%d", array2[i]);
    // }

    //converte os bits que estão guardados no array e escreve num ficheiro de texto
    for (int i = 0; i < j; i++){
        outputFile.writeBit(array2[i]);
    }
    cout << "Arquivo Criado";
    printf("\n");
    outputFile.close();
    // não sei como ir ler um ficheiro em binário e por o conteudo num array

    //exemplos
    // char A - 0x41 on ascci table
    // char byte[8] = {0, 1, 0, 0, 0, 0, 0, 1};

    // // char B - 0x42 on ascci table
    // char byte2[8] = {0, 1, 0, 0, 0, 0, 1, 0};


    // for(int i=0; i<8;i++){
    //     outputFile.writeBit(byte[i]);
    // }


    // for(int i=0; i<8;i++){
    //     outputFile.writeBit(byte2[i]);
    // }


    // outputFile.close();


    return 0;
}