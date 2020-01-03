#pragma once

#include "glm/glm.hpp"

#include "Hazel/Renderer/Shader.h"

namespace Hazel
{
    class OpenGLShader : public Shader
    {
    private:
        std::string name;
        unsigned int id = 0;

    public:
        OpenGLShader(
            const std::string &name,
            const std::string &vertexSource,
            const std::string &fragmentSource);
        OpenGLShader(
            const std::string &name,
            const std::string &filename);
        virtual ~OpenGLShader();

        void UploadUniformInt(const std::string &name, int value);
        void UploadUniformFloat(const std::string &name, float value);
        void UploadUniformFloat2(const std::string &name, const glm::vec2 &value);
        void UploadUniformFloat3(const std::string &name, const glm::vec3 &value);
        void UploadUniformFloat4(const std::string &name, const glm::vec4 &value);
        void UploadUniformMat3(const std::string &name, const glm::mat3 &value);
        void UploadUniformMat4(const std::string &name, const glm::mat4 &value);

        virtual bool IsExecutable() const override;
        virtual const std::string &GetName() const override;
        virtual void Bind() const override;
        virtual void UnBind() const override;

    private:
        int GetUniformLocation(const std::string &name);
    };
}