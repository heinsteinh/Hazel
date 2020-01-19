#pragma once

#include "Hazel/Rendering/Texture2D.h"

namespace Hazel
{
    class OpenGLTexture2D : public Texture2D
    {
    private:
        unsigned int id = 0;
        int width = 0;
        int height = 0;
        int numChannels = 0;
        unsigned int internalFormat = 0;
        unsigned int dataFormat = 0;

    public:
        OpenGLTexture2D(int width, int height);
        OpenGLTexture2D(const std::string &filename);
        virtual ~OpenGLTexture2D();

        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual void SetData(const void *data) override;
        virtual void Bind(unsigned int slot = 0) const override;

    private:
        void LoadData(const std::string &filename);
        void ValidateAndCreate(const void *data);
        bool Validate(const void *data);
        bool LoadFormat();
        void Create();
    };
}