#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Shader.h"

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

        void UploadUniform(const std::string &name, int value);
        void UploadUniform(const std::string &name, float value);
        void UploadUniform(const std::string &name, const glm::vec2 &value);
        void UploadUniform(const std::string &name, const glm::vec3 &value);
        void UploadUniform(const std::string &name, const glm::vec4 &value);
        void UploadUniform(const std::string &name, const glm::mat3 &value);
        void UploadUniform(const std::string &name, const glm::mat4 &value);

        virtual bool IsExecutable() const override;
        virtual const std::string &GetName() const override;
        virtual void Bind() const override;
        virtual void UnBind() const override;
        virtual void Put(const std::string &name, int value) override;
        virtual void Put(const std::string &name, float value) override;
        virtual void Put(const std::string &name, const glm::vec3 &value) override;
        virtual void Put(const std::string &name, const glm::vec4 &value) override;
        virtual void Put(const std::string &name, const glm::mat4 &value) override;

    private:
        int GetUniformLocation(const std::string &name);
    };
}