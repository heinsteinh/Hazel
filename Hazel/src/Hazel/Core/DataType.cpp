#include "DataType.h"

namespace Hazel
{
    const DataType DataType::Bool(1);
    const DataType DataType::Integer(sizeof(int));
    const DataType DataType::Float(sizeof(float));

    int DataType::currentId = 0;

    DataType::DataType(size_t size)
        : id(currentId++),
        size(static_cast<unsigned char>(size))
    {
    }
}