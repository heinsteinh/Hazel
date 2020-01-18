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
        auto data = stbi_load(filename.c_str(), &width, &height, &numChannels, 0);
        ValidateAndCreate(data);
        stbi_image_free(data);
    }

    void OpenGLTexture2D::ValidateAndCreate(const void *data)
    {
        if (!data)
        {
            CoreError("Failed to load image {}", filename);
            return;
        }
        if (!CheckFormat())
        {
            CoreError("Format with {} channels not supported.", numChannels);
            return;
        }
        Create(data);
    }

    static const std::unordered_map<int, std::pair<unsigned int, unsigned int>> formats = {
        {3, {GL_RGB8, GL_RGB}},
        {4, {GL_RGBA8, GL_RGBA}}
    };

    bool OpenGLTexture2D::CheckFormat()
    {
        auto i = formats.find(numChannels);
        if (i == formats.end())
        {
            internalFormat = dataFormat = 0;
            return false;
        }
        internalFormat = i->second.first;
        dataFormat = i->second.second;
        return true;
    }

    void OpenGLTexture2D::Create(const void *data)
    {
        glCreateTextures(GL_TEXTURE_2D, 1, &id);
        glTextureStorage2D(id, 1, internalFormat, width, height);
        glTextureParameteri(id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTextureParameteri(id, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(id, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTextureSubImage2D(id, 0, 0, 0, width, height, dataFormat, GL_UNSIGNED_BYTE, data);
        CoreInfo("Texture {} loaded successfuly from file {}", id, filename);
    }
}