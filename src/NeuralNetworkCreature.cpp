/*
 * NeuralNetworkCreature.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include <iostream>
#include "NeuralNetworkCreature.h"


void NeuralNetworkCreature::Create()
{
	CreateInputNeurons(1);
	CreateOutputNeurons(1);
	CreateFullMesh();

	m_inputNeurons[0]->SetValue(m_x);
	std::cout << m_outputNeurons[0]->getValue();
}

void NeuralNetworkCreature::Update()
{

}
