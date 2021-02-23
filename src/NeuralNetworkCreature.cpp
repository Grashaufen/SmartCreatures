/*
 * NeuralNetworkCreature.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include <iostream>
#include "NeuralNetworkCreature.h"
#include "Math.h"


void NeuralNetworkCreature::Create()
{
	CreateInputNeurons(2);
	CreateHiddenLayers(2);
	CreateHiddenNeurons(0, 2);
	CreateHiddenNeurons(1, 1);
	CreateOutputNeurons(1);
	CreateFullMesh();

	m_hiddenLayers[1]->at(0)->getConnections().at(0)->SetWeight(0.5f);

	m_inputNeurons[0]->SetValue(20.0f);
	m_inputNeurons[1]->SetValue(10.0f);

	std::cout << m_outputNeurons[0]->getValue() << std::endl;
}

void NeuralNetworkCreature::Update()
{

}
