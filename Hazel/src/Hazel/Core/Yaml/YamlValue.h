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

		size_t GetSize() const
		{
			if (IsValid())
			{
				return node.size();
			}
		}

		void Extract(bool &value) const
		{
			if (IsValid())
			{
				value = node.as<bool>(value);
			}
		}

		void Extract(int &value) const
		{
			if (IsValid())
			{
				value = node.as<int>(value);
			}
		}

		void Extract(uint32_t &value) const
		{
			if (IsValid())
			{
				value = node.as<uint32_t>(value);
			}
		}

		void Extract(size_t &value) const
		{
			if (IsValid())
			{
				value = node.as<size_t>(value);
			}
		}

		void Extract(float &value) const
		{
			if (IsValid())
			{
				value = node.as<float>(value);
			}
		}

		void Extract(std::string &value) const
		{
			if (IsValid())
			{
				value = node.as<std::string>(value);
			}
		}

		template<typename T>
		void Extract(T &value) const
		{
			if (IsValid())
			{
				YamlParser::Parse(*this, value);
			}
		}

		template<typename T>
		YamlValue operator[](const T &index) const
		{
			return node[index];
		}

	private:
		YamlValue(const YAML::Node &node)
			: node(node)
		{
		}
	};
}