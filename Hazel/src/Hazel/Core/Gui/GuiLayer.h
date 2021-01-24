#pragma once

#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Rendering/GuiRenderer/GuiRenderer.h"
#include "Private/GuiContext.h"

namespace Hazel
{
	class GuiLayer : public Layer
	{
	private:
		std::unique_ptr<GuiContext> context;
		std::shared_ptr<GuiRenderer> renderer;

	public:
		GuiLayer();

		void BeginRender();
		void EndRender();
		bool WantCaptureKeyboard() const;
		bool WantCaptureMouse() const;
		bool WantBlockEvent(Event &e) const;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event &e) override;
	};
}