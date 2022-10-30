#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class BitStream {
    private:
   
    std::string name;
    std::fstream file;
    int size;  
    std::string mode;  
    std::vector<int> bitArr; 
    int pointerBit;

    public:
        BitStream(std::string filename, std::string tipo){ 
            name = filename;
            mode = tipo;
            if(tipo == "w"){ // write, mode = 0
                file.open(name, ios::binary | ios::out);
                pointerBit = 0;
            }else if(tipo == "r"){  // read, mode = 1
                file.open(name, std::ios::binary | std::ios::in);
                pointerBit = 0;
                size = getSize();
            }else{ 
                std::cout << "Incorrect mode " << std::endl;
                
            }
        }

        int readBit(){ 
            if(mode == "w") throw runtime_error("Cannot read ");
            if(pointerBit == 0){
                char byte;
                file.read((&byte), 1);
                bitArr = getBit(byte);
            }

            int bit = bitArr[pointerBit];
            pointerBit = (pointerBit + 1) % 8;
            
            return bit;
        }

        std::vector<int> readNbits(int n){
            if(mode == "w") throw runtime_error("Cannot read ");
            std::vector<int> arrayNbits;
        
            for(int i = 0; i < n; i++){
                if(pointerBit == 0){
                    char byte;
                    file.read(&byte, 1);
                    bitArr = getBit(byte);
                }
                arrayNbits.push_back(bitArr[pointerBit]);
                pointerBit++;
                
                if(pointerBit == 8){
                    pointerBit = 0;//reset
                }
            }
            return arrayNbits;
        }

         void writeBit(int bit){
            if(mode == "r") throw runtime_error("Cannot write ");    
           
            if(pointerBit == 8){
                char byte = getByte(bitArr);
                file.write((&byte), 1);            
                pointerBit = 0;//reset 
            }
            
            if(pointerBit == 0){
                bitArr = std::vector<int>(8);
            }
            //Adicionar ao array o bit 
            bitArr[pointerBit] = bit;
            pointerBit++;
        }  

        void writeNbits(std::vector<int> array){    
            if(mode == "r") throw runtime_error("Cannot write ");
            
            int size = array.size();

            // percorrer 
            for(int i = 0; i < size; i++){
                if(pointerBit == 8){
                    char byte = getByte(bitArr);
                    file.write((&byte), 1);            
                    pointerBit = 0;//reset 
                }
               
                if(pointerBit == 0){
                    bitArr = std::vector<int>(8);
                }
                
                bitArr[pointerBit] = array[i];
                pointerBit++;
            }  
        }

        std::vector<int> getBit(char byte){
            std::vector<int> arrayBits;

            for(int i = 7; i >= 0; i--){
                arrayBits.push_back((byte >> i) & 0x01);
            }
            return arrayBits;
        }      

        char getByte(std::vector<int> array){
            char byte = 0;
            int counter = 7;
            for(int i = 0; i < 8; i++){
                byte |= array[i] << counter;
                counter--;
            }
            return byte;
        }

        int getSize() {
            int size;
            file.seekg(0, std::ios::end);
            size=file.tellg();
            file.seekg(0, std::ios::beg);
            return size;
        }

        void close(){
            if(mode == "w"){
                char byte = getByte(bitArr);
                file.write(&byte, 1);
                file.close();
            }
        }
};

#endif