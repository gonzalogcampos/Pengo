#include "Map.h"

#include "GameObject.h"
#include "Pengo.h"
#include "SnoBee.h"
#include "Ice.h"

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
    int s = sizeof(map)/sizeof(map[0]);
    for(int x; x<s; x++)
    {
        for(int y; y<s; y++)
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
GameObject* Map::getPengo()
{
    return nullptr;
}

/*
Calls the draw() function of all the Game Objects in the map
*/
void Map::draw()
{

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
    int s = sizeof(map)/sizeof(map[0]);
    for(int i; i<s; i++)
    {
        for(int j; j<s; j++)
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
GameObject* Map::createPengo(int x,int y)
{
    if(map[x] !=nullptr && map[x][y] == nullptr)
    {
        
        map[x][y] = new GameObject();
        return map[x][y];
    }
    return nullptr;
}

/*
Creates an ice in the xy position, then returns the pengo. Returns null if there is something in xy
*/
GameObject* Map::createIce(int x,int y)
{
    if(map[x] !=nullptr && map[x][y] == nullptr)
    {
        
        map[x][y] = new GameObject();
        return map[x][y];
    }
    return nullptr;
}

/*
Creates a Sno-Bee in the xy position, then returns the pengo. Returns null if there is something in xy
*/
GameObject* Map::createSnobee(int x,int y)
{
    if(map[x] !=nullptr && map[x][y] == nullptr)
    {
        
        map[x][y] = new GameObject();
        return map[x][y];
    }
    return nullptr;
}

/*
Calls the update(float dt) function of all the Game Objects in the map
*/
void Map::update(float dt)
{
    int s = sizeof(map)/sizeof(map[0]);
    for(int x; x<s; x++)
    {
        for(int y; y<s; y++)
        {
            if(map[x]!=nullptr && map[y]!=nullptr)
                map[x][y]->update(dt);
        }
    }
}