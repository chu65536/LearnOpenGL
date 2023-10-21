#pragma once

#include <glm/glm.hpp>

#include <vector>

#include "Shader.hpp" 

class ShaderProgram {
public:
    ShaderProgram(const std::vector<Shader>& shaders);
    void Use();
    void Delete();
    void SetInt(const std::string &name, int value) const;
    void SetMat4(const std::string& name, const glm::mat4& mat) const;
    unsigned int GetID() const;
private:
    unsigned int m_id;
};