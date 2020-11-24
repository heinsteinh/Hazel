#pragma once

namespace Hazel
{
	class OpenGLBinder
	{
	public:
		template<typename ObjectType, typename OpenGLType>
		static void Bind(OpenGLType *&target, const std::shared_ptr<ObjectType> &source)
		{
			if (target == source.get())
			{
				return;
			}
			if (source)
			{
				HZ_ASSERT(typeid(*source) == typeid(OpenGLType), "Not an OpenGL type.");
				target = static_cast<OpenGLType *>(source.get());
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