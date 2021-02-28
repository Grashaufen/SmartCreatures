/*
 * Food.h
 *
 *  Created on: 26.02.2021
 *      Author: jannes
 */

#ifndef FOOD_H_
#define FOOD_H_

#include <SFML/Graphics.hpp>

class Food
{
private:
	sf::CircleShape m_body;
	sf::Color       m_bodyColor;
	float           m_radius;

	float           m_energy;

public:
	Food(sf::Vector2f position, float energy = 20.0f);
	virtual ~Food() { }

	virtual void Update(const sf::Clock &clock) {}
	virtual void Render(sf::RenderWindow *pRenderWindow);

	float               getEnergy()   { return m_energy; }
	float               getRadius()   { return m_radius; }
	const sf::Vector2f& getPosition() { return m_body.getPosition(); }
};

#endif /* FOOD_H_ */
