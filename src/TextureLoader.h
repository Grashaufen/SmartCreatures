/*
 * TextureLoader.h
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <string>
#include <SFML/Graphics.hpp>

class TextureLoader
{
public:
	static sf::Texture *m_pFieldBackground;
	static sf::Texture *m_pCreatureBody;

	static void Load();
	static void Release();
};

#endif /* TEXTURELOADER_H_ */
