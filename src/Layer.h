/*
 * Layer.h
 *
 *  Created on: Dec 9, 2016
 *      Author: valerio
 */

#ifndef LAYER_H_
#define LAYER_H_

#include "Neuron.h"

class Layer {
protected:
	vector<Neuron> layer;
public:
	Layer(unsigned int numOfNeurons, unsigned int numOfOutputs, bool b);
	int size(void) { return this->layer.size(); }
	int getNumOfOutputs();
	virtual ~Layer();

	Neuron& get(unsigned int index) {
		return layer.at(index);
	}
};

#endif /* LAYER_H_ */
