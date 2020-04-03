#include <Render.h>
#include <iostream>

/*
Destructor que llama a  la  funcion close de Render.
*/
Render::~Render()
{
    close();
}

/*
Inicializa el render creando una nueva ventana y reservando memoria para ella.
*/
void Render::init()
{
    globalScale = 3;

    // Create the main window
    int width = 223*globalScale;
    int heigth = 255*globalScale;
    window = new sf::RenderWindow(sf::VideoMode(width, heigth), "Pengo | Gonzalo G. Campos");

    spritesCont = 1;

}

/*
Llama a la funcion clearMemory() y libera la memoria reservada para la ventana.
*/
void Render::close()
{
    clearMemory();
    delete window;
}

/*
Devuelve true si la ventana esta abierta, sino devuelve false.
*/
bool Render::isWindowOpen()
{
    return window->isOpen();
}


/*
Funcion que se llama cuando incia el loop antes de pintar sprites.
Comprueba que la ventana este abierta, y borra todo lo dibujado antes.
*/
void Render::preLoop(float dt)
{
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window->close();
        }
        // Clear screen
        window->clear();

        this->dt = dt;
}

/*
Funcion que se llama antes de terminar el loop.
Llama a la funcion update de la ventana.
*/
void Render::postLoop()
{
        // Update the window
        window->display();
}

/*
Borra toda la memoria reservada.
*/
void Render::clearMemory()
{
    sprites.clear();
    textures.clear();

    spritesCont = 1;
}

/*
Aplica la escala global a todos los sprites.
*/
void Render::setGlobalScale(float scale)
{
    globalScale = scale;
}

/*
Devuelve la escala global que se aplica a todos los sprites.
*/
float Render::getGlobalScale()
{
    return globalScale;
}

/*
Carga la textura en la memoria, devuelve true si existe y false si no existe.
Si la textura ya estaba cargada no la actualiza
*/
bool Render::loadTexture(std::string texture)
{
    sf:: Texture*  tex= new sf::Texture();
    if(!tex->loadFromFile(texture))
        return false;

    textures.insert(std::pair<std::string, sf::Texture*>(texture, tex));

    return true;
}

/*
Borra la textura de la memoria y la libera, devuelve true si la textura existia
y false si no existia.
*/
bool Render::deleteTexture(std::string texture)
{
    bool r = false;
    if(textures.find(texture)!=textures.end())
    {
        delete textures.find(texture)->second;
        textures.erase(texture);
        r=true;
    }

    return r;
}

/*
Si la textura estaba cargada en la memoria devuelve un puntero.
Si no estaba cargada devuelve nullptr.
*/
sf::Texture* Render::getTexture(std::string texture)
{
    auto it = textures.find(texture);
    if (it != textures.end())
        return it->second;
    
    return nullptr;
}


/*
Carga un sprite con la textura pasada por parametro.
Devuelve el ide en sprite. Devuelve 0 si no existe la textura
y no carga nada.
*/
Rint Render::createSprite(std::string texture)
{
    if(!loadTexture(texture))
        return 0;
    
    Rint id = spritesCont;
    spritesCont++;

    sf::Sprite* s = new sf::Sprite(*getTexture(texture));

    sprites.insert(std::pair<Rint, sf::Sprite*>(id, s));

    return id;
}

/*
Carga un sprite con la textura recortada por rectangle pasada por parametro.
Devuelve el id en sprite. Devuelve 0 si no existe la textura
y no carga nada.
*/
Rint Render::createSprite(std::string texture, Rrect rectangle)
{
        if(!loadTexture(texture))
        return 0;
    
    Rint id = spritesCont;
    spritesCont++;

    sf::Sprite* s = new sf::Sprite(*getTexture(texture), sf::IntRect(rectangle.x, rectangle.y, rectangle.w, rectangle.h));

    sprites.insert(std::pair<Rint, sf::Sprite*>(id, s));

    return id;
}

/*
Devuelve el puntero al sprite identificado en sprite, si no existe devuelve nullptr
*/
sf::Sprite* Render::getSprite(Rint sprite)
{
    auto it = sprites.find(sprite);
    if (it != sprites.end())
        return it->second;
    
    return nullptr;
}

/*
Borra el sprite de la memoria y la libera, devuelve true si el sprite existia
y false si no existia.
*/
bool Render::deleteSprite(Rint sprite)
{
    bool r = false;
    if(sprites.find(sprite)!=sprites.end())
    {
        delete sprites.find(sprite)->second;
        sprites.erase(sprite);
        r=true;
    }

    return r;
}

/*
Dibuja el sprite pasado por parametro.
Devuelve false si no existe.
*/
bool Render::drawSprite(Rint sprite)
{
    bool r = false;
    if(sprites.find(sprite)!=sprites.end())
    {
        sprites.find(sprite)->second->setScale(sf::Vector2f(1, 1));
        sprites.find(sprite)->second->scale(sf::Vector2f(globalScale, globalScale));
        window->draw(*sprites.find(sprite)->second);
        
        r=true;
    }

    return r;
}


