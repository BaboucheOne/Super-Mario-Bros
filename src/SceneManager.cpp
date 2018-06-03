#include "SceneManager.h"

#include <string>
#include <cstdio>

#include <math.h>
#include <stdio.h>

#include "rapidjson/prettywriter.h"

using namespace rapidjson;

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

/*
void SceneManager::LoadScene() {
    FILE *f = fopen("scene1.scene", "rb");
    if(f == NULL)
    {
        cout << "Could not load " << "scene1.scene" << endl;
        return;
    }

    Scene _scene;

    _scene.header.name = ""; //Allocate memory for name.
    fread(&_scene.header, sizeof(SceneHeader), 1, f);

    SceneData *dataToFill = new SceneData[_scene.header.dataLength];
    fread(dataToFill, sizeof(SceneData), _scene.header.dataLength, f);
    _scene.data = dataToFill;

    fclose(f);

    _currentScene = _scene;

    _sceneChunks = new Chunk[_scene.header.chuncksNumber]; //Allocate space for chunks
    for(int i = 0; i < _scene.header.chuncksNumber; i++) { //Fill chunks
        _sceneChunks[i].ID = i;
        _sceneChunks[i].x = 425 + i * 425;
        _sceneChunks[i].y = 300;
    }

    cout << "Scene name " << _scene.header.name << " |Data length " << _scene.header.dataLength << " |ChunkNumber " << _scene.header.chuncksNumber << endl;

    ConvertSceneToGameObjects();

    cout << "Scene loaded " << "scene1.scene" << endl;
}
*/
void SceneManager::UnloadScene() {
}

void SceneManager::CreateScene() {
    ofstream f;
    f.open("scene1.scene");
    if( !f.is_open() )
    {
        cout << "Missing file, unable to read scene data" << endl;
        return;
    }

    StringBuffer sb;
    PrettyWriter<StringBuffer> writer( sb );

    writer.StartObject();

    Scene _scene;


    writer.String( "scene" );
    _scene.header.name = "Scene";
    #if RAPIDJSON_HAS_STDSTRING
        writer.String(_scene.header.name);
    #else
        writer.String(_scene.header.name.c_str(), static_cast<SizeType>(_scene.header.name.length())); // Supplying length of string is faster.
    #endif

    writer.String("dataLength");
    _scene.header.dataLength = 10;
    writer.Int( _scene.header.dataLength );

    writer.String("chunksNumber");
    _scene.header.chuncksNumber = 10;
    writer.Int( _scene.header.chuncksNumber );

    writer.String( "chunks" );
    writer.StartArray();
    for(int i = 0; i < _scene.header.chuncksNumber; i++) {

        Chunk chunk;

        chunk.ID = i;
        chunk.x = 425 + i * 425;
        chunk.y = 300;

        for ( int i = 0; i < 10;  i++ )
        {
            Sprite sprite;
            sprite.SetPosition( i * 64.0f, 0 );
            sprite.SetScale( 64 );
            sprite.SetTexture( "textures/eagle.bmp" );
            chunk.sprite.push_back( sprite );
        }


        _sceneChunks.push_back( chunk );
        chunk.Serialize( writer );

    }
    writer.EndArray();
    writer.EndObject();

    f << sb.GetString();

    f.close();

    cout << "Scene created scene1.scene" << endl;
}


Chunk SceneManager::GetChunck(int _index) { return _sceneChunks[_index];}
Chunk SceneManager::GetChunckByID(int _id) {
    for(int i = 0; i < _sceneChunks.size(); i++) {
        if(_sceneChunks[i].ID == _id) {
            return _sceneChunks[i];
        }
    }
}

Chunk SceneManager::GetNearstChunckFrom(float x, float y) {
    for(int i = 0; i < _sceneChunks.size(); i++) {
        if(sqrt(pow(x - _sceneChunks[i].x, 2) + pow(y - _sceneChunks[i].y, 2)) <= 212.5) {
            return _sceneChunks[i];
        }
    }
}
