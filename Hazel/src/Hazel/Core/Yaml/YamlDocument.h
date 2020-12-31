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

		template<typename T>
		YamlDocument &WriteBasicType(const T &value)
		{
			emitter << value;
			return *this;
		}

		template<typename T>
		YamlDocument &Write(const T &value)
		{
			YamlSerializer<T>::Serialize(*this, value);
			return *this;
		}

		template<typename KeyType, typename ValueType>
		YamlDocument &Write(const KeyType &key, const ValueType &value)
		{
			Key().Write(key).Value().Write(value);
			return *this;
		}
	};
}