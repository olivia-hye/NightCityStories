#include <SFML/Graphics.hpp>
#include <iostream>

int width = 1280;
int height = 720;

void createTrapezoid(sf::RenderWindow &window, sf::Color c, int x1, int y1, int w1, int x2, int y2, int w2) {
    sf::ConvexShape trap(4);
    trap.setFillColor(c);
    trap.setPoint(0, sf::Vector2f(x1 - w1, y1));
    trap.setPoint(1, sf::Vector2f(x2 - w2, y2));
    trap.setPoint(2, sf::Vector2f(x2 + w2, y2));
    trap.setPoint(3, sf::Vector2f(x1 + w1, y1));
    window.draw(trap);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Night City Stories");
    window.setFramerateLimit(60);

    sf::Texture bgTex;
    if (!bgTex.loadFromFile("textures/bg.jpg")){}
    sf::RectangleShape bg(sf::Vector2f(width, height));
    bg.setTexture(&bgTex);

    sf::Image cloudImg;
    if (!cloudImg.loadFromFile("textures/cloud.png")) {}

    sf::Texture cloudTex;
    if (!cloudTex.loadFromImage(cloudImg)) {}

    sf::Sprite cloud;
    cloud.setTexture(cloudTex);
    cloud.setPosition(-400, 120);

    sf::Texture carTex;
    if (!carTex.loadFromFile("textures/car.png")){}
    sf::RectangleShape car(sf::Vector2f(250.f, 200.f));
    car.setPosition(width/2, height - (height/5));
    car.setOrigin(car.getSize().x / 2, car.getSize().y/2);
    car.setTexture(&carTex);

    std::cout << "GAME IS RUNNING \n";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {if (event.type == sf::Event::Closed) window.close();}
        window.clear();

        if (cloud.getPosition().x != 1300) {cloud.move(2.f, 0.f);}
        else cloud.setPosition(-400, 120);

        float posX = car.getPosition().x;
        float rightMove = 10.f;
        float leftMove = -10.f;
        if (posX == 1140) {rightMove = 0;}
        if (posX == 140) {leftMove = 0;}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){car.move(rightMove, 0);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){car.move(leftMove, 0);}
        
        window.draw(bg);
        createTrapezoid(window, sf::Color(90, 10, 40), 0, 720, 1280, 0, 520, 1280);
        createTrapezoid(window, sf::Color(100, 100, 100), 640, 720, 600, 640, 520, 200);
        createTrapezoid(window, sf::Color(255, 255, 255), 640, 700, 30, 640, 540, 15);
        window.draw(cloud);
        window.draw(car);

        window.display();
    }
    return 0;
}


/*      UNUSED CODE

        float posY = car.getPosition().y;
        float upMove = -10.f;
        float downMove = 10.f;
        if (posY == car.getSize().y / 2) {upMove = 0; }
        if (posY == height - (car.getSize().y/2)) {downMove= 0;}

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){car.move(0, upMove);}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){car.move(0, downMove);}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){car.rotate(leftMove);}
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){car.rotate(rightMove);}

*/