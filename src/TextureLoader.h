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
private:
	static std::string m_texturesFolder;

public:
	static sf::Texture m_fieldBackground;

	static void Load();
};

#endif /* TEXTURELOADER_H_ */
