#pragma once

#include "Hazel/Core/Application/ApplicationLayer.h"

namespace Hazel
{
	class GuiContext;
	class GuiRenderer;

	class GuiLayer : public ApplicationLayer
	{
	private:
		std::unique_ptr<GuiContext> context;
		std::unique_ptr<GuiRenderer> renderer;

	public:
		GuiLayer();

		void BeginRender();
		void EndRender();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event &e) override;

	private:
		bool CanBlockKeyboard() const;
		bool CanBlockMouse() const;
		bool WantCaptureKeyboard() const;
		bool WantCaptureMouse() const;
		bool WantBlockEvent(Event &e) const;
	};
}