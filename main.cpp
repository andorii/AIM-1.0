#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Menu.h"
using namespace sf;

int main()
{
	RenderWindow oknoAplikacji(VideoMode(800, 600, 32), "Aim Trainer 1.0 alpha"); //uzycie konstruktora klasy RenderWindow
	Menu menu(oknoAplikacji.getSize().x,oknoAplikacji.getSize().y);
	Event zdarzenie;
	while (oknoAplikacji.isOpen())
	{
		
		while (oknoAplikacji.pollEvent(zdarzenie))//odczytywanie zdarzen z okna aplikacja
		{
			switch (zdarzenie.type)
			{
			case Event::KeyReleased:
				switch (zdarzenie.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;
				case Keyboard::Down:
					menu.MoveDown();
					break;
				case Keyboard::Escape:
					oknoAplikacji.close();
					break;
				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button pressed" << std::endl;
						break;
					case 1:
						std::cout << "Options button pressed" << std::endl;
						break;
					case 2:
						oknoAplikacji.close();
						break;
					}

					break;
				}
				break;
			case Event::Closed:
				oknoAplikacji.close();
				break;
			}
		}
		oknoAplikacji.clear();
		menu.draw(oknoAplikacji);
		oknoAplikacji.display();

	}
	
	return 0;
}