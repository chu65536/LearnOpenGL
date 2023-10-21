#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(const std::vector<Shader>& shaders) {
    m_id = glCreateProgram();

    for (auto shader: shaders) {
        glAttachShader(m_id, shader.GetID());
    }

    glLinkProgram(m_id);
    int success;
    char infoLog[512];
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(m_id, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER PROGRAM LINKING FAILED\n" << infoLog << std::endl;
    }
    
    for (auto shader: shaders) {
        glDeleteShader(shader.GetID());
    }
}

void ShaderProgram::Use() {
    glUseProgram(m_id);
}

void ShaderProgram::Delete() {
    glDeleteProgram(m_id);
}

void ShaderProgram::SetInt(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), value);
}

void ShaderProgram::SetMat4(const std::string &name, const glm::mat4 &mat) const {
        glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
unsigned int ShaderProgram::GetID() const {
    return m_id;
}