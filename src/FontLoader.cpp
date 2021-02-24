/*
 * FontLoader.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "FontLoader.h"

std::string FontLoader::m_fontsFolder = "fonts/";

sf::Font FontLoader::m_arial = sf::Font();

void FontLoader::Load()
{
	FontLoader::m_arial.loadFromFile(m_fontsFolder + "arial.ttf");
}
