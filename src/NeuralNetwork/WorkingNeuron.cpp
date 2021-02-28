/*
 * WorkingNeuron.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include <iostream>
#include "WorkingNeuron.h"
#include "../Math.h"

WorkingNeuron::WorkingNeuron(ActivationFunction activationFunction)
	: m_activationFunction(activationFunction)
{ }

/*
 * Create the netinput: return one value calculated from the values received from the connections
 */
void WorkingNeuron::getNetInput()
{
	m_value = 0.0f;

	for(auto &connection : m_connections)
		m_value += connection->getNeuron()->getValue() * connection->getWeight();
}

/*
 * apply an mathematical activation function on the value of this neuron
 */
void WorkingNeuron::Activate()
{
	switch(m_activationFunction)
	{
	case ActivationFunction::ActivationSigmoid:
		m_value = Math::sigmoid(m_value);
		break;
	case ActivationFunction::ActivationHyperbolicTangent:
		m_value = Math::hyperpolicTangent(m_value);
		break;
	case ActivationFunction::ActivationLinear:
	default:
		break;
	}
}

float WorkingNeuron::getValue()
{
	getNetInput();
	Activate();
	return m_value;
}

void WorkingNeuron::AddConnection(std::unique_ptr<Connection> pConnection)
{
	m_connections.push_back(std::move(pConnection));
}
