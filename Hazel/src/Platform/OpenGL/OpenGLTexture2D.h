#pragma once

#include "Hazel/Rendering/Texture2D.h"

namespace Hazel
{
    class OpenGLTexture2D : public Texture2D
    {
    private:
        unsigned int id = 0;
        std::string filename;
        int width = 0;
        int height = 0;
        int numChannels = 0;
        unsigned int internalFormat = 0;
        unsigned int dataFormat = 0;

    public:
        OpenGLTexture2D(const std::string &filename);
        virtual ~OpenGLTexture2D();

        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual void Bind(unsigned int slot = 0) const override;

    private:
        void LoadData();
        void ValidateAndCreate(const void *data);
        bool CheckFormat();
        void Create(const void *data);
    };
}