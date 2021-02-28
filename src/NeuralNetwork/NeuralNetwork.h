/*
 * NeuralNetwork.h
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_NEURALNETWORK_H_
#define NEURALNETWORK_NEURALNETWORK_H_

#include <memory>

#include "InputNeuron.h"
#include "WorkingNeuron.h"
#include "Connection.h"

class NeuralNetwork
{
protected:
	std::vector<std::unique_ptr<InputNeuron>>                                 m_inputNeurons;
	std::vector<std::unique_ptr<std::vector<std::unique_ptr<WorkingNeuron>>>> m_hiddenNeurons;
	std::vector<std::unique_ptr<WorkingNeuron>>                               m_outputNeurons;

	void CreateHiddenLayers(unsigned int amount);

	void CreateInputNeurons(unsigned int amount);
	void CreateHiddenNeurons(unsigned int layer, unsigned int amount, ActivationFunction activationFunction);
	void CreateOutputNeurons(unsigned int amount, ActivationFunction activationFunction);

	void CreateFullMesh();

	void CopyNeuralNetwork(std::vector<std::unique_ptr<InputNeuron>> *pInputNeurons, std::vector<std::unique_ptr<std::vector<std::unique_ptr<WorkingNeuron>>>> *pHiddenNeurons,
	                       std::vector<std::unique_ptr<WorkingNeuron>> *pOutputNeurons);

public:
	virtual ~NeuralNetwork() { };

	virtual void Create() = 0;
};

#endif /* NEURALNETWORK_NEURALNETWORK_H_ */
