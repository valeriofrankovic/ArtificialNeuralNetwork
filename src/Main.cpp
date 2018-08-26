/*
 * Main.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: valerio
 */

#include <iostream>
#include <vector>
#include "Net.h"
#include "TrainingData.h"

#define numOfPasses 100000

using namespace std;

void showVectorVals(std::string label, std::vector<double> &v) {
	std::cout << label << " ";
	for (unsigned i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";

	std::cout << std::endl;
}

int main() {
	TrainingData trainData("trainsample/out_xor.txt");
	std::vector<unsigned> topology;
	trainData.getTopology(topology);
	Net aNN(topology);

	vector<double> inputVals, targetVals, resultVals;
	int trainingPass = 0;

	while (trainingPass < numOfPasses) {
		++trainingPass;
		std::cout << std::endl << "Pass " << trainingPass << std::endl;

		while (!trainData.isEof()) {
			// Get new input data and feed it forward:
			if (trainData.getNextInputs(inputVals) != topology[0]) {
				break;
			}

			//showVectorVals("Inputs:", inputVals);
			aNN.feedForward(inputVals);

			// Collect the net's actual output results:
			aNN.getResults(resultVals);
			showVectorVals("Outputs:", resultVals);

			// Train the net what the outputs should have been:
			trainData.getTargetOutputs(targetVals);
			showVectorVals("Targets:", targetVals);

			aNN.backpropagation(targetVals);

			// Report how well the training is working, average over recent samples:
			std::cout << "Net current error: " << aNN.getError() << std::endl;
			std::cout << "Net recent average error: " << aNN.getRecentAverageError() << std::endl;
			std::cout << endl;

		}

		trainData.reset();


	}

	std::cout << std::endl << "Done" << std::endl;

	if (topology[0] == 2) {
		std::cout << "TEST" << std::endl;
		std::cout << std::endl;

		unsigned dblarr_test[4][2] = { {0,0}, {0,1}, {1,0}, {1,1} };

		for (unsigned i = 0; i < 4; ++i) {
			inputVals.clear();
			inputVals.push_back(dblarr_test[i][0]);
			inputVals.push_back(dblarr_test[i][1]);

			aNN.feedForward(inputVals);
			aNN.getResults(resultVals);

			showVectorVals("Inputs:", inputVals);
			showVectorVals("Outputs:", resultVals);

			std::cout << std::endl;
		}

		std::cout << "/TEST" << std::endl;
	}
}
