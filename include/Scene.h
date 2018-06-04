#ifndef SCENE_H
#define SCENE_H


class Scene
{
    public:
        Scene();
        Scene( std::string _name );
        virtual ~Scene();
        
        Save( );
        Save( std::string filename );
        Save( std::string path, std::string filename );
        
        std::string Getname();
        void Setname(std::string val);

        Chunk GetChunks( unsigned int id );

        int AddChunks( Chunk val );
        void RemoveChunks( unsigned int id );
        void InsertChunks( unsigned int id, Chunk val);
        void SetChunks( unsigned int id, Chunk val );

    protected:

    private:
        std::string name;
        std::vector<Chunk> sceneChunks;
};

#endif // SCENE_H
