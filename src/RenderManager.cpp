#include "RenderManager.h"

RenderManager::RenderManager() : width(600), height(850)
{
    Init();
}

RenderManager::RenderManager(unsigned int _width, unsigned int _height) : width(_width), height(_height)
{
    Init();
}

void RenderManager::Init()
{

    if (SDL_VideoInit(NULL) < 0) {
		cout << "Can't create SDL video " << SDL_GetError() << endl;
		return;
	}

    window = SDL_CreateWindow("Scene loader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (window == NULL) {
		cout << "Error when creating window" << SDL_GetError() << endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void RenderManager::Update()
{

		SDL_RenderClear(renderer);

        /*
        int posX = 0;
        int posY = 0;
		SDL_Rect dest = {posX, posY, 64, 64};
		SDL_RenderCopy(renderer,text_img,NULL,&dest);
		*/

		for(unsigned int i = 0; i < _visibleChuncks.size(); i++) {
		    ElementsInChunk elementToDraw = _visibleChuncks.at(i);
            for(unsigned int j = 0; j < elementToDraw.rects.size(); j++) {
                SDL_RenderCopy(renderer, elementToDraw.textures.at(j), NULL, &elementToDraw.rects.at(j));
            }
		}

		SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255); //Background color.
		SDL_RenderPresent(renderer);

}

bool RenderManager::CheckChunkEquality(Chunk _chunk)
{

    if(_visibleChuncks.size() == 0) {
        return true;
    }

    for(unsigned int i = 0; i < _visibleChuncks.size(); i++) {
        if(_visibleChuncks.at(i).chunk.ID == _chunk.ID) {
            return true;
        }
    }

    return false;
}

void RenderManager::SendChunk(Chunk _chunk)
{
    if(!CheckChunkEquality(_chunk)) { return; }

    unsigned int goSize = _chunk.sprite.size();

    ElementsInChunk new_element;
    new_element.chunk = _chunk;

    for(unsigned int i = 0; i < goSize; i++) {
        Sprite sprt = _chunk.sprite.at(i);
        unsigned scale = sprt.GetScale();

        SDL_Rect rect = {(int)sprt.GetX(), (int)sprt.GetY(), (int)scale, (int)scale};
        SDL_Surface* surface = SDL_LoadBMP(sprt.GetTexture().c_str());

        if(surface == NULL) {
            cout << SDL_GetError() << endl;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        if(texture == NULL) {
            cout << SDL_GetError() << endl;
        }

        new_element.rects.push_back(rect);
        new_element.textures.push_back(texture);

        SDL_FreeSurface(surface);
    }

    _visibleChuncks.push_back(new_element);
}

void RenderManager::UnloadChunk(Chunk _chunk)
{
    for(unsigned int i = 0; i < _visibleChuncks.size(); i++) {
        if(_visibleChuncks.at(i).chunk.ID == _chunk.ID) {
            delete(&_visibleChuncks[i]);
            break;
        }
    }
}

void RenderManager::Exit()
{
    delete[] &_visibleChuncks;

    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

RenderManager::~RenderManager()
{
    Exit();
}
