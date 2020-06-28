#pragma once

namespace Hazel
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual void MakeCurrent() = 0;
		virtual void SwapBuffers() = 0;
	};
}