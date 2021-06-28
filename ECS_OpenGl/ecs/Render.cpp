#include "Render.h"

Render::Render()
{
	positionsLight[0] = Vec3(0.0f, 0.0f, -3.0f);
	positionsLight[1] = Vec3(1.9f, 0.0f, 2.0f);
	positionsLight[2] = Vec3(1.3f, 0.0f, -4.0f);

	positionsCube[0] = Vec3(0.0f, 0.0f, 0.0f);
	positionsCube[1] = Vec3(1.5f, 0.2f, -1.5f);
}

void Render::SetupTexture(const std::string& path_texture, const std::string& name) {
	TextureLoading texture(path_texture.c_str());
	textures[name] = texture;
}

void Render::SetupTexture(std::vector<std::string> path_textures, const std::string& name) {
	TextureLoading texture(path_textures);
	textures[name] = texture;
}

void Render::SetupShader(const std::string& path_shader, const std::string& name) {
	Shader shader(path_shader + ".vs", path_shader + ".fs");
	shaders[name] = shader;
}

void Render::Cube(Object object) {
	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	VertexBufferObjects VBO(vertices, sizeof(vertices) / sizeof(float));
	VBO.Binding();

	object.GetVAO().Binding();
	object.GetVAO().VertexAttribPointer(0, 3, 8 * sizeof(float), (void*)0);
	object.GetVAO().VertexAttribPointer(1, 3, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	object.GetVAO().VertexAttribPointer(2, 2, 8 * sizeof(float), (void*)(6 * sizeof(float)));
}

void Render::LightCube(Object object) {
	object.GetVAO().Binding();
	object.GetVAO().VertexAttribPointer(0, 3, 8 * sizeof(float), (void*)0);
}

void Render::SkyBox(Object object) {
	float vertices[] = {
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};

	object.GetVAO().Binding();
	VertexBufferObjects VBO(vertices, sizeof(vertices) / sizeof(float));
	object.GetVAO().VertexAttribPointer(0, 3, 3 * sizeof(float), (void*)0);

	object.GetID().Use();
	object.GetID().SetInt("skybox", 0);
}

void Render::DrawCube(Object object, Camera& camera) {
	Mat4 view(camera.GetViewMatrix());
	Mat4 projection(camera.GetProjectionMatrix());

	object.GetID().Use();
	object.GetID().SetMat4("view", view);
	object.GetID().SetMat4("projection", projection);

	object.GetVAO().Binding();

	for (int i = 0; i < 2; i++) {
		Mat4 model(1.0f);
		model = model.Translate(positionsCube[i]);
		object.GetID().SetMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void Render::DrawLightCube(Object object, Camera& camera) {
	Mat4 view(camera.GetViewMatrix());
	Mat4 projection(camera.GetProjectionMatrix());

	object.GetID().Use();
	object.GetID().SetMat4("view", view);
	object.GetID().SetMat4("projection", projection);

	object.GetVAO().Binding();

	for (int i = 0; i < 3; i++) {
		Mat4 model(1.0f);
		model = model.Translate(positionsLight[i]);
		object.GetID().SetMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

void Render::DrawSkyBox(Object object, Camera& camera) {
	Mat4 view(camera.GetViewMatrix());
	Mat4 projection(camera.GetProjectionMatrix());

	glDepthFunc(GL_LEQUAL);
	object.GetID().Use();
	view = camera.GetViewSkyBox();
	object.GetID().SetMat4("view", view);
	object.GetID().SetMat4("projection", projection);

	object.GetVAO().Binding();
	object.GetTexture().Binding(0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	object.GetVAO().Binding(0);
	glDepthFunc(GL_LESS);
}

void Render::SetLighting(Object object, Camera& camera) {
	object.GetID().Use();
	object.GetID().SetVec3("viewPos", camera.GetPosition());
	object.GetID().SetFloat("material.shininess", 32.0f);

	Light dirLight(Vec3(-0.2f, -1.0f, -0.3f), Vec3(0.05f, 0.05f, 0.05f), Vec3(0.4f, 0.4f, 0.4f), Vec3(0.5f, 0.5f, 0.5f));
	object.GetID().SetVec3("dirLight.direction", dirLight.direction);
	object.GetID().SetVec3("dirLight.ambient", dirLight.ambient);
	object.GetID().SetVec3("dirLight.diffuse", dirLight.diffuse);
	object.GetID().SetVec3("dirLight.specular", dirLight.specular);

	for (int i = 0; i < 3; i++) {
		object.GetID().SetVec3("pointLights[" + std::to_string(i) + "].position", positionsLight[i]);
		object.GetID().SetVec3("pointLights[" + std::to_string(i) + "].ambient", Vec3(0.05f, 0.05f, 0.05f));
		object.GetID().SetVec3("pointLights[" + std::to_string(i) + "].diffuse", Vec3(0.8f, 0.8f, 0.8f));
		object.GetID().SetVec3("pointLights[" + std::to_string(i) + "].specular", Vec3(1.0f, 1.0f, 1.0f));
		object.GetID().SetFloat("pointLights[" + std::to_string(i) + "].constant", 1.0f);
		object.GetID().SetFloat("pointLights[" + std::to_string(i) + "].linear", 0.09);
		object.GetID().SetFloat("pointLights[" + std::to_string(i) + "].quadratic", 0.032);
	}

	object.GetID().SetVec3("spotLight.position", camera.GetPosition());
	object.GetID().SetVec3("spotLight.direction", camera.GetFront());
	object.GetID().SetVec3("spotLight.ambient", Vec3(0.0f, 0.0f, 0.0f));
	object.GetID().SetVec3("spotLight.diffuse", Vec3(1.0f, 1.0f, 1.0f));
	object.GetID().SetVec3("spotLight.specular", Vec3(1.0f, 1.0f, 1.0f));
	object.GetID().SetFloat("spotLight.constant", 1.0f);
	object.GetID().SetFloat("spotLight.linear", 0.09);
	object.GetID().SetFloat("spotLight.quadratic", 0.032);
	object.GetID().SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.0f)));
	object.GetID().SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
}

TextureLoading Render::GetTexture(const std::string& name)
{
	return textures[name];
}

Shader Render::GetShader(const std::string& name)
{
	return shaders[name];
}
