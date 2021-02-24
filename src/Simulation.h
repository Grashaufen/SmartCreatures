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
	sf::Vector2f m_fieldSize = sf::Vector2f(15000.0f, 10000.0f);

	Camera                                 *m_pCamera;
	// std::vector<sf::PrimitiveCreature*>  m_creatures;
	// std::vector<Food*>                   m_foods;

	sf::RectangleShape *m_pBackground;

	unsigned int m_maxFoodQuantity     = 1000.0f;
	unsigned int m_currentFoodQuantity = 0.0f;
	unsigned int m_minCreatures        = 50.0f;


public:
	Simulation();
	virtual ~Simulation();

	void Create();
	void Update();
	void Render(sf::RenderWindow *pRenderWindow);
};

#endif /* SIMULATION_H_ */
