
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <list>
#include <stdlib.h>
#include <sys/stat.h>
#include <SDL2/SDL.h>
#include <cstdio>
#include <time.h>

using namespace std;



#include "Sprite.h"
#include "Chunk.h"
#include "Scene.h"
#include "RenderManager.h"



int main(int argc, char *argv[]) {

    RenderManager _rendererManager(600, 850);

    Scene _scene = Scene( "scene1" );
    Chunk chunk = Chunk( 1, 10, 10 );
    chunk.sprite.push_back( Sprite( 0, 0, "textures/eagle.bmp" ) );
    _scene.AddChunk( chunk );

    _scene.Save();

	Chunk* chunkPointer = _scene.GetChunk(0);
	if ( chunkPointer == NULL ) {
	    cout << "chunk pointer is NULL , terminating" << endl;
	    return EXIT_FAILURE;
	}
	Chunk c = *chunkPointer;
	cout << c.sprite.size() << endl;
	_rendererManager.SendChunk( c );
	//_rendererManager.UnloadChunk(c);

    bool running = true;
    unsigned int pass = 0;
    SDL_Event event;
    while (running) {
        pass++;
        cout << pass << endl;
        unsigned int time = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {

			switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
			}
		}



		_rendererManager.Update();

        time = SDL_GetTicks() - time;


        SDL_Delay( 1 / 60 * 1000 - time );

    }

	return EXIT_SUCCESS;
}

