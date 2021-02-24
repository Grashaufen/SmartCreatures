/*
 * WorkingNeuron.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include "WorkingNeuron.h"
#include "../Math.h"

WorkingNeuron::~WorkingNeuron()
{
	// delete all connections from the heap
	for(unsigned int i = 0; i < m_connections.size(); i++)
		if(m_connections[i]) { delete m_connections[i]; m_connections[i] = nullptr;  }
}


/*
 * Create the netinput: return one value calculated from the values received from the connections
 */
void WorkingNeuron::getNetInput()
{
	for(unsigned int i = 0; i < m_connections.size(); i++)
		m_value += m_connections[i]->getNeuron()->getValue() * m_connections[i]->getWeight();
}

/*
 * apply an mathematical activation function on the value of this neuron
 */
void WorkingNeuron::Activate()
{
	m_value = Math::sigmoid(m_value);
}

float WorkingNeuron::getValue()
{
	getNetInput();
	Activate();
	return m_value;
}

void WorkingNeuron::AddConnection(Connection *pConnection)
{
	m_connections.push_back(pConnection);
}

std::vector<Connection*>& WorkingNeuron::getConnections()
{
	return m_connections;
}
