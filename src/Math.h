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

	inline float sigmoid(float value)
	{
		return 1 / (1 + static_cast<float>(exp(static_cast<double>(-value))));
	}

	inline float hyperpolicTangent(float value)
	{
		return 1.0f - 2.0f / (static_cast<float>(exp(2 * static_cast<double>(value))) + 1.0f);
	}

	inline float frand(float min, float max)
	{
		return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX/(max-min));
	}

	inline float degreesToRadians(float angle)
	{
		return M_PIf32 / 180.0f * angle;
	}
}


#endif /* MATH_H_ */
