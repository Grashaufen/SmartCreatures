/*
 * PrimitiveCreature.h
 *
 *  Created on: 26.02.2021
 *      Author: jannes
 */

#ifndef PRIMITIVECREATURE_H_
#define PRIMITIVECREATURE_H_

#include <SFML/Graphics.hpp>
#include "NeuralNetwork/NeuralNetworkMutational.h"
#include "NeuralNetwork/WorkingNeuron.h"
#include "Food.h"

class Simulation;

class PrimitiveCreature : public NeuralNetworkMutational
{
protected:
	Simulation     *m_pSimulation;
	Food           *m_pNextFood;
	sf::CircleShape m_body;
	bool            m_isChild;
	float           m_radius;
	float           m_visionRadius;

	std::vector<std::unique_ptr<InputNeuron>>                                 *m_pParentInputNeurons;
	std::vector<std::unique_ptr<std::vector<std::unique_ptr<WorkingNeuron>>>> *m_pParentHiddenNeurons;
	std::vector<std::unique_ptr<WorkingNeuron>>                               *m_pParentOutputNeurons;

	// important netinput
	float        m_energy;           // i = 1
	float        m_voidDistance;     // i = 2
	float        m_nextFood;         // i = 3
	bool         m_isOnFood;         // i = 4

	// important netoutput
	sf::Vector2f m_moveDir;          // x = i = 0, y = i = 1
	float        m_moveSpeed;        // i = 2
	bool         m_wantToEat;        // i = 3
	bool         m_wantToReproduce;  // i = 4

	float m_energyMalus;
	float m_reproductionMalus;

	bool m_isAlive;

	virtual void PushNeuralInput();
	virtual void PullNeuralOutput();

	virtual void Eat();
	virtual void Reproduce();

public:
	PrimitiveCreature(Simulation *pSimulation, const sf::Vector2f &position, bool isChild = false);
	PrimitiveCreature(Simulation *pSimulation, const sf::Vector2f &position, std::vector<std::unique_ptr<InputNeuron>> *pInputNeurons,
	                  std::vector<std::unique_ptr<std::vector<std::unique_ptr<WorkingNeuron>>>> *pHiddenNeurons, std::vector<std::unique_ptr<WorkingNeuron>> *pOutputNeurons);

	virtual void Create() override;
	virtual void Update(const sf::Clock &clock);
	void Render(sf::RenderWindow *pRenderWindow);

	bool died() { return !m_isAlive; }
	bool isChild() { return m_isChild; }
};

#endif /* PRIMITIVECREATURE_H_ */
