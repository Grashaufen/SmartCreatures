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

enum ActivationFunction
{
	ActivationLinear,
	ActivationSigmoid,
	ActivationHyperbolicTangent
};

class WorkingNeuron : public Neuron
{
private:
	std::vector<std::unique_ptr<Connection>> m_connections;
	ActivationFunction                       m_activationFunction;

	void getNetInput();
	void Activate();

public:
	WorkingNeuron(ActivationFunction activationFunction);
	virtual ~WorkingNeuron() {}

	void AddConnection(std::unique_ptr<Connection> pConnection);


	std::vector<std::unique_ptr<Connection>>& getConnections()        { return m_connections; }
	ActivationFunction                        getActivationFunction() { return m_activationFunction; }

	virtual float                             getValue() override;
};

#endif /* NEURALNETWORK_WORKINGNEURON_H_ */
