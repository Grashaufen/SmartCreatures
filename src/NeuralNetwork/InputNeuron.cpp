/*
 * InputNeuron.cpp
 *
 *  Created on: 22.02.2021
 *      Author: jannes
 */

#include "InputNeuron.h"

float InputNeuron::getValue()
{
	return m_value;
}

void InputNeuron::SetValue(float value)
{
	m_value = value;
}
