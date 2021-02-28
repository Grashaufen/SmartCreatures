/*
 * NeuralNetworkMutational.h
 *
 *  Created on: 23.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_NEURALNETWORKMUTATIONAL_H_
#define NEURALNETWORK_NEURALNETWORKMUTATIONAL_H_

#include "NeuralNetwork.h"

class NeuralNetworkMutational : public NeuralNetwork
{
public:
	virtual ~NeuralNetworkMutational() = 0;

	virtual void Mutate(float highest, float lowest);
};

#endif /* NEURALNETWORK_NEURALNETWORKMUTATIONAL_H_ */
