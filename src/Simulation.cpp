/*
 * Simulation.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "Simulation.h"
#include "TextureLoader.h"

Simulation::Simulation()
{
	m_pCamera = new Camera();

	m_pBackground = new sf::RectangleShape();
	m_pBackground->setPosition(0.0f, 0.0f);
	m_pBackground->setSize(m_fieldSize);
	m_pBackground->setTextureRect({0, 0, (int)m_fieldSize.x, (int)m_fieldSize.y});
	m_pBackground->setTexture(TextureLoader::m_pFieldBackground);
}

Simulation::~Simulation()
{
	if(m_pBackground) { delete m_pBackground; m_pBackground = nullptr; }
	if(m_pCamera) { delete m_pCamera; m_pCamera = nullptr; }
}

void Simulation::Create()
{

}

void Simulation::Update()
{
	m_pCamera->Update();
}

void Simulation::Render(sf::RenderWindow *pRenderWindow)
{
	m_pCamera->Set(pRenderWindow);
	pRenderWindow->draw(*m_pBackground);
}
