#include "Window.hpp"

Window::Window() {
    this->createWindow();
    this->startLoop();
}

void Window::createWindow() {
    this->_window = new sf::RenderWindow(sf::VideoMode(length, height), "SFML Window");
}

void Window::startLoop() {
    while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) _window->close();
        }

        _window->clear(sf::Color::Black);
        _window->display();
    }
}
