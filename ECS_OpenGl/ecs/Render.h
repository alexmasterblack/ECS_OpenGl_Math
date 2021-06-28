#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include <map>

#include "../TextureLoading.h"
#include "../VertexArraysObject.h"
#include "../VertexBufferObjects.h"
#include "../Shader.h"
#include "Object.h"
#include "../Light.h"
#include "../Camera.h"

#include <GL/glew.h>
#include "../glm/gtc/matrix_transform.hpp"

#include "../my_math/Vec3.h"


class Render {
public:
	Render();

	void SetupTexture(const std::string& path_texture, const std::string& name);

	void SetupTexture(std::vector<std::string> path_textures, const std::string& name);

	void SetupShader(const std::string& path_shader, const std::string& name);

	void Cube(Object object);

	void LightCube(Object object);

	void SkyBox(Object object);

	void DrawCube(Object object, Camera& camera);

	void DrawLightCube(Object object, Camera& camera);

	void DrawSkyBox(Object object, Camera& camera);

	void SetLighting(Object object, Camera& camera);

	TextureLoading GetTexture(const std::string& name);

	Shader GetShader(const std::string& name);

private:
	std::map<std::string, TextureLoading> textures;

	std::map<std::string, Shader> shaders;

	//glm::vec3 positionsLight[3];

	Vec3 positionsLight[3];

	Vec3 positionsCube[2];

	//glm::vec3 positionsCube[2];
};

#endif