/*
 * Creature.cpp
 *
 *  Created on: 21.02.2021
 *      Author: jannes
 */

#include "Creature.h"

Creature::Creature()
{
	m_pBody = new sf::CircleShape(m_radius);
	m_pBody->setFillColor(m_bodyColor);

	/*
	 * TODO: create a mutation that defines new max values for speed, vision and strength but take care
	 *       that the sum of the max values does not exceed the total maximum (m_totalMaximum)
	 */

	/*
	 * TODO: let the radius of the creatures body defined by its strength
	 */
}

Creature::Creature(float radius)
{
	m_radius = radius;
	m_pBody = nullptr;
	Creature();
}

Creature::Creature(float x, float y)
{
	m_position = sf::Vector2f(x, y);
	m_pBody = nullptr;
	Creature();
}

Creature::Creature(float radius, float x, float y)
{
	m_radius = radius;
	m_position = sf::Vector2f(x, y);
	m_pBody = nullptr;
	Creature();
}

Creature::~Creature()
{
	delete m_pBody; m_pBody = nullptr;
}


void Creature::DoActions()
{
	Move();
}

void Creature::Move()
{
	// normalize the mvdir vector, so really only the direction takes effect
	Math::Vector2fNormalize(m_moveDir);

	// update the position of this creature
	m_position += sf::Vector2f(m_moveDir.x * m_speed, m_moveDir.y * m_speed);

	// update the sprites (visuals) positions of this creature
	m_pBody->setPosition(m_position);
}

void Creature::Update()
{
	// if the the energy level of this creature is equal to or below zero he must die
	if(m_energy <= 0)
	{
		Die();
		return;
	}

	/*
	 * TODO: let the creature only allow to buy a specific amount of speed, vision and strength
	 *       which is given by the genes
	 */

	// the creature must pay the energy price of his abilities every tick
	m_energy -= m_speedCost * m_speed;
	if(m_vision > 1.0f) 	m_energy -= m_visionCost * m_vision;
	if(m_strength > 1.0f) 	m_energy -= m_strengthCost * m_strength;

	DoActions();
}

void Creature::Render(sf::RenderWindow *pRenderWindow)
{
	pRenderWindow->draw(*m_pBody);
}

bool Creature::gainSpeed(float speed)
{
	float totalCost = m_speedCost * speed;
	float totalSpeed = m_speed + speed;

	if(m_energy < totalCost || totalSpeed > m_maxSpeed)
		return false;

	m_energy -= totalCost;
	m_speed = totalSpeed;

	return true;
}

bool Creature::gainVision(float vision)
{
	float totalCost = m_visionCost * vision;
	float totalVision = m_vision + vision;

	if(m_energy < totalCost || totalVision > m_maxVision)
		return false;

	m_energy -= totalCost;
	m_vision = totalVision;

	return true;
}

bool Creature::gainStrength(float strength)
{
	float totalCost = m_strengthCost * strength;
	float totalStrength = m_strength + strength;

	if(m_energy < totalCost || totalStrength > m_maxStrength)
		return false;

	m_energy -= totalCost;
	m_strength = totalStrength;

	return true;
}


void Creature::LoseSpeed(float speed)
{
	if(m_speed < speed)
	{
		m_speed = 0;
		return;
	}

	m_speed -= speed;
}

void Creature::LoseVision(float vision)
{
	if(m_vision < vision)
	{
		m_vision = 0;
		return;
	}

	m_vision -= vision;
}

void Creature::LoseStrength(float strength)
{
	if(m_strength < strength)
	{
		m_strength = 0;
		return;
	}

	m_strength -= strength;
}

void Creature::Spawn(float x, float y)
{
	m_position = sf::Vector2f(x, y);
}
