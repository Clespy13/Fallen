#pragma once

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
    public:
        Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
        ~Shader();

        void Use();

        void SetBool(std::string& name, bool value);
        void SetInt(std::string& name, int value);
        void SetFloat(std::string& name, float value);
        void SetFloat3(std::string& name, glm::vec3 value);
        void SetMat2(std::string& name, glm::mat2 value);
        void SetMat3(std::string& name, glm::mat3 value);
        void SetMat4(std::string& name, glm::mat4 value);


    private:
        unsigned int m_ID;

        void CheckCompileErrors(unsigned int shader, std::string type);
};
