#pragma once

namespace Sandbox
{
	class ImGuiDockSpace
	{
	private:
		bool open = true;

	public:
		void Begin();
		void End();

		constexpr bool IsOpen() const
		{
			return open;
		}

		constexpr void Open()
		{
			open = true;
		}

		constexpr void Close()
		{
			open = false;
		}
	};
}