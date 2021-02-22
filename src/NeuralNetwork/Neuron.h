/*
 * Neuron.h
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_NEURON_H_
#define NEURALNETWORK_NEURON_H_

class Neuron
{
protected:
	float m_value;

public:
	virtual ~Neuron() {}
	virtual float getValue() = 0;
};

#endif /* NEURALNETWORK_NEURON_H_ */
