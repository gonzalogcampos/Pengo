#pragma once
#include <string>
#include <map>
#include <vector>

//Cabecera de SFML
#include <SFML/Graphics.hpp>


/*
    Variables predefinidas para gestionar funciones del render
*/
typedef unsigned int Rint;
struct Rrect
{
    int x;
    int y;
    int w;
    int h;
    Rrect(int x, int y, int w, int h){this->x = x; this->y = y;this->w = w; this->h = h;}
};
struct Rvect
{
    float x;
    float y;
    Rvect(float x,float y){this->x = x; this->y = y;}
};


class Animation
{
    private:
        Rint frames;
        Rint fps;
        float dt;
        Rint drawing;
        std::vector<Rint> sprites;

    public:
    Animation(Rint fps);
    ~Animation();
    void addFrame(Rint frame);
    void draw(float dt);
    void draw(float dt, Rvect position, float rotation = 0.f, float scale = 0.f, bool centered = true);
};


/*
    Clase Render singleton
*/
class Render
{
    private:
        Render(){};

        sf::RenderWindow* window;

        std::map<std::string, sf::Texture*> textures;

        std::map<Rint, sf::Sprite*> sprites;

        std::map<Rint, Animation*> animations;


        Rint spritesCont = 1;
        Rint animationsCont = 1;

        float globalScale;

        float dt;

    public:
        bool g = false;
        bool x = false;
        bool n = false;

        static Render* getInstance()
        {
            static Render onlyInstance;
            return &onlyInstance;
        }

        ~Render();

        //System functions

        void init();

        void close();

        bool isWindowOpen();

        void preLoop(float dt);

        void postLoop();

        void clearMemory();

        void setGlobalScale(float scale);

        float getGlobalScale();

        //Textures function

        bool loadTexture(std::string texture);

        bool deleteTexture(std::string texture);

        sf::Texture* getTexture(std::string texture);

        //Sprites functions

        Rint createSprite(std::string texture);

        Rint createSprite(std::string texture, Rrect rectangle);

        sf::Sprite* getSprite(Rint sprite);

        bool deleteSprite(Rint sprite);

        bool drawSprite(Rint sprite);

        bool drawSprite(Rint sprite, Rvect position, float rotation = 0.f, float scale = 1.f, bool centered = true);

        //Animation functions

        Rint createAnimation(float fps);

        bool addFrameToAnimation(Rint animation, Rint sprite);

        Animation* getAnimation(Rint animation);

        bool deleteAnimation(Rint animation);

        bool drawAnimation(Rint animation);

        bool drawAnimation(Rint animation, Rvect position, float rotation = 0.f, float scale = 1.f, bool centered = true);


};