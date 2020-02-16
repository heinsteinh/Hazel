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

    const std::unordered_map<TextureInfo::Filter, unsigned int> OpenGLConvert::filters = {
        {TextureInfo::Filter::Nearest, GL_NEAREST},
        {TextureInfo::Filter::Linear, GL_LINEAR}
    };

    const std::unordered_map<TextureInfo::Wrap, unsigned int> OpenGLConvert::wraps = {
        {TextureInfo::Wrap::ClampToEdge, GL_CLAMP_TO_EDGE},
        {TextureInfo::Wrap::MirroredRepeat, GL_MIRRORED_REPEAT},
        {TextureInfo::Wrap::Repeat, GL_REPEAT}
    };

    const std::unordered_map<ColorFormat, unsigned int> OpenGLConvert::colorFormats = {
        {ColorFormat::Rgb, GL_RGB},
        {ColorFormat::Rgba, GL_RGBA}
    };
}