/*
 * WorkingNeuron.h
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#ifndef NEURALNETWORK_WORKINGNEURON_H_
#define NEURALNETWORK_WORKINGNEURON_H_

#include <vector>

#include "Neuron.h"
#include "Connection.h"

class WorkingNeuron : public Neuron
{
private:
	std::vector<Connection*>	m_connections;

	void getNetInput();
	void Activate();

public:
	virtual ~WorkingNeuron();

	virtual float getValue() override;

	void AddConnection(Connection *pConnection);
};

#endif /* NEURALNETWORK_WORKINGNEURON_H_ */
