#include <iostream>
#include <vector> //Estava a dar erro aqui nao sei pq
#include <sndfile.hh>
#include "wav_hist.h"

using namespace std;

constexpr size_t FRAMES_BUFFER_SIZE = 65536; // Buffer for reading frames

int main(int argc, char *argv[]) {

    SndfileHandle sndFile { argv[argc-2] };
	if(sndFile.error()) {
		cerr << "Error: invalid input file\n";
		return 1;
    }

	string mode { argv[argc-1] };
	if((mode != "Avg") && (mode != "Difference")) {
		cerr << "Invalid mode, try Avg or Difference\n";
		return 1;
	}

    size_t nFrames;
	vector<short> samples(FRAMES_BUFFER_SIZE * sndFile.channels());
	WAVHist hist { sndFile };
	while((nFrames = sndFile.readf(samples.data(), FRAMES_BUFFER_SIZE))) {
		//std::cout << samples[0];
		samples.resize(nFrames * sndFile.channels());
		//hist.update(samples);
		hist.average(samples);
		hist.difference(samples);
	}

	if (mode == "Avg"){
		hist.dumpAvg();
	}else{
		hist.dumpDifference();
	}
    return 0;
}   