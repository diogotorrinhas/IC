#ifndef WAVHIST_H
#define WAVHIST_H

#include <iostream>
#include <vector>
#include <map>
#include <sndfile.hh>

class WAVHist {
  private:
	std::vector<std::map<short, size_t>> counts;
	std::map<short, size_t> avg;
	std::map<short, size_t> diff;

  public:
	WAVHist(const SndfileHandle& sfh) {
		counts.resize(sfh.channels());
	}

	void update(const std::vector<short>& samples) {
		size_t n { };
		for(auto s : samples)
			counts[n++ % counts.size()][s]++;
	}

	void dump(const size_t channel) const {
		for(auto [value, counter] : counts[channel])
			std::cout << value << '\t' << counter << '\n';
	}
	
	// void dumpAvgChannels(){
	// 	//Se houver mais do que 2 canais
	// 	//counts.resize(2);
	// 	std::map<short, size_t> avgMono;
	// 	std::vector<short> sampleAvg;
	// 	//std::vector<std::map<short, size_t>> avg;
	// 	//size_t L;
	// 	//size_t R;
	// 	size_t sampleL = 0;
	// 	size_t sampleR = 0;	
	// 	int counterL = 0; //indexL
	// 	int counterR = 0; //indexR
	// 	size_t mono = 0;
	// 	//Se houver no maximo dois canais não é preciso fazer o resize
	// 	// if (counts.size() != 2){
	// 	// 	//cerr << "Audio não é stereo, numero de canais diferente de dois";
	// 	// 	counts.resize(2);
	// 	// }
			
	// 	for(auto val:counts[0]){ //channel 0
	// 		//L = val.second;
	// 		//std::cout << L;
	// 		sampleL = val.first;
	// 		for(auto element: counts[1]){	//channel 1
	// 			if (counterL == counterR){
	// 				sampleR = element.first;
	// 				//R = element.second;
	// 				counterR++;
	// 				break;
	// 			}
	// 		}
	// 		counterL++;
	// 		mono = (sampleL+sampleR)/2;

	// 		//calcular o valor mono
	// 		//avg.insert({val.first,mono});
	// 		sampleAvg.push_back(mono);
	// 		//std::cout<<sampleAvg;
	// 	}
	// 	//Calcular o histograma
	// 	for(size_t i = 0; i < sampleAvg.size(); i++){
	// 		short sample = sampleAvg[i];
	// 		if (avgMono.count(sample) == 0){
	// 			int counter = 1;
	// 			for(size_t j = i+1; j < sampleAvg.size(); j++){
	// 				if (sample == sampleAvg[j]){
	// 					counter = counter + 1;
	// 				}
	// 			}
	// 			avgMono.insert({sample,counter});
	// 		}
	// 	}
	// 	//Print histograma
	// 	for(auto [value, counter] : avgMono){
	// 		std::cout << value << '\t' << counter << '\n';
	// 	}
	// }

	void average(const std::vector<short>& samples){
		size_t mono = 0;
		std::vector<short> monoSampleAvg;
		//std::map<short, size_t> avg;
		for(size_t i = 0; i < samples.size(); i=i+2){
			// std::cout<<"L:\t";
			// std::cout<< samples[i];
			// std::cout<<"\n";
			// std::cout<<"R:\t";
			// std::cout<< samples[i+1];
			// std::cout<<"\n";
			// std::cout<<"Mono:\t";
			mono = (samples[i] + samples[i+1])/2;
			//std::cout<<mono;
			//std::cout<<"\n";
			monoSampleAvg.push_back(mono);
			avg[mono]++;
		}
		//Calcular histograma
		// for(size_t i = 0; i < monoSampleAvg.size(); i++){
		// 	short sample = monoSampleAvg[i];
		// 	// std::cout<<"Sample in monoSampleAvg:\n";
		// 	// std::cout<<sample;
		// 	// std::cout<<"\n";
		// 	if (avg.count(sample) == 0){ //ainda nao tem este valor no histograma
		// 		int counter = 1;
		// 		for(size_t j = i+1; j < monoSampleAvg.size(); j++){
		// 			if (sample == monoSampleAvg[j]){
		// 				counter = counter + 1;
		// 			}
		// 		}
		// 		avg.insert({sample,counter});
		// 	}
		// }
	}
	
	void dumpAvg(){
		for(auto [value, counter] : avg){
			std::cout << value << '\t' << counter << '\n';
		}
	}

	//TESTAR
	void difference(const std::vector<short>& samples){
		size_t mono = 0;
		std::vector<short> monoSampleDiff;
		//std::map<short, size_t> avg;
		for(size_t i = 0; i < samples.size(); i=i+2){
			mono = (samples[i] - samples[i+1])/2;;
			monoSampleDiff.push_back(mono);
			diff[mono]++;
		}
		// //Calcular histograma
		// for(size_t i = 0; i < monoSampleDiff.size(); i++){
		// 	short sample = monoSampleDiff[i];
		// 	if (diff.count(sample) == 0){ //ainda nao tem este valor no histograma
		// 		int counter = 1;
		// 		for(size_t j = i+1; j < monoSampleDiff.size(); j++){
		// 			if (sample == monoSampleDiff[j]){
		// 				counter = counter + 1;
		// 			}
		// 		}
		// 		diff.insert({sample,counter});
		// 	}
		// }
	}

	void dumpDifference(){
		for(auto [value, counter] : diff){
			std::cout << value << '\t' << counter << '\n';
		}
	}
};

#endif

