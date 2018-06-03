#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <vector>

#include "Chunk.h"

struct ElementsInChunk {
    Chunk chunk;
    vector<SDL_Rect> rects;
    vector<SDL_Surface*> surfaces;
    vector<SDL_Texture*> textures;
};

class RenderManager
{
    public:
        RenderManager();
        RenderManager(unsigned int _height, unsigned int _width);
        virtual ~RenderManager();

        void Update();
        void Exit();

        void SendChunk(Chunk _chunk);

    protected:

    private:
        unsigned int renderDistance = 350;
        unsigned int width;
        unsigned int height;
        SDL_Window* window;
        SDL_Renderer* renderer;
        vector<ElementsInChunk> _visibleChuncks;

        void Init();
        bool CheckChunkEquality(Chunk _chunk); //Is this chunk already in the vector "_visibleChuncks" ?
        void UnloadChunck();
};

#endif // RENDERMANAGER_H
