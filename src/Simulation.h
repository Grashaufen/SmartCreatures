/*
 * Simulation.h
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Food.h"
#include "PrimitiveCreature.h"

class Simulation
{
private:
	sf::RenderWindow *m_pRenderWindow;
	sf::Clock		  m_clock;

	std::unique_ptr<Camera>                         m_pCamera;
	std::vector<std::unique_ptr<Food>>              m_foods;
	std::vector<std::unique_ptr<PrimitiveCreature>> m_creatures;

	sf::CircleShape m_background;

	float        m_fieldRadius;
	unsigned int m_maxFoodQuantity;
	unsigned int m_minCreatures;

	void GenerateFood();
	void AddFood(unsigned int amount);
	void RemoveFood(unsigned int amount);

public:
	Simulation(sf::RenderWindow *pRenderWindow, float fieldRadius = 1000.0f, unsigned int maxFoodQuantity = 2000, unsigned int minCreatures = 40);

	void Create();
	void Update();
	void Render();

	float getFieldRadius()                                          { return m_fieldRadius; }
	std::vector<std::unique_ptr<Food>>& getFoods()                  { return m_foods; }
	std::vector<std::unique_ptr<PrimitiveCreature>>& getCreatures() { return m_creatures; }
};

#endif /* SIMULATION_H_ */
