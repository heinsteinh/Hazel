#include "OpenGLTexture2D.h"

#include "glad/glad.h"
#include "stb_image.h"

namespace Hazel
{
    OpenGLTexture2D::OpenGLTexture2D(const std::string &filename)
        : filename(filename)
    {
        LoadData();
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

    void OpenGLTexture2D::Bind(unsigned int slot) const
    {
        glBindTextureUnit(slot, id);
    }

    void OpenGLTexture2D::LoadData()
    {
        stbi_set_flip_vertically_on_load(1);
        int numChannels;
        auto data = stbi_load(filename.c_str(), &width, &height, &numChannels, 0);
        if (!data)
        {
            CoreError("Failed to load image {}", filename);
            return;
        }
        CreateTexture(data);
        stbi_image_free(data);
    }

    void OpenGLTexture2D::CreateTexture(const void *data)
    {
        glCreateTextures(GL_TEXTURE_2D, 1, &id);
        glTextureStorage2D(id, 1, GL_RGB8, width, height);
        glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTextureSubImage2D(id, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        CoreInfo("Texture {} loaded successfuly from file {}", id, filename);
    }
}