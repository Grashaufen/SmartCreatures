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
	sf::View m_view;

public:
	Camera();

	void Update();
	void Set(sf::RenderWindow *pRenderWindow);
};

#endif /* CAMERA_H_ */
