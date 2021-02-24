/*
 * TextureLoader.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "TextureLoader.h"


sf::Texture *TextureLoader::m_pFieldBackground = new sf::Texture();


void TextureLoader::Load()
{
	m_pFieldBackground->loadFromFile("textures/field-background.png");
	m_pFieldBackground->setRepeated(true);
}

void TextureLoader::Release()
{
	if(m_pFieldBackground) { delete m_pFieldBackground; m_pFieldBackground = nullptr; }
}
