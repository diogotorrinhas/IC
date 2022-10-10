#include <iostream>
#include <math.h>
#include "AudioFile.h"

using namespace std;

int main(int argc, char* argv[])
{
    //Argumentos da linha de comando 
    if(argc != 3){
        cout << "\033[1;31mError: Usage sintax is ./p8 <orignal filename> <compressed filename>\033[0m" << endl;
        return 0; 
    } 

    char *originalfile = argv[1];
    char *audiofile = argv[2];

    AudioFile<double> originalAF;
    originalAF.shouldLogErrorsToConsole(false);
    //Load original audio file
    if(originalAF.load(originalfile) == 0){
        cout << "\033[1;31mERROR: File doesn't exist or otherwise can't load file\033[0m" << endl;
        return 0; 
    }

    AudioFile<double> certainAF;
    certainAF.shouldLogErrorsToConsole(false);
    //Load certain audio file
    if(certainAF.load(audiofile) == 0){
        cout << "\033[1;31mERROR: File doesn't exist or otherwise can't load file\033[0m" << endl;
        return 0; 
    }
    //Ambos os ficheiros têm de ter o mesmo número de samples
    if(originalAF.getNumChannels() * originalAF.getNumSamplesPerChannel() != certainAF.getNumChannels() * certainAF.getNumSamplesPerChannel() ){
        cout << "\033[1;31mError: Both files must have the same number of samples\033[0m" << endl;
        return 0; 
    }
    
    //Variaveis para calcular o maximum per sample absolute error
    double maxError = 0;
    double tmpError;
    //Obter número total de samples
    double N = (double)originalAF.getNumChannels() * (double)originalAF.getNumSamplesPerChannel();

    //Obter info da audio file
    int numChannels = originalAF.getNumChannels();
    int numSamples = originalAF.getNumSamplesPerChannel();

    //Calcular energia do sinal e do noise, respetivamente
    double D = 0;
    double S = 0;
    for(int j = 0; j < numChannels; j++){
        for(int i = 0; i < numSamples; i++){
            S += pow(originalAF.samples[j][i], 2);                                  //fórmula nas notas de IC, Ex
            D += pow(originalAF.samples[j][i] - certainAF.samples[j][i], 2);        //Er
            tmpError = abs(originalAF.samples[j][i] - certainAF.samples[j][i]);     //per sample absolute error
            //Atualizar maximum per sample absolute error
            if(tmpError > maxError)
                maxError = tmpError;
        }
    }
    
    S = (1/N) * S;   //fórmula nas notas de IC, Px
    D = (1/N) * D;   // Pr
    

    //Calcular Signal-to-Noise ratio (dB)
    double SNR = 10*log10(S/D);                         //fórmula nas notas de IC
    cout << "\033[1;34mSNR: " << SNR << " dB\nMaximum per sample absolute error: " << maxError << "\033[0m" << endl;

    return 0;
}