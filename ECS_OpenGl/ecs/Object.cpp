#include "Object.h"

Object::Object(const std::string& name, TextureLoading texture, Shader shader) :
	name(name), texture(texture), shader(shader), active(active) {}

Object::Object(const std::string& name, Shader shader) :
	name(name), shader(shader), active(active) {}

const std::string& Object::GetName() const {
	return name;
}

TextureLoading Object::GetTexture() const {
	return texture;
}

void Object::SetName(const std::string name) {
	this->name = name;
}

void Object::SetTexture(TextureLoading texture) {
	this->texture = texture;
}

void Object::SetActive(bool active) {
	this->active = active;
}

bool Object::IsActive() const {
	return active;
}

void Object::SetID(Shader shader) {
	this->shader = shader;
}

Shader Object::GetID() {
	return shader;
}

VertexArraysObject Object::GetVAO() {
	return VAO;
}
