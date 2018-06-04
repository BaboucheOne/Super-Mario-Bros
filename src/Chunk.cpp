#include "rapidjson/prettywriter.h"

#include "Chunk.h"

using namespace rapidjson;
using namespace std;

Chunk::Chunk()
{
    //ctor
}

Chunk::~Chunk()
{
    //dtor
}

Chunk::Chunk(int _ID, int _x, int _y) : ID(_ID), x(_x), y(_y)
{
}

Chunk::Chunk(const Chunk& c)
{
    ID = c.ID;
    x = c.x;
    y = c.y;
    sprite.assign( c.sprite.begin(), c.sprite.end() );
}

Chunk Chunk::operator = (const Chunk& x)
{
    return Chunk( x );
}

void Chunk::Serialize( PrettyWriter<StringBuffer>& writer )
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
    cout << "saving sprites" << endl;
    if ( sprite.size() > 0 ) {
        for ( unsigned int i = 0; i < sprite.size(); i++ )
        {
            sprite[i].Serialize( writer );
            cout << "sprite " << i << endl;
        }
    }
    writer.EndArray();
    writer.EndObject();
}
