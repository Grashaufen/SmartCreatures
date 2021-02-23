/*
 * NeuralNetworkMutational.cpp
 *
 *  Created on: 23.02.2021
 *      Author: jannes
 */

#include "NeuralNetworkMutational.h"
#include "../Math.h"


void NeuralNetworkMutational::Mutate(float highest, float lowest)
{
	// every connection adds a random number to its weight between heighest and lowest
	for(unsigned int i = 0; i < m_hiddenNeurons.size(); i++)
			for(unsigned int j = 0; j < m_hiddenNeurons[i]->getConnections().size(); j++)
				m_hiddenNeurons[i]->getConnections().at(j)->SetWeight(
						m_hiddenNeurons[i]->getConnections().at(j)->getWeight() + Math::frand(lowest, highest));

	for(unsigned int i = 0; i < m_outputNeurons.size(); i++)
			for(unsigned int j = 0; j < m_outputNeurons[i]->getConnections().size(); j++)
				m_outputNeurons[i]->getConnections().at(j)->SetWeight(
						m_outputNeurons[i]->getConnections().at(j)->getWeight() + Math::frand(lowest, highest));
}