/*
Dibuja el sprite  pasado por parametro. Si centerd es true coloca el origen en el centro del objeto, sino en el 0,0.
Aplica las transformaciones pasadas en el orden S R T. Justo tras el escalado aplica el escalado global.
*/
bool Render::drawSprite(Rint sprite, Rvect position, float rotation, float scale, bool centered)
{
    if(sprites.find(sprite)==sprites.end())
        return false;


    sf::Sprite* s = sprites.find(sprite)->second;

    if(centered)
    {
        s->setOrigin(s->getLocalBounds().width*.5, s->getLocalBounds().height*.5);
    }else
    {
        s->setOrigin(0.f, 0.f);
    }
    
    s->setScale(sf::Vector2f(scale, scale));
    s->scale(sf::Vector2f(globalScale, globalScale));
    s->setRotation(rotation);
    s->setPosition(sf::Vector2f(position.x*globalScale, position.y*globalScale)); 

    window->draw(*s);


    return true;   
}


/*
Crea una animacion con los fps dados y devuelve el id de ella.
*/
Rint Render::createAnimation(float fps)
{
    Rint id = animationsCont;
    animationsCont++;

    Animation* a = new Animation(fps);

    animations.insert(std::pair<Rint, Animation*>(id, a));

    return id;
}

/*
Si encuentra la animacion , le añade el fotograma sprite, y devuelve true, sino devuelve false.
*/
bool Render::addFrameToAnimation(Rint animation, Rint sprite)
{
    bool r = false;
    if(animations.find(animation)!=animations.end())
    {
        animations.find(animation)->second->addFrame(sprite);
        r=true;
    }

    return r;
}

/*
Devuelve un puntero al objeto animation. En caso de no existir devuelve nullptr.
*/
Animation* Render::getAnimation(Rint animation)
{
    if(animations.find(animation)!=animations.end())
        return animations.find(animation)->second;

    return nullptr;
}

/*
Llama al desctructor de la case animation, que a su vez llama al destructor de todos los sprites, y se 
libera toda la memoria. En caso de que no encuentre la animacion devuelve false.
*/
bool Render::deleteAnimation(Rint animation)
{
    bool r = false;
    if(animations.find(animation)!=animations.end())
    {
        delete animations.find(animation)->second;
        animations.erase(animation);
        r=true;
    }

    return r;
}

/*
Si encuentra la animacion, dibuja el fotograma correspondiente sin aplicarle ninguna transfomrmacion y devuelve true.
En caso de no encontrar la animacion devuelve false.
*/
bool Render::drawAnimation(Rint animation)
{
    bool r = false;
    if(animations.find(animation)!=animations.end())
    {
        animations.find(animation)->second->draw(dt);        
        r=true;
    }

    return r;
}

/*
Si encuentra la animacion, dibuja el fotograma correspondiente aplicandole las transformaciones dadas por parametro y devuelve true.
En caso de no encontrar la animacion devuelve false.
*/
bool Render::drawAnimation(Rint animation, Rvect position, float rotation, float scale, bool centered)
{
    bool r = false;
    if(animations.find(animation)!=animations.end())
    {
        animations.find(animation)->second->draw(dt, position, rotation, scale, centered);        
        r=true;
    }

    return r;
}







/*
=============================================================================================
=============================================================================================
====================    Funciones de la clase Animacion     =================================
=============================================================================================
=============================================================================================
*/
/*
Crea una animacion con la velodicad en fps a la que se cambiara de frame.
*/
Animation::Animation(Rint fps)
{
    frames = 0;
    this->fps = fps;
    dt = 0.f;
    drawing = 0;
}


/*
Llama a la funcin deleteSprite de la clase Render de todos los sprites que tiene la animacion.
*/
Animation::~Animation()
{
    for(size_t i = 0; i< sprites.size(); i++)
    {
        if(sprites.at(i))
            Render::getInstance()->deleteSprite(sprites.at(i));
    }
    sprites.clear();
}

/*
Añade un nuevo fotograma a la animacion.
*/
void Animation::addFrame(Rint frame)
{
    sprites.push_back(frame);
    frames++;
}

/*
Dibuja la animacion.
*/
void Animation::draw(float dt)
{
    this->dt += dt;

    if(this->dt<1/fps)
    {
        this->dt = 0.f;
        drawing++;

        if(drawing>=frames)
            drawing = 0;
    }
    Render::getInstance()->drawSprite(sprites.at(drawing));
}

/*
Dibuja la animacion aplicandole las transformaciones pasadas por parametro
*/
void Animation::draw(float dt, Rvect position, float rotation, float scale, bool centered)
{
    this->dt += dt;

    float et = 1.f/fps;
    std::cout<<"estimated time betwen: "<<et<<"\n";
    if(this->dt>et)
    {
        this->dt = 0.f;
        drawing++;

        if(drawing>=frames)
            drawing = 0;
    }
    Render::getInstance()->drawSprite(sprites.at(drawing), position, rotation, scale, centered);
}