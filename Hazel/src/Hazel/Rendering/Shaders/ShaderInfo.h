#pragma once

#include "ShaderSourceMap.h"
#include "ShaderCompilationException.h"
#include "Hazel/Core/FileSystem/FileReader.h"
#include "Hazel/Core/FileSystem/Filename.h"

namespace Hazel
{
	struct ShaderInfo
	{
		std::string Name;
		ShaderSourceMap Sources;

		static ShaderInfo FromFiles(const ShaderSourceMap &files)
		{
			ShaderInfo result;
			result.Name = Filename::GetBaseName(files[ShaderType::Vertex]);
			for (const auto &[type, file] : files)
			{
				result.Sources[type] = FileReader::ReadAll(file);
			}
			return result;
		}
	};
}