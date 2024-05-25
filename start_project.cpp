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


    sf::Texture textureCh1_sit;
    if (!textureCh1_sit.loadFromFile("Character1/sitCh1.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh1_sit(textureCh1_sit);

    sf::Texture textureCh1_udar;
    if (!textureCh1_udar.loadFromFile("Character1/udarCh1.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh1_udar(textureCh1_udar);



    

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


    sf::Texture textureCh2_sit;
    if (!textureCh2_sit.loadFromFile("Character2/sitCh2.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh2_sit(textureCh2_sit);


    sf::Texture textureCh2_udar;
    if (!textureCh2_udar.loadFromFile("Character2/udarCh2.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh2_udar(textureCh2_udar);







    
    //******************* перс3 ******************************//

    sf::Texture textureCh3;
    if (!textureCh3.loadFromFile("Character3/staticCh3.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3(textureCh3);

    //третий перс зеркалка

    sf::Texture textureCh3Mir;
    if (!textureCh3Mir.loadFromFile("Character3/staticCh3_mirr.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3Mir(textureCh3Mir);



    spriteCh3.setTexture(textureCh3);
    spriteCh3.scale(2, 2);
    spriteCh3.setPosition(80, 345+100);


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


    sf::Texture textureCh3_sit;
    if (!textureCh3_sit.loadFromFile("Character3/sitCh3.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3_sit(textureCh3_sit);

    sf::Texture textureCh3_udar;
    if (!textureCh3_udar.loadFromFile("Character3/udarCh3.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3_udar(textureCh3_udar);




    //******************* перс4 ******************************//

    sf::Texture textureCh4;
    if (!textureCh4.loadFromFile("Character4/staticCh4.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh4(textureCh4);

    //четвертый перс зеркалка

    sf::Texture textureCh4Mir;
    if (!textureCh4Mir.loadFromFile("Character4/staticCh4_mirr.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh4Mir(textureCh4Mir);


    spriteCh4.setTexture(textureCh4);
    spriteCh4.scale(1.9,1.9);
    spriteCh4.setPosition(140, 395);


    spriteCh4Mir.setTexture(textureCh4Mir);
    spriteCh4Mir.scale(1.9, 1.9);
    spriteCh4Mir.setPosition(1210, 420);


    sf::Texture textureCh4StepOne;
    if (!textureCh4StepOne.loadFromFile("Character4/stepOneCh4.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh4StepOne(textureCh4StepOne);

    sf::Texture textureCh4StepTwo;
    if (!textureCh4StepTwo.loadFromFile("Character4/stepTwoCh4.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh4StepTwo(textureCh4StepTwo);


    sf::Texture textureCh4_sit;
    if (!textureCh4_sit.loadFromFile("Character4/sitCh4.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh4_sit(textureCh4_sit);

    sf::Texture textureCh4_udar;
    if (!textureCh4_udar.loadFromFile("Character4/udarCh4.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh4_udar(textureCh4_udar);


    //************************************************************************************************//





   
    sf::Text healthOne;
    sf::Font txtOne;
    if (!txtOne.loadFromFile("arial.ttf")) {
        cout << "error";
    }

    healthOne.setFont(txtOne);

    sf::Text healthTwo;
    sf::Font txtTwo;
    if (!txtTwo.loadFromFile("arial.ttf")) {
        cout << "error";
    }

    healthTwo.setFont(txtTwo);

    sf::Text txt;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "error";
    }
    txt.setFont(font);





    bool map1 = false, map2 = false, map3 = false, map4 = false;
    bool CharacterSelected = false; bool MouseClick = false;

    bool Ch1 = false, Ch2 = false, Ch3 = false, Ch4 = false;
    

    int h1 = 100, h2 = 100;




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
                        if (h1 != 0 && h2 != 0)
                        {
                            if (Ch1)
                            {
                                DrawCharacter1(window, textureRightCh1, spR1, spR2, textureCh1,
                                    spriteCh1, spriteCh1Mir, spriteCh1_sit, spriteCh1_udar);
                            }
                            if (Ch2)
                            {
                                DrawCharacter2(window, spriteCh2Step, textureCh2, spriteCh2,
                                    spriteCh2Mir, spriteCh2_sit, spriteCh2_udar);

                            }
                            if (Ch3)
                            {
                                DrawCharacter3(window, spriteCh3StepOne, spriteCh3StepTwo, spriteCh3,
                                    spriteCh3Mir, spriteCh3_sit, spriteCh3_udar);
                            }
                            if (Ch4)
                            {
                                DrawCharacter4(window, spriteCh4StepOne, spriteCh4StepTwo, spriteCh4,
                                    spriteCh4Mir, spriteCh4_sit, spriteCh4_udar);
                            }
                            health(window, spriteCh1, spriteCh2, spriteCh3, spriteCh4,
                                spriteCh1Mir, spriteCh2Mir, spriteCh3Mir, spriteCh4Mir,
                                Ch1, Ch2, Ch3, Ch4, h1, h2, healthOne, healthTwo);
                        }
                        
                        else
                        {
                            if (h1 == 0) { winner_two(window, txt); }
                            else winner_one(window, txt);
                        }


                    }
                    if (map2)
                    {
                        loading(window, frames2);
                        sf::sleep(sf::milliseconds(300));
                        playInMap4(window, spritePlace2, texturePlace2);

                        if (h1 != 0 && h2 != 0)
                        {
                            if (Ch1)
                            {
                                DrawCharacter1(window, textureRightCh1, spR1, spR2, textureCh1,
                                    spriteCh1, spriteCh1Mir, spriteCh1_sit, spriteCh1_udar);
                            }
                            if (Ch2)
                            {
                                DrawCharacter2(window, spriteCh2Step, textureCh2, spriteCh2,
                                    spriteCh2Mir, spriteCh2_sit, spriteCh2_udar);

                            }
                            if (Ch3)
                            {
                                DrawCharacter3(window, spriteCh3StepOne, spriteCh3StepTwo, spriteCh3,
                                    spriteCh3Mir, spriteCh3_sit, spriteCh3_udar);
                            }
                            if (Ch4)
                            {
                                DrawCharacter4(window, spriteCh4StepOne, spriteCh4StepTwo, spriteCh4,
                                    spriteCh4Mir, spriteCh4_sit, spriteCh4_udar);
                            }
                            health(window, spriteCh1, spriteCh2, spriteCh3, spriteCh4,
                                spriteCh1Mir, spriteCh2Mir, spriteCh3Mir, spriteCh4Mir,
                                Ch1, Ch2, Ch3, Ch4, h1, h2, healthOne, healthTwo);
                        }

                        else
                        {
                            if (h1 == 0) { winner_two(window, txt); }
                            else winner_one(window, txt);
                        }

                    }
                    if (map3)
                    {
                        loading(window, frames2);
                        sf::sleep(sf::milliseconds(300));
                        playInMap4(window, spritePlace3, texturePlace3);
                        if (h1 != 0 && h2 != 0)
                        {
                            if (Ch1)
                            {
                                DrawCharacter1(window, textureRightCh1, spR1, spR2, textureCh1,
                                    spriteCh1, spriteCh1Mir, spriteCh1_sit, spriteCh1_udar);
                            }
                            if (Ch2)
                            {
                                DrawCharacter2(window, spriteCh2Step, textureCh2, spriteCh2,
                                    spriteCh2Mir, spriteCh2_sit, spriteCh2_udar);

                            }
                            if (Ch3)
                            {
                                DrawCharacter3(window, spriteCh3StepOne, spriteCh3StepTwo, spriteCh3,
                                    spriteCh3Mir, spriteCh3_sit, spriteCh3_udar);
                            }
                            if (Ch4)
                            {
                                DrawCharacter4(window, spriteCh4StepOne, spriteCh4StepTwo, spriteCh4,
                                    spriteCh4Mir, spriteCh4_sit, spriteCh4_udar);
                            }
                            health(window, spriteCh1, spriteCh2, spriteCh3, spriteCh4,
                                spriteCh1Mir, spriteCh2Mir, spriteCh3Mir, spriteCh4Mir,
                                Ch1, Ch2, Ch3, Ch4, h1, h2, healthOne, healthTwo);
                        }

                        else
                        {
                            if (h1 == 0) { winner_two(window, txt); }
                            else winner_one(window, txt);
                        }

                    }

                    if (map4)
                    {
                        loading(window, frames2);
                        sf::sleep(sf::milliseconds(300));
                        playInMap4(window, spritePlace4, texturePlace4);

                        if (h1 != 0 && h2 != 0)
                        {
                            if (Ch1)
                            {
                                DrawCharacter1(window, textureRightCh1, spR1, spR2, textureCh1,
                                    spriteCh1, spriteCh1Mir, spriteCh1_sit, spriteCh1_udar);
                            }
                            if (Ch2)
                            {
                                DrawCharacter2(window, spriteCh2Step, textureCh2, spriteCh2,
                                    spriteCh2Mir, spriteCh2_sit, spriteCh2_udar);

                            }
                            if (Ch3)
                            {
                                DrawCharacter3(window, spriteCh3StepOne, spriteCh3StepTwo, spriteCh3,
                                    spriteCh3Mir, spriteCh3_sit, spriteCh3_udar);
                            }
                            if (Ch4)
                            {
                                DrawCharacter4(window, spriteCh4StepOne, spriteCh4StepTwo, spriteCh4,
                                    spriteCh4Mir, spriteCh4_sit, spriteCh4_udar);
                            }
                            health(window, spriteCh1, spriteCh2, spriteCh3, spriteCh4,
                                spriteCh1Mir, spriteCh2Mir, spriteCh3Mir, spriteCh4Mir,
                                Ch1, Ch2, Ch3, Ch4, h1, h2, healthOne, healthTwo);
                        }

                        else
                        {
                            if (h1 == 0) { winner_two(window, txt); }
                            else winner_one(window, txt);
                        }

                    }

                }
            }

            

        }

        

        window.display();
    }

    return 0;
}
