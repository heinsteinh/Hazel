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
        unsigned char id = 0;
        unsigned char size = 0;

    public:
        constexpr DataType(const DataType &other) = default;

        constexpr size_t GetHashCode() const
        {
            return static_cast<size_t>(id);
        }

        constexpr size_t GetSize() const
        {
            return static_cast<size_t>(size);
        }

        constexpr DataType &operator=(const DataType &other) = default;

        constexpr bool operator==(const DataType &other) const
        {
            return id == other.id;
        }

    private:
        DataType(unsigned char id, size_t size)
            : id(id),
            size(static_cast<unsigned char>(size))
        {
        }
    };

    inline const DataType DataType::Bool(0, 1);
    inline const DataType DataType::Integer(1, sizeof(int));
    inline const DataType DataType::Float(2, sizeof(float));
}

namespace std
{
    template<>
    struct hash<Hazel::DataType>
    {
        constexpr size_t operator()(const Hazel::DataType &dataType) const
        {
            return dataType.GetHashCode();
        }
    };
}