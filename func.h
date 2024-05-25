

bool isMainMenuVisible = false; // Флаг для отслеживания видимости главного меню
int currentFrame1 = 1; // Начинаем с первого кадра, так как 0-й кадр - заглушка





void showLoadingScreen(sf::RenderWindow& window, std::vector<sf::Texture>& frames)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text text;
    text.setFont(font);

    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);

    int currentFrame = 1; // Начинаем с первого кадра, так как 0-й кадр - заглушка

    // Отображение всех кадров анимации
    while (currentFrame < frames.size())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(text);

        // Отобразите текущий кадр анимации с установкой новой позиции
        sf::Sprite sprite(frames[currentFrame]);
        sprite.setPosition(600, 300);
        window.draw(sprite);

        window.display();

        // Переключение кадров анимации
        ++currentFrame;

        // Задержка между кадрами
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Можно изменить время задержки

    }
}


void simulateLoading()
{
    // Имитация загрузки
    for (int i = 0; i < 100; ++i)
    {
        // Сюда можно добавить любую логику загрузки игры
        std::this_thread::sleep_for(std::chrono::milliseconds(2)); // Имитация загрузки
    }
}




void playInMap1(sf::RenderWindow& window, sf::Sprite& spritePlace1, sf::Texture& texturePlace1)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    spritePlace1.setTexture(texturePlace1);

   
    float xScale = (float)window.getSize().x / texturePlace1.getSize().x;
    float yScale = (float)window.getSize().y / texturePlace1.getSize().y;

  
    float scale = std::min(xScale, yScale);

    
    spritePlace1.setScale(scale, scale);

    
    spritePlace1.setPosition(0, 0);

    window.clear(sf::Color::Black);
    window.draw(spritePlace1);


}
void playInMap2(sf::RenderWindow& window, sf::Sprite& spritePlace2, sf::Texture& texturePlace2)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    spritePlace2.setTexture(texturePlace2);


    float xScale = (float)window.getSize().x / texturePlace2.getSize().x;
    float yScale = (float)window.getSize().y / texturePlace2.getSize().y;


    float scale = std::min(xScale, yScale);


    spritePlace2.setScale(scale, scale);


    spritePlace2.setPosition(0, 0);

    window.clear(sf::Color::Black);
    window.draw(spritePlace2);


}
void playInMap3(sf::RenderWindow& window, sf::Sprite& spritePlace3, sf::Texture& texturePlace3)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    spritePlace3.setTexture(texturePlace3);


    float xScale = (float)window.getSize().x / texturePlace3.getSize().x;
    float yScale = (float)window.getSize().y / texturePlace3.getSize().y;


    float scale = std::min(xScale, yScale);


    spritePlace3.setScale(scale, scale);


    spritePlace3.setPosition(0, 0);

    window.clear(sf::Color::Black);
    window.draw(spritePlace3);


}
void playInMap4(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    sprite.setTexture(texture);

    // Определяем коэффициенты масштабирования по осям X и Y
    float xScale = (float)window.getSize().x / texture.getSize().x;
    float yScale = (float)window.getSize().y / texture.getSize().y;

    // Выбираем минимальный коэффициент масштабирования, чтобы изображение вместилось полностью
    float scale = std::min(xScale, yScale);

    // Устанавливаем масштаб с сохранением пропорций
    sprite.setScale(scale, scale);

    // Позиционируем спрайт так, чтобы его верхний левый угол был в точке (0, 0) окна
    sprite.setPosition(0, 0);

    window.clear(sf::Color::Black);
    window.draw(sprite);


}


void menuWithPlay(sf::RenderWindow& window, sf::Sprite& spriteMenu, sf::Texture& textureMenu,
    sf::Sprite& spritePlay, sf::Texture& texturePlay)
{



    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

       
        if (event.type == sf::Event::MouseMoved) {
            
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            
            sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);
           
            if (spritePlay.getGlobalBounds().contains(mouseWorldPos))
            {
               
                spritePlay.setScale(0.9f, 0.9f); 
            }
            else
            {
                           
                spritePlay.setScale(1.0f, 1.0f);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlay.getGlobalBounds().contains(mouseWorldPos))
                {
                    // Нажатие произошло в области кнопки "PLAY"
                    isMainMenuVisible = true;
                }

            }
        }
    }

    spriteMenu.setTexture(textureMenu);
    spritePlay.setTexture(texturePlay);


    float xScale = (float)window.getSize().x / textureMenu.getSize().x;
    float yScale = (float)window.getSize().y / textureMenu.getSize().y;
    float scale = std::min(xScale, yScale);
    spriteMenu.setScale(scale, scale);



    spriteMenu.setPosition(0, 0);
    spritePlay.setPosition(500, 500);

    window.clear(sf::Color::Black);

    window.draw(spriteMenu);
    window.draw(spritePlay);



}



void animationAfterPlay(sf::RenderWindow& window, std::vector<sf::Texture>& clips)
{
    sf::Sprite sprite;
    sprite.setPosition(0, 0);
    float scaleFactor = 0.935f; // Коэффициент масштабирования

    // Отображение всех кадров анимации
    while (currentFrame1 < clips.size()-1)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Установка текстуры текущего кадра на спрайт
        sprite.setTexture(clips[currentFrame1]);

        // Установка масштаба спрайта
        sprite.setScale(sf::Vector2f(scaleFactor, scaleFactor));

        // Отображение текущего кадра анимации с установкой новой позиции
        window.draw(sprite);

        window.display();

        // Переключение кадров анимации
        ++currentFrame1;

        // Задержка между кадрами
        std::this_thread::sleep_for(std::chrono::milliseconds(45)); // Можно изменить время задержки
    }
    

}

