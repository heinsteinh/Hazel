#pragma once

#include "Hazel/Layers/Layer.h"
#include "ImGuiRenderer.h"
#include "Helpers/ImGuiContextHolder.h"

namespace Hazel
{
	class ImGuiLayer : public Layer
	{
	private:
		std::shared_ptr<ImGuiRenderer> renderer;
		std::shared_ptr<ImGuiContextHolder> imGuiContext;

	public:
		ImGuiLayer();

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