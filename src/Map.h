#pragma once

class GameObject;

class Map
{
    private:
        GameObject* map[10][10];
        Map();
        ~Map();
    
    public:
        /*
        Singleton
        */
        static Map* getInstance()
        {
            static Map only_instance;
            return &only_instance;
        }


        /*
        Calls the destructor of all the GameObjects in the map
        */
        void clear();

        /*
        Returns the Game Object located in the position xy. Returns null if it is empty
        */
        GameObject* getGameobject(int x, int y);

        /*
        Returns the Pengo iten in the map or null if there is no Pengo
        */
        GameObject* getPengo();

        /*
        Calls the draw() function of all the Game Objects in the map
        */
        void draw();

        /*
        Allocate gameObject at the xy position, returns true if xy was empty and false if has a Game Object
        */
        bool put(GameObject* gameObject, int x, int y);

        /*
        Removes the Game Object located in the position xy
        */
        bool push(int x, int y);

        /*
        If the gameObject is in the map returns true and the xy position, else returns false
        */
        bool getPosition(GameObject* gameObject, int &x, int &y);

        /*
        Creates a Pengo in the xy position, then returns the pengo. Returns null if there is something in xy
        */
        GameObject* createPengo(int x, int y);

        /*
        Creates an ice in the xy position, then returns the pengo. Returns null if there is something in xy
        */
        GameObject* createIce(int x, int y);

        /*
        Creates a Sno-Bee in the xy position, then returns the pengo. Returns null if there is something in xy
        */
        GameObject* createSnobee(int x, int y);

        /*
        Calls the update(float dt) function of all the Game Objects in the map
        */
        void update(float dt);



};