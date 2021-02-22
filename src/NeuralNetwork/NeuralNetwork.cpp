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

	for(unsigned int i = 0; i < m_hiddenNeurons.size(); i++)
			if(m_inputNeurons[i]) { delete m_hiddenNeurons[i]; m_hiddenNeurons[i] = nullptr; }

	for(unsigned int i = 0; i < m_outputNeurons.size(); i++)
			if(m_outputNeurons[i]) { delete m_outputNeurons[i]; m_outputNeurons[i] = nullptr; }

}


void NeuralNetwork::CreateInputNeurons(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_inputNeurons.push_back(new InputNeuron());
}

void NeuralNetwork::CreateHiddenNeurons(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_hiddenNeurons.push_back(new WorkingNeuron());
}

void NeuralNetwork::CreateOutputNeurons(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
		m_outputNeurons.push_back(new WorkingNeuron());
}

void NeuralNetwork::CreateFullMesh()
{
	if(m_hiddenNeurons.size() == 0) // The neural network hasn`t got hidden neurons
	{
		for(unsigned int i = 0; i < m_outputNeurons.size(); i++)
		{
			for(unsigned int j = 0; j < m_inputNeurons.size(); j++)
				m_outputNeurons[i]->AddConnection(new Connection(m_inputNeurons[j]));
		}
	}
	else // the neural network has hidden neurons
	{
		// connect the hidden neurons with the input neurons
		for(unsigned int i = 0; i < m_hiddenNeurons.size(); i++)
		{
			for(unsigned int j = 0; j < m_inputNeurons.size(); j++)
				m_hiddenNeurons[i]->AddConnection(new Connection(m_inputNeurons[j]));
		}

		// connect the output neurons with the hidden neurons
		for(unsigned int i = 0; i < m_outputNeurons.size(); i++)
		{
			for(unsigned int j = 0; j < m_hiddenNeurons.size(); j++)
				m_outputNeurons[i]->AddConnection(new Connection(m_hiddenNeurons[j]));
		}
	}
}

