#pragma once

#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	class OpenGLBinder
	{
	public:
		template<typename BaseType, typename OpenGLType>
		static void Bind(OpenGLType *&target, BaseType *source)
		{
			if (target == source)
			{
				return;
			}
			if (source)
			{
				HZ_ASSERT(typeid(*source) == typeid(OpenGLType), "Not an OpenGL type.");
				target = static_cast<OpenGLType *>(source);
				target->Bind();
			}
			else
			{
				target->Unbind();
				target = nullptr;
			}
		}
	};
}