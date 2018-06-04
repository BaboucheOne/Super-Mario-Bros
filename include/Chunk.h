#ifndef CHUNK_H
#define CHUNK_H

#include "rapidjson/prettywriter.h"

#include <string>
#include <vector>

#include "Sprite.h"

class Chunk {
    public:
        Chunk();
        Chunk( int _ID,int _x, int _y);
        Chunk( const Chunk& c);
        virtual ~Chunk();
        void Serialize( rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer );

        int ID;
        int x;
        int y;
        std::vector <Sprite> sprite;

        Chunk operator= (const Chunk& c);

    protected:

    private:


};

#endif // CHUNK_H
