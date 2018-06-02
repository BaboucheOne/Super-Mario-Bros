#include "SceneManager.h"
#include "RenderManager.h"

using namespace std;

int main(int argc, char *argv[]) {

    RenderManager _rendererManager(600, 850);

    SceneManager _sceneManager;
	_sceneManager.UploadScene();
	_sceneManager.LoadScene();
	Chunk c = _sceneManager.GetChunckByID(0);
	std::cout << c.gameobject.size() << std::endl;
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

