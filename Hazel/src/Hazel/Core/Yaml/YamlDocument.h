#pragma once

#include <string>

#include "yaml-cpp/yaml.h"

namespace Hazel
{
	class YamlDocument
	{
	private:
		YAML::Emitter emitter;

	public:
		const char *GetData() const
		{
			return emitter.c_str();
		}

		YamlDocument &Write(bool value)
		{
			emitter << value;
			return *this;
		}

		YamlDocument &Write(int value)
		{
			emitter << value;
			return *this;
		}

		YamlDocument &Write(uint32_t value)
		{
			emitter << value;
			return *this;
		}

		YamlDocument &Write(size_t value)
		{
			emitter << value;
			return *this;
		}

		YamlDocument &Write(float value)
		{
			emitter << value;
			return *this;
		}

		YamlDocument &Write(const char *value)
		{
			emitter << value;
			return *this;
		}

		YamlDocument &Write(const std::string &value)
		{
			emitter << value;
			return *this;
		}

		template<typename T>
		YamlDocument &Write(const T &value)
		{
			YamlSerializer::Serialize(*this, value);
			return *this;
		}

		YamlDocument &Key()
		{
			emitter << YAML::Key;
			return *this;
		}

		YamlDocument &Value()
		{
			emitter << YAML::Value;
			return *this;
		}

		YamlDocument &InlineBlock()
		{
			emitter << YAML::Flow;
			return *this;
		}

		YamlDocument &BeginSequence()
		{
			emitter << YAML::BeginSeq;
			return *this;
		}

		YamlDocument &EndSequence()
		{
			emitter << YAML::EndSeq;
			return *this;
		}

		YamlDocument &BeginMap()
		{
			emitter << YAML::BeginMap;
			return *this;
		}

		YamlDocument &EndMap()
		{
			emitter << YAML::EndMap;
			return *this;
		}
	};
}