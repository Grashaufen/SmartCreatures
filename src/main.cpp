// MAIN_CPP //
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

#include "NeuralNetworkCreature.h"

#include "Creature.h"
#include "CreatureStats.h"

#include <time.h>

int main(int argc, char** argv)
{
	srand(time(nullptr));

	sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "SmartCreatures", sf::Style::Close);

	std::shared_ptr<Creature> creature(new Creature());
	creature->Spawn(400.0f, 300.0f);

	std::unique_ptr<CreatureStats> pStats(new CreatureStats(creature));
	pStats->Create();

	while(renderWindow.isOpen())
	{
		sf::Event event;
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				renderWindow.close();
		}

		creature->Update();
		pStats->Update();

		renderWindow.clear(sf::Color::Black);
		creature->Render(&renderWindow);
		pStats->Render(&renderWindow);
		renderWindow.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}
