/*
 * Connection.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include "Connection.h"
#include "../Math.h"

Connection::Connection(Neuron *pNeuron)
	: m_pNeuron(pNeuron)
{
	m_weight = Math::frand(-0.5f, 0.5f);
}

float Connection::getWeight()
{
	return m_weight;
}

void Connection::SetWeight(float weight)
{
	m_weight = weight;
}

Neuron* Connection::getNeuron() const
{
	return m_pNeuron;
}
