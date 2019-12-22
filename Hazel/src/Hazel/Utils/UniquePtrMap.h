#pragma once

#include <memory>
#include <unordered_map>

namespace Hazel
{
    template<typename K, typename V>
    class UniquePtrMap
    {
    private:
        std::unordered_map<K, std::unique_ptr<V>> data;

    public:
        UniquePtrMap(std::initializer_list<std::pair<K, V *>> args)
        {
            for (const auto &arg : args)
            {
                data[arg.first] = std::move(std::unique_ptr<V>(arg.second));
            }
        }

        inline bool Contains(const K &key) const
        {
            return data.find(key) != data.end();
        }

        inline const V &operator[](const K &key) const
        {
            return *data.at(key).get();
        }

        inline V &operator[](const K &key)
        {
            return *data[key].get();
        }
    };
}