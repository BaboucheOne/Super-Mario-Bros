#include "SceneManager.h"

/*

    Chunks:
    425 => half of the screen (800 /2 = 425)
    212.5 => half of 425. Length of a box size.
    300 => half of the screen (600 /2 => 300)

*/

SceneManager::SceneManager() {
    //ctor
}

SceneManager::~SceneManager() {
    //dtor
}

void SceneManager::LoadScene() {
    FILE *f = fopen("scene1.scene", "rb");
    if(f == NULL)
    {
        std::cout << "Could not load " << "scene1.scene" << std::endl;
        return;
    }

    Scene _scene;

    _scene.header.name = new char[40]; //Allocate memory for name.
    fread(&_scene.header, sizeof(SceneHeader), 1, f);

    SceneData *dataToFill = new SceneData[_scene.header.dataLength];
    fread(dataToFill, sizeof(SceneData), _scene.header.dataLength, f);
    _scene.data = dataToFill;

    fclose(f);

    _currentScene = _scene;

    _sceneChunks = new Chunk[_scene.header.chuncksNumber]; //Allocate space for chunks
    for(unsigned int i = 0; i < _scene.header.chuncksNumber; i++) { //Fill chunks
        _sceneChunks[i].ID = i;
        _sceneChunks[i].x = 425 + i * 425;
        _sceneChunks[i].y = 300;
    }

    std::cout << "Scene name " << _scene.header.name << " |Data length " << _scene.header.dataLength << " |ChunkNumber " << _scene.header.chuncksNumber << std::endl;

    ConvertSceneToGameObjects();

    std::cout << "Scene loaded " << "scene1.scene" << std::endl;
}

void SceneManager::UnloadScene() {
}

void SceneManager::UploadScene() {
    FILE *f = fopen("scene1.scene", "wb");

    if(f == NULL)
    {
        std::cout << "Missing file, unable to read it" << std::endl;
        return;
    }

    Scene _scene;

    _scene.header.name = new char[40];
    _scene.header.name = "Scene";
    _scene.header.dataLength = 10;
    _scene.header.chuncksNumber = 10;

    _scene.data = new SceneData[_scene.header.dataLength];

    SceneData data[_scene.header.dataLength];
    for(unsigned int i = 0; i < 10; i++) {
        data[i].x = i * 2.0f;
        data[i].y = i * 2.0f;
        data[i].scale = 64;
        data[i].texture = "Textures/eagle.bmp";
    }

    _scene.data = data;

    fwrite(&_scene.header, sizeof(SceneHeader), 1, f);
    fwrite(data, sizeof(SceneData), _scene.header.dataLength, f);
    fclose(f);

    std::cout << "Scene created scene1.scene" << std::endl;
}

void SceneManager::ConvertSceneToGameObjects() {
    int dataLength = _currentScene.header.dataLength;
    int chunkNumber = _currentScene.header.chuncksNumber;
    _sceneGameObjects = new GameObject[dataLength];

    for(unsigned int i = 0; i < dataLength; i++) {
        SceneData sceneData = _currentScene.data[i];

        GameObject go = GameObject(sceneData.x, sceneData.y, sceneData.texture);
        _sceneGameObjects[i] = go;

        for(unsigned int j = 0; j < chunkNumber; j++) {
            Chunk chunk = _sceneChunks[j];
            if(sqrt(pow(go.GetX() - chunk.x,2) + pow(go.GetY() - chunk.y,2)) <= 212.5) {
                chunk.gameobject.push_back(go);
                break;
            }
        }
    }

    std::cout << "Scene converted to gameObjects" << std::endl;
}

Scene SceneManager::GetActiveScene() {
    std::cout << _currentScene.header.name << std::endl;
    std::cout << _currentScene.header.dataLength << std::endl;
    return _currentScene;
}

GameObject SceneManager::GetGameObjects(int _index) {
    if(_index > sizeof(_sceneGameObjects)) {
        std::cout << "Impossible to get gameobject at ID"  << _index << std::endl;
        return GameObject();
    }

    return _sceneGameObjects[_index];
}


Chunk SceneManager::GetChunck(int _index) { return _sceneChunks[_index];}
Chunk SceneManager::GetChunckByID(int _id) {
    for(int i = 0; i < _currentScene.header.dataLength; i++) {
        if(_sceneChunks[i].ID == _id) {
            return _sceneChunks[i];
        }
    }
}

Chunk SceneManager::GetNearstChunckFrom(float x, float y) {
    for(int i = 0; i < _currentScene.header.dataLength; i++) {
        if(sqrt(pow(x - _sceneChunks[i].x, 2) + pow(y - _sceneChunks[i].y, 2)) <= 212.5) {
            return _sceneChunks[i];
        }
    }
}
