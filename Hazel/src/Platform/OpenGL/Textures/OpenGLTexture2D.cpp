#include "OpenGLTexture2D.h"

#include "glad/glad.h"

#include "Platform/OpenGL/Utils/OpenGLConvert.h"

namespace Hazel
{
    OpenGLTexture2D::OpenGLTexture2D(const TextureInfo &info)
        : width(info.Width),
        height(info.Height),
        colorFormat(info.Format)
    {
        Init(info);
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &id);
    }

    int OpenGLTexture2D::GetWidth() const
    {
        return width;
    }

    int OpenGLTexture2D::GetHeight() const
    {
        return height;
    }

    void OpenGLTexture2D::SetData(const void *data)
    {
        glTextureSubImage2D(id, 0, 0, 0, width, height,
            OpenGLConvert::ToInternal(colorFormat), GL_UNSIGNED_BYTE, data);
    }

    void OpenGLTexture2D::Bind(unsigned int slot) const
    {
        glBindTextureUnit(slot, id);
    }

    void OpenGLTexture2D::Init(const TextureInfo &info)
    {
        Create();
        SetParameters(info);
        CoreInfo("Texture successfuly loaded with id {}", id);
    }

    void OpenGLTexture2D::Create()
    {
        glCreateTextures(GL_TEXTURE_2D, 1, &id);
        glTextureStorage2D(id, 1, GetInternalFormat(), width, height);
    }

    void OpenGLTexture2D::SetParameters(const TextureInfo &info)
    {
        glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, OpenGLConvert::ToInternal(info.MinFilter));
        glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, OpenGLConvert::ToInternal(info.MagFilter));
        glTextureParameteri(id, GL_TEXTURE_WRAP_S, OpenGLConvert::ToInternal(info.SWrap));
        glTextureParameteri(id, GL_TEXTURE_WRAP_T, OpenGLConvert::ToInternal(info.TWrap));
    }

    static const std::unordered_map<ColorFormat, unsigned int> internalFormats = {
        {ColorFormat::Rgb, GL_RGB8},
        {ColorFormat::Rgba, GL_RGBA8}
    };

    unsigned int OpenGLTexture2D::GetInternalFormat()
    {
        auto i = internalFormats.find(colorFormat);
        if (i == internalFormats.end())
        {
            CoreError("Unknown color format for texture creation {}", colorFormat);
            return 0;
        }
        return i->second;
    }
}