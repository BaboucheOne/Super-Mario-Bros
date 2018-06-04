
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <list>
#include <stdlib.h>
#include <sys/stat.h>
#include <SDL2/SDL.h>
#include <cstdio>

using namespace std;



#include "Sprite.h"
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

    SDL_Event event;

    while (running) {

        while (SDL_PollEvent(&event)) {

			switch (event.type) {

			case SDL_QUIT:
				running = false;
				break;
			}
		}
        _rendererManager.Update();
    }

	return EXIT_SUCCESS;
}

