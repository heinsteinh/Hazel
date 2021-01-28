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
			auto newlyBound = Bind(strongRef, newObject);
			currentObject = strongRef;
			return newlyBound;
		}

		template<typename OpenGLType, typename BaseType>
		static bool Bind(std::shared_ptr<OpenGLType> &currentObject, const std::shared_ptr<BaseType> &newObject)
		{
			return Bind(currentObject, StaticCast::Convert<OpenGLType>(newObject));
		}

		template<typename OpenGLType>
		static bool Bind(std::shared_ptr<OpenGLType> &currentObject, const std::shared_ptr<OpenGLType> &newObject)
		{
			if (newObject == currentObject)
			{
				return false;
			}
			if (!newObject)
			{
				currentObject->Unbind();
				currentObject = nullptr;
				return false;
			}
			newObject->Bind();
			currentObject = newObject;
			return true;
		}
	};
}