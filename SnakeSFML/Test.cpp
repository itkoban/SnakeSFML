#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Snake.h"
#include "Menu.h"
#include "Game.h"
#include "Dictionary.h"

using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode::getDesktopMode(), "Snake Game!", sf::Style::Fullscreen);

    window.setFramerateLimit(60);

    Menu menu(window);

    Game game;

    Dictionary dic;

    Clock clock;
    float timer = 0, delay = 0.15;

    dic.init("dictionaries/Dictionary.txt");
    dic.initWords();
    
    

    

    
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::KeyPressed) {
                

                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {

                    if (menu.isMenu()) {

                        game.stop(false);
                        menu.goMenu(false);
                    }
                    else {
                        game.stop(true);
                        menu.goMenu(true);
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::Space))
                {

                    if (game.isPause()) 
                    {
                        game.pause(false);
                    }
                    else 
                    {
                        game.pause(true);
                    }
                }
                
                

            }

            if (e.type == Event::KeyReleased)
            {
                if (e.key.code == Keyboard::Left)
                {
                    if (!game.isPause())
                    {
                        game.input(Keyboard::Left);
                    }
                }
                
                if (e.key.code == Keyboard::Right)
                {
                    if (!game.isPause())
                    {
                        game.input(Keyboard::Right);
                    }
                }
                
                if (e.key.code == Keyboard::Up)
                {
                    if (!game.isPause())
                    {
                        game.input(Keyboard::Up);
                    }
                }
                
                if (e.key.code == Keyboard::Down)
                {
                    if (!game.isPause())
                    {
                        game.input(Keyboard::Down);
                    }
                }
            }

        }
        
        
        window.clear(Color::White);
        if (menu.isMenu()) {
            
            menu.draw(window);
            menu.events(window);
            if (!menu.isMenu()) game.stop(false);
        }
        else if (!game.isStop()) {
            game.Tick();
            game.draw(window);
        }
        else {
            menu.goMenu(true);
        }
        window.display();
    }
    
    return 0;
}

