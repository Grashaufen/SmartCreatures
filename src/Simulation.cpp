/*
 * Simulation.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "Simulation.h"
#include "TextureLoader.h"

Simulation::Simulation(sf::RenderWindow *pRenderWindow, float fieldRadius, unsigned int maxFoodQuantity, unsigned int minCreatures)
	: m_pRenderWindow(pRenderWindow),
	  m_currentFoodQuantity(0)
{
	m_fieldRadius     = fieldRadius;
	m_maxFoodQuantity = maxFoodQuantity;
	m_minCreatures    = minCreatures;

	m_pCamera = std::make_unique<Camera>(pRenderWindow, sf::Vector2f(fieldRadius - 640.0f, fieldRadius - 360.0f));

	m_background.setPosition(0.0f, 0.0f);
	m_background.setRadius(4000.0f);
	m_background.setPointCount(100);
	m_background.setTextureRect({0, 0, static_cast<int>(fieldRadius), static_cast<int>(fieldRadius)});
	m_background.setTexture(TextureLoader::m_pFieldBackground);
}

void Simulation::Create()
{

}

void Simulation::Update()
{
	m_pCamera->Set();
	m_pCamera->Update();
}

void Simulation::Render()
{
	m_pRenderWindow->draw(m_background);
}
