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

	float             m_zoomSpeed;
	float             m_zoom;

public:
	Camera(sf::RenderWindow *pRenderWindow, sf::Vector2f spawnPoint, float zoomSpeed = 0.01f);

	void Update(const sf::Clock &clock);
	void Set();
};

#endif /* CAMERA_H_ */
