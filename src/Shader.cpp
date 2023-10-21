#include "Shader.hpp"


Shader::Shader(unsigned int type, const std::string& path): m_type(type) {
    std::ifstream sourceFile(path);
    std::stringstream buffer;
    buffer << sourceFile.rdbuf();

    std::string sourceCode = buffer.str();
    Compile(sourceCode);
}

void Shader::Compile(const std::string& source) {
    const char* shaderSource = source.c_str();
    unsigned int shader = glCreateShader(m_type);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::string type = "";
        switch(m_type) {
        case GL_VERTEX_SHADER:
            type = "VERTEX";
            break;
        case GL_FRAGMENT_SHADER:
            type = "FRAGMENT";
            break;
        }
        std::cout << "ERROR: " << type << "SHADER COMPILATION FAILED\n" << infoLog << std::endl;
        m_id = 0u;
        return;
    }
    m_id = shader;
}

unsigned int Shader::GetID() const {
    return m_id;
}
