
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
#include "Global.h"
#include "SceneManager.h"
#include "RenderManager.h"



int main(int argc, char *argv[]) {

    RenderManager _rendererManager(600, 850);

    SceneManager _sceneManager;
	_sceneManager.CreateScene();
	//_sceneManager.LoadScene();
	Chunk c = _sceneManager.GetChunckByID(2);
	cout << c.sprite.size() << endl;
	_rendererManager.SendChunk(c);

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

