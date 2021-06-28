#include "Scene.h"

Scene::~Scene() {
	objects.clear();
}

void Scene::CreateObject(const std::string& name, const std::string& path_texture, const std::string& path_shader) {
	render.SetupShader(path_shader, name);
	render.SetupTexture(path_texture, name);
	std::shared_ptr<Object> object(new Object(name, render.GetTexture(name), render.GetShader(name)));
	objects.push_back(object);
}

void Scene::CreateObject(const std::string& name, std::vector<std::string> path_textures, const std::string& path_shader) {
	render.SetupShader(path_shader, name);
	render.SetupTexture(path_textures, name);
	std::shared_ptr<Object> object(new Object(name, render.GetTexture(name), render.GetShader(name)));
	objects.push_back(object);
}

void Scene::CreateObject(const std::string& name, const std::string& path_shader) {
	render.SetupShader(path_shader, name);
	std::shared_ptr<Object> object(new Object(name, render.GetShader(name)));
	objects.push_back(object);
}

void Scene::Setup() {
	render.Cube(FindObjectByName("Cube"));
	render.LightCube(FindObjectByName("LightCube"));
	render.SkyBox(FindObjectByName("Skybox"));
}

void Scene::Light(Camera& camera) {
	render.SetLighting(FindObjectByName("Cube"), camera);
}

void Scene::Draw(Camera& camera) {
	render.DrawCube(FindObjectByName("Cube"), camera);
	render.DrawLightCube(FindObjectByName("LightCube"), camera);
	render.DrawSkyBox(FindObjectByName("Skybox"), camera);
}

Object Scene::FindObjectByName(const std::string& name) {
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i].get()->GetName() == name) {
			return *objects[i].get();
			break;
		}
	}
}

std::vector<std::shared_ptr<Object>>& Scene::GetObjects() {
	return objects;
}