/*
 * Math.h
 *
 *  Created on: 21.02.2021
 *      Author: jannes
 */

#ifndef MATH_H_
#define MATH_H_

#include <SFML/Graphics.hpp>
#include <math.h>

namespace Math
{
	inline float Vector2fGetLength(const sf::Vector2f &vec)
	{
		return sqrtf(vec.x * vec.x + vec.y * vec.y);
	}

	inline sf::Vector2f Vector2fNormalize(sf::Vector2f &vec)
	{
		float length = Vector2fGetLength(vec);

		if(length != 0.0f)
		{
			vec.x /= length;
			vec.y /= length;
		}

		return vec;
	}
}


#endif /* MATH_H_ */
