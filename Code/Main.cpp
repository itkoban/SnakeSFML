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

    GameMenu game_menu(window);

    Menu menu(window);

    Game game(window);

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

                    if (game.getGameState() == GAME_STATE::PLAY || game.getGameState() == GAME_STATE::PAUSE)
                    {

                        game.setGameState(GAME_STATE::MENU);
        
                    }

                }

                if (Keyboard::isKeyPressed(Keyboard::Space))
                {

                    if (game.getGameState() == GAME_STATE::PLAY)
                    {

                        game.setGameState(GAME_STATE::PAUSE);

                    }
                    else if (game.getGameState() == GAME_STATE::PAUSE)
                    {

                        game.setGameState(GAME_STATE::PLAY);

                    }
                }
                
                

            }

            if (e.type == Event::KeyReleased)
            {
                if (game.getGameState() == GAME_STATE::PLAY)
                {
                    if (e.key.code == Keyboard::Left)
                    {
                        game.input(Keyboard::Left);
                    }

                    else if (e.key.code == Keyboard::Right)
                    {
                        game.input(Keyboard::Right);
                    }

                    else if (e.key.code == Keyboard::Up)
                    {
                        game.input(Keyboard::Up);
                    }

                    else if (e.key.code == Keyboard::Down)
                    {
                        game.input(Keyboard::Down);
                    }

                    else if (e.key.code == Keyboard::Escape)
                    {
                        game.setGameState(GAME_STATE::MENU);
                    }
                    
                }  
                if (game.getGameState() == GAME_STATE::PAUSE)
                {
                    if (e.key.code == Keyboard::Escape)
                    {
                        game.setGameState(GAME_STATE::MENU);
                    }
                }
            }
        }
        
        
        window.clear(Color::White);
        if (game.getGameState() == GAME_STATE::MENU) {
            
            menu.draw(window);
           
            if (!menu.isActive())
            {
                menu.activate();
            }
            else
            {
                menu.events(window);

                switch (menu.getState())
                {
                case MENU_STATE::GAME:
                {
                    game.setGameState(GAME_STATE::PLAY);
                    menu.setState(MENU_STATE::NONE);
                    break;
                }

                case MENU_STATE::CLOSE:
                {
                    window.close();
                    break;
                }

                case MENU_STATE::NONE:
                {

                }

                }
            }
        }
        else if (game.getGameState() == GAME_STATE::PLAY) {
            game.Tick(window);
            game.draw(window);
        }
        else if (game.getGameState() == GAME_STATE::PAUSE) {
            game.draw(window);
        }
        else if (game.getGameState() == GAME_STATE::RESULT) {
            game_menu.draw(window);
            switch (game_menu.events(window))
            {
                
                case COMMAND::BACK:
                {
                    if (!game.isGameOver())
                    {
                        game.setGameState(GAME_STATE::PLAY);
                    }
                    break;
                }

                case COMMAND::MENU:
                {
                    game.restart();
                    game.setGameState(GAME_STATE::MENU);
                    menu.setState(MENU_STATE::NONE);
                    menu.disable();
                    break;
                }

                case COMMAND::RETRY:
                {
                    game.restart();
                    game.setGameState(GAME_STATE::PLAY);
                    break;
                }

                case COMMAND::NONE:
                {

                }

            }
        }
        window.display();
    }
    
    return 0;
}