void backgroundSelection(sf::RenderWindow& window, sf::Sprite& spriteChoice, sf::Texture& textureChoice, bool& map1, bool& map2, bool& map3, bool& map4,
    bool& MouseClick)
{
    

    spriteChoice.setTexture(textureChoice);
   
    float xScale = (float)window.getSize().x / textureChoice.getSize().x;
    float yScale = (float)window.getSize().y / textureChoice.getSize().y;
    float scale = std::min(xScale, yScale);
    spriteChoice.setScale(scale, scale);
    spriteChoice.setPosition(0, 0);

    //1 карта
    sf::Texture texturePlaceOne;
    if (!texturePlaceOne.loadFromFile("choice/map1.jpg"))
    {
        throw std::runtime_error("map2 is not open");
    }
    sf::Sprite spritePlaceOne(texturePlaceOne);
    spritePlaceOne.setTexture(texturePlaceOne);
    spritePlaceOne.setPosition(300, 250);

    //2 карта
    sf::Texture texturePlaceTwo;
    if (!texturePlaceTwo.loadFromFile("choice/map2.jpg"))
    {
        throw std::runtime_error("map2 is not open");
    }
    sf::Sprite spritePlaceTwo(texturePlaceTwo);
    spritePlaceTwo.setTexture(texturePlaceTwo);
    spritePlaceTwo.setPosition(300, 600);

    //3 карта
    sf::Texture texturePlaceThree;
    if (!texturePlaceThree.loadFromFile("choice/map3.jpg"))
    {
        throw std::runtime_error("map2 is not open");
    }
    sf::Sprite spritePlaceThree(texturePlaceThree);
    spritePlaceThree.setTexture(texturePlaceThree);
    spritePlaceThree.setPosition(1150, 250);

    //4 карта
    sf::Texture texturePlaceFour;
    if (!texturePlaceFour.loadFromFile("choice/map4.jpg"))
    {
        throw std::runtime_error("map2 is not open");
    }
    sf::Sprite spritePlaceFour(texturePlaceFour);
    spritePlaceFour.setTexture(texturePlaceFour);
    spritePlaceFour.setPosition(1150, 600);



    
    
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

            
            if (spritePlaceOne.getGlobalBounds().contains(mouseWorldPos))
            {
                
                spritePlaceOne.setScale(0.9f, 0.9f); 
            }
            else
            {
                
                spritePlaceOne.setScale(1.0f, 1.0f); 
               
            }

            if (spritePlaceTwo.getGlobalBounds().contains(mouseWorldPos))
            {

                spritePlaceTwo.setScale(0.9f, 0.9f);
            }
            else
            {

                spritePlaceTwo.setScale(1.0f, 1.0f);

            }

            if (spritePlaceThree.getGlobalBounds().contains(mouseWorldPos))
            {

                spritePlaceThree.setScale(0.9f, 0.9f);
            }
            else
            {

                spritePlaceThree.setScale(1.0f, 1.0f);

            }

            if (spritePlaceFour.getGlobalBounds().contains(mouseWorldPos))
            {

                spritePlaceFour.setScale(0.9f, 0.9f);
            }
            else
            {

                spritePlaceFour.setScale(1.0f, 1.0f);

            }


            
            





            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlaceOne.getGlobalBounds().contains(mouseWorldPos))
                {
                   
                    MouseClick = true;
                    map1 = true;
                }
            }




        

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlaceTwo.getGlobalBounds().contains(mouseWorldPos))
                {
                    
                    MouseClick = true;
                    map2 = true;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlaceThree.getGlobalBounds().contains(mouseWorldPos))
                {
                     
                    MouseClick = true;
                    map3 = true;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlaceFour.getGlobalBounds().contains(mouseWorldPos))
                {
                    
                    MouseClick = true;
                    map4 = true;
                }
            }
            
        }
        


    

    
    window.clear(sf::Color::Black);

    window.draw(spriteChoice);
    window.draw(spritePlaceOne);
    window.draw(spritePlaceTwo);
    window.draw(spritePlaceThree);
    window.draw(spritePlaceFour);


}



int positionPlayer1 = 0, positionPlayer2 = 0;
bool firstClick = false;
bool secondClick = false;


bool Ch1_player1 = false, Ch2_player1 = false, Ch3_player1 = false, Ch4_player1 = false;
bool Ch1_player2 = false, Ch2_player2 = false, Ch3_player2 = false, Ch4_player2 = false;




