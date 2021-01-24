#pragma once

#include <optional>

#include "Uniform.h"

namespace Hazel
{
	struct ShaderUniformMap
	{
		std::optional<size_t> ViewProjectionIndex;

		template<typename T>
		void UpdateAttribute(Uniform &uniform, std::optional<size_t> index, const T &value)
		{
			if (index)
			{
				uniform.GetAttribute<T>(*index) = value;
			}
		}
	};
}