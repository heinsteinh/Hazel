#pragma once

#include <string>

#include "yaml-cpp/yaml.h"

namespace Hazel
{
	class YamlValue
	{
	private:
		YAML::Node node;

	public:
		static YamlValue FromYaml(const std::string &yaml)
		{
			return YAML::Load(yaml);
		}

		YamlValue() = default;

		bool IsValid() const
		{
			return node.IsDefined();
		}

		bool IsNull() const
		{
			return IsValid() && node.IsNull();
		}

		bool IsScalar() const
		{
			return IsValid() && node.IsScalar();
		}

		bool IsSequence() const
		{
			return IsValid() && node.IsSequence();
		}

		bool IsMap() const
		{
			return IsValid() && node.IsMap();
		}

		size_t GetSize() const
		{
			return IsValid() ? node.size() : 0;
		}

		template<typename T>
		YamlValue operator[](const T &key) const
		{
			return IsMap() || IsSequence() ? node[key] : YamlValue();
		}

		template<typename T>
		void ExtractBasicType(T &value) const
		{
			value = node.as<T>(value);
		}

		template<typename T>
		void Extract(T &value) const
		{
			YamlSerializer<T>::Deserialize(*this, value);
		}

		template<typename T>
		T GetValueOr(const T &defaultValue) const
		{
			T value = defaultValue;
			Extract(value);
			return value;
		}

		template<typename FunctorType>
		void ForEachSequence(FunctorType functor) const
		{
			if (IsSequence())
			{
				for (const auto &item : node)
				{
					functor(YamlValue(item));
				}
			}
		}

		template<typename FunctorType>
		void ForEachMap(FunctorType functor) const
		{
			if (IsMap())
			{
				for (const auto &item : node)
				{
					functor(YamlValue(item.first), YamlValue(item.second));
				}
			}
		}

	private:
		YamlValue(const YAML::Node &node)
			: node(node)
		{
		}
	};
}