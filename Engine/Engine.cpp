//
// Game engine
//

#include "Engine.h"

// Const
const int W_WIDTH = 800;
const int W_HEIGHT = 600;
//EndConst

//Private
void Engine::init() {
    e_Window.create(VideoMode(W_WIDTH, W_HEIGHT),
                    "MAD PONG");
    e_Window.setFramerateLimit(120);
}

void Engine::update(float dtAsSeconds) {
    handleWindowEvents();

    //update objs

    //endUO
}

void Engine::draw() {
    e_Window.clear(Color::White);

    //draw objs

    //endDO

    e_Window.display();
}

void Engine::handleWindowEvents() {
    Event event;

    while (e_Window.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                e_Window.close();
                break;
            case Event::Resized:
                break;
            case Event::LostFocus:
                break;
            case Event::GainedFocus:
                break;
            case Event::TextEntered:
                break;
            case Event::KeyPressed:
                break;
            case Event::KeyReleased:
                break;
            case Event::MouseWheelMoved:
                break;
            case Event::MouseWheelScrolled:
                break;
            case Event::MouseButtonPressed:
                break;
            case Event::MouseButtonReleased:
                break;
            case Event::MouseMoved:
                break;
            case Event::MouseEntered:
                break;
            case Event::MouseLeft:
                break;
            case Event::JoystickButtonPressed:
                break;
            case Event::JoystickButtonReleased:
                break;
            case Event::JoystickMoved:
                break;
            case Event::JoystickConnected:
                break;
            case Event::JoystickDisconnected:
                break;
            case Event::TouchBegan:
                break;
            case Event::TouchMoved:
                break;
            case Event::TouchEnded:
                break;
            case Event::SensorChanged:
                break;
            case Event::Count:
                break;
        }
    }
}
//EndPrivate

// Public
Engine::Engine() {
    init();
}

void Engine::start() {
    Clock clock;

    while(e_Window.isOpen()) {
        Time dt = clock.restart();

        float dtAsSec = dt.asSeconds();

        update(dtAsSec);
        draw();
    }
}
//EndPublic
