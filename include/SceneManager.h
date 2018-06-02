#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Global.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

#include "GameObject.h"

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
    char* texture; //Texture path.
};

struct SceneHeader {
    char* name;
    int dataLength; //Length of SceneData's array.
    int chuncksNumber; //How many chunks.
};

struct Scene {
    SceneHeader header;
    SceneData* data;
};

class SceneManager
{
    public:
        SceneManager();
        virtual ~SceneManager();

        void LoadScene();
        void UnloadScene();
        void UploadScene();
        Scene GetActiveScene();

        GameObject GetGameObjects(int _index);

        Chunk GetChunckByID(int _id);
        Chunk GetChunck(int _index);
        Chunk GetNearstChunckFrom(float x, float y); //BUGGER


    protected:

    private:
        Scene _currentScene;
        GameObject *_sceneGameObjects;
        Chunk *_sceneChunks;
        void ConvertSceneToGameObjects();
};

#endif // SCENEMANAGER_H
