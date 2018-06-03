#ifndef CHUNK_H
#define CHUNK_H

#include "rapidjson/prettywriter.h"

#include <string>
#include <vector>

#include "Sprite.h"

using namespace std;
using namespace rapidjson;
class Chunk {
    public:
        Chunk();
        Chunk( int _ID,int _x, int _y);
        Chunk( const Chunk& c);
        virtual ~Chunk();
        template <typename Writer>
        void Serialize( Writer& writer );

        int ID;
        int x;
        int y;
        vector <Sprite> sprite;

    protected:

    private:


};

#endif // CHUNK_H
