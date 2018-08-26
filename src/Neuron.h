/*
 * Neuron.h
 *
 *  Created on: Dec 7, 2016
 *      Author: valerio
 */

#ifndef NEURON_H_
#define NEURON_H_

#include <vector>
#include <cstdlib>

using namespace std;

class Neuron {
private:
	vector<double> weights;
	double delta;
	unsigned int index; // sluzi da se raspozna ki po redu je u sloju
	double output;
	double randomWeight(void);
public:
	Neuron(unsigned int index, unsigned int numOfOutputs);
	Neuron(unsigned int index, unsigned int numOfOutputs, double output);
	unsigned int getIndex();
	double getWeightAt(int index) const;
	void setWeightAt(unsigned int index, double value);
	double getDelta() const;
	void setDelta(double value);
	virtual ~Neuron();


	int getNumOfOutputs() const {
		return weights.size();
	}

	double getOutput() const {
		return output;
	}

	void setOutput(double value) {
		this->output = value;
	}

};

#endif /* NEURON_H_ */
