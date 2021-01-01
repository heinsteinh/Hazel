#pragma once

#include <string>

#include "yaml-cpp/yaml.h"

namespace Hazel
{
	class YamlValue
	{
	public:
		class Iterator
		{
		private:
			YAML::const_iterator iterator;

		public:
			Iterator() = default;

			Iterator(YAML::const_iterator iterator)
				: iterator(iterator)
			{
			}

			bool operator!=(const Iterator &other) const
			{
				return iterator != other.iterator;
			}

			Iterator &operator++()
			{
				++iterator;
				return *this;
			}

			YamlValue operator*() const
			{
				return *iterator;
			}
		};

	private:
		YAML::Node node;

	public:
		static YamlValue FromYaml(const std::string &yaml)
		{
			return YAML::Load(yaml);
		}

		YamlValue() = default;

		Iterator begin() const
		{
			return node.begin();
		}

		Iterator end() const
		{
			return node.end();
		}

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
		T ValueOr(const T &defaultValue)
		{
			T value = defaultValue;
			Extract(value);
			return value;
		}

	private:
		YamlValue(const YAML::Node &node)
			: node(node)
		{
		}
	};
}