#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread> // для имитации загрузки
#include <Windows.h>


using namespace std;





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
        sprite.setPosition(600 , 300);
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






void drawBoard(sf::RenderWindow& window, sf::Sprite& sprite, sf::Texture& texture)
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
        frames[i].loadFromFile("load-" + to_string(i) + ".png");

        
    }



    showLoadingScreen(window, frames);
    simulateLoading(); // Имитация загрузки

    


    sf::Texture texture;
    if (!texture.loadFromFile("fon1.png"))
    {
        throw std::runtime_error("IMG is not open");
    }

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        drawBoard(window, sprite, texture);

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
