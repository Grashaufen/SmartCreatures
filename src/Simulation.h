/*
 * Simulation.h
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <SFML/Graphics.hpp>

#include "Camera.h"

class Simulation
{
private:
	sf::RenderWindow *m_pRenderWindow;
	sf::Clock		  m_clock;

	std::unique_ptr<Camera>                m_pCamera;
	// std::vector<sf::PrimitiveCreature*> m_creatures;
	// std::vector<Food*>                  m_foods;

	sf::CircleShape m_background;

	float        m_fieldRadius;
	unsigned int m_maxFoodQuantity;
	unsigned int m_currentFoodQuantity;
	unsigned int m_minCreatures;


public:
	Simulation(sf::RenderWindow *pRenderWindow, float fieldRadius = 3000.0f, unsigned int maxFoodQuantity = 1000, unsigned int minCreatures = 50);

	void Create();
	void Update();
	void Render();
};

#endif /* SIMULATION_H_ */
