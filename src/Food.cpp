/*
 * Food.cpp
 *
 *  Created on: 26.02.2021
 *      Author: jannes
 */

#include "Food.h"

Food::Food(sf::Vector2f position, float energy)
	: m_energy(energy)
{
	m_radius = 4.0f;
	m_bodyColor = sf::Color::Red;

	m_body.setPosition(position);
	m_body.setFillColor(m_bodyColor);
	m_body.setRadius(m_radius);
}

void Food::Render(sf::RenderWindow *pRenderWindow)
{
	pRenderWindow->draw(m_body);
}
