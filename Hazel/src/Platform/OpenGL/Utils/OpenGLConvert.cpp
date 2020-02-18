#include "OpenGLConvert.h"

#include "glad/glad.h"

namespace Hazel
{
    const std::unordered_map<DataType, unsigned int> OpenGLConvert::dataTypes = {
        {DataType::Float, GL_FLOAT},
        {DataType::Integer, GL_INT},
        {DataType::Bool, GL_BOOL}
    };

    const std::unordered_map<ShaderType, unsigned int> OpenGLConvert::shaderTypes = {
        {ShaderType::Vertex, GL_VERTEX_SHADER},
        {ShaderType::Pixel, GL_FRAGMENT_SHADER}
    };

    const std::unordered_map<TextureFiltering, unsigned int> OpenGLConvert::filters = {
        {TextureFiltering::Nearest, GL_NEAREST},
        {TextureFiltering::Linear, GL_LINEAR}
    };

    const std::unordered_map<TextureWrapping, unsigned int> OpenGLConvert::wraps = {
        {TextureWrapping::Repeat, GL_REPEAT},
        {TextureWrapping::MirroredRepeat, GL_MIRRORED_REPEAT},
        {TextureWrapping::ClampToEdge, GL_CLAMP_TO_EDGE}
    };

    const std::unordered_map<ColorFormat, unsigned int> OpenGLConvert::colorFormats = {
        {ColorFormat::Rgb, GL_RGB},
        {ColorFormat::Rgba, GL_RGBA}
    };
}