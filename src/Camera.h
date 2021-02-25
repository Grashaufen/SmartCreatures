/*
 * Camera.h
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <SFML/Graphics.hpp>

class Camera
{
private:
	sf::RenderWindow *m_pRenderWindow;
	sf::View          m_view;

	sf::Vector2f      m_viewport;

	sf::Vector2f      m_mousePositionLastTick;
	sf::Vector2f      m_mousePositionCurrentTick;

	float             m_moveSpeed;
	float             m_zoom;

public:
	Camera(sf::RenderWindow *pRenderWindow, sf::Vector2f spawnPoint, float moveSpeed = 20.0f);

	void Update();
	void Set();
};

#endif /* CAMERA_H_ */
