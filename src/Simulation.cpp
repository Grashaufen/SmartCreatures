/*
 * Simulation.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "Simulation.h"
#include "TextureLoader.h"
#include "Math.h"

Simulation::Simulation(sf::RenderWindow *pRenderWindow, float fieldRadius, unsigned int maxFoodQuantity, unsigned int minCreatures)
	: m_pRenderWindow(pRenderWindow),
	  m_currentFoodQuantity(0)
{
	m_fieldRadius     = fieldRadius;
	m_maxFoodQuantity = maxFoodQuantity;
	m_minCreatures    = minCreatures;

	m_pCamera = std::make_unique<Camera>(pRenderWindow, sf::Vector2f(fieldRadius - 640.0f, fieldRadius - 360.0f));

	m_background.setPosition(0.0f, 0.0f);
	m_background.setRadius(m_fieldRadius);
	m_background.setPointCount(100);
	m_background.setTextureRect({0, 0, static_cast<int>(fieldRadius), static_cast<int>(fieldRadius)});
	m_background.setTexture(TextureLoader::m_pFieldBackground);
}


void Simulation::GenerateFood()
{
	if(m_currentFoodQuantity < m_maxFoodQuantity-1)
		for(unsigned int i = 0; i < (m_maxFoodQuantity - m_currentFoodQuantity); i++)
			AddFood(1);
}

void Simulation::AddFood(unsigned int amount)
{
	for(unsigned int i = 0; i < amount; i++)
	{
		float randAngle = Math::degreeToRadians(Math::frand(0.0f, 360.0f));

		m_foods.push_back(std::make_unique<Food>(sf::Vector2f(Math::frand(0.0f, m_fieldRadius) * cosf(randAngle) + m_fieldRadius,
															  Math::frand(0.0f, m_fieldRadius) * sinf(randAngle) + m_fieldRadius)));
		m_currentFoodQuantity++;
	}
}

void Simulation::RemoveFood(unsigned int amount)
{
	if(m_currentFoodQuantity - amount >= 0)
	{
		for(unsigned int i = 0; i < amount; i++)
		{
			m_foods.pop_back();
			m_currentFoodQuantity--;
		}
	}
}


void Simulation::Create()
{
	// create foods
	GenerateFood();
}

void Simulation::Update()
{
	// update camera
	m_pCamera->Set();
	m_pCamera->Update(m_clock);

	// update foods
	GenerateFood();

	for(auto &food : m_foods)
		food->Update(m_clock);

	m_clock.restart();
}

void Simulation::Render()
{
	m_pRenderWindow->draw(m_background);

	// draw foods
	for(auto &food : m_foods)
		food->Render(m_pRenderWindow);
}
