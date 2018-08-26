/*
 * Net.h
 *
 *  Created on: Dec 7, 2016
 *      Author: valerio
 */

#ifndef NET_H_
#define NET_H_

#include <iostream>
#include <cmath>
#include "Layer.h"

#define eta 0.15
#define m_recentAverageSmoothingFactor 0.0

using namespace std;

class Net {
private:
	vector<Layer> layers;
	double activationFunction(double net);
	double m_error;
	double m_recentAverageError;
public:
	Net(const vector<unsigned int> &topology);
	void feedForward(vector<double> &inputVals);
	void backpropagation(vector<double> &outputVals);
	void getResults(vector<double> &resultVals);
	double getError(void) const { return m_error; }
	double getRecentAverageError(void) const { return m_recentAverageError; }
	virtual ~Net();
};

#endif /* NET_H_ */
