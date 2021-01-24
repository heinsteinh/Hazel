#pragma once

#include <memory>

#include "Hazel/Core/Utils/StaticCast.h"

namespace Hazel
{
	class OpenGLBinder
	{
	public:
		template<typename OpenGLType, typename BaseType>
		static bool Bind(std::weak_ptr<OpenGLType> &currentObject, const std::shared_ptr<BaseType> &newObject)
		{
			return Bind(currentObject, StaticCast::Convert<OpenGLType>(newObject));
		}

		template<typename OpenGLType>
		static bool Bind(std::weak_ptr<OpenGLType> &currentObject, const std::shared_ptr<OpenGLType> &newObject)
		{
			auto strongRef = currentObject.lock();
			auto bound = Bind(strongRef, newObject);
			currentObject = strongRef;
			return bound;
		}

		template<typename OpenGLType, typename BaseType>
		static bool Bind(std::shared_ptr<OpenGLType> &currentObject, const std::shared_ptr<BaseType> &newObject)
		{
			return Bind(currentObject, StaticCast::Convert<OpenGLType>(newObject));
		}

		template<typename OpenGLType>
		static bool Bind(std::shared_ptr<OpenGLType> &currentObject, const std::shared_ptr<OpenGLType> &newObject)
		{
			if (newObject != currentObject)
			{
				if (newObject)
				{
					newObject->Bind();
					currentObject = newObject;
					return true;
				}
				else
				{
					currentObject->Unbind();
					currentObject = nullptr;
				}
			}
			return false;
		}
	};
}