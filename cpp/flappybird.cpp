#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML works!");
   
    Sprite bird,tube;
    Texture birdtexture,tubetexture;
    birdtexture.loadFromFile("birdimage.png");
    bird.setTexture(birdtexture);
    tubetexture.loadFromFile("tube.png");
    tube.setTexture(tubetexture);
    Vector2f velocity(0.0f, 0.0f);
    Vector2f velocityt(0.0f,0.0f);
    Clock clock;
    float dt;
    bool flag = false;
    Vector2f getpos;
    bird.setPosition(Vector2f(60.0f, 100.0f));
    bird.setOrigin(Vector2f(30.0f, 30.0f));
    tube.setPosition(Vector2f(800.0f, 0.0f));
    tube.setOrigin(Vector2f(100.0f, 0.0f));
    while (window.isOpen())
    {
        dt = clock.restart().asSeconds();
        velocity.y = 0;
        velocityt.x = 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            // velocity.y = (velocity.y - 1000.0f) * dt;
            getpos = bird.getPosition(); 
            flag = true;
            velocity.y = (velocity.y + 200) * dt;
            bird.setRotation(+20);
       
        }
        else if (flag)
        {
            bird.setRotation(-20);
           velocity.y = (velocity.y - 500.0f) * dt ;
           //bird.setRotation(-20);
        }
        else
        {
            
            velocity.y = (velocity.y + 250 )* dt;
            bird.setRotation(+40);

        }
        if (bird.getPosition().y <= (getpos.y - 100.0f))
        {
            flag = false;
        }
        if (bird.getGlobalBounds().intersects(tube.getGlobalBounds()))
        {
            break;
        }
        velocityt.x -= (200.0f * dt);
        if (tube.getPosition().x <= 0.0f)
        {
            tube.setPosition(1350.0f, 0.0f);
        }
        tube.move(velocityt);
        bird.move(velocity);
        window.clear(Color::Magenta);
        window.draw(bird);
        window.draw(tube);
        window.display();
    }

    return 0;
}