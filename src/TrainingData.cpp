/*
 * TrainingData.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: valerio
 */

#include "TrainingData.h"

TrainingData::TrainingData(const std::string filename) {
	// TODO Auto-generated constructor stub
	m_trainingDataFile.open(filename.c_str());
}

void TrainingData::getTopology(std::vector<unsigned> &topology) {
    std::string line;
    std::string label;

    getline(m_trainingDataFile, line);
    std::stringstream ss(line);
    ss >> label;
    if (this->isEof() || label.compare("topology:") != 0) {
        abort();
    }

    while (!ss.eof()) {
        unsigned n;
        ss >> n;
        topology.push_back(n);
    }

    return;
}

unsigned TrainingData::getNextInputs(t_vals &inputVals) {
	inputVals.clear();

	std::string line;
	getline(m_trainingDataFile, line);
	std::stringstream ss(line);

	std::string label;
	ss>> label;
	if (label.compare("in:") == 0)
	{
		double oneValue;

		while (ss >> oneValue)
			inputVals.push_back(oneValue);
	}

	return inputVals.size();
}

unsigned TrainingData::getTargetOutputs(t_vals &targetOutputVals) {
	targetOutputVals.clear();

	std::string line;
	getline(m_trainingDataFile, line);
	std::stringstream ss(line);

	std::string label;
	ss >> label;
	if (label.compare("out:") == 0)
	{
		double oneValue;

		while (ss >> oneValue)
			targetOutputVals.push_back(oneValue);
	}

	return targetOutputVals.size();
}

void TrainingData::reset() {
	m_trainingDataFile.clear(); // clear bad state after eof
	m_trainingDataFile.seekg(0);
	std::string line;
	getline(m_trainingDataFile, line);
}

TrainingData::~TrainingData() {
	// TODO Auto-generated destructor stub
}

