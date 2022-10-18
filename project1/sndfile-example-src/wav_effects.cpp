#include <iostream>
#include "AudioFile.h"
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    //Command line arguments processing
    if(argc != 3){
        cout << "\033[1;31mError: Usage sintax is ./p3 <input filename> <output filename>\033[0m" << endl;
        return 0; 
    }
    char *inputfile = argv[1];
    char *outputfile = argv[2];

    //Audiofile Object
    AudioFile<double> af;
    af.shouldLogErrorsToConsole(false);
    //Load audiofile
    if(af.load (inputfile) == 0){
        cout << "\033[1;31mERROR: File doesn't exist or otherwise can't load file\033[0m" << endl;
        return 0; 
    }
    //Get numSamples per Channel
    int numSamples = af.getNumSamplesPerChannel();
    //Get num Channels
    int numChannels = af.getNumChannels();
    
    AudioFile<double> output;
    // Set both the number of channels and number of samples per channel of output
    output.setAudioBufferSize (numChannels, numSamples);
    // Set the number of samples per channel of output
    output.setNumSamplesPerChannel (numSamples);
    // Set the number of channels of output
    output.setNumChannels (numChannels);
    // Set Sample Rate
    output.setSampleRate(af.getSampleRate());
    // Set Bit Depth
    output.setBitDepth(af.getBitDepth());
    
    //Buffer to store samples
    AudioFile<double>::AudioBuffer buffer;
    buffer.resize(numChannels);
    for(int i = 0; i < numChannels; i++)
        buffer[i].resize(numSamples);

    //Ganho
    double alfa=0.8;    //Podemos mudar este valor, variando entre 0 e 1

    //atraso do eco de 1 
    int a=1;        //Podemos aumentar ou diminuir atraso

    //Copy samples from one buffer to another
    for(int j = 0; j < numChannels; j++){
        for(int i = 0; i < numSamples; i++){

            // DESCOMENTAR O TIPO QUE QUEREMOS

            //Eco
            //buffer[j][i+1] = af.samples[j][i+1] + alfa*af.samples[j][i+1-a] ;
    
            //Múltiplos Ecos até expoente = 3 , podemos aumentar ou diminui
            buffer[j][i+1] = af.samples[j][i+1] + pow(alfa,1) * af.samples[j][i+1-(a*1)] + pow(alfa,2) * af.samples[j][i+1-(a*2)] + pow(alfa,3) * af.samples[j][i+1-(a*3)];

        }
    }

    //Set audiobuffer
    output.setAudioBuffer(buffer);
    output.save(outputfile);
    cout << "\033[1;34mCopy Successfully!\033[0m" << endl;

    return 0;
}
