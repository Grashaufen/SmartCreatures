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
public:
	static sf::Font    *m_pArial;

	static void Load();
	static void Release();
};

#endif /* FONTLOADER_H_ */
