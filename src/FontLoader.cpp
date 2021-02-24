/*
 * FontLoader.cpp
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#include "FontLoader.h"


sf::Font *FontLoader::m_pArial = new sf::Font();

void FontLoader::Load()
{
	FontLoader::m_pArial->loadFromFile("fonts/arial.ttf");
}

void FontLoader::Release()
{
	if(m_pArial) { delete m_pArial; m_pArial = nullptr; }
}
