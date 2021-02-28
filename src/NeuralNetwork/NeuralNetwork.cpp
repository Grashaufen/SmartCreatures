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

void NeuralNetwork::CreateHiddenNeurons(unsigned int layer, unsigned int amount, ActivationFunction activationFunction)
{
	if(layer > m_hiddenNeurons.size()-1) // the demanded layer does not exist
		return;

	for(unsigned int i = 0; i < amount; i++)
		m_hiddenNeurons[layer]->push_back(std::make_unique<WorkingNeuron>(activationFunction));
}

void NeuralNetwork::CreateOutputNeurons(unsigned int amount, ActivationFunction activationFunction)
{
	for(unsigned int i = 0; i < amount; i++)
		m_outputNeurons.push_back(std::make_unique<WorkingNeuron>(activationFunction));
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

void NeuralNetwork::CopyNeuralNetwork(std::vector<std::unique_ptr<InputNeuron>> *pInputNeurons, std::vector<std::unique_ptr<std::vector<std::unique_ptr<WorkingNeuron>>>> *pHiddenNeurons,
	                                  std::vector<std::unique_ptr<WorkingNeuron>> *pOutputNeurons)
{
	// create the input neurons
	m_inputNeurons.clear();
	for(unsigned int i = 0; i < pInputNeurons->size(); i++)
		m_inputNeurons.push_back(std::make_unique<InputNeuron>());

	// create the output neurons
	m_outputNeurons.clear();
	for(auto &outputNeuron : *pOutputNeurons)
		m_outputNeurons.push_back(std::make_unique<WorkingNeuron>(outputNeuron->getActivationFunction()));

	// create the hidden layers and the hidden neurons
	unsigned int i = 0;
	m_hiddenNeurons.clear();
	for(auto &hiddenLayer : *pHiddenNeurons)
	{
		m_hiddenNeurons.push_back(std::make_unique<std::vector<std::unique_ptr<WorkingNeuron>>>());

		for(unsigned int j = 0; j < hiddenLayer->size(); j++)
		{
			m_hiddenNeurons[i]->push_back(std::make_unique<WorkingNeuron>(hiddenLayer->at(j)->getActivationFunction()));

			// create the connections
			if(i == 0) // create the first hidden layer with the input neurons
			{
				for(unsigned int k = 0; k < m_inputNeurons.size(); k++)
				{
					m_hiddenNeurons[i]->at(j)->AddConnection(std::make_unique<Connection>(dynamic_cast<Neuron*>(m_inputNeurons[k].get())));
					m_hiddenNeurons[i]->at(j)->getConnections().at(k)->SetWeight(hiddenLayer->at(j)->getConnections().at(k)->getWeight());
				}
			}
			else if(i == pHiddenNeurons->size()-1) // connect the output neurons to the last hidden layer
			{
				for(unsigned int k = 0; k < m_outputNeurons.size(); k++)
				{
					m_outputNeurons[k]->AddConnection(std::make_unique<Connection>(dynamic_cast<Neuron*>(m_hiddenNeurons[i]->at(j).get())));
					m_outputNeurons[k]->getConnections().at(k)->SetWeight(hiddenLayer->at(j)->getConnections().at(k)->getWeight());
				}
			}
			else // connect the hidden layers
			{
				for(unsigned int k = 0; k < m_hiddenNeurons[i-1]->size(); k++)
				{
					m_hiddenNeurons[i]->at(j)->AddConnection(std::make_unique<Connection>(dynamic_cast<Neuron*>(m_hiddenNeurons[i-1]->at(k).get())));
					m_hiddenNeurons[i]->at(j)->getConnections().at(k)->SetWeight(hiddenLayer->at(j)->getConnections().at(k)->getWeight());
				}
			}
		}

		i++;
	} i = 0;
}
