/*
 * TextureLoader.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "TextureLoader.h"

std::string TextureLoader::m_texturesFolder = "textures/";

sf::Texture TextureLoader::m_fieldBackground = sf::Texture();


void TextureLoader::Load()
{
	m_fieldBackground.loadFromFile(m_texturesFolder + "field-background.png");
}
