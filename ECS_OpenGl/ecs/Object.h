#ifndef OBJECT_H
#define OBJECT_H

#include <string>

#include "../Shader.h"
#include "../TextureLoading.h"
#include "../VertexArraysObject.h"

class Object {
public:
	Object() = default;

	Object(const std::string& name, TextureLoading texture, Shader shader);

	Object(const std::string& name, Shader shader);

	const std::string& GetName() const;

	TextureLoading GetTexture() const;

	void SetName(const std::string name);

	void SetTexture(TextureLoading texture);

	void SetActive(bool active);

	bool IsActive() const;

	void SetID(Shader shader);

	Shader GetID();

	VertexArraysObject GetVAO();
private:
	std::string name = "";

	TextureLoading texture;

	Shader shader;

	bool active = false;

	VertexArraysObject VAO;
};

#endif