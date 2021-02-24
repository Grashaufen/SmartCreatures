/*
 * FontLoader.h
 *
 *  Created on: 24.02.2021
 *      Author: jannes
 */

#ifndef FONTLOADER_H_
#define FONTLOADER_H_

#include <string>
#include <SFML/Graphics.hpp>

class FontLoader
{
private:
	static std::string m_fontsFolder;

public:
	static sf::Font    m_arial;

	static void Load();
};

#endif /* FONTLOADER_H_ */
