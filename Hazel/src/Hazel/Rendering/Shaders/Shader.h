#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Mesh/Uniform.h"
#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "ShaderInfo.h"
#include "ShaderCompilationException.h"

namespace Hazel
{
	class Shader
	{
	private:
		std::string name;
		std::string filename;
		Uniform uniform;
		bool uniformUpdated = true;
		VertexLayout inputLayout;
		ShaderProperties properties;

	public:
		Shader(const ShaderInfo &info)
			: name(info.Name),
			filename(info.Filename),
			uniform(info.UniformLayout),
			inputLayout(info.InputLayout),
			properties(info.Properties)
		{
		}

		virtual ~Shader() = default;

		const std::string &GetName() const
		{
			return name;
		}

		void SetName(const std::string &name)
		{
			this->name = name;
		}

		const std::string &GetFilename() const
		{
			return filename;
		}

		const Uniform &GetUniform() const
		{
			return uniform;
		}

		Uniform &UpdateUniform()
		{
			uniformUpdated = true;
			return uniform;
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

		const ShaderProperties &GetProperties() const
		{
			return properties;
		}
	};
}