//
// Game engine
//

//INCLUDE//
#include "Engine.h"
#include "Game.h"
//EncInclude//

//Private
void Engine::init() {
    e_Window.create(VideoMode(W_WIDTH, W_HEIGHT),
                    "MAD Pong");
    e_Window.setFramerateLimit(120);
}

void Engine::update(float dtAsSeconds) {
    handleWindowEvents();

    //update objs

    //endUO
}

void Engine::draw() {
    e_Window.clear(Color::Black);

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
        }
    }
}
//EndPrivate

// Public
Engine::Engine() {
    init();
}

void Engine::start() {
    // Тут запустить меню надо
    Game game(1);

    Clock clock;

    while(e_Window.isOpen()) {
        Time dt = clock.restart();

        float dtAsSec = dt.asSeconds();

        update(dtAsSec);
        draw();
    }
}
//EndPublic
