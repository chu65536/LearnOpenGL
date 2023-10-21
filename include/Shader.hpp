#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    Shader(unsigned int type, const std::string& path);
    unsigned int GetID() const;
private:
    void Compile(const std::string& source);
    unsigned int m_id;
    unsigned int m_type;
};