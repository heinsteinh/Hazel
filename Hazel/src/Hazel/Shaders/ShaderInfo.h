#pragma once

#include "Hazel/Shaders/ShaderType.h"
#include "Hazel/FileSystem/FileReader.h"
#include "Hazel/FileSystem/Filename.h"

namespace Hazel
{
	struct ShaderInfo
	{
		std::string Name;
		std::unordered_map<ShaderType, std::string> Sources;

		static inline ShaderInfo FromFiles(const std::unordered_map<ShaderType, std::string> &files)
		{
			ShaderInfo result = {Filename::GetBaseName(files.at(ShaderType::Vertex))};
			result.Sources.reserve(files.size());
			for (const auto &[type, file] : files)
			{
				result.Sources[type] = FileReader::ReadAll(file);
			}
			return result;
		}
	};
}