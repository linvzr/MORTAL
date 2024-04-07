

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
    while (currentFrame1 < clips.size())
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
        std::this_thread::sleep_for(std::chrono::milliseconds(48)); // Можно изменить время задержки
    }
    

}

void backgroundSelection(sf::RenderWindow& window, sf::Sprite& spriteChoice, sf::Texture& textureChoice, bool& map1, bool& map2, bool& map3, bool& map4)
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
                   
                    
                    map1 = true;
                }
            }




        

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlaceTwo.getGlobalBounds().contains(mouseWorldPos))
                {
                    
                    
                    map2 = true;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlaceThree.getGlobalBounds().contains(mouseWorldPos))
                {
                     
                    
                    map3 = true;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition);

                if (spritePlaceFour.getGlobalBounds().contains(mouseWorldPos))
                {
                    
                    
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