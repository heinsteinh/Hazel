#pragma once

#include "spdlog/fmt/ostr.h"

namespace Hazel
{
    class HAZEL_API ColorFormat
    {
    public:
        static const ColorFormat Invalid;
        static const ColorFormat Rgb;
        static const ColorFormat Rgba;

    private:
        static int currentId;
        static std::unordered_map<int, ColorFormat> formats;
        static std::vector<std::string> names;

        int id = 0;
        int numChannels = 0;

    public:
        static inline ColorFormat FromNumChannels(int numChannels)
        {
            auto keyValue = formats.find(numChannels);
            return keyValue == formats.end() ? Invalid : keyValue->second;
        }

        ColorFormat() = default;

        inline size_t GetHashCode() const
        {
            return static_cast<size_t>(id);
        }

        inline int GetNumChannels() const
        {
            return numChannels;
        }

        inline const std::string &GetName() const
        {
            return names[id];
        }

        inline bool operator==(ColorFormat other) const
        {
            return id == other.id;
        }

        inline bool operator!=(ColorFormat other) const
        {
            return id != other.id;
        }

    private:
        ColorFormat(int numChannels);
    };
}

namespace std
{
    template<>
    struct hash<Hazel::ColorFormat>
    {
        inline size_t operator()(Hazel::ColorFormat format) const
        {
            return format.GetHashCode();
        }
    };
}

inline std::ostream &operator<<(std::ostream &stream, Hazel::ColorFormat colorFormat)
{
    return stream << colorFormat.GetName() << " (" << colorFormat.GetNumChannels() << " channels)";
}