/*
 * CreatureStats.cpp
 *
 *  Created on: 21.02.2021
 *      Author: jannes
 */

#include "CreatureStats.h"

CreatureStats::CreatureStats(std::shared_ptr<Creature> pCreature, float x, float y)
{
	m_pCreature 	= pCreature;
	m_pValEnergy 	= nullptr;
	m_pValSpeed 	= nullptr;
	m_pValVision 	= nullptr;
	m_pValStrength 	= nullptr;

	m_statsFont.loadFromFile("fonts/arial.ttf");
	m_position = sf::Vector2f(x, y);
}

CreatureStats::~CreatureStats()
{
}


void CreatureStats::Create()
{
	m_txtStats.setString("Stats");
	m_txtStats.setStyle(sf::Text::Bold);
	m_txtStats.setFont(m_statsFont);
	m_txtStats.setFillColor(m_colorHeader);
	m_txtStats.setCharacterSize(m_charSizeHeader);
	m_txtStats.setPosition(m_position);

	for(int i = 0; i < 4; i++) // Create four variables to show
	{
		m_txtVariables.push_back(new sf::Text());

		float y = m_position.y + (float)m_txtStats.getCharacterSize() + m_gapHeader
					+ i * ((float)m_txtVariables[i]->getCharacterSize() + m_gapVariables);

		m_txtVariables[i]->setFont(m_statsFont);
		m_txtVariables[i]->setFillColor(m_colorVariables);
		m_txtVariables[i]->setCharacterSize(m_charSizeVariables);
		m_txtVariables[i]->setPosition(m_position.x, y);
	}
}

void CreatureStats::Update()
{
	m_txtVariables[0]->setString("Energy:\t" + std::to_string(m_pCreature->getEnergy()));
	m_txtVariables[1]->setString("Speed:\t" + std::to_string(m_pCreature->getSpeed()));
	m_txtVariables[2]->setString("Vision:\t" + std::to_string(m_pCreature->getVision()));
	m_txtVariables[3]->setString("Strength:\t" + std::to_string(m_pCreature->getStrength()));
}

void CreatureStats::Render(sf::RenderWindow *pRenderWindow)
{
	pRenderWindow->draw(m_txtStats);

	for(unsigned int i = 0; i < m_txtVariables.size(); i++)
		pRenderWindow->draw(*m_txtVariables[i]);
}
