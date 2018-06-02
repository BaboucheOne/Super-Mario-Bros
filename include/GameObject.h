#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <fstream>
#include <iostream>

#include <SDL2/SDL.h>
#include <sys/stat.h>
#include <stdlib.h>

class GameObject
{
    public:
        GameObject();
        GameObject(float _x, float _y);
        GameObject(float _x, float _y, char* _texture);
        GameObject(const GameObject& go);
        virtual ~GameObject();

        void SetPosition(float _x, float _y);
        void SetTexture(char* _texturePath);

        float GetX();
        float GetY();
        int GetScale();
        char* GetTexture();

    protected:

    private:
        float x;
        float y;
        int scale;
        char *texture = new char[40];
};

#endif // GAMEOBJECT_H
