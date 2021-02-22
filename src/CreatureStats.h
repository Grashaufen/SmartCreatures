/*
 * CreatureStats.h
 *
 *  Created on: 21.02.2021
 *      Author: jannes
 */

#ifndef CREATURESTATS_H_
#define CREATURESTATS_H_

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Creature.h"

class CreatureStats
{
private:
	std::shared_ptr<Creature> m_pCreature;

	unsigned int m_charSizeHeader 		= 16;
	unsigned int m_charSizeVariables 	= 14;

	float m_gapHeader 		= 8.0f;
	float m_gapVariables 	= 0.0f;

	int *m_pValEnergy;
	float *m_pValSpeed;
	float *m_pValVision;
	float *m_pValStrength;

	sf::Vector2f m_position;

	sf::Color m_colorHeader 	= sf::Color::White;
	sf::Color m_colorVariables	= sf::Color::White;

	sf::Font m_statsFont;
	sf::Text m_txtStats;

	std::vector<sf::Text*> 		m_txtVariables;

public:
	CreatureStats(std::shared_ptr<Creature> pCreature, float x = 10.0f, float y = 10.0f);
	virtual ~CreatureStats();

	void Create();
	void Update();
	void Render(sf::RenderWindow *pRenderWindow);
};

#endif /* CREATURESTATS_H_ */
