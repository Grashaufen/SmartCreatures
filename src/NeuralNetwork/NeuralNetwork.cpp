/*
 * NeuralNetwork.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include "NeuralNetwork.h"

NeuralNetwork::~NeuralNetwork()
{
	// release the memory of the neurons from the heap
	for(unsigned int i = 0; i < m_inputNeurons.size(); i++)
		if(m_inputNeurons[i]) { delete m_inputNeurons[i]; m_inputNeurons[i] = nullptr; }

	for(unsigned int i = 0; i < m_hiddenLayers.size(); i++)
		for(unsigned int j = 0; j < m_hiddenLayers[i]->size(); j++)
			if(m_hiddenLayers[i]->at(j)) { delete m_hiddenLayers[i]->at(j); m_hiddenLayers[i]->at(j) = nullptr; }

	for(unsigned int i = 0; i < m_outputNeurons.size(); i++)
		if(m_outputNeurons[i]) { delete m_outputNeurons[i]; m_outputNeurons[i] = nullptr; }

	// release the memory of the hidden layers
	for(unsigned int i = 0; i < m_hiddenLayers.size(); i++)
		if(m_hiddenLayers[i]) { delete m_hiddenLayers[i]; m_hiddenLayers[i] = nullptr; }

}


void NeuralNetwork::CreateHiddenLayers(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_hiddenLayers.push_back(new std::vector<WorkingNeuron*>());
}

void NeuralNetwork::CreateInputNeurons(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_inputNeurons.push_back(new InputNeuron());
}

void NeuralNetwork::CreateHiddenNeurons(unsigned int layer, unsigned int amount)
{
	if(layer > m_hiddenLayers.size()-1) // the demanded layer does not exist
		return;

	for(unsigned int i = 0; i < amount; i++)
		m_hiddenLayers[layer]->push_back(new WorkingNeuron());
}

void NeuralNetwork::CreateOutputNeurons(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_outputNeurons.push_back(new WorkingNeuron());
}

void NeuralNetwork::CreateFullMesh()
{
	if(m_hiddenLayers.size() == 0) // The neural network hasn`t got any hidden neurons
	{
		for(unsigned int i = 0; i < m_outputNeurons.size(); i++)
		{
			for(unsigned int j = 0; j < m_inputNeurons.size(); j++)
				m_outputNeurons[i]->AddConnection(new Connection(m_inputNeurons[j]));
		}
	}
	else // the neural network has hidden layers
	{
		// connect the hidden neurons with the input neurons
		for(unsigned int i = 0; i < m_hiddenLayers[0]->size(); i++)
			for(unsigned int j = 0; j < m_inputNeurons.size(); j++)
				m_hiddenLayers[0]->at(i)->AddConnection(new Connection(m_inputNeurons[j]));

		// connections between hidden layers
		if(m_hiddenLayers.size() > 1)
			for(unsigned int i = 1; i < m_hiddenLayers.size(); i++)
				for(unsigned int j = 0; j < m_hiddenLayers[i]->size(); j++)
					for(unsigned int k = 0; k < m_hiddenLayers[i-1]->size(); k++)
						m_hiddenLayers[i]->at(j)->AddConnection(new Connection(m_hiddenLayers[i-1]->at(k)));

		// connect the output neurons with the hidden neurons
		for(unsigned int i = 0; i < m_outputNeurons.size(); i++)
			for(unsigned int j = 0; j < m_hiddenLayers[m_hiddenLayers.size()-1]->size(); j++)
				m_outputNeurons[i]->AddConnection(new Connection(m_hiddenLayers[m_hiddenLayers.size()-1]->at(j)));
	}
}

