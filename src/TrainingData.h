/*
 * TrainingData.h
 *
 *  Created on: Dec 7, 2016
 *      Author: valerio
 */

#ifndef TRAININGDATA_H_
#define TRAININGDATA_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef std::vector<double> t_vals;

class TrainingData {
private:
	ifstream m_trainingDataFile;
public:
	TrainingData(const std::string filename);
	bool isEof(void) { return m_trainingDataFile.eof(); }
	void getTopology(std::vector<unsigned> &topology);

	// Returns the number of input values read from the file:
	unsigned getNextInputs(t_vals &inputVals);
	unsigned getTargetOutputs(t_vals &targetOutputVals);
	void reset();
	virtual ~TrainingData();
};

#endif /* TRAININGDATA_H_ */
