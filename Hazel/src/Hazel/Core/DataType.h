#pragma once

namespace Hazel
{
    class HAZEL_API DataType
    {
    public:
        static const DataType Bool;
        static const DataType Integer;
        static const DataType Float;

    private:
        static int currentId;

        unsigned char id = 0;
        unsigned char size = 0;

    public:
        inline size_t GetHashCode() const
        {
            return std::hash<unsigned char>()(id);
        }

        constexpr size_t GetSize() const
        {
            return static_cast<size_t>(size);
        }

        constexpr bool operator==(const DataType &other) const
        {
            return id == other.id;
        }

        constexpr bool operator!=(const DataType &other) const
        {
            return id != other.id;
        }

    private:
        DataType(size_t size);
    };
}

namespace std
{
    template<>
    struct hash<Hazel::DataType>
    {
        inline size_t operator()(Hazel::DataType dataType) const
        {
            return dataType.GetHashCode();
        }
    };
}