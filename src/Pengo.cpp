#include <Pengo.h>
#include <Console.h>
#include <SpriteBank.h>


const float kVel  = 5;

sf::Sprite sprite;

void Pengo::Start(void)
{
    //Creamos una ventana
    window.create(sf::VideoMode(223*3, 255*3), "Pengo | Gonzalo G. Campos");


    level = Level1();
    level.start();
    
}



void Pengo::Run(void)
{
    //Bucle del juego
    while (window.isOpen()) 
    {
        //Bucle de obtención de eventos
        sf::Event event;
        K_DOWN = false; K_UP=false; K_LEFT=false; K_RIGHT=false; K_SPACE=false; K_ESC=false; K_G=false; K_N=false; K_X=false;
        while (window.pollEvent(event)) 
        {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }else if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            K_ESC = true;
                            break;
                        case sf::Keyboard::Up:
                            K_UP = true;
                            break;
                        case sf::Keyboard::Down:
                            K_DOWN = true;
                            break;
                        case sf::Keyboard::Left:
                            K_LEFT = true;
                            break;
                        case sf::Keyboard::Right:
                            K_RIGHT = true;
                            break;
                        case sf::Keyboard::W:
                            K_UP = true;
                            break;
                        case sf::Keyboard::S:
                            K_DOWN = true;
                            break;
                        case sf::Keyboard::A:
                            K_LEFT = true;
                            break;
                        case sf::Keyboard::D:
                            K_RIGHT = true;
                            break;
                        case sf::Keyboard::Space:
                            K_SPACE = true;
                            break;
                        case sf::Keyboard::G:
                            K_G = true;
                            break;
                        case sf::Keyboard::N:
                            K_N = true;
                            break;
                        case sf::Keyboard::X:
                            K_X = true;
                            break;
                        default:
                            break;
                    }
                }
        }

        window.clear();
        if(!level.update(0.1f))
            window.close();
        window.display();   
    }
}



void Pengo::Close(void)
{
}