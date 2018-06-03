#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <fstream>
#include <iostream>
#include <vector>

#include <stdlib.h>

#include "Chunk.h"
#include "Sprite.h"


/*

    Stuct of scene file.
        SceneHeader:
            scene name,
            data length => length of the SceneData array.
        SceneData:
            x => position x of go,
            y => position y of go,
            scale => scale of go,
            texture => texture path of go.

        Scene => Regroup both [SceneHeader;SceneData]
*/

struct SceneData {
    float x;
    float y;
    int scale;
    std::string texture; //Texture path.
};

struct SceneHeader {
    std::string name;
    int dataLength; //Length of SceneData's array.
    int chuncksNumber; //How many chunks.
};

struct Scene {
    SceneHeader header;
    std::vector<SceneData> data;
};

class SceneManager
{
    public:
        SceneManager();
        virtual ~SceneManager();

        void LoadScene();
        void UnloadScene();
        void CreateScene();

        Chunk GetChunckByID(int _id);
        Chunk GetChunck(int _index);
        Chunk GetNearstChunckFrom(float x, float y); //BUGGER


    protected:

    private:
        std::string name;
        std::vector<Chunk> _sceneChunks;
};

#endif // SCENEMANAGER_H
