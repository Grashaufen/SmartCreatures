// MAIN_CPP //
#include <iostream>
#include <thread>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "FontLoader.h"
#include "TextureLoader.h"

#include "Simulation.h"

#include "NeuralNetworkCreature.h"
//#include "Creature.h"
//#include "CreatureStats.h"

int main(int argc, char** argv)
{
	srand(time(nullptr));

	sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "SmartCreatures", sf::Style::Close);

	Simulation sim(&renderWindow);

//	std::shared_ptr<Creature> creature(new Creature());
//	creature->Spawn(400.0f, 300.0f);
//
//	std::unique_ptr<CreatureStats> pStats(new CreatureStats(creature));
//	pStats->Create();
//
	NeuralNetworkCreature nn;
	nn.Create();

	// initialisation of content
	FontLoader::Load();
	TextureLoader::Load();

	sim.Create();

	while(renderWindow.isOpen())
	{
		sf::Event event;
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				renderWindow.close();
		}

		sim.Update();
//		creature->Update();
//		pStats->Update();

		renderWindow.clear(sf::Color::Black);

		sim.Render();
//		creature->Render(&renderWindow);
//		pStats->Render(&renderWindow);
		renderWindow.display();
	}

	FontLoader::Release();
	TextureLoader::Release();

	return 0;
}
