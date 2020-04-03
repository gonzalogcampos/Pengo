#include "Map.h"

#include "GameObject.h"
#include "Pengo.h"
#include "SnoBee.h"
#include "Ice.h"
#include "Render.h"
#include <iostream>

/*
Initialize all the values
*/
Map::Map()
{

}


/*
Calls clear()
*/
Map::~Map()
{
    clear();
}

/*
Calls the destructor of all the GameObjects in the map
*/
void Map::clear()
{
    for(int x = 0; x<MAP_W; x++)
    {
        for(int y = 0; y<MAP_H; y++)
        {
            if(map[x]!=nullptr && map[y]!=nullptr)
                delete map[x][y];
        }
    }
}

/*
Returns the Game Object located in the position xy. Returns null if it is empty
*/
GameObject* Map::getGameobject(int x, int y)
{
    GameObject* r = nullptr;

    if(map[x]!=nullptr && map[x][y]!=nullptr)
        r = map[x][y];

    return r;
}

/*
Returns the Pengo iten in the map or null if there is no Pengo
*/
Pengo* Map::getPengo()
{
    return pengo;
}

/*
Calls the draw() function of all the Game Objects in the map
*/
void Map::draw()
{
    Render::getInstance()->drawSprite(spriteBack, Rvect(0,0), 0.f, 1.f, false);
    for(int x=0; x<MAP_W; x++)
    {
        for(int y=0; y<MAP_H; y++)
        {
            if(map[x][y]!=nullptr)
            {
                map[x][y]->draw();
            }
        }
    }
}

/*
Allocate gameObject at the xy position, returns true if xy was empty and false if has a Game Object
*/
bool Map::put(GameObject* gameObject, int x, int y)
{
    if(map[x] !=nullptr && map[x][y] == nullptr)
    {
        map[x][y] = gameObject;
        return true;
    }

    return false;
}

/*
Removes the Game Object located in the position xy
*/
bool Map::push(int x, int y)
{
    if(map[x] !=nullptr && map[x][y] != nullptr)
    {
        delete map[x][y];
        map[x][y] = nullptr;
        return true;
    }

    return false;
}

/*
If the gameObject is in the map returns true and the xy position, else returns false
*/
bool Map::getPosition(GameObject* gameObject, int &x, int &y)
{
    if(gameObject==nullptr)
        return false;

    for(int i = 0; i<MAP_W; i++)
    {
        for(int j = 0; j<MAP_H; j++)
        {
            if(map[i]!=nullptr && map[j]!=nullptr && map[i][j] == gameObject)
            {
                x = i;
                y = j;
                return true;
            }
            
        }
    }
    return false;
}

/*
Creates a Pengo in the xy position, then returns the pengo. Returns null if there is something in xy
*/
Pengo* Map::createPengo(int x,int y)
{
    if(map[x] !=nullptr && map[x][y] == nullptr)
    {

        map[x][y] = new Pengo(x, y);
        pengo = (Pengo*)map[x][y];
        return pengo;
    }
    return nullptr;
}

/*
Creates an ice in the xy position, then returns the pengo. Returns null if there is something in xy
*/
Ice* Map::createIce(int x,int y)
{
    if(map[x] !=nullptr && map[x][y] == nullptr)
    {
        
        map[x][y] = new Ice(x, y);
        return (Ice*)map[x][y];
    }
    return nullptr;
}

/*
Creates a Sno-Bee in the xy position, then returns the pengo. Returns null if there is something in xy
*/
SnoBee* Map::createSnobee(int x,int y)
{
    if(map[x] !=nullptr && map[x][y] == nullptr)
    {
        
        map[x][y] = new SnoBee(x, y);
        return (SnoBee*)map[x][y];
    }
    return nullptr;
}

/*
Calls the update(float dt) function of all the Game Objects in the map
*/
void Map::update(float dt)
{
    int s = sizeof(map)/sizeof(map[0]);
    
    for(int x = 0; x<MAP_W; x++)
        for(int y = 0; y<MAP_H; y++)
            if(map[x]!=nullptr && map[x][y]!=nullptr)
                map[x][y]->noUpdate();
    

    
    for(int x = 0; x<MAP_W; x++)
        for(int y = 0; y<MAP_H; y++)
            if(map[x]!=nullptr && map[x][y]!=nullptr)
                map[x][y]->update(dt);
    
}

void Map::init()
{
    spriteBack = Render::getInstance()->createSprite("res/T2.png", Rrect(0, 0, 223, 255) );

    createPengo(0, 0);
}

bool Map::moveUp(GameObject* gameobject)
{   
    if(gameobject==nullptr)
        return false;
    
    int x = -1;
    int y = -1;
    for(int i = 0; i<MAP_W; i++)
    {
        for(int j = 0 ; j<MAP_H; j++)
        {
            if(map[i]!=nullptr && map[j]!=nullptr && map[i][j] == gameobject)
            {
                x = i;
                y = j;
            }
        }
    }

    if(x>=0 && x<MAP_W && (y-1)>=0 && (y-1)<MAP_H && map[x][y-1]==nullptr)
    {
        map[x][y-1] = map[x][y];
        map[x][y] = nullptr;
        return true;
    }
    return false;
}
bool Map::moveDown(GameObject* gameobject)
{

    if(gameobject==nullptr)
        return false;
    
    int x = -1;
    int y = -1;
    for(int i = 0; i<MAP_W; i++)
    {
        for(int j = 0; j<MAP_H; j++)
        {
            if(map[i]!=nullptr && map[j]!=nullptr && map[i][j] == gameobject)
            {
                x = i;
                y = j;
            }
        }
    }
    if(x>=0 && x<MAP_W && (y+1)>=0 && (y+1)<MAP_H && map[x][y+1]==nullptr)
    {
        map[x][y+1] = map[x][y];
        map[x][y] = nullptr;
        return true;
    }
    return false;
}

bool Map::moveLeft(GameObject* gameobject)
{
    if(gameobject==nullptr)
        return false;
    
    int x = -1;
    int y = -1;
    for(int i = 0; i<MAP_W; i++)
    {
        for(int j = 0; j<MAP_H; j++)
        {
            if(map[i]!=nullptr && map[j]!=nullptr && map[i][j] == gameobject)
            {
                x = i;
                y = j;
            }
        }
    }

    if((x-1)>=0 && (x-1)<MAP_W && y>=0 && y<MAP_H && map[x-1][y]==nullptr)
    {
        map[x-1][y] = map[x][y];
        map[x][y] = nullptr;
        return true;
    }
    return false;
}

bool Map::moveRight(GameObject* gameobject)
{
    if(gameobject==nullptr)
        return false;
    
    int x = -1;
    int y = -1;
    for(int i = 0; i<MAP_W; i++)
    {
        for(int j = 0; j<MAP_H; j++)
        {
            if(map[i]!=nullptr && map[j]!=nullptr && map[i][j] == gameobject)
            {
                x = i;
                y = j;
            }
        }
    }

    if((x+1)>=0 && (x+1)<MAP_W && y>=0 && y<MAP_H && map[x+1][y]==nullptr)
    {
        map[x+1][y] = map[x][y];
        map[x][y] = nullptr;
        return true;
    }
    return false;
}

