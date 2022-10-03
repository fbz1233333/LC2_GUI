#pragma once

#include "stdafx.h"

class Shader 
{
public:

public:
	Shader(std::string vertexPath, std::string fragmentPath);
	Shader(std::string vertexPath, std::string fragmentPath, std::string geometryPath);

private:

	void LoadFromPath(std::string vertexPath, std::string fragmentPath);
	void LoadFromPath(std::string vertexPath, std::string fragmentPath, std::string geomertry);

	void LoadFromCode(const char* vShaderCode, const char* fShaderCode, const char* geometry = nullptr);

public:
	unsigned int GetId();

	unsigned int ID;

	void Use() const;

	void SetBool(const std::string &name, bool value)const;

	void SetInt(const std::string &name, int value) const;

	void SetFloat(const std::string &name, float value) const;

	void SetVec2(const std::string &name, const glm::vec2 &value) const;

	void SetVec2(const std::string &name, float x, float y) const;

	void SetVec3(const std::string &name, const glm::vec3 &value) const;

	void SetVec3(const std::string &name, float x, float y, float z) const;

	void SetVec4(const std::string &name, const glm::vec4 &value) const;

	void SetVec4(const std::string &name, float x, float y, float z, float w);

	void SetMat2(const std::string &name, const glm::mat2 &mat) const;

	void SetMat3(const std::string &name, const glm::mat3 &mat) const;

	void SetMat4(const std::string &name, const glm::mat4 &mat) const;
	
	unsigned int GetLoc(const std::string& name);
private:

	void checkCompileErrors(GLuint shader, std::string type);

};
