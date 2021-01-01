#pragma once

#include "ShaderSourceMap.h"
#include "ShaderCompilationException.h"
#include "Hazel/Core/FileSystem/FileReader.h"
#include "Hazel/Core/FileSystem/Filename.h"

namespace Hazel
{
	struct ShaderInfo
	{
		ShaderSourceMap Sources;

		static ShaderInfo FromFiles(const ShaderSourceMap &files)
		{
			ShaderInfo result;
			for (const auto &[type, file] : files)
			{
				if (!file.empty())
				{
					result.Sources[type] = FileReader::ReadAll(file);
				}
			}
			return result;
		}
	};
}