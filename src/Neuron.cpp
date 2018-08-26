/*
 * Neuron.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: valerio
 */

#include "Neuron.h"

Neuron::Neuron(unsigned int index, unsigned int numOfOutputs) {
	// TODO Auto-generated constructor stub
	this->index = index;
	for (int i = 0; i < numOfOutputs; i++) {
		weights.push_back(randomWeight());
	}
	this->output = 0.;
	this->delta = 0.;
}

Neuron::Neuron(unsigned int index, unsigned int numOfOutputs, double output) {
	// TODO Auto-generated constructor stub
	this->index = index;
	for (int i = 0; i < numOfOutputs; i++) {
		weights.push_back(randomWeight());
	}
	this->output = output;
	this->delta = 0.;
}

double Neuron::randomWeight(void) {
	return rand() / double(RAND_MAX);
}

unsigned int Neuron::getIndex() {
	return this->index;
}

double Neuron::getWeightAt(int index) const {
	return this->weights.at(index);
}

void Neuron::setWeightAt(unsigned int index, double value) {
	this->weights.at(index) = value;
}

double Neuron::getDelta() const {
	return this->delta;
}

void Neuron::setDelta(double value) {
	this->delta = value;
}

Neuron::~Neuron() {
	// TODO Auto-generated destructor stub
}

