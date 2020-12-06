#pragma once

namespace Hazel
{
	class EditorMenu
	{
	private:
		bool open = true;

	public:
		void Draw();

		bool IsOpen() const
		{
			return open;
		}
	};
}