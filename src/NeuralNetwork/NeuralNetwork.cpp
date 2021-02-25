/*
 * NeuralNetwork.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include "NeuralNetwork.h"


void NeuralNetwork::CreateHiddenLayers(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_hiddenNeurons.push_back(std::make_unique<std::vector<std::unique_ptr<WorkingNeuron>>>());
}

void NeuralNetwork::CreateInputNeurons(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_inputNeurons.push_back(std::make_unique<InputNeuron>());
}

void NeuralNetwork::CreateHiddenNeurons(unsigned int layer, unsigned int amount)
{
	if(layer > m_hiddenNeurons.size()-1) // the demanded layer does not exist
		return;

	for(unsigned int i = 0; i < amount; i++)
		m_hiddenNeurons[layer]->push_back(std::make_unique<WorkingNeuron>());
}

void NeuralNetwork::CreateOutputNeurons(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_outputNeurons.push_back(std::make_unique<WorkingNeuron>());
}

void NeuralNetwork::CreateFullMesh()
{
	if(m_hiddenNeurons.size() == 0) // The neural network hasn`t got any hidden neurons
	{
		for(auto &outputNeuron : m_outputNeurons)
			for(auto &inputNeuron : m_inputNeurons)
				outputNeuron->AddConnection(std::make_unique<Connection>(dynamic_cast<Neuron*>(inputNeuron.get())));
	}
	else // the neural network has hidden layers
	{
		// connect the first layer of hidden neurons with the input neurons
		for(auto &hiddenNeuron : *m_hiddenNeurons[0])
			for(auto &inputNeuron : m_inputNeurons)
				hiddenNeuron->AddConnection(std::make_unique<Connection>(dynamic_cast<Neuron*>(inputNeuron.get())));

		// connections between hidden layers
		if(m_hiddenNeurons.size() > 1)
			for(unsigned int i = 1; i < m_hiddenNeurons.size(); i++)
				for(unsigned int j = 0; j < m_hiddenNeurons[i]->size(); j++)
					for(unsigned int k = 0; k < m_hiddenNeurons[i-1]->size(); k++)
						m_hiddenNeurons[i]->at(j)->AddConnection(std::make_unique<Connection>(dynamic_cast<Neuron*>(m_hiddenNeurons[i-1]->at(k).get())));

		// connect the output neurons with the last layer of hidden neurons
		for(auto &outputNeuron : m_outputNeurons)
			for(auto &hiddenNeuron : *m_hiddenNeurons.back())
				outputNeuron->AddConnection(std::make_unique<Connection>(dynamic_cast<Neuron*>(hiddenNeuron.get())));
	}
}

