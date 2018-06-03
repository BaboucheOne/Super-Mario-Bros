#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <vector>

#include "Chunk.h"

/*

    Cree une fonction qui regarde si un chunk est hors de porte pour le supprimer.

*/

struct ElementsInChunk {
    Chunk chunk;
    vector<SDL_Rect> rects;
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
        void UnloadChunk(Chunk _chunk);

    protected:

    private:
        unsigned int renderDistance;
        unsigned int width;
        unsigned int height;
        SDL_Window* window;
        SDL_Renderer* renderer;
        vector<ElementsInChunk> _visibleChuncks;

        void Init();
        bool CheckChunkEquality(Chunk _chunk); //Is this chunk already in the vector "_visibleChuncks" ?
};

#endif // RENDERMANAGER_H
