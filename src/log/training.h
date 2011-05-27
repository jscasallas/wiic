#ifndef TRAINING_H
#define TRAINING_H

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "sample.h"
#include "accsample.h"
#include "gyrosample.h"

using namespace std;

/**
 * Class Training to save the individual training of a gesture  
 */
class Training
{
public:
	/**
	 * Constructor void
	 */
	Training() { }
	~Training();

	bool loadTraining(ifstream&);
	void save(ofstream&) const;
	void addSample(Sample*);
	void clear();

	inline const Sample* sampleAt(unsigned int i) const { 
		if(i < samples.size())
			return samples[i]; 
		else {
			cout << "[Error]: requested out of array bound index in training." << endl;
			return 0;
		}
	}

	inline Sample* sampleAt(unsigned int i) { 
		if(i < samples.size())
			return samples[i]; 
		else {
			cout << "[Error]: requested out of array bound index in training." << endl;
			return 0;
		}
	}

	inline unsigned int size() const { return samples.size(); }

private:
	vector<Sample*> samples;
	struct timeval timestamp; // Training timestamp (beginning of the gesture)
};

#endif
