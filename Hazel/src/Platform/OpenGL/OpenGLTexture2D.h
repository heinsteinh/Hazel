#pragma once

#include "Hazel/Renderer/Texture2D.h"

namespace Hazel
{
    class OpenGLTexture2D : public Texture2D
    {
    private:
        std::string filename;
        int width = 0;
        int height = 0;
        unsigned int id = 0;

    public:
        OpenGLTexture2D(const std::string &filename);
        virtual ~OpenGLTexture2D();

        virtual int GetWidth() const override;
        virtual int GetHeight() const override;
        virtual void Bind(unsigned int slot = 0) const override;

    private:
        void LoadData();
        void CreateTexture(const void *data);
    };
}