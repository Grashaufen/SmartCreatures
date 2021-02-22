/*
 * Connection.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include "Connection.h"

Connection::Connection(Neuron *pNeuron)
{
	m_pNeuron = pNeuron;
	m_weight = 1.0f;
}

float Connection::getWeight()
{
	return m_weight;
}

void Connection::SetWeight(float weight)
{
	m_weight = weight;
}

Neuron* Connection::getNeuron()
{
	return m_pNeuron;
}
