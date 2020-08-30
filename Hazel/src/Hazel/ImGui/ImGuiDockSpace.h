#pragma once

namespace Hazel
{
	class ImGuiDockSpace
	{
	private:
		bool open = true;

	public:
		ImGuiDockSpace();

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