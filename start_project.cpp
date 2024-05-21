#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread> // для имитации загрузки
#include <Windows.h>
#include "func.h"
#include "CharactersMoov.h"
#include <sstream>



using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");

    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(1775, 1000), "Mortal Kombat");
    window.setFramerateLimit(120);


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

    std::vector<sf::Texture> frames2;
    frames2.push_back(sf::Texture());
    for (int i = 0; i < 163; ++i)
    {
        frames2.push_back(sf::Texture());
        frames2[i].loadFromFile("tenor/tenor-" + to_string(i) + ".png");


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

    sf::Texture textureSelectCharacter;
    if (!textureSelectCharacter.loadFromFile("selectCharacter.jpeg"))
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
    sf::Sprite spriteSelectCharacter(textureSelectCharacter);


    

    //******************* перс1 ******************************//

    sf::Texture textureCh1;
    if (!textureCh1.loadFromFile("Character1/Character1_static.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh1(textureCh1);

    //первый перс зеркалка

    sf::Texture textureCh1Mir;
    if (!textureCh1Mir.loadFromFile("Character1/Character1_mir_static.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh1Mir(textureCh1Mir);



    spriteCh1.setTexture(textureCh1);
    spriteCh1.scale(0.9, 0.9);
    spriteCh1.setPosition(100, 250);


    spriteCh1Mir.setTexture(textureCh1Mir);
    spriteCh1Mir.scale(0.9, 0.9);
    spriteCh1Mir.setPosition(1200, 250);

    std::vector<sf::Texture> textureRightCh1;
    textureRightCh1.push_back(sf::Texture());
    textureRightCh1.push_back(sf::Texture());
    textureRightCh1[0].loadFromFile("Character1/Character1_runL.png");
    textureRightCh1[1].loadFromFile("Character1/Character1_runR.png");



    sf::Sprite spriteR;

    sf::Sprite spR1(textureRightCh1[0]);
    spR1.setScale(0.7f, 0.7f);
    
    sf::Sprite spR2(textureRightCh1[1]);
    spR2.setScale(0.6f, 0.6f);



    

    //******************* перс2 ******************************//


    sf::Texture textureCh2;
    if (!textureCh2.loadFromFile("Character2/stepOneCh2.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh2(textureCh2);

    //второй перс зеркалка

    sf::Texture textureCh2Mir;
    if (!textureCh2Mir.loadFromFile("Character2/stepOneCh2_mirr.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh2Mir(textureCh2Mir);



    spriteCh2.setTexture(textureCh2);
    spriteCh2.scale(1.3, 1.3);
    spriteCh2.setPosition(100, 375);


    spriteCh2Mir.setTexture(textureCh2Mir);
    spriteCh2Mir.scale(1.3, 1.3);
    spriteCh2Mir.setPosition(1200, 375);


    sf::Texture textureCh2Step;
    if (!textureCh2Step.loadFromFile("Character2/stepTwoCh2.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh2Step(textureCh2Step);




    
    //******************* перс3 ******************************//

    sf::Texture textureCh3;
    if (!textureCh3.loadFromFile("Character3/staticCh3.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3(textureCh3);

    //второй перс зеркалка

    sf::Texture textureCh3Mir;
    if (!textureCh3Mir.loadFromFile("Character3/staticCh3_mirr.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3Mir(textureCh3Mir);



    spriteCh3.setTexture(textureCh3);
    spriteCh3.scale(2, 2);
    spriteCh3.setPosition(80, 345);


    spriteCh3Mir.setTexture(textureCh3Mir);
    spriteCh3Mir.scale(1.8, 1.8);
    spriteCh3Mir.setPosition(1200, 430);


    sf::Texture textureCh3StepOne;
    if (!textureCh3StepOne.loadFromFile("Character3/stepOneCh3.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3StepOne(textureCh3StepOne);

    sf::Texture textureCh3StepTwo;
    if (!textureCh3StepTwo.loadFromFile("Character3/stepTwoCh3.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3StepTwo(textureCh3StepTwo);









    bool map1 = false, map2 = false, map3 = false, map4 = false;
    bool CharacterSelected = false; bool MouseClick = false;

    bool Ch1 = false, Ch2 = false, Ch3 = false, Ch4 = false;
    

   




    while (window.isOpen())
    {
        menuWithPlay(window, spriteMenu, textureMenu, spritePlay, texturePlay);

        if(isMainMenuVisible)
        {
            animationAfterPlay(window, clips);
            backgroundSelection(window, spriteChoice, textureChoice,
                map1, map2, map3, map4, MouseClick);
            
            if(MouseClick)
            {
                
                sf::sleep(sf::milliseconds(300));
                ChoiceCharacter(window, spriteSelectCharacter, textureSelectCharacter, CharacterSelected, Ch1, Ch2, Ch3, Ch4);

                if (CharacterSelected)
                {
                    loading(window, frames2);
                    
                    
                    if (map1)
                    {
                        loading(window, frames2);
                        sf::sleep(sf::milliseconds(300));
                        playInMap4(window, spritePlace1, texturePlace1);

                        if(Ch1)
                        {
                            DrawCharacter1(window, textureRightCh1, spR1, spR2, textureCh1, spriteCh1, spriteCh1Mir);
                        }
                        if (Ch2)
                        {
                            DrawCharacter2(window, spriteCh2Step, textureCh2, spriteCh2, spriteCh2Mir);

                        }
                        if (Ch3)
                        {
                            DrawCharacter3(window, spriteCh3StepOne, spriteCh3StepTwo, spriteCh3, spriteCh3Mir);
                        }
                    }
                    if (map2)
                    {
                        loading(window, frames2);
                        sf::sleep(sf::milliseconds(300));
                        playInMap4(window, spritePlace2, texturePlace2);

                        //DrawCharacters(window);
                    }
                    if (map3)
                    {
                        loading(window, frames2);
                        sf::sleep(sf::milliseconds(300));
                        playInMap4(window, spritePlace3, texturePlace3);

                        //DrawCharacters(window);
                    }

                    if (map4)
                    {
                        loading(window, frames2);
                        sf::sleep(sf::milliseconds(300));
                        playInMap4(window, spritePlace4, texturePlace4);

                        //DrawCharacters(window);
                    }

                }
            }

            

        }

        

        window.display();
    }

    return 0;
}