void ChoiceCharacter(sf::RenderWindow& window, sf::Sprite& spriteSelectCharacter, sf::Texture& textureSelectCharacter, bool& CharacterSelected,
    bool& Ch1, bool& Ch2, bool& Ch3, bool& Ch4)
{
    spriteSelectCharacter.setTexture(textureSelectCharacter);

    float xScale = (float)window.getSize().x / textureSelectCharacter.getSize().x;
    float yScale = (float)window.getSize().y / textureSelectCharacter.getSize().y;
    float scale = std::min(xScale, yScale);
    spriteSelectCharacter.setScale(scale, scale);
    spriteSelectCharacter.setPosition(0, 0);


    sf::Texture textureNext;
    if (!textureNext.loadFromFile("next.png"))
    {
        throw std::runtime_error("next image is not open");
    }
    sf::Sprite spriteNext(textureNext);
    spriteNext.setTexture(textureNext);
    spriteNext.setPosition(1300, 700);
   






    sf::Texture textureCh1;
    if (!textureCh1.loadFromFile("iconCh1.jpg"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh1(textureCh1);
    spriteCh1.setTexture(textureCh1);
    spriteCh1.setPosition(100, 250);


    sf::Texture textureCh2;
    if (!textureCh2.loadFromFile("iconCh2.jpg"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh2(textureCh2);
    spriteCh2.setTexture(textureCh2);
    spriteCh2.setPosition(500, 250);



    sf::Texture textureCh3;
    if (!textureCh3.loadFromFile("iconCh3.jpg"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh3(textureCh3);
    spriteCh3.setTexture(textureCh3);
    spriteCh3.scale(0.5, 0.5);
    spriteCh3.setPosition(900, 250);


    sf::Texture textureCh4;
    if (!textureCh4.loadFromFile("iconCh4.jpg"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh4(textureCh4);
    spriteCh4.setTexture(textureCh4);
    spriteCh4.scale(0.5, 0.5);
    spriteCh4.setPosition(1300, 250);


    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Ошибка загрузки шрифта!" << std::endl;
        
    }
    //координатф для первого ирока
    sf::Text textForCh1_1("player 1", font, 40);
    textForCh1_1.setPosition(175, 550);
    textForCh1_1.setFillColor(sf::Color::Red);

    sf::Text textForCh1_2("player 1", font, 40);
    textForCh1_2.setPosition(575,550);
    textForCh1_2.setFillColor(sf::Color::Red);

    sf::Text textForCh1_3("player 1", font, 40);
    textForCh1_3.setPosition(975, 550);
    textForCh1_3.setFillColor(sf::Color::Red);

    sf::Text textForCh1_4("player 1", font, 40);
    textForCh1_4.setPosition(1375, 550);
    textForCh1_4.setFillColor(sf::Color::Red);


    //координаты для второго игрока
    sf::Text textForCh2_1("player 2", font, 40);
    textForCh2_1.setPosition(175, 550);
    textForCh2_1.setFillColor(sf::Color::Blue);

    sf::Text textForCh2_2("player 2", font, 40);
    textForCh2_2.setPosition(575, 550);
    textForCh2_2.setFillColor(sf::Color::Blue);

    sf::Text textForCh2_3("player 2", font, 40);
    textForCh2_3.setPosition(975, 550);
    textForCh2_3.setFillColor(sf::Color::Blue);

    sf::Text textForCh2_4("player 2", font, 40);
    textForCh2_4.setPosition(1375, 550);
    textForCh2_4.setFillColor(sf::Color::Blue);




    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);


        if (spriteCh1.getGlobalBounds().contains(mouseWorldPos))
        {

            spriteCh1.setScale(0.9f, 0.9f);
            
        }
        else
        {

            spriteCh1.setScale(1.0f, 1.0f);

        }

        if (spriteCh2.getGlobalBounds().contains(mouseWorldPos))
        {

            spriteCh2.setScale(0.9f, 0.9f);
        }
        else
        {

            spriteCh2.setScale(1.0f, 1.0f);

        }
        if (spriteCh3.getGlobalBounds().contains(mouseWorldPos))
        {

            spriteCh3.setScale(0.45f, 0.45f);
        }
        else
        {

            spriteCh3.setScale(0.5f, 0.5f);

        }

        if (spriteCh4.getGlobalBounds().contains(mouseWorldPos))
        {
            
            spriteCh4.setScale(0.45f, 0.45f);
        }
        else
        {

            spriteCh4.setScale(0.5f, 0.5f);

        }

        if (spriteNext.getGlobalBounds().contains(mouseWorldPos))
        {

            spriteNext.setScale(0.9f, 0.9f);
        }
        else
        {

            spriteNext.setScale(1.0f, 1.0f);

        }


        if (event.type == sf::Event::MouseButtonPressed)
        {
            
            if (event.mouseButton.button == sf::Mouse::Left) 
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (spriteCh1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
                {
                    
                    if (!firstClick)
                    {
                        firstClick = true;
                        positionPlayer1 = 1;

                    }
                    if (firstClick && !secondClick && positionPlayer1 != 1)
                    {
                        secondClick = true;
                        positionPlayer2 = 1;

                    }
                    

                }

                if (spriteCh2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if (!firstClick)
                    {
                        firstClick = true;
                        positionPlayer1 = 2;

                    }
                    if (firstClick && !secondClick && positionPlayer1 != 2)
                    {
                        secondClick = true;
                        positionPlayer2 = 2;

                    }


                }

                if (spriteCh3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if (!firstClick)
                    {
                        firstClick = true;
                        positionPlayer1 = 3;

                    }
                    if (firstClick && !secondClick && positionPlayer1 != 3)
                    {
                        secondClick = true;
                        positionPlayer2 = 3;

                    }


                }


                if (spriteCh4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if (!firstClick)
                    {
                        firstClick = true;
                        positionPlayer1 = 4;

                    }
                    if (firstClick && !secondClick && positionPlayer1 != 4)
                    {
                        secondClick = true;
                        positionPlayer2 = 4;

                    }


                }

                if (spriteNext.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if(firstClick && secondClick)
                    {
                        CharacterSelected = true;
                    }
                }
            }
        }
    }

    
   

   

    window.clear(sf::Color::Black);


    window.draw(spriteSelectCharacter);
    window.draw(spriteCh1);
    window.draw(spriteCh2);
    window.draw(spriteCh3);
    window.draw(spriteCh4);
    window.draw(spriteNext);

    
    
    
    if (positionPlayer1 == 1) { window.draw(textForCh1_1); Ch1_player1 = true; Ch1 = true; }
    if (positionPlayer1 == 2) { window.draw(textForCh1_2); Ch2_player1 = true; Ch2 = true; }
    if (positionPlayer1 == 3) { window.draw(textForCh1_3); Ch3_player1 = true; Ch3 = true; }
    if (positionPlayer1 == 4) { window.draw(textForCh1_4); Ch4_player1 = true; Ch4 = true; }

    if (positionPlayer2 == 1) { window.draw(textForCh2_1); Ch1_player2 = true; Ch1 = true; }
    if (positionPlayer2 == 2) { window.draw(textForCh2_2); Ch2_player2 = true; Ch2 = true; }
    if (positionPlayer2 == 3) { window.draw(textForCh2_3); Ch3_player2 = true; Ch3 = true; }
    if (positionPlayer2 == 4) { window.draw(textForCh2_4); Ch4_player2 = true; Ch4 = true;  }

        
  
   

}

void loading(sf::RenderWindow& window, std::vector<sf::Texture>& tenor)
{
    sf::Sprite sprite;
    sprite.setPosition(0, 0);
    float scaleFactor = 0.935f;

    // Отображение всех кадров анимации
    while (currentFrame1 < tenor.size()-1)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        
        sprite.setTexture(tenor[currentFrame1]);

        
        sprite.setScale(sf::Vector2f(scaleFactor, scaleFactor));
        sprite.setPosition(570, 355);

        
        window.draw(sprite);

        window.display();

        
        ++currentFrame1;

        
        std::this_thread::sleep_for(std::chrono::milliseconds(2)); 
    }


    


}

int currentFrame = 0; 
bool mirrCh1 = false;
 

void DrawCharacter1(sf::RenderWindow& window, std::vector<sf::Texture>& textureRightCh1, sf::Sprite& spR1, sf::Sprite& spR2,
    sf::Texture& textureCh1, sf::Sprite& spriteCh1, sf::Sprite& spriteCh1Mir, sf::Sprite& spriteCh1_sit, sf::Sprite& spriteCh1_udar)
{


    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        
    }
    if(Ch1_player1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            
            mirrCh1 = false;

                sf::Vector2f currentPosition = spriteCh1.getPosition();
                if (currentFrame == 2)
                {
                    currentFrame = 0;
                }

                if (currentFrame == 0)
                {
                    spR1.move(100, 0);
                    spR1.setScale(0.7f, 0.7f);
                    spR1.setPosition(currentPosition.x, 195);
                    window.draw(spR1);
                }
                else
                {
                    spR2.move(100, 0);
                    spR2.setScale(0.6f, 0.6f);
                    spR2.setPosition(currentPosition.x, currentPosition.y+30);
                    window.draw(spR2);
                    spriteCh1.setScale(0.9, 0.9);
                }

                ++currentFrame;
            

            spriteCh1.move(100, 0);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::Vector2f currentPosition = spriteCh1.getPosition();
            mirrCh1 = true;
            
            if (currentFrame == 2)
            {
                currentFrame = 0;
            }

            if (currentFrame == 0)
            {
                spR1.move(-100, 0);
                spR1.setScale(-0.7f, 0.7f);
                spR1.setPosition(currentPosition.x + 250, 195);
                window.draw(spR1);
            }
            else
            {
                spR2.move(-100, 0);
                spR2.setScale(-0.6f, 0.6f);
                spR2.setPosition(currentPosition.x + 250, currentPosition.y+30);
                window.draw(spR2);
                spriteCh1.setScale(-0.9, 0.9);
                
            }

            ++currentFrame;

            spriteCh1.move(-100, 0);
            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(!mirrCh1)
            {
                sf::Vector2f currentPosition = spriteCh1.getPosition();
                spriteCh1_sit.setPosition(currentPosition.x, currentPosition.y + 200);
                spriteCh1_sit.setScale(1, 1);
                window.draw(spriteCh1_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh1.getPosition();
                spriteCh1_sit.setPosition(currentPosition.x, currentPosition.y + 200);
                spriteCh1_sit.setScale(-1, 1);
                window.draw(spriteCh1_sit);

            }
            

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if (!mirrCh1)
            {
                sf::Vector2f currentPosition = spriteCh1.getPosition();
                spriteCh1_udar.setPosition(currentPosition.x, currentPosition.y+100);
                spriteCh1_udar.setScale(1.3, 1.3);
                window.draw(spriteCh1_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh1.getPosition();
                spriteCh1_udar.setPosition(currentPosition.x, currentPosition.y+100);
                spriteCh1_udar.setScale(-1.3, 1.3);
                window.draw(spriteCh1_udar);

            }


        }
        else
        {
             window.draw(spriteCh1);
            

        }

    }
    if (Ch1_player2)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mirrCh1 = true;

                sf::Vector2f currentPosition = spriteCh1Mir.getPosition();
                if (currentFrame == 2)
                {
                    currentFrame = 0;
                }

                if (currentFrame == 0)
                {
                    spR1.move(100, 0);
                    spR1.setScale(0.7f, 0.7f);
                    spR1.setPosition(currentPosition.x-200, 195);
                    window.draw(spR1);
                }
                else
                {
                    spR2.move(100, 0);
                    spR2.setScale(0.6f, 0.6f);
                    spR2.setPosition(currentPosition.x-200, currentPosition.y);
                    window.draw(spR2);
                    spriteCh1Mir.setScale(-0.9, 0.9);
                    spriteCh1Mir.setPosition(currentPosition.x+500, currentPosition.y);
                    
                }

                ++currentFrame;
            
            spriteCh1Mir.move(100, 0);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mirrCh1 = false;
            sf::Vector2f currentPosition = spriteCh1Mir.getPosition();
            
            if (currentFrame == 2)
            {
                currentFrame = 0;
            }

            if (currentFrame == 0)
            {
                spR1.move(-100, 0);
                spR1.setScale(-0.7f, 0.7f);
                spR1.setPosition(currentPosition.x + 250, 195);
                window.draw(spR1);
            }
            else
            {
                spR2.move(-100, 0);
                spR2.setScale(-0.6f, 0.6f);
                spR2.setPosition(currentPosition.x + 200, currentPosition.y);
                window.draw(spR2);
                spriteCh1Mir.setScale(0.9, 0.9);
                spriteCh1Mir.setPosition(currentPosition.x, currentPosition.y);
                
            }

            ++currentFrame;

            spriteCh1Mir.move(-175, 0);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (!mirrCh1)
            {
                sf::Vector2f currentPosition = spriteCh1Mir.getPosition();
                spriteCh1_sit.setPosition(currentPosition.x+330, currentPosition.y + 200);
                spriteCh1_sit.setScale(-1, 1);
                window.draw(spriteCh1_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh1Mir.getPosition();
                spriteCh1_sit.setPosition(currentPosition.x-330, currentPosition.y + 200);
                spriteCh1_sit.setScale(1, 1);
                window.draw(spriteCh1_sit);

            }


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
        {
            if (!mirrCh1)
            {
                sf::Vector2f currentPosition = spriteCh1Mir.getPosition();
                spriteCh1_udar.setPosition(currentPosition.x+300, currentPosition.y + 100);
                spriteCh1_udar.setScale(-1.3, 1.3);
                window.draw(spriteCh1_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh1Mir.getPosition();
                spriteCh1_udar.setPosition(currentPosition.x-340, currentPosition.y + 100);
                spriteCh1_udar.setScale(1.3, 1.3);
                window.draw(spriteCh1_udar);

            }


        }
        else
        {
            
             window.draw(spriteCh1Mir);

        }

    }
    


}



int currentFrame2 = 0; bool mirrCh2 = false;

void DrawCharacter2(sf::RenderWindow& window, sf::Sprite& spriteCh2Step, sf::Texture& textureCh2, sf::Sprite& spriteCh2,
    sf::Sprite& spriteCh2Mir, sf::Sprite& spriteCh2_sit, sf::Sprite& spriteCh2_udar)
{

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();


    }

    if (Ch2_player1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            mirrCh2 = false;
            sf::Vector2f currentPosition = spriteCh2.getPosition();
            if (currentFrame2 == 2)
            {
                currentFrame2 = 0;
            }

            if (currentFrame2 == 0)
            {
                spriteCh2Step.move(100, 0);
                spriteCh2Step.setScale(1.3f, 1.3f);
                spriteCh2Step.setPosition(currentPosition.x, 300);
                window.draw(spriteCh2Step);
            }
            else
            {
                spriteCh2.move(100, 0);
                spriteCh2.setScale(1.3, 1.3);
                spriteCh2.setPosition(currentPosition.x, currentPosition.y);
                window.draw(spriteCh2);
            }

            ++currentFrame2;

            spriteCh2.move(100, 0);



        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            mirrCh2 = true;
            sf::Vector2f currentPosition = spriteCh2.getPosition();
            if (currentFrame2 == 2)
            {
                currentFrame2 = 0;
            }

            if (currentFrame2 == 0)
            {
                spriteCh2Step.move(-100, 0);
                spriteCh2Step.setScale(-1.3f, 1.3f);
                spriteCh2Step.setPosition(currentPosition.x+200, 300);
                window.draw(spriteCh2Step);
            }
            else
            {
                spriteCh2.move(-100, 0);
                spriteCh2.setScale(-1.3, 1.3);
                spriteCh2.setPosition(currentPosition.x+100, currentPosition.y);
                window.draw(spriteCh2);
            }

            ++currentFrame2;

            spriteCh2.move(-100, 0);
            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (!mirrCh2)
            {
                sf::Vector2f currentPosition = spriteCh2.getPosition();
                spriteCh2_sit.setPosition(currentPosition.x, currentPosition.y+200);
                spriteCh2_sit.setScale(0.75, 0.75);
                window.draw(spriteCh2_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh2.getPosition();
                spriteCh2_sit.setPosition(currentPosition.x, currentPosition.y+200);
                spriteCh2_sit.setScale(-0.75, 0.75);
                window.draw(spriteCh2_sit);

            }


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if (!mirrCh2)
            {
                sf::Vector2f currentPosition = spriteCh2.getPosition();
                spriteCh2_udar.setPosition(currentPosition.x, currentPosition.y+50 );
                spriteCh2_udar.setScale(1.1, 1.1);
                window.draw(spriteCh2_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh2.getPosition();
                spriteCh2_udar.setPosition(currentPosition.x, currentPosition.y +50);
                spriteCh2_udar.setScale(-1.1, 1.1);
                window.draw(spriteCh2_udar);

            }


        }
        else
        {
            window.draw(spriteCh2);


        }

    }
    if (Ch2_player2)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mirrCh2 = true;
            sf::Vector2f currentPosition = spriteCh2Mir.getPosition();
            if (currentFrame2 == 2)
            {
                currentFrame2 = 0;
            }

            if (currentFrame2 == 0)
            {
                spriteCh2Step.move(100, 0);
                spriteCh2Step.setScale(1.3f, 1.3f);
                spriteCh2Step.setPosition(currentPosition.x-300, 300);
                window.draw(spriteCh2Step);
            }
            else
            {
                spriteCh2Mir.move(100, 0);
                spriteCh2Mir.setScale(-1.3, 1.3);
                spriteCh2Mir.setPosition(currentPosition.x+300, currentPosition.y);
                window.draw(spriteCh2Mir);
            }

            ++currentFrame2;

            spriteCh2Mir.move(100, 0);

            
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mirrCh2 = false;
            sf::Vector2f currentPosition = spriteCh2Mir.getPosition();
            if (currentFrame2 == 2)
            {
                currentFrame2 = 0;
            }

            if (currentFrame2 == 0)
            {
                spriteCh2Step.move(-100, 0);
                spriteCh2Step.setScale(-1.3f, 1.3f);
                spriteCh2Step.setPosition(currentPosition.x+200, 300);
                window.draw(spriteCh2Step);
            }
            else
            {
                spriteCh2Mir.move(-100, 0);
                spriteCh2Mir.setScale(1.3, 1.3);
                spriteCh2Mir.setPosition(currentPosition.x, currentPosition.y);
                window.draw(spriteCh2Mir);
            }

            ++currentFrame2;

            spriteCh2Mir.move(-100, 0);

            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (!mirrCh2)
            {
                sf::Vector2f currentPosition = spriteCh2Mir.getPosition();
                spriteCh2_sit.setPosition(currentPosition.x+300, currentPosition.y + 200);
                spriteCh2_sit.setScale(-0.75, 0.75);
                window.draw(spriteCh2_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh2Mir.getPosition();
                spriteCh2_sit.setPosition(currentPosition.x-300, currentPosition.y + 200);
                spriteCh2_sit.setScale(0.75, 0.75);
                window.draw(spriteCh2_sit);

            }


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
        {
            if (!mirrCh2)
            {
                sf::Vector2f currentPosition = spriteCh2Mir.getPosition();
                spriteCh2_udar.setPosition(currentPosition.x+300, currentPosition.y + 50);
                spriteCh2_udar.setScale(-1.1, 1.1);
                window.draw(spriteCh2_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh2Mir.getPosition();
                spriteCh2_udar.setPosition(currentPosition.x-300, currentPosition.y + 50);
                spriteCh2_udar.setScale(1.1, 1.1);
                window.draw(spriteCh2_udar);

            }


        }
        else
        {

            window.draw(spriteCh2Mir);

        }

    }





}

int currentFrame3 = 0; bool mirrCh3 = false;

void DrawCharacter3(sf::RenderWindow& window, sf::Sprite& spriteCh3StepOne, sf::Sprite& spriteCh3StepTwo, sf::Sprite& spriteCh3,
    sf::Sprite& spriteCh3Mir, sf::Sprite& spriteCh3_sit, sf::Sprite& spriteCh3_udar)
{

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();


    }

    if (Ch3_player1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            mirrCh3 = false;
            sf::Vector2f currentPosition = spriteCh3.getPosition();
            if (currentFrame3 == 2)
            {
                currentFrame3 = 0;
            }

            if (currentFrame3 == 0)
            {
                spriteCh3StepOne.move(100, 0);
                spriteCh3StepOne.setScale(1.5f, 1.5f);
                spriteCh3StepOne.setPosition(currentPosition.x+200, 450);
                window.draw(spriteCh3StepOne);
            }
            else
            {
                spriteCh3StepTwo.move(100, 0);
                spriteCh3StepTwo.setScale(0.9, 0.9);
                spriteCh3StepTwo.setPosition(currentPosition.x+200, currentPosition.y+125-100);
                window.draw(spriteCh3StepTwo);
                spriteCh3.setScale(2, 2);
            }

            ++currentFrame3;

            spriteCh3.move(100, 0);



        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            mirrCh3 = true;
            sf::Vector2f currentPosition = spriteCh3.getPosition();
            if (currentFrame3 == 2)
            {
                currentFrame3 = 0;
            }

            if (currentFrame3 == 0)
            {
                
                spriteCh3StepOne.setScale(-1.5f, 1.5f);
                spriteCh3StepOne.setPosition(currentPosition.x+250, 450);
                window.draw(spriteCh3StepOne);
            }
            else
            {
                
                spriteCh3StepTwo.setScale(-0.9, 0.9);
                spriteCh3StepTwo.setPosition(currentPosition.x+300, currentPosition.y + 125-100);
                window.draw(spriteCh3StepTwo);
                spriteCh3.setScale(-2, 2);
                spriteCh3.setPosition(currentPosition.x+300, currentPosition.y);
                
                
                
            }

            ++currentFrame3;

            spriteCh3.move(-250, 0);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (!mirrCh3)
            {
                sf::Vector2f currentPosition = spriteCh3.getPosition();
                spriteCh3_sit.setPosition(currentPosition.x, currentPosition.y+95);
                spriteCh3_sit.setScale(0.9, 0.9);
                window.draw(spriteCh3_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh3.getPosition();
                spriteCh3_sit.setPosition(currentPosition.x, currentPosition.y+95);
                spriteCh3_sit.setScale(-0.9, 0.9);
                window.draw(spriteCh3_sit);

            }


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if (!mirrCh3)
            {
                sf::Vector2f currentPosition = spriteCh3.getPosition();
                spriteCh3_udar.setPosition(currentPosition.x, currentPosition.y + 95);
                spriteCh3_udar.setScale(1.2, 1.2);
                window.draw(spriteCh3_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh3.getPosition();
                spriteCh3_udar.setPosition(currentPosition.x, currentPosition.y + 95);
                spriteCh3_udar.setScale(-1.2, 1.2);
                window.draw(spriteCh3_udar);

            }


        }
        else
        {
            window.draw(spriteCh3);


        }

    }
    if (Ch3_player2)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mirrCh3 = true;
            sf::Vector2f currentPosition = spriteCh3Mir.getPosition();
            if (currentFrame3 == 2)
            {
                currentFrame3 = 0;
            }

            if (currentFrame3 == 0)
            {
                spriteCh3StepOne.move(100, 0);
                spriteCh3StepOne.setScale(1.5f, 1.5f);
                spriteCh3StepOne.setPosition(currentPosition.x-100, 450);
                window.draw(spriteCh3StepOne);
            }
            else
            {
                spriteCh3StepTwo.move(100, 0);
                spriteCh3StepTwo.setScale(0.9, 0.9);
                spriteCh3StepTwo.setPosition(currentPosition.x, currentPosition.y+50);
                window.draw(spriteCh3StepTwo);
                spriteCh3Mir.setScale(-1.8, 1.8);
                spriteCh3Mir.setPosition(currentPosition.x + 300, currentPosition.y);
            }

            ++currentFrame3;

            

            spriteCh3Mir.move(100, 0);


        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mirrCh3 = false;
            sf::Vector2f currentPosition = spriteCh3Mir.getPosition();
            if (currentFrame3 == 2)
            {
                currentFrame3 = 0;
            }

            if (currentFrame3 == 0)
            {

                spriteCh3StepOne.setScale(-1.5f, 1.5f);
                spriteCh3StepOne.setPosition(currentPosition.x+200, 450);
                window.draw(spriteCh3StepOne);
            }
            else
            {

                spriteCh3StepTwo.setScale(-0.9, 0.9);
                spriteCh3StepTwo.setPosition(currentPosition.x+200, currentPosition.y+50);
                window.draw(spriteCh3StepTwo);
                
                spriteCh3Mir.setScale(1.8, 1.8);
                spriteCh3Mir.setPosition(currentPosition.x, currentPosition.y);


            }

            ++currentFrame3;

            spriteCh3Mir.move(-110, 0);


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (!mirrCh3)
            {
                sf::Vector2f currentPosition = spriteCh3Mir.getPosition();
                spriteCh3_sit.setPosition(currentPosition.x+350, currentPosition.y + 95);
                spriteCh3_sit.setScale(-0.9, 0.9);
                window.draw(spriteCh3_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh3Mir.getPosition();
                spriteCh3_sit.setPosition(currentPosition.x-350, currentPosition.y + 95);
                spriteCh3_sit.setScale(0.9, 0.9);
                window.draw(spriteCh3_sit);

            }


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
        {
            if (!mirrCh3)
            {
                sf::Vector2f currentPosition = spriteCh3Mir.getPosition();
                spriteCh3_udar.setPosition(currentPosition.x+300, currentPosition.y + 95);
                spriteCh3_udar.setScale(-1.2, 1.2);
                window.draw(spriteCh3_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh3Mir.getPosition();
                spriteCh3_udar.setPosition(currentPosition.x-300, currentPosition.y + 95);
                spriteCh3_udar.setScale(1.2, 1.2);
                window.draw(spriteCh3_udar);

            }


        }
        else
        {

            window.draw(spriteCh3Mir);

        }

    }


}


int currentFrame4 = 0; bool mirrCh4 = false;

void DrawCharacter4(sf::RenderWindow& window, sf::Sprite& spriteCh4StepOne, sf::Sprite& spriteCh4StepTwo, sf::Sprite& spriteCh4,
    sf::Sprite& spriteCh4Mir, sf::Sprite& spriteCh4_sit, sf::Sprite& spriteCh4_udar)
{

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();


    }

    if (Ch4_player1)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            mirrCh4 = false;
            sf::Vector2f currentPosition = spriteCh4.getPosition();
            if (currentFrame4 == 2)
            {
                currentFrame4 = 0;
            }

            if (currentFrame4 == 0)
            {
                spriteCh4StepOne.move(100, 0);
                spriteCh4StepOne.setScale(1, 1);
                spriteCh4StepOne.setPosition(currentPosition.x, 395);
                window.draw(spriteCh4StepOne);
            }
            else
            {
                spriteCh4StepTwo.move(100, 0);
                spriteCh4StepTwo.setScale(1, 1);
                spriteCh4StepTwo.setPosition(currentPosition.x, currentPosition.y);
                window.draw(spriteCh4StepTwo);
                spriteCh4.setScale(1.9, 1.9);
            }

            ++currentFrame4;

            spriteCh4.move(100, 0);



        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            mirrCh4 = true;
            sf::Vector2f currentPosition = spriteCh4.getPosition();
            if (currentFrame4 == 2)
            {
                currentFrame4 = 0;
            }

            if (currentFrame4 == 0)
            {
                spriteCh4StepOne.move(-100, 0);
                spriteCh4StepOne.setScale(-1, 1);
                spriteCh4StepOne.setPosition(currentPosition.x+300-200, 395);
                window.draw(spriteCh4StepOne);
            }
            else
            {
                spriteCh4StepTwo.move(-100, 0);
                spriteCh4StepTwo.setScale(-1, 1);
                spriteCh4StepTwo.setPosition(currentPosition.x+300-200, currentPosition.y);
                window.draw(spriteCh4StepTwo);
                spriteCh4.setScale(-1.9, 1.9);
                
            }

            ++currentFrame4;

            spriteCh4.move(-100, 0);
            

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (!mirrCh4)
            {
                sf::Vector2f currentPosition = spriteCh4.getPosition();
                spriteCh4_sit.setPosition(currentPosition.x, currentPosition.y+125);
                spriteCh4_sit.setScale(0.75, 0.75);
                window.draw(spriteCh4_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh4.getPosition();
                spriteCh4_sit.setPosition(currentPosition.x, currentPosition.y+125);
                spriteCh4_sit.setScale(-0.75, 0.75);
                window.draw(spriteCh4_sit);

            }


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if (!mirrCh4)
            {
                sf::Vector2f currentPosition = spriteCh4.getPosition();
                spriteCh4_udar.setPosition(currentPosition.x, currentPosition.y + 125-50);
                spriteCh4_udar.setScale(1, 1);
                window.draw(spriteCh4_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh4.getPosition();
                spriteCh4_udar.setPosition(currentPosition.x, currentPosition.y + 125-50);
                spriteCh4_udar.setScale(-1, 1);
                window.draw(spriteCh4_udar);

            }


        }
        else
        {
            window.draw(spriteCh4);


        }

    }
    if (Ch4_player2)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mirrCh4 = true;
            sf::Vector2f currentPosition = spriteCh4Mir.getPosition();
            if (currentFrame4 == 2)
            {
                currentFrame4 = 0;
            }

            if (currentFrame4 == 0)
            {
                spriteCh4StepOne.move(100, 0);
                spriteCh4StepOne.setScale(1, 1);
                spriteCh4StepOne.setPosition(currentPosition.x, 395);
                window.draw(spriteCh4StepOne);
            }
            else
            {
                spriteCh4StepTwo.move(100, 0);
                spriteCh4StepTwo.setScale(1, 1);
                spriteCh4StepTwo.setPosition(currentPosition.x, currentPosition.y);
                window.draw(spriteCh4StepTwo);
                spriteCh4Mir.setScale(-1.9, 1.9);
                spriteCh4Mir.setPosition(currentPosition.x + 100, currentPosition.y);
            }

            ++currentFrame4;

            spriteCh4Mir.move(200, 0);
            


        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mirrCh4 = false;
            sf::Vector2f currentPosition = spriteCh4Mir.getPosition();
            if (currentFrame4 == 2)
            {
                currentFrame4 = 0;
            }

            if (currentFrame4 == 0)
            {
                spriteCh4StepOne.move(100, 0);
                spriteCh4StepOne.setScale(-1, 1);
                spriteCh4StepOne.setPosition(currentPosition.x+300, 395);
                window.draw(spriteCh4StepOne);
            }
            else
            {
                spriteCh4StepTwo.move(100, 0);
                spriteCh4StepTwo.setScale(-1, 1);
                spriteCh4StepTwo.setPosition(currentPosition.x+300, currentPosition.y);
                window.draw(spriteCh4StepTwo);
                spriteCh4Mir.setScale(1.9, 1.9);
            }

            ++currentFrame4;

            spriteCh4Mir.move(-100, 0);
           

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (!mirrCh4)
            {
                sf::Vector2f currentPosition = spriteCh4Mir.getPosition();
                spriteCh4_sit.setPosition(currentPosition.x+300, currentPosition.y + 125);
                spriteCh4_sit.setScale(-0.75, 0.75);
                window.draw(spriteCh4_sit);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh4Mir.getPosition();
                spriteCh4_sit.setPosition(currentPosition.x-300, currentPosition.y + 125);
                spriteCh4_sit.setScale(0.75, 0.75);
                window.draw(spriteCh4_sit);

            }


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
        {
            if (!mirrCh4)
            {
                sf::Vector2f currentPosition = spriteCh4Mir.getPosition();
                spriteCh4_udar.setPosition(currentPosition.x+300, currentPosition.y + 125 - 50);
                spriteCh4_udar.setScale(-1, 1);
                window.draw(spriteCh4_udar);
            }
            else
            {
                sf::Vector2f currentPosition = spriteCh4Mir.getPosition();
                spriteCh4_udar.setPosition(currentPosition.x-300, currentPosition.y + 125 - 50);
                spriteCh4_udar.setScale(1, 1);
                window.draw(spriteCh4_udar);

            }


        }
        else
        {

            window.draw(spriteCh4Mir);

        }

    }


}



void health(sf::RenderWindow& window, sf::Sprite& spriteCh1, sf::Sprite& spriteCh2, sf::Sprite& spriteCh3, sf::Sprite& spriteCh4,
    sf::Sprite& spriteCh1Mir, sf::Sprite& spriteCh2Mir, sf::Sprite& spriteCh3Mir, sf::Sprite& spriteCh4Mir,
    bool& Ch1, bool& Ch2, bool& Ch3, bool& Ch4, int& h1, int& h2, sf::Text& healthOne, sf::Text& healthTwo )
{
    if (Ch1 && Ch2)
    {
        if (Ch1_player1)
        {
            sf::Vector2f currentPosition_1 = spriteCh1.getPosition();
            sf::Vector2f currentPosition_2 = spriteCh2Mir.getPosition();

            sf::FloatRect bounds1 = spriteCh1.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh2Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;

            

        }
        else
        {
            sf::Vector2f currentPosition_1 = spriteCh2.getPosition();
            sf::Vector2f currentPosition_2 = spriteCh1Mir.getPosition();

            sf::FloatRect bounds1 = spriteCh2.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh1Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;

        }


    }

    if (Ch1 && Ch3)
    {
        if (Ch1_player1)
        {
            sf::Vector2f currentPosition_1 = spriteCh1.getPosition();
            sf::Vector2f currentPosition_2 = spriteCh3Mir.getPosition();

            sf::FloatRect bounds1 = spriteCh1.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh3Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;



        }
        else
        {
            sf::Vector2f currentPosition_1 = spriteCh3.getPosition();
            sf::Vector2f currentPosition_2 = spriteCh1Mir.getPosition();

            sf::FloatRect bounds1 = spriteCh3.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh1Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;

        }


    }

    if (Ch1 && Ch4)
    {
        if (Ch1_player1)
        {
            sf::Vector2f currentPosition_1 = spriteCh1.getPosition();
            sf::Vector2f currentPosition_2 = spriteCh4Mir.getPosition();

            sf::FloatRect bounds1 = spriteCh1.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh4Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;



        }
        else
        {
            sf::Vector2f currentPosition_1 = spriteCh4.getPosition();
            sf::Vector2f currentPosition_2 = spriteCh1Mir.getPosition();

            sf::FloatRect bounds1 = spriteCh4.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh1Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;

        }


    }


    if (Ch2 && Ch3)
    {
        if (Ch2_player1)
        {
            

            sf::FloatRect bounds1 = spriteCh2.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh3Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;



        }
        else
        {
           

            sf::FloatRect bounds1 = spriteCh3.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh2Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;

        }


    }

    if (Ch2 && Ch4)
    {
        if (Ch2_player1)
        {


            sf::FloatRect bounds1 = spriteCh2.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh4Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;



        }
        else
        {


            sf::FloatRect bounds1 = spriteCh4.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh2Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;

        }


    }
    if (Ch3 && Ch4)
    {
        if (Ch2_player1)
        {


            sf::FloatRect bounds1 = spriteCh3.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh4Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;



        }
        else
        {


            sf::FloatRect bounds1 = spriteCh4.getGlobalBounds();
            sf::FloatRect bounds2 = spriteCh3Mir.getGlobalBounds();

            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::F)) h2 -= 25;
            if (bounds1.intersects(bounds2) && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) h1 -= 25;

        }


    }

    std::string healthL = std::to_string(h1);
    std::string healthR = std::to_string(h2);

    healthOne.setString(healthL);
    healthOne.setPosition(300, 100);
    healthOne.setCharacterSize(60);
    healthOne.setFillColor(sf::Color::Red);

    healthTwo.setString(healthR);
    healthTwo.setPosition(1400, 100);
    healthTwo.setCharacterSize(60);
    healthTwo.setFillColor(sf::Color::Blue);



    
    sf::RectangleShape rectangle1;
    rectangle1.setSize(sf::Vector2f(200, 100));
    rectangle1.setPosition(250, 95);
    rectangle1.setFillColor(sf::Color::Black);
    rectangle1.setFillColor(sf::Color(0, 0, 0, 178)); 


    sf::RectangleShape rectangle2;
    rectangle2.setSize(sf::Vector2f(200, 100));
    rectangle2.setPosition(1350, 95);
    rectangle2.setFillColor(sf::Color::Black);
    rectangle2.setFillColor(sf::Color(0, 0, 0, 178));
   
    window.draw(rectangle1);
    window.draw(rectangle2);





    window.draw(healthOne);
    window.draw(healthTwo);



}



void winner_two(sf::RenderWindow& window, sf::Text& txt)
{

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(700, 400));
    rectangle.setPosition(500, 200);
    rectangle.setFillColor(sf::Color::Black);
    
    

    txt.setString("WINNER: player2");
    txt.setCharacterSize(60);
    txt.setPosition(610, 350);




    window.draw(rectangle);
    window.draw(txt);
    



}

void winner_one(sf::RenderWindow& window, sf::Text& txt)
{

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(700, 400));
    rectangle.setPosition(500, 200);
    rectangle.setFillColor(sf::Color::Black);



    txt.setString("WINNER: player1");
    txt.setCharacterSize(60);
    txt.setPosition(610, 350);




    window.draw(rectangle);
    window.draw(txt);




}