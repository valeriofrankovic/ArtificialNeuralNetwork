/*
 * Layer.cpp
 *
 *  Created on: Dec 9, 2016
 *      Author: valerio
 */

#include "Layer.h"

// b za bias, ako true onda stori i bias, ako false, onda ne
Layer::Layer(unsigned int numOfNeurons, unsigned int numOfOutputs, bool b) {
	// TODO Auto-generated constructor stub
	int i = 0;
	for (; i < numOfNeurons; i++) {
		this->layer.push_back(Neuron(i, numOfOutputs));
	}
	if (b) {
		Neuron bias = Neuron(i, numOfOutputs, 1);
		this->layer.push_back(bias);
	}

}


int Layer::getNumOfOutputs() {
	return this->layer.at(0).getNumOfOutputs();
}

Layer::~Layer() {
	// TODO Auto-generated destructor stub
}

