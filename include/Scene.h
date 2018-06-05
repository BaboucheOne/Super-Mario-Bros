#ifndef SCENE_H
#define SCENE_H

#include <string>

#include "Chunk.h"

class Scene
{
    public:
        Scene();
        Scene( std::string _name );
        virtual ~Scene();

        void Save( );
        void Save( std::string filename );
        void Save( std::string path, std::string filename );

        void Load( std::string filename );
        void Load( std::string path, std::string filename );

        std::string Getname();
        void Setname(std::string val);

        Chunk* GetChunk( unsigned int id );
        Chunk* GetNearestChunk( int _x, int _y );
        void AddChunk( Chunk val );
        void RemoveChunk( unsigned int id );
        void InsertChunk( unsigned int id, Chunk val);
        void SetChunk( unsigned int id, Chunk val );

    protected:

    private:
        std::string name;
        std::vector<Chunk> sceneChunks;
};

#endif // SCENE_H
