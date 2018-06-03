#include "Sprite.h"

Sprite::Sprite() : x(0), y(0), scale(64), texture("") {
    SetTexture("Textures/missing.bmp");
}

Sprite::Sprite(float _x, float _y) : x(_x), y(_y), scale(64), texture("") {
    SetTexture("Textures/missing.bmp");
}

Sprite::Sprite(float _x, float _y, std::string _texture) : x(_x), y(_y), scale(64), texture(_texture) {
    SetTexture(texture);
}

Sprite::Sprite(const Sprite& go) {
    x = go.x;
    y = go.y;
    scale = go.scale;
    texture = go.texture;

    SetTexture(texture);
}

void Sprite::SetTexture( std::string _texturePath) {
    struct stat fileAtt;
    if(stat( _texturePath.c_str(), &fileAtt) != 0) {
       texture = "Textures/missing.bmp";
       std::cout << "Missing texture set on path : " << _texturePath << std::endl;
    } else {
        texture = _texturePath;
    }
}

void Sprite::SetPosition(float _x, float _y) {
    x = _x;
    y = _y;
}
void Sprite::SetScale( int _scale )
{
    scale = _scale;
}

void Sprite::Serialize( PrettyWriter<StringBuffer>& writer )
{
    writer.StartObject();
    writer.String("x");
    writer.Double( x );
    writer.String("y");
    writer.Double( y );
    writer.String("scale");
    writer.Int( scale );
    writer.String("textures");
    #if RAPIDJSON_HAS_STDSTRING
        writer.String(texture);
    #else
        writer.String(texture.c_str(), static_cast<SizeType>(texture.length())); // Supplying length of string is faster.
    #endif
    writer.EndObject();
}

float Sprite::GetX() { return x; }
float Sprite::GetY() { return y; }
int Sprite::GetScale() { return scale; }
std::string Sprite::GetTexture() { return texture; }

Sprite::~Sprite() {
}
