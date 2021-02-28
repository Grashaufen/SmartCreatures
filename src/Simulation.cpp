/*
 * Simulation.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include <iostream>
#include "Simulation.h"
#include "TextureLoader.h"
#include "Math.h"

Simulation::Simulation(sf::RenderWindow *pRenderWindow, float fieldRadius, unsigned int maxFoodQuantity, unsigned int minCreatures)
	: m_pRenderWindow(pRenderWindow)
{
	m_fieldRadius     = fieldRadius;
	m_maxFoodQuantity = maxFoodQuantity;
	m_minCreatures    = minCreatures;

	m_pCamera = std::make_unique<Camera>(pRenderWindow, sf::Vector2f());

	m_background.setOrigin(fieldRadius, fieldRadius);
	m_background.setPosition(0.0f, 0.0f);
	m_background.setRadius(m_fieldRadius);
	m_background.setPointCount(100);
	m_background.setTextureRect({0, 0, static_cast<int>(fieldRadius), static_cast<int>(fieldRadius)});
	m_background.setTexture(TextureLoader::m_pFieldBackground);
}


void Simulation::GenerateFood()
{
	if(m_foods.size() < m_maxFoodQuantity-1)
		for(unsigned int i = 0; i < (m_maxFoodQuantity - m_foods.size()); i++)
			AddFood(1);
}

void Simulation::AddFood(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
	{
		float randAngle = Math::degreesToRadians(Math::frand(0.0f, 360.0f));

		m_foods.push_back(std::make_unique<Food>(sf::Vector2f(Math::frand(0.0f, m_fieldRadius) * cosf(randAngle),
	                                                          Math::frand(0.0f, m_fieldRadius) * sinf(randAngle))));
	}
}

void Simulation::RemoveFood(unsigned int amount)
{
	if(m_foods.size() - amount >= 0)
		for(unsigned int i = 0; i < amount; i++)
			m_foods.pop_back();
}


void Simulation::Create()
{
	// create foods
	GenerateFood();

	for(unsigned int i = 0; i < m_minCreatures; i++)
	{
		float randAngle = Math::degreesToRadians(Math::frand(0.0f, 360.0f));
		m_creatures.push_back(std::make_unique<PrimitiveCreature>(this, sf::Vector2f(Math::frand(0.0f, m_fieldRadius) * cosf(randAngle),
                Math::frand(0.0f, m_fieldRadius) * sinf(randAngle))));
		m_creatures[i]->Create();
	}
}

void Simulation::Update()
{
	// update camera
	m_pCamera->Set();
	m_pCamera->Update(m_clock);

	GenerateFood();

	for(auto &food : m_foods)
		food->Update(m_clock);

	// creatures
	if(m_creatures.size() < m_minCreatures)
	{
		unsigned int currentCreatureQuantity = m_creatures.size();
		for(unsigned int i = 0; i < (m_minCreatures - currentCreatureQuantity); i++)
		{
			float randAngle = Math::degreesToRadians(Math::frand(0.0f, 360.0f));
			m_creatures.push_back(std::make_unique<PrimitiveCreature>(this, sf::Vector2f(Math::frand(0.0f, m_fieldRadius) * cosf(randAngle),
					Math::frand(0.0f, m_fieldRadius) * sinf(randAngle))));

			m_creatures[i + currentCreatureQuantity]->Create();
		}
	}

	for(auto creature = m_creatures.begin(); creature != m_creatures.end();)
	{
		if((*creature)->died())
			m_creatures.erase(creature);
		else
			creature++;
	}

	unsigned int creaturesSize = m_creatures.size();
	for (unsigned int i = 0; i < creaturesSize; i++)
	{
		creaturesSize = m_creatures.size();
		m_creatures[i]->Update(m_clock);
	}

	std::cout << m_creatures.size() << std::endl;

	m_clock.restart();
}

void Simulation::Render()
{
	m_pRenderWindow->draw(m_background);

	// draw foods
	for(auto &food : m_foods)
		food->Render(m_pRenderWindow);

	for(auto &creature : m_creatures)
		creature->Render(m_pRenderWindow);
}
