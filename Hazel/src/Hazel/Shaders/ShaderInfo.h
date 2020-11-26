#pragma once

#include "ShaderSourceMap.h"
#include "ShaderCompilationException.h"
#include "Hazel/FileSystem/FileReader.h"
#include "Hazel/FileSystem/Filename.h"

namespace Hazel
{
	struct ShaderInfo
	{
		std::string Name;
		ShaderSourceMap Sources;

		static ShaderInfo FromFiles(const std::vector<std::pair<ShaderType, std::string>> &files)
		{
			ShaderInfo result;
			for (const auto &[type, file] : files)
			{
				result.Sources[type] = FileReader::ReadAll(file);
			}
			if (!result.Sources.Contains(ShaderType::Vertex))
			{
				throw ShaderCompilationException("Missing vertex shader.");
			}
			if (!result.Sources.Contains(ShaderType::Pixel))
			{
				throw ShaderCompilationException("Missing pixel shader.");
			}
			result.Name = Filename::GetBaseName(files[0].second);
			return result;
		}
	};
}