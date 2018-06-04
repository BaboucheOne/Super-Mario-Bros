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

void Scene::Save()
{
    Save( "", name );
}

void Scene::Save( string filename )
{
    Save( "", filename );
}

void Scene::Save( string path, string filename )
{

    ofstream f;
    string filepath = path + filename + ".scene";
    cout << " Saving scene \"" << name << "\" to \"" << filepath << "\"" << endl;
    f.open( filepath.c_str() );
    if( !f.is_open() )
    {
        cout << "Unable to create file \""<< filepath << "\", scene not saved " << endl;
        return;
    }

    StringBuffer sb;
    PrettyWriter<StringBuffer> writer( sb );

    writer.StartObject();

    writer.String("scene");
    #if RAPIDJSON_HAS_STDSTRING
        writer.String( name );
    #else
        writer.String( name.c_str(), static_cast<SizeType>(name.length())); // Supplying length of string is faster.
    #endif
    writer.String("chunks");
    cout << "saving chunks" << endl;
    writer.StartArray();
    if ( sceneChunks.size() > 0 ) {
        for ( unsigned int i = 0 ; i < sceneChunks.size(); i++ ) {
            sceneChunks[i].Serialize( writer );
            cout << " chunk " << i << " saved" << endl;
        }
    }
    writer.EndArray();
    writer.EndObject();

    f << sb.GetString();

    f.close();

    cout << "saved scene \"" << name << "\" as \"" << filename << "\" at \"" << path << "\"" << endl ;

}

void Scene::Load( string filename )
{
    Load( "", filename);
}

void Scene::Load( string path, string filename )
{
    ifstream f;
    string filepath = path + filename + ".sccene";
    if( !f.is_open() )
    {
        cout << "Unable to load file \""<< filepath << "\", scene not loaded " << endl;
        return;
    }
    f.close();
}

std::string Scene::Getname()
{
    return name;
}
void Scene::Setname(std::string val)
{
    name = val;
}
Chunk* Scene::GetChunk( unsigned int id )
{
    if ( id < sceneChunks.size() ) {
        return &sceneChunks[ id ];
    }
    return NULL;
}
void Scene::AddChunk( Chunk val )
{
    sceneChunks.push_back( val );
}
void Scene::RemoveChunk( unsigned int id )
{
    if ( id < sceneChunks.size() ) {
        sceneChunks.erase( sceneChunks.begin() + id );
    }
}
void Scene::InsertChunk( unsigned int id, Chunk val)
{
    if ( id < sceneChunks.size() ) {
        sceneChunks.insert( sceneChunks.begin() + id , val );
    }
    else {
        sceneChunks.push_back( val );
    }
}
void Scene::SetChunk( unsigned int id, Chunk val )
{
    if ( id < sceneChunks.size() ) {
        sceneChunks[id] = val;
    }
}
