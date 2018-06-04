#ifndef Sprite_H
#define Sprite_H

#include <fstream>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "rapidjson/prettywriter.h"

class Sprite
{
    public:
        Sprite();
        Sprite(float _x, float _y);
        Sprite(float _x, float _y, std::string _texture);
        Sprite(const Sprite& go);
        virtual ~Sprite();

        void SetPosition(float _x, float _y);
        void SetScale( int _scale );
        void SetTexture( std::string _texturePath);

        void Serialize( rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer );

        Sprite operator=( const Sprite& s );

        float GetX();
        float GetY();
        int GetScale();
        std::string GetTexture();

    protected:

    private:
        float x;
        float y;
        int scale;
        std::string texture;
};

#endif // Sprite_H
