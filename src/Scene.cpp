#include "Scene.h"
#include "rapidjson/prettywriter.h"

using namespace rapidjson;
using namespace std;

Scene::Scene()
{
    Scene("default");
}

Scene::Scene( string _name )
{
    name = _name;
}

Scene::~Scene()
{
    //dtor
}

std::string Scene::Getname()
{
    return name;
}
void Scene::Setname(std::string val)
{
    name = val;
}
Chunk Scene::GetChunks( unsigned int id )
{
    if ( id < sceneChunks.size() ) {
        return sceneChunks[ id ];
    }
}
void Scene::AddChunks( Chunk val )
{
    sceneChunks.push_back( val );
}
void Scene::RemoveChunks( unsigned int id )
{
    if ( id < sceneChunks.size() ) {
        sceneChunks.erase( sceneChunks.begin() + id )
    }
}
void Scene::InsertChunks( unsigned int id, Chunk val)
{
    if ( id < sceneChunks.size() ) {
        sceneChunks.insert( sceneChunks.begin() + id , val );
    }
    else {
        sceneChunks.push_back( val );
    }
}
void Scene::SetChunks( unsigned int id, Chunk val )
{
    if ( id < sceneChunks.size() ) {
        sceneChunks[id] = val;
    }
}
