

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

        // Обработка событий мыши
        if (event.type == sf::Event::MouseMoved) {
            // Получаем позицию курсора мыши относительно окна
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            // Преобразуем позицию курсора в координаты окна
            sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);
            // Проверяем, наведен ли курсор на кнопку "PLAY"
            if (spritePlay.getGlobalBounds().contains(mouseWorldPos))
            {
                // Уменьшаем масштаб кнопки "PLAY"
                spritePlay.setScale(0.9f, 0.9f); // Примерный коэффициент уменьшения
            }
            else
            {
                // Возвращаем исходный масштаб кнопки "PLAY"
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



int posirionPlayer1 = 0, posirionPlayer2 = 0;
bool firstClick = false;
bool secondClick = false;


bool Ch1_player1 = false, Ch2_player1 = false, Ch3_player1 = false, Ch4_player1 = false;
bool Ch1_player2 = false, Ch2_player2 = false, Ch3_player2 = false, Ch4_player2 = false;




void ChoiceCharacter(sf::RenderWindow& window, sf::Sprite& spriteSelectCharacter, sf::Texture& textureSelectCharacter, bool& CharacterSelected)
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
                        posirionPlayer1 = 1;

                    }
                    if (firstClick && !secondClick && posirionPlayer1 != 1)
                    {
                        secondClick = true;
                        posirionPlayer2 = 1;

                    }
                    

                }

                if (spriteCh2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if (!firstClick)
                    {
                        firstClick = true;
                        posirionPlayer1 = 2;

                    }
                    if (firstClick && !secondClick && posirionPlayer1 != 2)
                    {
                        secondClick = true;
                        posirionPlayer2 = 2;

                    }


                }

                if (spriteCh3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if (!firstClick)
                    {
                        firstClick = true;
                        posirionPlayer1 = 3;

                    }
                    if (firstClick && !secondClick && posirionPlayer1 != 3)
                    {
                        secondClick = true;
                        posirionPlayer2 = 3;

                    }


                }


                if (spriteCh4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
                {
                    if (!firstClick)
                    {
                        firstClick = true;
                        posirionPlayer1 = 4;

                    }
                    if (firstClick && !secondClick && posirionPlayer1 != 4)
                    {
                        secondClick = true;
                        posirionPlayer2 = 4;

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

    
    
    
    if (posirionPlayer1 == 1) { window.draw(textForCh1_1); Ch1_player1 = true; }
    if (posirionPlayer1 == 2) { window.draw(textForCh1_2); Ch2_player1 = true;}
    if (posirionPlayer1 == 3) { window.draw(textForCh1_3); Ch3_player1 = true; }
    if (posirionPlayer1 == 4) { window.draw(textForCh1_4); Ch4_player1 = true; }

    if (posirionPlayer2 == 1) { window.draw(textForCh2_1); Ch1_player2 = true; }
    if (posirionPlayer2 == 2) { window.draw(textForCh2_2); Ch2_player2 = true;}
    if (posirionPlayer2 == 3) { window.draw(textForCh2_3); Ch3_player2 = true;}
    if (posirionPlayer2 == 4) { window.draw(textForCh2_4); Ch4_player2 = true;}

        
  
   

}

void loading(sf::RenderWindow& window, std::vector<sf::Texture>& tenor)
{
    sf::Sprite sprite;
    sprite.setPosition(0, 0);
    float scaleFactor = 0.935f; // Коэффициент масштабирования

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

        // Установка текстуры текущего кадра на спрайт
        sprite.setTexture(tenor[currentFrame1]);

        // Установка масштаба спрайта
        sprite.setScale(sf::Vector2f(scaleFactor, scaleFactor));
        sprite.setPosition(570, 355);

        // Отображение текущего кадра анимации с установкой новой позиции
        window.draw(sprite);

        window.display();

        // Переключение кадров анимации
        ++currentFrame1;

        // Задержка между кадрами
        std::this_thread::sleep_for(std::chrono::milliseconds(2)); // Можно изменить время задержки
    }


    


}



void DrawCharacters(sf::RenderWindow& window)
{


    //первый перс)

    sf::Texture textureCh1;
    if (!textureCh1.loadFromFile("Character1/Character1_static.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh1(textureCh1);
    spriteCh1.setTexture(textureCh1);
    spriteCh1.scale(0.9, 0.9);
    spriteCh1.setPosition(100, 250);

    //первый перс зеркалка

    sf::Texture textureCh1Mir;
    if (!textureCh1Mir.loadFromFile("Character1/Character1_mir_static.png"))
    {
        throw std::runtime_error("Character image is not open");
    }
    sf::Sprite spriteCh1Mir(textureCh1Mir);
    spriteCh1Mir.setTexture(textureCh1Mir);
    spriteCh1Mir.scale(0.9, 0.9);
    spriteCh1Mir.setPosition(1200, 250);


    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
        
            
            
               
            

     


 
 



    //window.clear(sf::Color::Black);
    
    if (Ch1_player1) { window.draw(spriteCh1); }
    if (Ch1_player2) { window.draw(spriteCh1Mir); }



}