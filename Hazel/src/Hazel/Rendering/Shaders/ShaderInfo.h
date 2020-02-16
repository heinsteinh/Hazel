#pragma once

#include "ShaderLanguage.h"
#include "ShaderType.h"
#include "GlslParser.h"

#include "Hazel/Utils/FileInfo.h"

namespace Hazel
{
    class HAZEL_API ShaderInfo
    {
    private:
        ShaderLanguage language = ShaderLanguage::Glsl;
        std::string name;
        std::unordered_map<ShaderType, std::string> sources;

    public:
        static inline ShaderInfo FromFile(const std::string &filename)
        {
            ShaderInfo info;
            info.language = ShaderLanguage::Glsl;
            info.name = FileInfo(filename).GetBaseName();
            info.sources = GlslParser().Parse(filename);
            return info;
        }

        ShaderInfo() = default;

        inline ShaderLanguage GetLanguage() const
        {
            return language;
        }

        inline const std::string &GetName() const
        {
            return name;
        }

        inline const auto &GetSources() const
        {
            return sources;
        }

        inline const std::string &GetSource(ShaderType type) const
        {
            static const std::string empty;
            auto i = sources.find(type);
            return i == sources.end() ? empty : i->second;
        }

        inline void SetLanguage(ShaderLanguage language)
        {
            this->language = language;
        }

        inline void SetName(const std::string &name)
        {
            this->name = name;
        }

        inline void AddSource(ShaderType type, const std::string &source)
        {
            sources[type] = source;
        }
    };
}