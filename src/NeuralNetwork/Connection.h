/*
 * Connection.h
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_CONNECTION_H_
#define NEURALNETWORK_CONNECTION_H_

#include <memory>
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

	void    setNeuron(Neuron *pNeuron);
	Neuron* getNeuron() const;
};

#endif /* NEURALNETWORK_CONNECTION_H_ */
