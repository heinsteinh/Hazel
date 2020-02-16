#pragma once

namespace Hazel
{
    class ShaderLanguage
    {
    public:
        static const ShaderLanguage Unknown;
        static const ShaderLanguage Glsl;

    private:
        static int currentId;
        static std::vector<std::string> names;
        static const std::unordered_map<std::string, ShaderLanguage> extensions;

        int id;

    public:
        static ShaderLanguage FromFileExtension(const std::string &extension)
        {
            auto i = extensions.find(extension);
            return i == extensions.end() ? Unknown : i->second;
        }

        inline size_t GetHashCode() const
        {
            return std::hash<int>()(id);
        }

        inline const std::string &GetName() const
        {
            return names[id];
        }

        constexpr bool operator==(const ShaderLanguage &other) const
        {
            return id == other.id;
        }

        constexpr bool operator!=(const ShaderLanguage &other) const
        {
            return id != other.id;
        }

    private:
        ShaderLanguage();
    };
}

namespace std
{
    template<>
    struct hash<Hazel::ShaderLanguage>
    {
        inline size_t operator()(Hazel::ShaderLanguage language) const
        {
            return language.GetHashCode();
        }
    };
}