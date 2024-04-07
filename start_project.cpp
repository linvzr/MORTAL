#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread> // для имитации загрузки
#include <Windows.h>
#include "func.h"
#include <sstream>


using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");

    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(1775, 1000), "Mortal Kombat");


    std::vector<sf::Texture> frames;
    frames.push_back(sf::Texture());
    for(int i = 0; i < 164; ++i)
    {
        frames.push_back(sf::Texture());
        frames[i].loadFromFile("load/load-" + to_string(i) + ".png");

        
    }
    std::vector<sf::Texture> clips;
    clips.push_back(sf::Texture());
    for (int i = 0; i < 8; ++i)
    {
        if(i < 10)
        {
            clips.push_back(sf::Texture());
            clips[i].loadFromFile("perehod/perehod_00" + to_string(i) + ".png");
        }
        else
        {
            clips.push_back(sf::Texture());
            clips[i].loadFromFile("perehod/perehod_0" + to_string(i) + ".png");
        }


    }



    showLoadingScreen(window, frames);
    simulateLoading(); // Имитация загрузки


    sf::Texture texturePlace1;
    if (!texturePlace1.loadFromFile("place1.jpeg"))
    {
        throw std::runtime_error("IMG is not open");
    }

    sf::Texture texturePlace2;
    if (!texturePlace2.loadFromFile("place2.jpeg"))
    {
        throw std::runtime_error("IMG is not open");
    }

    sf::Texture texturePlace3;
    if (!texturePlace3.loadFromFile("place3.jpeg"))
    {
        throw std::runtime_error("IMG is not open");
    }
    


    sf::Texture texturePlace4;
    if (!texturePlace4.loadFromFile("place4.png"))
    {
        throw std::runtime_error("IMG is not open");
    }


    sf::Texture textureMenu;
    if (!textureMenu.loadFromFile("Menu.jpeg"))
    {
        throw std::runtime_error("Menu image is not open");
    }


    sf::Texture texturePlay;
    if (!texturePlay.loadFromFile("start.png"))
    {
        throw std::runtime_error("PLAY image is not open");
    }

    sf::Texture textureChoice;
    if (!textureChoice.loadFromFile("background_selection.jpeg"))
    {
        throw std::runtime_error("Choice image is not open");
    }




    sf::Sprite spritePlace1(texturePlace1);
    sf::Sprite spritePlace2(texturePlace2);
    sf::Sprite spritePlace3(texturePlace3);
    sf::Sprite spritePlace4(texturePlace4);


    sf::Sprite spriteMenu(textureMenu);
    sf::Sprite spritePlay(texturePlay);
    sf::Sprite spriteChoice(textureChoice);

    bool map1 = false, map2 = false, map3 = false, map4 = false;


    while (window.isOpen())
    {
        menuWithPlay(window, spriteMenu, textureMenu, spritePlay, texturePlay);

        if(isMainMenuVisible)
        {
            animationAfterPlay(window, clips);
            backgroundSelection(window, spriteChoice, textureChoice,
                map1, map2, map3, map4);
            if (map1)
            {
                sf::sleep(sf::milliseconds(300));
                playInMap4(window, spritePlace1, texturePlace1);
            }
            if (map2)
            {
                sf::sleep(sf::milliseconds(300));
                playInMap4(window, spritePlace2, texturePlace2);
            }
            if (map3)
            {
                sf::sleep(sf::milliseconds(300));
                playInMap4(window, spritePlace3, texturePlace3);
            }

            if (map4)
            {
                sf::sleep(sf::milliseconds(300));
                playInMap4(window, spritePlace4, texturePlace4);
            }

            

        }

        if (GetAsyncKeyState(VK_F11))
        {
            HWND hwnd = window.getSystemHandle();
            SetForegroundWindow(hwnd);
            SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }

        window.display();
    }

    return 0;
}
