/*
 * NeuralNetworkMutational.cpp
 *
 *  Created on: 23.02.2021
 *      Author: jannes
 */

#include "NeuralNetworkMutational.h"
#include "../Math.h"

NeuralNetworkMutational::~NeuralNetworkMutational() { }

void NeuralNetworkMutational::Mutate(float highest, float lowest)
{
	// every connection adds a random number to its weight between heighest and lowest
	for(auto &hiddenLayer : m_hiddenNeurons)
		for(auto &hiddenNeuron : *hiddenLayer)
			for(auto &connection : hiddenNeuron->getConnections())
				connection->SetWeight(connection->getWeight() + Math::frand(lowest, highest));

	for(auto &outputNeuron : m_outputNeurons)
		for(auto &connection : outputNeuron->getConnections())
			connection->SetWeight(connection->getWeight() + Math::frand(lowest, highest));
}
