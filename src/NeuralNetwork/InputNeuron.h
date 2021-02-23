/*
 * InputNeuron.h
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_INPUTNEURON_H_
#define NEURALNETWORK_INPUTNEURON_H_

#include "Neuron.h"

class InputNeuron : public Neuron
{
public:
	InputNeuron();

	virtual float getValue() override;
	void SetValue(float value);
};

#endif /* NEURALNETWORK_INPUTNEURON_H_ */
