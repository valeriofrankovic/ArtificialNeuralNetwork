/*
 * Net.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: valerio
 */

#include "Net.h"

Net::Net(const vector<unsigned int> &topology) {
	// TODO Auto-generated constructor stub
	int i = 0;
	for (; i < topology.size() - 1; i++) {
		// svaki broj u topologiji je jedan novi sloj
		// at.(i) je broj neurona u trenutnom sloju, .at(i+1) je broj u sljedecem sloju i sluzi za num of outputs
		layers.push_back(Layer(topology.at(i), topology.at(i+1), true));
	}
	// dodaj posljednji sloj
	// va posljednjem sloju za broj izlaza stavljan jedan, svaki neuron ima jedan delta
	cout << topology.at(i) << endl;
	layers.push_back(Layer(topology.at(i), 1, false));
	m_error = 0.;
	m_recentAverageError = 0.;
}

double Net::activationFunction(double net) {
	return (1. / (1 + exp(-net)));
}

void Net::feedForward(vector<double> &inputVals) {
	Layer &entryLayer = layers.at(0);
	for (int i = 0; i < inputVals.size(); i++) {
		Neuron &n = entryLayer.get(i);
		n.setOutput(inputVals.at(i));
	}
	// korigiram output u skrivenom sloju i izlaznom sloju
	for (int i = 1; i < layers.size(); i++) {
		Layer &currLayer = layers.at(i);
		Layer &prevLayer = layers.at(i-1);
		int layerSize = currLayer.size() - 1;
		if (i == layers.size()-1) layerSize++;
		// tu gre size - 1 zato ca necu korigirat output biasu (size() - 1 je bias)
		for (int j = 0; j < layerSize; j++) {

			// izvlacin neuron i njegov index
			Neuron& currNeuron = currLayer.get(j);
			unsigned int currNeuronIndex = currNeuron.getIndex();

			// postavljan net na nulu
			double net = 0.;

			// racunan w(i) * x(i)
			for (int k = 0; k < prevLayer.size(); k++) {
				Neuron &tempNeuron = prevLayer.get(k);
				net += (tempNeuron.getOutput() * tempNeuron.getWeightAt(currNeuronIndex));
			}

			// pasan kroz sigmoidu
			double output = activationFunction(net);

			// postavin output
			currNeuron.setOutput(output);
		}
	}
}

void Net::backpropagation(vector<double> &outputVals) {
	int i = this->layers.size();
	Layer &zadnjiLayer = this->layers.at(i-1);
	m_error = 0.;
	for (int j = 0; j < outputVals.size(); j++) {
		Neuron &n = zadnjiLayer.get(j);
		double error = outputVals.at(j) - n.getOutput();
		m_error += (error * error);
		double delta = n.getOutput() * (1 - n.getOutput()) * (outputVals.at(j) - n.getOutput());
		n.setDelta(delta);
	}
	m_error /= zadnjiLayer.size();
	m_error = sqrt(m_error); // RMS

	// implement a recent average measurment
	m_recentAverageError = (m_recentAverageError * m_recentAverageSmoothingFactor + m_error) / (m_recentAverageSmoothingFactor + 1.0);

	// i mi sluzi za dohvat preostalih layera pocevsi od i-2 (predzadnjeg)
	// iteriram po neuronima
	for (i = i - 2; i >= 0; i--) {
		Layer &currLayer = this->layers.at(i);
		Layer &succLayer = this->layers.at(i+1);
		int numOfOutputs = currLayer.getNumOfOutputs();
		// iteriraj po svim neuronima
		for (int k = 0; k < currLayer.size(); k++) {
			Neuron &n = currLayer.get(k);
			double sumOfDeltaTimesW = 0.;
			// iteriraj po svim tezinama i namesti in delta
			for (int j = 0; j < numOfOutputs; j++) {
				sumOfDeltaTimesW = sumOfDeltaTimesW + succLayer.get(j).getDelta() * n.getWeightAt(j);
				double newWeight = n.getWeightAt(j) + eta * succLayer.get(j).getDelta() * n.getOutput();
				n.setWeightAt(j, newWeight);
			}
			double delta = n.getOutput() * (1 - n.getOutput()) * sumOfDeltaTimesW;
			n.setDelta(delta);
		}
	}
}

void Net::getResults(vector<double> &resultVals) {
	resultVals.clear();
	int sizeOfOutputLayer = layers.at(layers.size() - 1).size();
	for (unsigned n = 0; n < sizeOfOutputLayer; n++) {
		resultVals.push_back(layers.at(layers.size()-1).get(n).getOutput());
	}
}



Net::~Net() {
	// TODO Auto-generated destructor stub
}

