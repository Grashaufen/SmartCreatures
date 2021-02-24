/*
 * Camera.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "Camera.h"

/*
 * TODO: Make the window size accessible to this class and implement basic camera functions
 */

Camera::Camera()
{
	m_view.reset(sf::FloatRect(10.0f, 10.0f, 1280.0f, 720.0f));
}


void Camera::Update()
{
	//m_view.rotate(1.0f);
	m_view.move(1.0f, 0.4f);
}

void Camera::Set(sf::RenderWindow *pRenderWindow)
{
	pRenderWindow->setView(m_view);
}
