#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>


class Window {
public:
    Window();
    ~Window() = default;

    void createWindow();
    void startLoop();

private:
    sf::RenderWindow* _window;
    int length = 800;
    int height = 600;

};