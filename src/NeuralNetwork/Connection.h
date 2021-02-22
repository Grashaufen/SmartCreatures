/*
 * Connection.h
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_CONNECTION_H_
#define NEURALNETWORK_CONNECTION_H_

#include "Neuron.h"

class Connection
{
private:
	Neuron *m_pNeuron;
	float   m_weight;

public:
	Connection(Neuron *pNeuron);

	float getWeight();
	void SetWeight(float weight);

	Neuron *getNeuron();
};

#endif /* NEURALNETWORK_CONNECTION_H_ */
