#include "GameObject.h"

GameObject::GameObject() : x(0), y(0), scale(64), texture(new char[40]) {
    SetTexture("Textures/missing.bmp");
}

GameObject::GameObject(float _x, float _y) : x(_x), y(_y), scale(64), texture(new char[40]) {
    SetTexture("Textures/missing.bmp");
}

GameObject::GameObject(float _x, float _y, char* _texture) : x(_x), y(_y), scale(64), texture(_texture) {
    SetTexture(texture);
}

GameObject::GameObject(const GameObject& go) {
    x = go.x;
    y = go.y;
    scale = go.scale;
    texture = go.texture;

    SetTexture(texture);
}

void GameObject::SetTexture(char* _texturePath) {
    struct stat fileAtt;
    if(stat(_texturePath, &fileAtt) != 0) {
       texture = "Textures/missing.bmp";
       std::cout << "Missing texture set on path : " << _texturePath << std::endl;
    } else {
        texture = _texturePath;
    }
}

void GameObject::SetPosition(float _x, float _y) {
    x = _x;
    y = _y;
}

float GameObject::GetX() { return x; }
float GameObject::GetY() { return y; }
int GameObject::GetScale() { return scale; }
char* GameObject::GetTexture() { return texture; }

GameObject::~GameObject() {
}
