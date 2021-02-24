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
	CreateInputNeurons(3);
	CreateHiddenLayers(4);
	CreateHiddenNeurons(0, 2);
	CreateHiddenNeurons(1, 3);
	CreateHiddenNeurons(2, 4);
	CreateHiddenNeurons(3, 5);
	CreateOutputNeurons(3);
	CreateFullMesh();

	Mutate(0.1f, -0.1f);

	m_inputNeurons[0]->SetValue(20.0f);
	m_inputNeurons[1]->SetValue(10.0f);
	m_inputNeurons[2]->SetValue(1.0f);

	std::cout << m_outputNeurons[0]->getValue() << std::endl;
	std::cout << m_outputNeurons[1]->getValue() << std::endl;
	std::cout << m_outputNeurons[2]->getValue() << std::endl;
}

void NeuralNetworkCreature::Update()
{

}
