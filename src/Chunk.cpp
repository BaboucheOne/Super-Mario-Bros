#include "rapidjson/prettywriter.h"

#include "Chunk.h"

using namespace rapidjson;

Chunk::Chunk()
{
    //ctor
}

Chunk::~Chunk()
{
    //dtor
}

Chunk::Chunk(int _ID, int _x, int _y)
{
    ID = _ID;
    x = _x;
    y = _y;
}

Chunk::Chunk(const Chunk& c)
{
    ID = c.ID;
    x = c.x;
    y = c.y;
    sprite.assign( c.sprite.begin(), c.sprite.end() );
}
template <typename Writer>
void Chunk::Serialize( Writer& writer )
{
    writer.StartObject();
    writer.String("ID");
    writer.Int( ID );
    writer.String("x");
    writer.Int( x );
    writer.String("y");
    writer.Int( y );
    writer.String("sprites");
    writer.StartArray();
    for ( int i = 0; i < sprite.size(); i++ )
    {
        sprite[i].Serialize( writer );
    }
    writer.EndArray();
    writer.EndObject();
}
