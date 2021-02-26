/*
 * Camera.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "Camera.h"
#include "Math.h"
#include <iostream>

/*
 * TODO: Make the window size accessible to this class and implement basic camera functions
 */

Camera::Camera(sf::RenderWindow *pRenderWindow, sf::Vector2f spawnPoint)
	: m_pRenderWindow(pRenderWindow),
	  m_mousePositionLastTick(sf::Vector2f()),
	  m_mousePositionCurrentTick(sf::Vector2f()),
	  m_zoom(1.0f)
{
	m_viewport = static_cast<sf::Vector2f>(pRenderWindow->getSize());

	m_view.reset(sf::FloatRect(spawnPoint.x, spawnPoint.y, m_viewport.x, m_viewport.y));
}


void Camera::Update()
{
	// camera movement
	m_mousePositionLastTick = m_mousePositionCurrentTick;
	m_mousePositionCurrentTick = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*m_pRenderWindow));

	sf::Vector2f mousePosDelta = m_mousePositionLastTick - m_mousePositionCurrentTick;

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		m_view.move(m_zoom * mousePosDelta.x, m_zoom * mousePosDelta.y);

	// camera zoom
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_zoom < 10.0f)
		m_zoom += 0.1f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_zoom > 0.1f)
		m_zoom -= 0.1f;

	m_view.setSize(m_viewport.x * m_zoom, m_viewport.y * m_zoom);
}

void Camera::Set()
{
	m_pRenderWindow->setView(m_view);
}
