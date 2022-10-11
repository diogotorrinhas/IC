#include <iostream>
#include <vector>
#include <sndfile.hh>
#include "wav_quant.h"

using namespace std;
constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {
    

	if(argc < 4) {
		cerr << "Usage: " << argv[0] << " <input file> <bits> <output_file>\n";
		return 1;
	}

	SndfileHandle sfhIn { argv[argc-3] };
	if(sfhIn.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

    SndfileHandle sfhOut { argv[argc-1],SFM_WRITE, sfhIn.format(),sfhIn.channels(), sfhIn.samplerate() };
	if(sfhOut.error()) {
		cerr << "Error: invalid output file\n";
		return 1;
    }

    int number_of_bits { stoi(argv[argc-2]) };

    vector<short> samples(FRAMES_BUFFER_SIZE * sfhIn.channels());

    WAVQuant quant { sfhIn };

    size_t nFrames;
    while((nFrames = sfhIn.readf(samples.data(), FRAMES_BUFFER_SIZE))) {
        samples.resize(nFrames * sfhIn.channels());
        quant.quant(samples, number_of_bits);
    }
    quant.toFile(sfhOut);
}
