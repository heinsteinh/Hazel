#pragma once

#include <memory>
#include <optional>

#include "Hazel/Rendering/Shaders/Shader.h"
#include "Hazel/Rendering/GraphicsBuffers/InputLayout.h"
#include "Uniform.h"

namespace Hazel
{
	struct MaterialShader
	{
		std::shared_ptr<Shader> Shader;
		Uniform Uniform;
		std::optional<size_t> ViewProjectionIndex;
		std::shared_ptr<InputLayout> InputLayout;
	};
}