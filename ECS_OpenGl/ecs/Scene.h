#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <memory>

#include "../TextureLoading.h"
#include "../Shader.h"
#include "Object.h"
#include "Render.h"
#include "../Camera.h"

class Scene {
public:
	Scene() = default;

	~Scene();

	void CreateObject(const std::string& name, const std::string& path_texture, const std::string& path_shader);

	void CreateObject(const std::string& name, std::vector<std::string> path_texture, const std::string& path_shader);

	void CreateObject(const std::string& name, const std::string& path_shader);

	void Setup();

	void Light(Camera& camera);

	void Draw(Camera& camera);

	Object FindObjectByName(const std::string& name);

	std::vector<std::shared_ptr<Object>>& GetObjects();
private:
	std::vector<std::shared_ptr<Object>> objects;

	Render render;
};

#endif