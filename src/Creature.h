/*
 * Creature.h
 *
 *  Created on: 21.02.2021
 *      Author: jannes
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Math.h"

class Creature
{
private:
	float m_radius 	     = 32.0f;
	bool m_isAlive       = true;

	float m_maxEnergy    = 10000.0f;
	float m_energy       = 5000.0f;

	float m_speedCost    = 1.0f;
	float m_visionCost   = 2.0f;
	float m_strengthCost = 3.0f;

	float m_totalMaximum = 10.0f;
	float m_maxSpeed     = 0.0f;
	float m_maxVision    = 0.0f;
	float m_maxStrength  = 0.0f;

	float m_speed        = 0.0f;
	float m_vision       = 1.0f;
	float m_strength     = 1.0f;

	sf::Vector2f m_moveDir  = sf::Vector2f();
	sf::Vector2f m_position = sf::Vector2f();

	sf::Color    m_bodyColor = sf::Color(52, 52, 39);

	sf::CircleShape                  *m_pBody;
	std::vector<sf::RectangleShape*>  m_connectors;
	std::vector<sf::Sprite*>          m_eyes;

	void DoActions();
	void Move();

public:
	Creature();
	Creature(float radius);
	Creature(float x, float y);
	Creature(float radius, float x, float y);
	virtual ~Creature();

	void Update();
	void Render(sf::RenderWindow *pRenderWindow);

	void Die() { m_isAlive = false; }

	bool isAlive() { return m_isAlive; }

	bool gainSpeed(float speed);
	bool gainVision(float vision);
	bool gainStrength(float strength);

	void LoseSpeed(float speed);
	void LoseVision(float vision);
	void LoseStrength(float strength);

	void Spawn(float x, float y);

	int   getEnergy()   { return m_energy; }
	float getSpeed()    { return m_speed; }
	float getVision()   { return m_vision; }
	float getStrength() { return m_strength; }

	void SetMoveDirX(float x)         { m_moveDir.x = x; }
	void SetMoveDirY(float y)         { m_moveDir.y = y; }
	void SetMoveDir(float x, float y) {m_moveDir.x = x; m_moveDir.y = y; }
};

#endif /* CREATURE_H_ */
