/*
 * NeuralNetwork.h
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_NEURALNETWORK_H_
#define NEURALNETWORK_NEURALNETWORK_H_

#include "InputNeuron.h"
#include "WorkingNeuron.h"
#include "Connection.h"

class NeuralNetwork
{
protected:
	std::vector<InputNeuron*>     m_inputNeurons;
	std::vector<WorkingNeuron*>   m_hiddenNeurons;
	std::vector<WorkingNeuron*>   m_outputNeurons;

public:
	virtual ~NeuralNetwork();

	void CreateInputNeurons(unsigned int amount);
	void CreateHiddenNeurons(unsigned int amount);
	void CreateOutputNeurons(unsigned int amount);

	void CreateFullMesh();

	virtual void Create() = 0;
	virtual void Update() = 0;
};

#endif /* NEURALNETWORK_NEURALNETWORK_H_ */
