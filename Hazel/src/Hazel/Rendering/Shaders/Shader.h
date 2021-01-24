#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "ShaderInfo.h"
#include "Uniform.h"
#include "ShaderCompilationException.h"

namespace Hazel
{
	class Shader
	{
	private:
		Uniform uniform;
		ShaderUniformMap uniformMap;
		bool uniformUpdated = true;
		VertexLayout inputLayout;

	public:
		Shader(const ShaderInfo &info)
			: uniform(info.UniformLayout),
			uniformMap(info.UniformMap),
			inputLayout(info.InputLayout)
		{
		}

		virtual ~Shader() = default;

		const Uniform &GetUniform() const
		{
			return uniform;
		}

		Uniform &UpdateUniform()
		{
			uniformUpdated = true;
			return uniform;
		}

		void SetViewProjection(const glm::mat4 &viewProjection)
		{
			uniformMap.UpdateAttribute(uniform, uniformMap.ViewProjectionIndex, viewProjection);
			uniformUpdated = true;
		}

		bool IsUniformUpdated() const
		{
			return uniformUpdated;
		}

		void ResetUniformUpdated()
		{
			uniformUpdated = false;
		}

		const VertexLayout &GetUniformLayout() const
		{
			return uniform.GetLayout();
		}

		const VertexLayout &GetInputLayout() const
		{
			return inputLayout;
		}
	};
}