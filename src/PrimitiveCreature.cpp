/*
 * PrimitiveCreature.cpp
 *
 *  Created on: 26.02.2021
 *      Author: jannes
 */

#include "PrimitiveCreature.h"
#include "TextureLoader.h"
#include "Simulation.h"
#include "Math.h"

PrimitiveCreature::PrimitiveCreature(Simulation *pSimulation, const sf::Vector2f &position, bool isChild)
	: m_pSimulation(pSimulation),
	  m_pNextFood(nullptr),
	  m_isChild(isChild),
	  m_radius(10.0f),
	  m_visionRadius(20.0f),
	  m_pParentInputNeurons(nullptr),
	  m_pParentHiddenNeurons(nullptr),
	  m_pParentOutputNeurons(nullptr),
	  m_energy(400.0f),
	  m_voidDistance(0.0f),
	  m_nextFood(0.0f),
	  m_isOnFood(false),
	  m_moveDir(sf::Vector2f()),
	  m_moveSpeed(0.0f),
	  m_wantToEat(false),
	  m_wantToReproduce(false),
	  m_energyMalus(1.0f),
	  m_reproductionMalus(200.0f),
	  m_isAlive(true)
{
	m_body.setPosition(position);
	m_body.setRadius(m_radius);
	m_body.setOutlineThickness(m_radius / 4.0f);
	m_body.setFillColor(sf::Color(36, 126, 43));
	m_body.setOutlineColor(sf::Color(23, 102, 28));
}

PrimitiveCreature::PrimitiveCreature(Simulation *pSimulation, const sf::Vector2f &position, std::vector<std::unique_ptr<InputNeuron>> *pInputNeurons,
                  std::vector<std::unique_ptr<std::vector<std::unique_ptr<WorkingNeuron>>>> *pHiddenNeurons, std::vector<std::unique_ptr<WorkingNeuron>> *pOutputNeurons)
	: PrimitiveCreature(pSimulation, position, true)
{
	m_pParentInputNeurons  = pInputNeurons;
	m_pParentHiddenNeurons = pHiddenNeurons;
	m_pParentOutputNeurons = pOutputNeurons;
}


void PrimitiveCreature::PushNeuralInput()
{
	m_inputNeurons[1]->SetValue(m_energy);
	m_inputNeurons[2]->SetValue(m_voidDistance);
	m_inputNeurons[3]->SetValue(static_cast<float>(m_isOnFood));
	m_inputNeurons[4]->SetValue(m_nextFood);
}

void PrimitiveCreature::PullNeuralOutput()
{
	m_moveDir.x       = m_outputNeurons[0]->getValue();
	m_moveDir.y       = m_outputNeurons[1]->getValue();
	m_moveSpeed       = m_outputNeurons[2]->getValue();
	m_wantToEat       = (m_outputNeurons[3]->getValue() > 0) ? true : false;
	m_wantToReproduce = (m_outputNeurons[4]->getValue() > 0) ? true : false;
}

void PrimitiveCreature::Eat()
{
	if(m_pNextFood && m_isOnFood)
	{
		m_energy += m_pNextFood->getEnergy();

		for(auto food = m_pSimulation->getFoods().begin(); food != m_pSimulation->getFoods().end(); food++)
		{
			if(food->get() == m_pNextFood)
			{
				m_pSimulation->getFoods().erase(food);
				m_pNextFood = nullptr;
				break;
			}
		}
	}
}

void PrimitiveCreature::Reproduce()
{
	if(m_energy < m_reproductionMalus)
		return;

	m_energy -= m_reproductionMalus;

	// create a new creature as a copy of his parent
	std::unique_ptr<PrimitiveCreature> pCreature = std::make_unique<PrimitiveCreature>(m_pSimulation, m_body.getPosition(), &m_inputNeurons, &m_hiddenNeurons, &m_outputNeurons);
	pCreature->Create();
	m_pSimulation->getCreatures().push_back(std::move(pCreature));
}


void PrimitiveCreature::Create()
{
	if(!m_isChild)
	{
		// create the input neurons
		CreateInputNeurons(5);
		m_inputNeurons[0]->SetValue(1); // Bias

		// create hidden neurons
		CreateHiddenLayers(1);
		CreateHiddenNeurons(0, 5, ActivationFunction::ActivationSigmoid);

		// create output neurons
		CreateOutputNeurons(5, ActivationFunction::ActivationHyperbolicTangent);
		CreateFullMesh();
	}
	else
	{
		CopyNeuralNetwork(m_pParentInputNeurons, m_pParentHiddenNeurons, m_pParentOutputNeurons);
		Mutate(0.1f, -0.1f);
	}

}

void PrimitiveCreature::Update(const sf::Clock &clock)
{
	// update the neural network
	PushNeuralInput();
	PullNeuralOutput();

	// get the new voidDistance value
	m_voidDistance = m_pSimulation->getFieldRadius() - Math::Vector2fGetLength(m_body.getPosition());

	// get nextFood and isOnFood values
	for(auto &food : m_pSimulation->getFoods())
	{
		sf::Vector2f vecDist = food->getPosition() - m_body.getPosition();
		float distance = Math::Vector2fGetLength(vecDist);

		if(distance < m_visionRadius)
		{
			m_nextFood = distance;

			if(distance < m_radius)
				m_isOnFood = true;

			m_pNextFood = food.get();
			break;
		}
	}

	m_moveSpeed = m_moveSpeed < 0 ? -m_moveSpeed : m_moveSpeed;
	m_energy -= (1.0f + 0.5f * m_moveSpeed) * m_energyMalus; // lose energy

	if(m_voidDistance < 0.0f) m_energy -= 10.0f * m_energyMalus; // lose more energy if in void
	if(m_energy <= 0.0f) m_isAlive = false; // die if the energy level is equal or below zero
	if(m_wantToEat) Eat();
	if(m_wantToReproduce) Reproduce();

	// move the creature
	Math::Vector2fNormalize(m_moveDir);
	m_body.move(5.0f * m_moveSpeed * m_moveDir.x, 5.0f * m_moveSpeed * m_moveDir.y);
}

void PrimitiveCreature::Render(sf::RenderWindow *pRenderWindow)
{
	pRenderWindow->draw(m_body);
}
