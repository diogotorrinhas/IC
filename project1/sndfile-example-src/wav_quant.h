#ifndef WAVQUANT_H
#define WAVQUANT_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>


class WAVQuant {
  private:
    std::vector<short> quant_samples;

  public:
	WAVQuant(const SndfileHandle& sfh) {
		quant_samples.resize(sfh.channels());
	}

	void quant(const std::vector<short>& samples, size_t num_of_bits) {
        short temp = 0;
		for (auto sample : samples) {
            
            sample = sample >> num_of_bits;
            temp = sample << num_of_bits;       //move bits
            quant_samples.insert(quant_samples.end(), temp);
        }
	}

	void toFile(SndfileHandle sfhOut) const {
        sfhOut.write(quant_samples.data(), quant_samples.size());
		
	}
};

#endif