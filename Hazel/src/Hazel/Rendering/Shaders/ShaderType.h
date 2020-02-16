#pragma once

namespace Hazel
{
    class HAZEL_API ShaderType
    {
    public:
        static const ShaderType Unknown;
        static const ShaderType Vertex;
        static const ShaderType Pixel;

    private:
        static int currentId;
        static std::vector<std::string> keys;
        static std::unordered_map<std::string, ShaderType> shaderTypes;

        int id = 0;

    public:
        static ShaderType FromKey(const std::string &key)
        {
            auto i = shaderTypes.find(key);
            return i == shaderTypes.end() ? Unknown : i->second;
        }

        inline size_t GetHashCode() const
        {
            return std::hash<int>()(id);
        }

        inline const std::string &GetKey() const
        {
            return keys[id];
        }

        constexpr bool operator==(const ShaderType &other) const
        {
            return id == other.id;
        }

        constexpr bool operator!=(const ShaderType &other) const
        {
            return id != other.id;
        }

    private:
        ShaderType();
    };
}

namespace std
{
    template<>
    struct hash<Hazel::ShaderType>
    {
        inline size_t operator()(Hazel::ShaderType shaderType) const
        {
            return shaderType.GetHashCode();
        }
    };
}